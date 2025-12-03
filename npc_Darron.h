
! ---------------------------------------------------------------------------- !
!       DARRON 12/31/24
!

Object  darron "Darron"
  with  name 'body' 'darren' 'darron' 'friend',
        describe [;
          rtrue;
        ],
        before [;
          AskFor, AskFor2nd:
            print "Darron isn't going to do ";
            "much in his condition.";
          Attack, Burn, Cut:
            print "You don't want to hurt ";
            "your friend.";
          Examine:
            print "Darron looks grey as he ";
            print "lies in front of the door. ";
            print "You're not sure what to do. ";
            print "An arrow has pierced his ";
            print "chest, but he's still ";
            print "alive. His blood mixes with ";
            print "water at the entrance";
            if (scroll.objectTaken == false) {
              print ". In his hands he clutches ";
              "a scroll.";
            }
            print ". You pray Osric can ";
            "help him.";
          Climb, Take:
            print "Darron's barely alive. ";
            "Leave him be.";
          Push, PushDir, Pull:
            if (scroll.objectRead) {
              print "~I'll take care of him from ";
              print "here,~ says Osric. ~You ";
              "know what you must do.~";
            }
            if (scroll.objectTaken) {
              print "~What's going on?~ asks ";
              print "Osric. ~Read the scroll, ";
              "will you.~";
            }
            print "~No. Look at that scroll,~ ";
            print "Osric says, pointing to ";
            "Darron's body.";
          Talk:
            print "Darron isn't going to say ";
            "much in his condition.";
          Search:
            print "You pat Darron down, ";
            if (scroll.objectRead) {
              print "but find nothing. Why would ";
              print "the necromancer have him ";
              "killed?";
            }
            print "all he has is the scroll. ";
            print "You're not sure why this ";
            "happened.";
        ],
        life [;
          Ask, Answer, Tell:
            print "Darron isn't going to say ";
            "much in his condition.";
          ThrowAt:
            if (noun == axe) {
              print "You don't want to hurt ";
              "your friend.";
            }
            return PNFS();
        ],
        orders [;
          default:
            print "Darron's barely alive and ";
            "isn't doing anything.";
        ],
   has  animate proper;
