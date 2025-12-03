
! ---------------------------------------------------------------------------- !
!       FARM 1/2/25
!
! With this puzzle, there's a crow in the tree.
! If the player looks at the crow, they'll see he's holding onto a key.
! That is the key to the root cellar in this room.
! The player needs to throw the axe to kill the crow
! Then climb the tree to get the axe

Object  farm "Farm"
 with   description [;
          print "This weathered farmhouse ";
          print "could use a fresh coat of ";
          print "white paint. It sits on a ";
          print "road that runs east to west, ";
          print "with a haunted oak tree ";
          print "towering over the home. ";
          print "Attached to the house is ";
          print "a root cellar, while fields ";
          "of grapes lie west.";
        ],
        daemon [;
          if (player in self) {
            iBirdCall++;
            if (iBirdCall >= 3) {
              iBirdCall = 0;
              if (crow in self) {
                print "^The crow calls down from ";
                "the tree, taunting you.";
              }
            }
          }
        ],
        d_to [; <<Enter farmCellar>>; ],
        in_to [;
            if (farmCellar.doorsOpen) {
              print "You step into the dark ";
              print "cellar.^^";
              PlayerTo(rootCellar, 2);
              rtrue;
            }
            if (key in player) {
                if (farmCellar.doorsLocked) {
                  farmCellar.doorsLocked = false;
                  print "With an audible click, the ";
                  print "lock disengages. ";
                }
                farmCellar.doorsOpen=true;
                print "You swing the doors open as ";
                print "a cold blast of air hits ";
                print "your face.^^";
                PlayerTo(rootCellar, 2);
                rtrue;
            }
            print "The doors to the cellar are ";
            print "locked. You're going to ";
            "need a key.";
        ],
        w_to [; <<Enter farmFields>>; ],
        e_to [;
          print "The land becomes hilly to ";
          print "the east, with the nearest ";
          print "town three leagues away. ";
          print "But it's the wrong direction ";
          "to find Belkor.";
        ],
        u_to [; <<Climb farmTree>>; ],
        out_to [; <<Enter farmFields>>; ],
        before [;
          Listen:
            if (crow in farm) {
              print "It's hard to hear anything ";
              print "with the bird laughing all ";
              "the time.";
            }
            print "Far to the east, you listen ";
            print "to thunder roll over the ";
            "hills.";
          Smell:
            print "Fresh air blows through the ";
            print "farm, along with the ";
            print "sweetness of grapes hanging ";
            "in the air.";
        ],
        cant_go [;
          print "You can head west";
          if (farmCellar.doorsOpen) {
            " or down into the cellar.";
          }
          ", back to the fields.";
        ],
  has   light;

RoomObj farmObj "farm" farm
  with  name 'farm',
        description [;
          <<Look farm>>;
        ];

Object  farmHouse "house" farm
 with   name 'house' 'white' 'farmhouse' 'door',
        before [;
          Attack, Cut:
            print "That might relieve some ";
            print "stress, but you don't need ";
            "to get into the house.";
          Examine:
            print "This house looks tiny, ";
            print "sitting beneath such a ";
            print "large tree. The door is ";
            print "closed, and the windows ";
            print "are covered, while a root ";
            print "cellar sits off to the ";
            "side.";
          Open, Enter:
            print "You try the door to the ";
            print "house, but it's locked. ";
            "You're not getting inside.";
          Close:
            print "The door to the house is ";
            "closed.";
          Take, Push, PushDir, Pull:
            print "The house isn't going ";
            "anywhere.";
          Unlock:
            print "The door to the house is ";
            if (key in player) {
              print "locked, but the key doesn't ";
              print "fit. It must go to something ";
              "else around here.";
            }
            "locked.";
        ],
   has  concealed static;

Object  farmWindows "windows" farm
 with   name 'window' 'windows',
        before [;
          Attack:
            print "You rattle the windows, but ";
            print "hear nothing in return. It ";
            print "looks like the house is ";
            "empty.";
          Cut:
            <<Cut farmHouse>>;
          Examine:
            print "The windows are covered. It ";
            print "looks like there is no ";
            "way in.";
          Open, Enter:
            print "The windows don't budge. ";
            print "You're not pulling a ";
            "Zork here.";
          Take, Push, PushDir, Pull:
            print "The house isn't going ";
            "anywhere.";
        ],
   has  concealed static pluralname;

