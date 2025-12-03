! ---------------------------------------------------------------------------- !
!       LOINCLOTH 1/9/25
!

Object  loincloth "loincloth"
  with  name 'loincloth' 'cloth' 'junk',
        short_name [;
          print "your ";
        ],
        before [;
            Attack:
                print "Tearing it off would be ";
                "embarrassing.";
            Give:
                print "You don't want to lose that. ";
                print "It's the only thing ";
                "covering you.";
            Examine:
                print "The loincloth is just big ";
                "enough to cover you.";
            Insert, Take, Disrobe:
                print "Taking it off would be ";
                "embarrassing.";
        ],
        beenTaken false,
   has  clothing worn proper;
