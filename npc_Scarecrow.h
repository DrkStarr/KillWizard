
! ---------------------------------------------------------------------------- !
!       SCARECROW 1/1/25
!

Object  scarecrow "scarecrow" fields
 with   name 'scarecrow' 'enemy' 'man' 'strawman',
        article [;
          print "the";
        ],
        before [;
          Attack, Cut:
            if (self.firstTime) "You can't do that from here.";
            score++;
            remove self;
            StopDaemon(fields);
            self.mobDead = true;
            move fieldsStraw to fields;
            move fieldsScarecrows to fields;
            print "You swing your axe at the ";
            print "straw-filled man, taking ";
            print "chunks out of a scarecrow ";
            print "animated by magic from that ";
            print "dark land to the south. A ";
            print "true demon he is, something ";
            print "that must be put down, so ";
            print "you lay into him as pieces ";
            print "go flying. When done, ";
            print "there's nothing left but a ";
            "straw pile.";
          Close, Open:
            if (self.firstTime) "You can't do that from here.";
            return ScarecrowDeath();
          Examine, Enter:
            if (self.firstTime) {
              self.firstTime = false;
              print "In the distance, a scarecrow ";
              print "starts to twitch as you look ";
              print "at it. Squinting, you watch ";
              print "the strawman come to life. ";
              print "Not accepting what you see, ";
              print "it walks up to you, ready ";
              "to fight.";
            }
            self.surpressScarecrow = true;
            print "The scarecrow is animated. ";
            print "Alive with ";
            "erratic behavior.";
          Ask, AskFor, AskFor2nd, Talk:
            if (self.firstTime) "You can't do that from here.";
            print "Although the monster looks ";
            print "alive, it's not going to ";
            "talk.";
          Shoot:
            if (bow in player) {
              if (arrows in player) {
                if (self.firstTime) {
                  print "He's too far to hit ";
                  "from here.";
                }
                if (self.shootArrow) {
                  print "You're not going to kill ";
                  print "him that way. You'd only ";
                  "waste an arrow.";
                }
                self.shootArrow = true;
                print "You pull back the bow, ";
                print "planting an arrow squarely ";
                print "in his chest. But he ";
                print "doesn't flinch. He's ";
                "animated by dark magic.";
              }
              "How are you going to hit him. You don't have any arrows.";
            }
            "What are you going to shoot him with? You don't have a bow.";
          default:
            if (self.firstTime) "You can't do that from here.";
            return ScarecrowDeath();
        ],
        life [;
          ThrowAt:
            if (noun == axe) "Hitting it once won't do it. You need to really lay into him.";
            return ScarecrowDeath();
          default:
            return ScarecrowDeath();
          ],
          orders [;
              "The scarecrow pays no attention as it thrashes around.";
          ],
          mobDead false,
          firstTime true,
          shootArrow false,
          surpressScarecrow false,
     has  animate concealed;

[ ScarecrowDeath;
    print "You're smarter than that. ";
    print "You've seen this type of ";
    print "magic in Stygia before and ";
    print "know you must destroy this ";
    "abomination.";
];

Object  fieldsStraw "straw pile"
 with   name 'straw' 'pile' 'mob' 'monster',
        before [;
          Examine:
            print "You made short work of the ";
            print "scarecrow. All that remains ";
            print "of him is a straw pile on ";
            "the ground.";
          Take, Pull:
            print "The straw is worthless. You ";
            print "should leave what's left of ";
            "the scarecrow alone.";
          Push, PushDir:
            "It will blow away in time.";
        ],
   has  static;
