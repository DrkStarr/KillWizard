
! ---------------------------------------------------------------------------- !
!       GATEHOUSE 1/4/25
!
Object  gatehouse "Gatehouse"
  with  description [;
          print "The gatehouse that used to ";
          print "protect the tower has been ";
          print "scorched. There are no ";
          print "guards to greet you, and ";
          print "there's no way into the ";
          print "tower - only the allure that ";
          print "wraps around it. To the ";
          print "south, the drawbridge ";
          "extends over the chasm.";
        ],
		    e_to [; print "As you head east, "; return TriggerTrap(); ],
        w_to [; print "As you head west, "; return TriggerTrap(); ],
        s_to [; <<Enter ghDrawbridge>>; ],
        out_to [; <<Enter ghDrawbridge>>; ],
		    before [;
          Listen:
            print "Across the chasm you hear ";
            "creatures cry out.";
          Smell:
            print "The air is foul, as if death ";
            print "is coming up from the chasm ";
            "below.";
		    ],
        cant_go [;
          "There's no direct way into the tower. You can go east or west along
          the allure or south, back across the drawbridge.";
        ],
  has   light;

Object    ghDrawbridge "drawbridge" gatehouse
   with   name 'drawbridge' 'bridge',
          before [;
            Enter:
              PlayerTo(drawbridge,2);
              rtrue;
            Examine:
              print "The bridge spans the chasm, ";
              print "allowing you to return to ";
              "the forest.";
            Close:
              "You don't need to do that.";
            Open:
              "That's already open.";
          ],
    has   concealed static;

Object    ghGatehouse "gatehouse" gatehouse
   with   name 'gatehouse' 'house' 'gate' 'station',
          before [;
            Enter:
              print "You peek your head into the ";
              print "gatehouse. It smells of ";
              print "charred wood. The only thing ";
              print "in the room is moonlight ";
              print "cutting through dust from ";
              "a cross cut into the wall.";
            Examine:
              print "The gatehouse is completely ";
              print "burnt out, as if a fireball ";
              print "exploded, incinerating ";
              print "everything in sight. If ";
              print "there were guards inside, ";
              print "not even their remains ";
              "are left.";
            Close:
              "You don't need to do that.";
            Open:
              "That's already open.";
          ],
    has   concealed static;

OutRch    ghAllure "allure" gatehouse
   with   name 'allure' 'walkway',
          before [;
            Enter:
              print "As you step into the allure, ";
              return TriggerTrap();
            Examine:
              print "The allure is a protected ";
              print "walkway that wraps around ";
              print "the outside of the tower. ";
              print "Guards used it to travel ";
              "safely between stations.";
          ];

Object    ghTower "tower" gatehouse
   with   name 'tower',
          before [;
            Enter:
              <<Enter ghAllure>>;
            Climb:
              print "The tower walls are slick. ";
              print "The only way in is through ";
              "the allure.";
            Examine:
              print "The tower rises high into ";
              print "the sky. There's no easy ";
              print "way in, only the allure ";
              "that wraps around it.";
          ],
    has   concealed static;

[ TriggerTrap;
    print "two portcullis come ";
    print "crashing down, trapping ";
    print "you in the walkway.^^";
    StartDaemon(allure);
    PlayerTo(allure,2);
    rtrue;
];
