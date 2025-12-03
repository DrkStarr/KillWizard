
! ---------------------------------------------------------------------------- !
!       KITCHEN 1/9/25
!
Object  kitchen "Kitchen"
  with  description [;
          if (self.chefDead) {
            if (golems.mobDead) {
              print "This room is filled with ";
              print "pots and pans, while a pile ";
              print "of plates is on the floor - ";
              print "the chef is on top of them, ";
              print "no longer animated. The hall ";
              print "to the west is empty, with ";
              print "the skeletons cleared out. ";
              print "The door to the north ";
              if (kDoor.hasOpen) "is open.";
              "is closed.";
            } else {
              print "This room is filled with ";
              print "pots and pans, with the pile ";
              print "of stacked plates now on the ";
              print "floor. The chef, who was so ";
              print "animated, lies down on the ";
              print "ground. In the hall, ";
              print "undead make for the ";
              print "kitchen, upset you ruined ";
              print "their meal. The way north ";
              "is clear.";
            }
          }
          print "This room is filled with ";
          print "pots and pans, along with ";
          print "plates stacked to the ";
          print "ceiling. The chef, a ";
          print "skeleton himself, ";
          print "frantically opens ";
          print "and closes cupboards, ";
          print "searching for missing ";
          print "ingredients";
          if (self.firstTime) {
            self.firstTime = false;
            chef.suppressChef = true;
            print ".^^Blocking the door to the ";
            print "north, the chef spins ";
            "around, arms flailing.";
          }
          ". The way north is blocked.";
        ],
        daemon [;
          iSkeletonDeath++;
          switch (iSkeletonDeath) {
            2: print "^The undead in the hall ";
               print "advance towards the ";
               print "kitchen, looking for their ";
               "revenge.";
            3: print "^The undead advance, moaning ";
               "in a low undertone.";
            4: print "^The undead start to ";
               print "enter this room. You need ";
               "to get out of here.";
            5: deadflag=1;
               print "^The undead swarm into the ";
               print "small kitchen, piling on ";
               print "you. They decide you're ";
               print "what's on the menu tonight. ";
               print "Too bad you didn't make it ";
               "out the north door.";
          }
        ],
        n_to [; <<Enter kDoor>>; ],
        in_to [; <<Enter kDoor>>; ],
        out_to [;
          if (self.chefDead) <<Enter kDoor>>;
          <<Enter kHall>>;
        ],
        w_to [; <<Enter kHall>>; ],
		    before [;
          Listen:
            if (golems.mobDead) {
              print "The place is quiet. Your ";
              "footsteps ring hollow.";
            }
            if (self.chefDead) {
              print "The undead moan as they ";
              "advance on this room.";
            }
            print "The chef makes all sorts of ";
            print "noise, opening and closing ";
            "the cabinets.";
          Smell:
            if (golems.mobDead) {
              print "The smell of crushed bone, ";
              print "like chalk, lingers in the ";
              "air.";
            }
            print "For some reason, the air ";
            "smells like baked bread.";
		    ],
        cant_go [;
          if (golems.mobDead) {
            print "You can north towards the ";
            print "necromancer or west into ";
            "the hall.";
          }
          if (self.chefDead) {
            print "With all the undead ";
            print "coming at you, the only ";
            "safe way out is north.";
          }
          print "You need to go deeper into ";
          print "the tower, but the door ";
          print "north is blocked. You can ";
          print "also go west, back to the ";
          "hall.";
        ],
        firstTime true,
        chefDead false,
  has   light;

RoomObj kObj "kitchen" kitchen
  with  name 'kitchen',
        description [;
          <<Look kitchen>>;
        ];

Object  kDoor "door" kitchen
  with  name 'door',
        before [;
          Open:
            if (kitchen.chefDead) {
              if (self.hasOpen) "The door is already open.";
              self.hasOpen = true;
              "You open the door.";
            }
            chef.suppressChef = true;
            print "You can't reach the door. ";
            print "The chef thrashes around, ";
            print "blocking your way. You ";
            "can't get past him.";
          Enter:
            if (golems.mobDead) {
              if (kDoor.hasOpen == false) {
                kDoor.hasOpen = true;
                print "(first opening the door)^";
              }
              PlayerTo (grandCorridor, 2);
              rtrue;
            }
            if (kitchen.chefDead) {
              if (kDoor.hasOpen == false) {
                kDoor.hasOpen = true;
                print "(first opening the door)^";
              }
              StopDaemon(kitchen);
              print "You make it out the door, ";
              print "slamming it behind you. ";
              print "Stepping back, you hear ";
              print "skeletons ";
              if (iSkeletonDeath == 4) {
                print "pounding";
              } else {
                print "advance and then pound";
              }
              print " on it, but it ";
              print "remains shut.^^";
              PlayerTo (grandCorridor, 2);
              rtrue;
            }
            chef.suppressChef = true;
            print "You can't reach the door. ";
            print "The chef thrashes around, ";
            print "blocking your way. You ";
            "can't get past him.";
          Examine:
            print "The door to the next room ";
            if (self.hasOpen) "is open.";
            "is closed.";
          Close:
            if (kitchen.chefDead) {
              if (self.hasOpen) {
                self.hasOpen = false;
                "You close the door.";
              }
              "That's already closed.";
            } else {
              chef.suppressChef = true;
              print "You can't reach the door. ";
              print "The chef thrashes around, ";
              print "blocking your way. You ";
              "can't get past him.";
            }
          Take, Push, PushDir, Pull:
            if (kitchen.chefDead) {
              print "The door isn't going ";
              "anywhere.";
            }
            chef.suppressChef = true;
            print "You can't reach the door. ";
            print "The chef thrashes around, ";
            print "blocking your way. You ";
            "can't get past him.";
          default:
            if (kitchen.chefDead) rfalse;
            chef.suppressChef = true;
            print "You can't reach the door. ";
            print "The chef thrashes around, ";
            print "blocking your way. You ";
            "can't get past him.";
        ],
        hasOpen false,
   has  concealed static;

