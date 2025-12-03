
! ---------------------------------------------------------------------------- !
!       WINE 1/2/25
!

Object  wine "wine" rootCellar
  with  name 'wine' 'jug' 'drink' 'bottle',
        short_name [;
            print "some ";
        ],
        describe [;
            if (self.takeWine == false) {
              print "^A jug of wine sits in the ";
              "corner.";
            }
        ],
        before [;
            Close:
              "The wine is already sealed.";
            Drop:
              if (player in slums) {
                ScoreWine();
                print "~Don't do that,~ the drunk ";
                print "says, catching the bottle ";
                print "before it hits the ground.^";
                print "^~Keep it,~ you say. He ";
                print "hands you a talisman in ";
                print "trade and mumbles ~thanks~ ";
                print "before walking down an alley ";
                print "to be alone with the jug.^";
                print "^Looking over the trinket, ";
                print "you see it's a necklace ";
                "and decide to wear it.";
              }
            Examine:
                if (self in rootCellar) {
                  print "The jug has been sitting ";
                  print "here for a long time. It ";
                  "must be the farmer's best.";
                }
                print "The jug's a bit dusty, but ";
                "the wine is oh-so tasty.";
            Take:
              self.takeWine = true;
            Give:
              if (second == drunk) {
                ScoreWine();
                print "Handing the wine to the man, ";
                print "he opens it and takes a deep ";
                print "swig. ~This is the good ";
                print "stuff,~ he says, smiling. ";
                print "Handing you a talisman in ";
                print "trade, he mumbles, ~All I ";
                print "have.~^^~Watch it,~ he ";
                print "adds, ~death is loose ";
                print "tonight. No man is safe.~ ";
                print "Then walks down an alley ";
                print "to be alone with the jug.^";
                print "^Looking over the trinket, ";
                print "you see it's a necklace ";
                "and decide to wear it.";
              }
              if (second == slumsPoor) return PPA();
              print "You need to give the wine ";
              "to someone.";
            Drink, Open:
              print "You don't need to get drunk. ";
              print "You need to focus on killing ";
              "Belkor.";
            Show:
              if (second == drunk) "~Awe. Don't tease me.~";
        ],
        takeWine false,
        givenAway false,
   has  proper;


[ ScoreWine;
    score++;
    move wine to drunk;
    remove drunk;
    remove slumsTalisman;
    give talisman worn;
    move talisman to player;
    wine.givenAway = true;
];