Object  farmTree "oak tree" farm
 with   name 'oak' 'tree' 'haunted' 'large',
        daemon [;
          iBirdReturn++;
          if (iBirdReturn >= 4) {
            crow.away = false;
            move crow to farm;
            move key to farm;
            StopDaemon(self);
            print "^You watch the crow circle ";
            print "for a moment, landing back ";
            print "on the branch, only to ";
            "laugh at you one more time.";
          }
        ],
        describe [;
          if (crow in farm && crow.animalDead == false) {
            print "^A crow is perched on a ";
            print "tree limb, keeping his ";
            print "eyes on you and almost ";
            "laughing as he caws.";
          }
          rtrue;
        ],
        before [;
          Climb:
            if (crow in farm) {
              remove crow;
              remove key;
              crow.away = true;
              iBirdReturn = 0;
              StartDaemon(self);
              print "As you approach the base ";
              print "of the tree, the crow ";
              print "takes off";
              if (crow.seenKey) ", flying away with the key.";
              ".";
            }
            if (crow.away) {
              print "You scared the bird once. ";
              print "You'd only keep the crow ";
              "away.";
            }
            print "You already took care of ";
            print "the crow. There's nothing ";
            "up there.";
          Examine:
            print "This large oak stands over ";
            print "the building, its branches ";
            print "stretching outward like a ";
            print "clawed hand holding the ";
            print "house in place";
            if (crow in farm) {
              print ". A crow is perched on ";
              print "one of the limbs, laughing ";
              "with a maniacal caw.";
            }
            ".";
          Take, Push, PushDir, Pull:
            print "The tree is firmly rooted ";
            "in the ground.";
        ],
   has  static;

OutRch  farmBranch "branch" farm
 with   name 'branch' 'branches',
        before [;
          Climb:
            <<Climb farmTree>>;
          Examine:
            <<Examine farmTree>>;
        ],
   has  concealed static;

Object  farmCellar "cellar" farm
 with   name 'root' 'cellar' 'lock',
        before [;
          Attack, Cut:
            if (self.doorsOpen) {
              print "You don't need to. The ";
              "cellar is open.";
            }
            if (second == axe) {
              print "Brute forcing it with the ";
              "axe isn't going to do it.";
            }
            print "You could slam into it, but ";
            print "there has to be an easier ";
            "way.";
          Enter:
            if (self.doorsOpen) {
              print "You step into the ";
              print "dark cellar.^^";
              PlayerTo(rootCellar, 2);
              rtrue;
            }
            print "The doors to the cellar ";
            if (self.doorsLocked) {
              print "are locked";
              if (key in player) ".";
              ". You're going to need a key.";
            }
            "are closed.";
          Open:
            if (self.doorsOpen) "The doors are already opened.";
            if (self.doorsLocked) {
              print "The doors to the cellar are ";
              "locked.";
            }
            if (key in player) return OpenCellar();
            print "The doors to the cellar are ";
            print "locked, and you don't have ";
            "the key.";
          Close:
            if (self.doorsOpen) {
              print "You're not going to be able ";
              print "to hide the fact that you ";
              "were here.";
            }
            print "The doors to the cellar ";
            "are closed.";
          Examine:
            print "The doors to the root ";
            print "cellar are ";
            if (self.doorsOpen) "open.";
            if (self.doorsLocked) "locked.";
            "closed.";
          Take, Push, PushDir, Pull:
            print "The cellar isn't going ";
            "anywhere.";
          Unlock:
            if (self.doorsLocked) {
              if (key in player) return UnlockCellar();
              print "You're going to need a key ";
              "to unlock the doors.";
            }
            print "The doors are already ";
            "unlocked.";
        ],
        doorsOpen false,
        doorsLocked true,
   has  concealed static locked;

Object  farmDoors "doors" farm
 with   name 'doors',
        before [;
          Attack, Cut:
            if (farmCellar.doorsOpen) {
              print "You don't need to. They ";
              "are open.";
            }
            if (second == axe) {
              print "Brute forcing them with the ";
              "axe isn't going to do it.";
            }
            print "You could slam into them, ";
            print "but there has to be an ";
            "easier way.";
          Enter:
            <<Enter farmCellar>>;
          Open:
            <<Open farmCellar>>;
          Close:
            <<Close farmCellar>>;
          Examine:
            <<Examine farmCellar>>;
          Take, Push, PushDir, Pull:
            <<Take farmCellar>>;
          Unlock:
            <<Unlock farmCellar>>;
        ],
   has  concealed static locked pluralname;

OutRch  farmFields "fields" farm
 with   name 'field' 'fields' 'grapes',
        before [;
          Enter:
            iBirdReturn = 0;
            ! return the crow if he was flying away when the player leaves the farm
            crow.away = false;
            if (crow.animalDead == false) move crow to farm;
            StopDaemon(farm);
            StopDaemon(farmTree);
            PlayerTo(fields, 2);
            rtrue;
          Examine:
            print "Vast fields of grapes lay ";
            print "to the west, blanketing ";
            print "the land in a sea of ";
            print "purple under the ";
            "moonlight.";
        ];

[ OpenCellar;
    farmCellar.doorsOpen=true;
    print "You swing the doors open as ";
    print "a cold blast of air hits ";
    "your face.";
];

[ UnlockCellar;
    farmCellar.doorsLocked=false;
    print "With an audible click, the ";
    "lock disengages.";
];