Object  kPlates "plates" kitchen
  with  name 'plate' 'plates' 'dish' 'dishes',
        before [;
          Examine:
            print "The plates are ";
            if (golems.mobDead) {
              print "broken and ";
              "lie all over the floor.";
            }
            if (kitchen.chefDead) {
              print "broken and ";
              print "lie all over the floor. ";
              print "From the hall, the ";
              print "undead slowly close ";
              "in on you.";
            }
            print "stacked to ";
            print "the ceiling. Amazingly, ";
            print "they don't fall with the ";
            print "chef gyrating back and ";
            "forth.";
          Attack, Cut, Push, PushDir, Pull:
            if (golems.mobDead) "You don't need to do that.";
            if (kitchen.chefDead) {
              print "The plates are already ";
              print "broken. You need to ";
              "get out of here.";
            }
            score++;
            kitchen.chefDead = true;
            StopDaemon(chef);
            StartDaemon(kitchen);
            self.&name-->2 = 'broken';
            self.&name-->3 = 'pieces';
            print "The pile of plates hit the ";
            print "ground, shattering, and the ";
            print "chef goes down with them. ";
            print "He gives up the struggle. ";
            print "The skeletons get up from ";
            print "their seats in the great ";
            print "hall and head for this room ";
            print "- angry that you have ";
            "disturbed their meal.";
          Take:
            if (kitchen.chefDead) {
              print "You don't need the broken ";
              "pieces.";
            }
            <<Push self>>;
        ],
   has  concealed static pluralname;

Object  kCabinets "cabinets" kitchen
  with  name 'cabinets' 'cabinet' 'cupboard' 'cupboards',
        before [;
          Examine:
            if (kitchen.chefDead) {
              print "One of the cabinets is open, ";
              print "and you can see it's empty. ";
              print "You have no idea what the ";
              "chef was looking for.";
            }
            print "The chef doesn't know what ";
            print "he's doing. He opens and ";
            print "closes cabinets, but there's ";
            print "nothing to pull out. ";
            "They're empty.";
          Open, Close:
            if (golems.mobDead) "You don't need to do that.";
            if (kitchen.chefDead) {
              print "You don't need to do that. ";
              "You need to get out of here.";
            }
            chef.suppressChef = true;
            print "The chef twists around ";
            print "madly. You can't get close ";
            "to the cabinets.";
          Take, Push, PushDir, Pull:
            print "The cabinets aren't going ";
            "anywhere.";
        ],
   has  concealed static pluralname container open;

Object  kPots "pots" kitchen
  with  name 'pots' 'pans' 'pot' 'pan',
        before [;
          Attack, Cut, Push, PushDir, Pull:
            if (golems.mobDead) "You don't need to do that.";
            if (kitchen.chefDead) {
              print "The kitchen is already a ";
              print "mess. You need to get out ";
              "of here.";
            }
            print "You hit one of the pots ";
            print "as it slides into the ";
            print "plates.^^";
            <<Push kPlates>>;
          Examine:
            print "Pots and pans ";
            if (kitchen.chefDead) {
              print "lie all ";
              print "around, along with a ";
              print "pile of plates that's ";
              "been knocked over.";
            }
            print "clutter the ";
            print "kitchen, while a stacked ";
            print "pile of plates reaches the ";
            "ceiling.";
          Take:
            if (kitchen.chefDead) "You don't need those.";
            print "You try to take a pot, but ";
            print "you hit one of the plates.^^";
            <<Push kPlates>>;
        ],
   has  concealed static pluralname;

OutRch    kHall "hall" kitchen
   with   name 'great' 'hall',
          before [;
            Enter:
              if (kitchen.chefDead) {
                  if (golems.mobDead == false) {
                    print "You'd be throwing yourself ";
                    print "into the lion's den. The ";
                    print "undead are coming ";
                    "for you.";
                  }
              }
              PlayerTo(greatHall, 2);
              rtrue;
            Examine:
              print "The hall is ";
              if (golems.mobDead) "empty.";
              print "filled with ";
              if (kitchen.chefDead) {
                print "undead that slowly ";
                "approach.";
              }
              print "skeletons that patiently ";
              print "wait for their meal to ";
              "be served.";
          ];

OutRch    kSkeletons "skeletons" kitchen
   with   name 'skeleton' 'skeletons' 'undead',
          before [;
            Examine:
              print "The hall is filled with ";
              if (kitchen.chefDead) {
                print "undead that slowly ";
                "approach.";
              }
              print "skeletons that patiently ";
              print "wait for their meal to ";
              "be served.";
          ],
    has   animate pluralname;
