
! ---------------------------------------------------------------------------- !
!       ALLURE 1/5/25
!
Object  allure "Allure"
  with  description [;
          print "In a narrow walkway, you ";
          print "are trapped between two ";
          print "portcullis - solid gates ";
          print "that have dropped into ";
          print "place. The walls of the ";
          print "allure ";
          if (allureWalls.examineWalls) print "are pitted and cracked";
          else print "look smooth";
          if (self.firstTime) {
            self.firstTime = false;
            print ", and you hear liquid ";
            print "flowing down from above. ";
            "There is no way out.";
          } else {
            if (allureWalls.examineWalls) {
              print ". Hot oil pools at ";
              "your feet.";
            }
            print ". Hot oil pools at your ";
            print "feet, and there is no ";
            "way out.";
          }
        ],
        u_to [; <<Climb allureWalls>>; ],
        out_to[;
          print "~It's not going to be that ";
          print "easy,~ the wizard laughs ";
          "from the top of the tower.";
        ],
        daemon [;
          iHotOil++;
          switch (iHotOil) {
            1: print "^Hot oil begins to splash ";
               print "on the ground. From ";
               print "somewhere in the tower, ";
               print "you hear, ~Die ";
               "barbarian.~";
            2: print "^The oil pools up quickly. ";
               "You don't have long.";
            3: print "^You try to stand in the ";
               print "corner, but the oil is ";
               "rising.";
            4: print "^Suddenly, more oil comes ";
               "pouring down.";
            5: deadflag=1;
               print "^The oil rises fast, ";
               print "searing your flesh to the ";
               print "bone. You beat on the ";
               print "portcullis as you scream ";
               print "out in pain, only to die in ";
               "scalding liquid.";
          }
        ],
		    before [;
          Listen:
            print "From above, you hear ";
            "liquid flowing.";
          Smell:
            "It smells of burning oil.";
		    ],
        cant_go [;
          print "You're trapped. There seems ";
          print "to be no way out, and hot ";
          "oil is pouring down.";
        ],
        firstTime true,
  has   light;

RoomObj allureObj "allure" allure
  with  name 'allure' 'walkway',
        description [;
          <<Look allure>>;
        ];

Object  allureWalls "walls" allure
 with   name 'wall' 'walls' 'rock',
        before [;
          Climb:
            print "Digging your fingers into ";
            print "stone, you find a handhold ";
            print "as you pull yourself up. ";
            print "Spotting another crack in ";
            print "the rock, you make your way ";
            print "over the wall.^^Only to ";
            print "miss landing on your feet. ";
            print "You hear a snap as you hit ";
            print "the ground, hoping it's not ";
            print "your spine.^^";
            StopDaemon(allure);
            StartDaemon(courtyard);
            PlayerTo(courtyard,2);
            rtrue;
          Examine:
            self.examineWalls = true;
            print "Upon closer inspection, the ";
            print "allure walls are pitted and ";
            print "cracked. You might be able ";
            "to scale them.";
          Push, PushDir, Pull:
            print "Made from thick stone, the ";
            "walls aren't going anywhere.";
        ],
        examineWalls false,
   has  concealed static pluralname;

Object  allureTower "tower" allure
 with   name 'tower',
        before [;
          Climb:
            <<Climb allureWalls>>;
          Examine:
            <<Examine allureWalls>>;
          Push, PushDir, Pull:
            <<Push allureWalls>>;
        ],
   has  concealed static;

Object  allurePort "portcullis" allure
 with   name 'portcullis' 'gate' 'gates' 'stone',
        before [;
          Climb:
            <<Climb allureWalls>>;
          Open, Push:
            print "The stone blocks are too ";
            print "heavy to lift, making ";
            print "a trap to kill anyone who ";
            "enters.";
          Examine:
            print "The portcullis is a pair ";
            print "of large stones on either ";
            print "side that fell in place ";
            print "when the trap was ";
            print "triggered, blocking ";
            "you in.";
        ],
   has  concealed static pluralname;

Object  allureOil "hot oil" allure
 with   name 'hot' 'oil' 'liquid',
        before [;
          Touch:
            print "You're trying not to ";
            "do that.";
          Burn:
            print "It might be oil, but it ";
            "won't ignite.";
          Examine:
            switch (iHotOil) {
              3: print "Hot oil begins to rise ";
                 print "as it collects at the ";
                 "bottom of the allure.";
              2: print "Hot oil pours down from ";
                 print "above as it pools at the ";
                 "bottom of the allure.";
              default:
                print "Hot oil starts to drip ";
                print "down from above, pooling ";
                "at the bottom of the allure.";
            }
        ],
   has  concealed static pluralname;

OutRch  allureMoon "moon"
 with   name 'moon' 'moonlight' 'sky' 'light',
        before [;
          Examine:
            print "Down here, you can't see ";
            print "the moon because it's low ";
            print "on the horizon, but light ";
            "still finds a way in.";
          Take, Push, PushDir, Pull:
            "Don't be ridiculous.";
        ],
        found_in allure courtyard;
