! ---------------------------------------------------------------------------- !
!       PLAYER. 10/08/21
!

Object  selfPlayer "self"
  with  name 'yourself' 'self' 'me' 'frame',
        description [;
          print "Wrapped in a loincloth, your ";
          print "large muscular frame is ";
          print "imposing even to the ";
          "strongest man.";
        ],
        before [;
          Attack, Cut:
            print "You don't need to do ";
            print "that. Plenty of others ";
            print "would love to hunt ";
            "you down.";
          Talk:
            print "Do you usually go around ";
            print "muttering things to ";
            "yourself?";
          Push, Pull, Take:
            "You know that makes no sense.";
        ],
   has  animate concealed proper;
