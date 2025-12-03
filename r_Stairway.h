
! ---------------------------------------------------------------------------- !
!       STAIRWAY 1/10/25
!
Object  stairway "Stairway"
  with  description [;
          print "The corridor ends here at ";
          print "a set of stairs leading up ";
          print "into the tower. On each ";
          print "baluster, a clawed hand ";
          print "holds a burning candle. ";
          print "The wizard must be up there";
          if (golems.mobDead == false) {
            print ". But two stone golems ";
            print "block your path";
            if (self.firstTime) {
              self.firstTime = false;
              print " - this is the last line ";
              "of defense.";
            }
          }
          ".";
        ],
		    e_to [; <<Enter stairCorridor>>; ],
        u_to [; <<Enter stairStairway>>; ],
        in_to [; <<Enter stairStairway>>; ],
		    out_to [; <<Enter stairCorridor>>; ],
		    before [;
          Listen:
            if (golems.mobDead) {
              print "It's quiet now. It's ";
              "almost too quiet.";
            }
            print "You can still hear the ";
            print "skeletons beating on ";
            "the door to the east.";
          Smell:
            print "The smell of burning candles ";
            "hangs thick in the air.";
		    ],
        cant_go [;
          if (golems.mobDead) {
            print "You can head east or go up ";
            "the stairs.";
          }
          print "You can only go east, back ";
          print "down the corridor towards ";
          "the kitchen.";
        ],
        firstTime true,
  has   light;

Object  stairStairway "stairway" stairway
  with  name 'stairs' 'stairway' 'stair',
          before [;
            Enter, Climb:
              if (golems.mobDead) {
                  print "Silently, you climb the ";
                  print "stairs like a cat and ";
                  print "enter the lair.^^";
                  StartDaemon(necrosLair);
                  PlayerTo(necrosLair, 2);
                  rtrue;
              }
              print "You can't get past ";
              "the golems.";
            Examine:
              print "The stairway goes up into ";
              "the dark void of the tower.";
            Take, Push, PushDir, Pull:
              print "The stairway isn't going ";
              "anywhere.";
          ],
    has   concealed static;

Object  stairBaluster "balusters" stairway
  with  name 'baluster' 'balusters' 'claw' 'claws',
          before [;
            Examine:
              print "The balusters are made from ";
              print "marble and have claws ";
              print "coming out of the top of ";
              print "them. Each claw holds a ";
              "candle.";
            Take, Push, PushDir, Pull:
              print "The balusters aren't going ";
              "anywhere.";
          ],
    has   concealed static pluralname;


Object  stairCandle "candles" stairway
  with  name 'candle' 'candles',
          before [;
            Examine:
              print "The candles barely provide ";
              print "any light in the area but ";
              print "hint that the wizard is up ";
              "there.";
            Take:
              "You don't need them.";
            Push, PushDir, Pull:
              print "The candles aren't going ";
              "anywhere.";
          ],
    has   concealed static pluralname;


OutRch  stairCorridor "corridor" stairway
 with   name 'corridor',
          before [;
            Enter:
              if (golems.startedMovement) {
                print "With golems chasing you, you ";
                print "head back down the corridor ";
                print "towards the armory.^^";
              }
              PlayerTo(grandCorridor, 2);
              rtrue;
            Examine:
              print "The corridor stretches east, ";
              "fading into darkness.";
          ];
