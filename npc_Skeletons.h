
! ---------------------------------------------------------------------------- !
!       SKELETONS 1/9/25
!

Object  skeletons "skeletons" greatHall
  with  name 'skeletons' 'skeleton' 'undead' 'ph001',
        before [;
          Attack, Cut, Burn:
            if (golems.mobDead) {
              print "But they've been broken ";
              "into so many pieces.";
            }
            print "You don't want to disturb ";
            "the undead.";
          Examine:
            if (golems.mobDead) {
              print "The skeletons are nothing ";
              "more than pieces of bone.";
            }
            print "The undead fill this room, ";
            print "all of them sitting ";
            print "motionless at a table like ";
            print "someone stopped time in ";
            "this hall.";
          Climb, Enter, Push, PushDir, Pull, Take:
            if (golems.mobDead) {
              print "They're nothing but a pile ";
              "of chips.";
            }
            print "The skeletons are inanimate, ";
            print "and you don't want to ";
            "trigger them.";
          Ask, AskFor, AskFor2nd, Talk:
            if (golems.mobDead) {
              print "They're nothing but a ";
              "pile of chips.";
            }
            print "They're undead, and you're ";
            print "not going to hold a ";
            "conversation with them.";
        ],
        life [;
          if (golems.mobDead) {
            print "They're nothing but a ";
            "pile of chips.";
          }
          print "The skeletons ignore you, ";
          "sitting there motionless.";
        ],
        orders [;
          if (golems.mobDead) {
            print "They're nothing but a pile ";
            "of chips.";
          }
          print "The skeletons ignore you, ";
          "sitting there motionless.";
        ],
   has  animate concealed pluralname;
