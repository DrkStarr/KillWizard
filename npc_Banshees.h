
! ---------------------------------------------------------------------------- !
!       BANSHEES 1/2/25
!

OutRch   banshees "banshees" moors
   with   name 'spirits' 'banshees' 'ghosts' 'apparitions',
          article [;
              print "the";
          ],
          before [;
              Ask, AskFor, AskFor2nd:
                print "The banshees only scream ";
                "in reply.";
              Attack:
                print "There's nothing to attack. ";
                print "The apparitions are like ";
                "mist.";
              Examine:
                print "Banshees cry out, trapped ";
                print "here and angry. They can't ";
                print "leave and try to drive all ";
                "away.";
              Shoot:
                print "They're no more than mist. ";
                "There's nothing to shoot.";
              default:
                print "Spinning around the pillar, ";
                print "the banshees are out of ";
                "reach.";
          ],
          life [;
            print "The banshees only scream ";
            "in reply.";
          ],
          orders [;
            print "The banshees only scream ";
            "in reply.";
          ],
          ghostsGone false,
     has  animate pluralname concealed;
