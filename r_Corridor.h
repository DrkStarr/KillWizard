
! ---------------------------------------------------------------------------- !
!       GRAND CORRIDOR 1/10/25
!
Object  grandCorridor "Grand Corridor"
  with  description [;
          print "This long passageway ";
          print "stretches east to west ";
          print "through the lower level ";
          print "of the tower. ";
          if (golems.mobDead == false) {
            print "Your talisman provides ";
            print "light, but y";
          } else {
            print "Y";
          }
          print "ou see flickering candles ";
          print "to the west. To the east, ";
          print "the hallway ends at an ";
          print "armory.^^";
          if (golems.mobDead) {
              print "A pile of dust and bone ";
              print "lies in front of the door ";
              "to the south.";
          }
          print "Skeletons are pounding on ";
          "the door to the south.";
        ],
        out_to [;
          if (golems.mobDead == false) "You can go east or west.";
          <<Enter corrDoor>>;
        ],
        s_to [;
          if (golems.mobDead == false) "You can go east or west.";
          <<Enter corrDoor>>;
        ],
        e_to [; <<Enter corrArmory>>; ],
        w_to [; <<Enter corrCandles>>; ],
        in_to [; <<Enter corrCandles>>; ],
		    before [;
          Listen:
            if (golems.mobDead) {
              print "It's quiet now since ";
              "everything is dead.";
            }
            print "The undead won't stop until ";
            print "they have their revenge. ";
            print "They continue to beat on ";
            "the door.";
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
            print "You need to go west and deal ";
            "with the wizard for good.";
          }
          print "You can go east to the ";
          print "armory or west down the ";
          "grand corridor.";
        ],
  has   light;

RoomObj corrObj "corridor" grandCorridor
  with  name 'grand' 'corridor' 'passageway' 'passage',
        description [;
          <<Look grandCorridor>>;
        ];

Object  corrDoor "door" grandCorridor
  with  name 'door' 'kitchen',
        before [;
          Close:
            if (golems.mobDead) {
              if (kDoor.hasOpen) {
                kDoor.hasOpen = false;
                print "You close the door to the ";
                "kitchen.";
              }
              print "The door to the kitchen ";
              "is closed.";
            }
            print "The door to the kitchen is ";
            print "closed as skeletons try to ";
            "beat it down.";
          Enter:
            if (golems.mobDead) {
              if (kDoor.hasOpen == false) {
                kDoor.hasOpen = true;
                print "(first opening the door)^";
              }
              PlayerTo(kitchen, 2);
              rtrue;
            }
            <<Open self>>;
          Open, Pull:
            if (golems.mobDead) {
              if (kDoor.hasOpen) {
                print "The door to the kitchen ";
                "is open.";
              }
              kDoor.hasOpen = true;
              print "You open the door to ";
              "the kitchen.";
            }
            if (golems.startedMovement) {
              kDoor.hasOpen = true;
              golems.startedMovement = false;
              move golems to grandCorridor;
              move skeletons to grandCorridor;
              remove kSkeletons;
              StopDaemon(golems);
              score++;
              golems.mobDead = true;
              golems.&name-->2 = 'dust';
              golems.&name-->3 = 'pile';
              skeletons.&name-->2 = 'bone';
              skeletons.&name-->3 = 'chips';
              print "You open the door, pointing ";
              print "the skeleton towards the ";
              print "golems with your back to ";
              print "the armory.^";
              if (iGolemMovement == 2) {
                print "^The golems come up the ";
                print "corridor taking on the ";
                print "skeletons";
              } else {
                print "^The golems take on the ";
                print "skeletons";
              }
              print ", smashing bone as stone ";
              print "collides. But the skeletons ";
              print "don't go down so quickly, ";
              print "with a hundred of them ";
              print "beating the stone back into ";
              print "the ground. When the fight ";
              print "is over, it's a draw. The ";
              print "skeletons beat the golems ";
              print "into dust, but all that's ";
              "left of them are bone chips.";
            }
            deadflag = 1;
            print "Popping open the door causes ";
            print "a horde of skeletons to pour ";
            print "into the corridor. You try ";
            print "to back up, to get away, but ";
            print "they claw at your flesh, ";
            print "tearing off chunks of meat ";
            "until there is no more.";
          Examine:
            if (golems.mobDead) {
              if (kDoor.hasOpen) {
                print "The door is open and leads ";
                "into the kitchen.";
              }
              print "The door to the kitchen ";
              "is closed.";
            }
            print "The door shacks as skeletons ";
            print "pound on the wood. You're ";
            "glad it holds.";
          Take, Push, PushDir:
            print "The door isn't going ";
            "anywhere.";
        ],
   has  concealed static;

OutRch  corrCandles "candles" grandCorridor
  with  name 'candles' 'candle' 'candlelight' 'light',
        before [;
          Enter:
            if (golems.startedMovement) {
              if (golems in grandCorridor) {
                print "You're not getting past the ";
                print "golems. They shift and ";
                print "maneuver, trying to ";
                "catch you.";
              }
              print "The golems are coming up ";
              print "the corridor. You can't go ";
              "that way.";
            }
            if (golems.mobDead == false) {
              golems.startedMovement = true;
              StartDaemon(golems);
            }
            PlayerTo(stairway, 2);
            rtrue;
          Examine:
              if (golems.startedMovement) {
                print "Candles flicker, but it's ";
                print "hard to see anything down ";
                print "there with two golems in ";
                "the way.";
              }
              print "Candles flicker in the ";
              "distance to the west.";
          ],
     has  pluralname;

OutRch  corrArmory "armory" grandCorridor
  with  name 'armory' 'storage',
        before [;
          Enter:
            if (golems.startedMovement && iGolemMovement == 3) {
              print "You feel the thunder coming ";
              print "off the golems as they ";
              print "pursue you.^^";
            }
            if (golems.mobDead == false) {
              StopDaemon(golems);
              move golems to stairway;
            }
            PlayerTo(armory, 2);
            rtrue;
          Examine:
            print "The armory lies to the east. ";
            print "You can't see inside it from ";
            "here.";
        ];
