! The scarecrow in the field is not the same as the npc that gets killed
! This creates a strange error where if you try to kill "him", it says you can't see the scarecrow
! This is because you're removing one for the other

! ---------------------------------------------------------------------------- !
!       FIELDS 1/1/25
!
! With this puzzle, the game waits until the player looks at the scarecrow before it attacks
! If the player never looks, it doesn't attack, no score
! The player can run from the scarecrow, getting the poker, coming back to burn him

Object  fields "Fields"
 with   description [;
          if (self.firstTime) {
              self.firstTime = false;
              slumsDen.doorRepair = true;
              move slumsOsric to slums;
          }
          print "In the moonlight, rows of ";
          print "trellises support ";
          print "grapevines, with the purple ";
          print "fruit almost glowing. ";
          print "Scattered throughout the ";
          print "field are a few scarecrows ";
          print "keeping the carrion birds ";
          print "at bay. There's a farm to ";
          print "the east and a crossroads ";
          "to the west.";
        ],
        daemon [;
          if (scarecrow.firstTime == false) {
            if (scarecrow.surpressScarecrow) {
              scarecrow.surpressScarecrow = false;
            } else {
              iMobTrigger++;
              if (iMobTrigger >= 2) {
                iMobTrigger = 0;
                print "^The strawman lunges, but ";
                print "you step back, watching ";
                "him right himself.";
              } else {
                print "^The scarecrow watches you ";
                print "with hollow, black eyes, ";
                print "its arms jerking, ready ";
                "to attack.";
              }
            }
          }
        ],
        e_to [; <<Enter fieldsFarm>>; ],
        w_to [; <<Enter fieldsCrossroads>>; ],
        out_to [; <<Enter fieldsCrossroads>>; ],
        before [;
          Listen:
            if (scarecrow in self && scarecrow.firstTime == false) {
              print "An odd sound comes from ";
              print "the scarecrow as he ";
              "twitches around.";
            }
            print "Far to the east, you ";
            print "listen to thunder roll ";
            "over the hills.";
          Smell:
            print "Fresh air blows through the ";
            print "fields, along with the ";
            "sweetness of grapes.";
        ],
        cant_go [;
          print "You can follow the road ";
          "east or west.";
        ],
        firstTime true,
  has   light;

RoomObj fieldsObj "fields" fields
  with  name 'fields' 'field',
        description [;
          <<Look fields>>;
        ];

Object  fieldsTrellis "trellises" fields
 with   name 'framework' 'trellises' 'latticework',
        before [;
          Examine:
            print "Vines are threaded through ";
            print "the latticework. It's filled ";
            print "in thick with grapes covered ";
            print "in soft dew, which glisten ";
            "in the moonlight.";
          Take, Pull:
            print "There's no need to take ";
            "any of the grapes.";
          Push, PushDir:
            print "The trellises aren't ";
            "going anywhere.";
        ],
   has  concealed static pluralname;

Object  fieldsGrapes "grapes" fields
 with   name 'grapes' 'grape' 'fruit' 'vines',
        before [;
          Examine:
            print "Grapevines densely cover ";
            print "the trellises, thick ";
            "with fruit.";
          Take, Pull:
            print "There's no need to take ";
            "any of the grapes.";
          Push, PushDir:
            print "The grapes aren't going ";
            "anywhere.";
        ],
   has  concealed static pluralname;

OutRch  fieldsCrossroads "crossroads" fields
 with   name 'road' 'crossroad' 'crossroads',
        before [;
          Enter:
            if (scarecrow in fields && scarecrow.firstTime == false) {
              print "You don't dare turn your ";
              "back on the scarecrow.";
            }
            print "You walk for a bit before ";
            print "reaching the crossroads.^^";
            StopDaemon(fields);
            PlayerTo(crossroad,2);
            rtrue;
          Examine:
            print "In the distance, you watch ";
            "crows circle the crossroads.";
        ];

OutRch  fieldsCrows "crows" fields
 with   name 'bird' 'crow' 'birds' 'crows',
        before [;
          Examine:
            print "In the distance, you watch ";
            "crows circle the crossroads.";
        ];

OutRch  fieldsFarm "farm" fields
 with   name 'farm',
        before [;
          Enter:
            if (scarecrow.mobDead) {
              if (crow in farm) StartDaemon(farm);
              PlayerTo(farm, 2);
              rtrue;
            } else {
              if (scarecrow.firstTime == false) {
                print "You're smarter than that. ";
                print "You've seen this type of ";
                print "magic before in Stygia and ";
                print "know you must destroy this ";
                "abomination.";
              } else {
                scarecrow.firstTime = false;
                print "Before heading to the farm, ";
                print "you see a scarecrow twitch ";
                print "in the distance. Squinting, ";
                print "you watch the strawman come ";
                print "to life. Not accepting what ";
                print "you see, it walks up to ";
                "you, ready to fight.";
              }
            }
          Examine:
            print "There's a farm located to ";
            print "the east. You can see a ";
            print "barn silhouetted against ";
            "the night sky.";
        ];

OutRch  fieldsScarecrows "scarecrows"
 with   name 'scarecrow' 'scarecrows' 'strawman' 'man',
        before [;
          Examine:
            print "Scarecrows dot the field. ";
            "Luckily, no more come alive.";
        ];
