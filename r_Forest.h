
! ---------------------------------------------------------------------------- !
!       BRIARTHORN FOREST 1/3/25
!
Object  forest "Briarthorn Forest"
  with  description [;
          print "With the moon obscured by ";
          print "trees, the forest is dark ";
          print "and foreboding. Animals ";
          print "cry out, but you see nothing";
          if (panther.animalDead || panther.animalGone) {
            print ". You can go north, up the ";
            print "hill, or return east, back ";
            print "to the moors";
          } else {
            print ". You can return east, back ";
            print "to the moors";
          }
          ".";
        ],
        daemon [;
          if (panther.animalDead == false) {
            if (panther.surpressPanther) {
              panther.surpressPanther = false;
            } else {
              if (player in self) {
                iMobTrigger++;
                if (iMobTrigger >= 2) {
                  iMobTrigger = 0;
                  print "^The panther paces, glaring ";
                  "at you, ready to attack.";
                } else {
                  print "^The panther watches you, ";
                  print "waiting for the perfect ";
                  "moment to strike.";
                }
              }
            }
          }
        ],
		    u_to [; <<Enter forestForest>>; ],
		    n_to [; <<Enter forestForest>>; ],
        e_to [; <<Enter forestMoors>>; ],
        out_to [; <<Enter forestMoors>>; ],
		    before [;
          Listen:
            if (panther.animalDead || panther.animalGone) {
              print "Rarely an animal cries out ";
              print "in the darkness, but you ";
              "see nothing.";
            }
            panther.surpressPanther = true;
            print "The panther growls, she ";
            print "doesn't like your ";
            "presence.";
          Smell:
            print "The air is foul. Stagnant ";
            "water lies all around.";
		    ],
        cant_go [;
          if (panther.animalDead || panther.animalGone) {
            print "You can go north, exiting ";
            print "the forest, or east, back ";
            "to the moors.";
          }
          panther.surpressPanther = true;
          print "The panther is about ";
          "to kill you.";
        ],
  has   light;

OutRch    forestForest "forest" forest
   with   name 'forest' 'woods' 'trees' 'tree',
          before [;
            Enter:
              if (panther.animalDead || panther.animalGone) {
                print "Climbing uphill, you ";
                print "come out of the forest ";
                print "into a clearing.^^";
                PlayerTo(drawbridge,2);
                rtrue;
              }
              panther.surpressPanther = true;
              print "The panther is about to ";
              "kill you.";
            Climb:
              print "Sharp thorns line all the ";
              "trees. You can't climb them.";
            Examine:
              print "The forest trees are thick ";
              print "and old, and covered in ";
              print "thorns. Very few animals ";
              "live in them.";
          ],
    has   concealed static;

OutRch    forestMoors "moors" forest
   with   name 'moors' 'marsh' 'swamp',
          before [;
            Enter:
              if (panther.animalDead || panther.animalGone) {
                PlayerTo(moors,2);
                rtrue;
              }
              print "Locking eyes with the ";
              print "panther, you slowly back ";
              print "away until you find ";
              print "yourself in the moors.^^";
              PlayerTo(moors,2);
              rtrue;
            Examine:
              print "To the east are the moors - ";
              "the tip of the swamp.";
          ],
    has   concealed static;

 OutRch   forestMoon "moon" forest
   with   name 'moon',
          before [;
            Examine:
              print "With the moon low on the ";
              print "horizon tonight, you can't ";
              print "see it. It is hidden ";
              "behind trees.";
            Take, Push, PushDir, Pull:
              "Don't be ridiculous.";
          ];
