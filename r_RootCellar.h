
! ---------------------------------------------------------------------------- !
!       ROOT CELLAR 1/2/25
!
! Down in the cellar is the wine needed to give to the drunk to get the talisman

Object  rootCellar "Root Cellar"
 with   description [;
          print "Although moonlight streams ";
          print "in through the open doors, ";
          print "it's difficult to see what's ";
          print "in this cellar. Shadows seem ";
          print "to shift and move. It's ";
          print "unnaturally cold down here, ";
          print "and the breeze tries to ";
          "clear the stale air.";
        ],
        u_to [; <<Enter cellarDoor>>; ],
        out_to [; <<Enter cellarDoor>>; ],
        before [;
          Listen:
            print "A soft moan can be heard ";
            print "down here. You look, but ";
            "see no one.";
          Smell:
            print "Fresh air fights to make ";
            print "its way in as a musty odor ";
            "prevails.";
        ],
        cant_go [;
          print "It's not that big. You can ";
          print "only go back out the ";
          "cellar doors.";
        ],
  has   light;

RoomObj cellarObj "cellar" rootCellar
  with  name 'root' 'cellar',
        description [;
          <<Look rootCellar>>;
        ];

Object  cellarDoor "doors" rootCellar
 with   name 'door' 'doors' 'heavy',
        before [;
          Examine:
            print "The heavy doors are open, ";
            "letting moonlight in.";
          Enter:
            PlayerTo(farm,2);
            rtrue;
          Open:
            "The doors are already open.";
          Close:
            print "You don't need to shut ";
            "yourself in.";
          Take, Push, PushDir, Pull:
            print "The doors aren't going ";
            "anywhere.";
        ],
   has  concealed static pluralname;

OutRch  cellarMoon "moon" rootCellar
 with   name 'moon' 'moonlight' 'light',
        before [;
          Examine:
            print "Moonlight shines through the ";
            print "open doors. But it's still ";
            "hard to make anything out.";
          Take, Push, PushDir, Pull:
            "Don't be ridiculous.";
        ];

! Shadows need to be here so it fails in the root cellar properly & the old forest

OutRch  cellarShadows "shadows"
 with   name 'shadows' 'shadow',
        before [;
          Examine:
            print "You can't see any such ";
            "thing.";
        ];
