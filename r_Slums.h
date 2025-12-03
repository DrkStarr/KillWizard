
! ---------------------------------------------------------------------------- !
!       SLUMS 12/31/24
!
Object  slums "Slums"
 with   description [;
          print "In the slums of Khalir, the ";
          print "poor beg for alms amidst ";
          print "the stench of urine. ";
          if (self.firstTime) {
            self.firstTime = false;
            print "The rain has let up, but the ";
            print "streets are made of mud. ";
            print "Whoever killed Darron is ";
            print "long gone. ";
          }
          print "To the northwest, a dark ";
          print "tower emerges from the ";
          print "forest, but the only way ";
          print "out is through the gate ";
          "to the north.";
        ],
        s_to [; <<Enter slumsDen>>; ],
        in_to [; <<Enter slumsDen>>; ],
        n_to [; <<Enter slumsGate>>; ],
        out_to [; <<Enter slumsGate>>; ],
        before [;
          Listen:
            if (slumsDen.doorRepair) {
              print "You hear hammering as Osric ";
              print "tries to repair the door to ";
              "the Den.";
            }
            print "You listen to thunder roll ";
            "over the hills.";
          Smell:
            print "The air smells rank. Even ";
            print "though it rained, it still ";
            "smells of urine.";
        ],
        cant_go [;
          print "There's no need to explore ";
          "the slums.";
        ],
        firstTime true,
  has   light;

RoomObj slumsObj "slums" slums
  with  name 'slum' 'slums' 'khalir',
        description [;
          <<Look slums>>;
        ];

Object  slumsPoor "poor" slums
 with   name 'poor' 'people' 'destitute' 'rags',
        article [;
          print "the";
        ],
        before [;
          Attack:
            return PKE();
          Examine:
            print "A few destitute people sit ";
            print "in front of the tavern, ";
            print "hands out, begging for ";
            "coins.";
          AskFor, AskFor2nd, Talk:
            print "They just beg. They don't ";
            "want to talk.";
        ],
        life [;
          ThrowAt:
            if (noun == axe) return PKE();
            return PPA();
          default:
            return PPA();
        ],
        orders [;
          default:
            return PPA();
        ],
   has  animate concealed pluralname;

Object  slumsDen "Scavenger's Den" slums
 with   name 'bar' 'den' 'tavern' 'inn',
        before [;
          Enter:
            if (self.doorRepair) {
              print "Osric's repairing the front ";
              print "door. You'll have to come ";
              "back later.";
            }
            if (self.knowAboutDrink) {
              print "Osric can't help you. He's ";
              print "busy trying to help Darron. ";
              "You need to leave him be.";
            }
            print "Osric's busy trying to help ";
            print "Darron. You need to leave ";
            "him be.";
          Examine:
            print "Scavenger's Den is an old ";
            print "building whose walls have ";
            print "long since seen a fresh ";
            print "coat of paint";
            if (self.doorRepair) {
              print ". The door is closed, and ";
              print "you can hear hammering ";
              "on the other side.";
            }
            ".";
          Take, Push, PushDir, Pull:
            "The tavern isn't going anywhere.";
        ],
        doorRepair false,
        knowAboutDrink false,
   has  concealed static proper;

Object  slumsDoor "door" slums
  with  name 'front' 'door',
        before [;
          Attack:
            if (slumsDen.doorRepair) {
              print "You don't want to do that, ";
              "Osric is busy repairing it.";
            }
          Close:
            if (slumsDen.doorRepair) "That's already closed.";
            print "This is no time to start ";
            "playing with the door.";
          Examine:
            if (slumsDen.doorRepair) {
              print "The door's closed. Osric ";
              print "is busy trying to ";
              "repair it.";
            }
            print "The door's broken open. All ";
            print "you see is the glow from ";
            "the firelight inside.";
          Enter, Open:
            <<Enter slumsDen>>;
          Open:
            if (slumsDen.doorRepair) <<Enter slumsDen>>;
            "That's already open.";
          Push, Pull, PushDir:
            if (slumsDen.doorRepair) <<Enter slumsDen>>;
            print "There's no need to show ";
            "off your strength.";
          Take:
            print "The door isn't going ";
            "anywhere.";
        ],
  has   concealed static;

Object  slumsStreet "street" slums
 with   name 'street' 'streets' 'mud',
        article [;
          print "the";
        ],
        before [;
          Examine:
            print "The streets over here in the ";
            print "slums are unpaved. Dirt ";
            print "roads are now mud with ruts ";
            "full of water.";
          Take, Push, PushDir, Pull:
            "That's not going anywhere.";
        ],
   has  concealed static;

Object  slumsGate "gate" slums
  with  name 'gate' 'entrance',
        article [;
          print "the";
        ],
        before [;
          Enter:
            PlayerTo(crossroad,2);
            rtrue;
          Examine:
            print "The gate stands open, ";
            print "allowing people to pass ";
            "through.";
          Take, Push, PushDir, Pull:
            print "The gate isn't going ";
            "anywhere.";
        ],
   has  concealed static;

Object  slumsTalisman "talisman" slums
  with  name 'talisman' 'trinket' 'item' 'charm',
        before [;
          Examine:
            print "The drunk holds the trinket ";
            print "tightly in his hand. How he ";
            print "came to have the thing is ";
            "remarkable.";
          default:
            print "You can't have the charm. ";
            "It's the drunk's.";
        ],
   has  concealed static;

! Need space for Z3 due to Apple II Interpreter: info3m
#Iftrue (#version_number == 5);
OutRch  slumsAlley "alley" slums
  with  name 'alley',
        before [;
          Examine:
            print "An alley runs between the ";
            print "Scavenger's Den and some ";
            "homes.";
          Enter:
            if (wine.givenAway) {
              print "You don't need to follow ";
              print "the drunk. You need to ";
              "find Belkor.";
            }
            print "There's no need to go ";
            "down the alley.";
        ],
   has  concealed static;

OutRch  slumsHomes "home" slums
  with  name 'home' 'homes' 'house' 'houses',
        before [;
          Examine:
            print "The houses lining the ";
            print "streets are packed with ";
            print "people. They live in ";
            print "crowded conditions where ";
            print "the homes are not ";
            "maintained.";
          Enter:
            print "You don't need to enter ";
            print "any of the homes. They're ";
            "no help tonight.";
        ],
   has  concealed static;
#Endif;

OutRch  slumsTower "tower"
 with   name 'dark' 'tower' 'forest' 'trees',
        before [;
          Examine:
            if (self in crossroad) {
              print "Over the forest to the ";
              print "northwest, a tower rises ";
              "above the trees.";
            }
            print "Above a bunch of shabby ";
            print "homes, a tower rises ";
            print "in the distance, past the ";
            print "forest, far to the ";
            "northwest.";
          Enter:
            if (self in crossroad) {
              print "The tower is too far away. ";
              "You need to head west.";
            }
            print "The tower is far to the ";
            print "north. You need to leave ";
            "the town first.";
        ],
        found_in slums crossroad;

Object  slumsOsric "Osric"
  with  name 'osric' 'bartender',
        before [;
          Attack, Burn, Push:
            return PGH();
          AskFor, AskFor2nd, Talk:
            return POO();
          Examine:
            print "Osric is inside the ";
            print "building, repairing the ";
            "door. You can't see him.";
        ],
        life [;
          Answer, Ask, Tell:
            return POO();
          default:
            return PGH();
        ],
        orders [;
          default:
            return POO();
        ],
  has   animate proper concealed;

 [ PPA;
     print "The poor pay no attention. ";
     "They only want coins.";
 ];

 [ POO;
     print "Osric's on the other side ";
     print "of the door, repairing it ";
     print "with a hammer. He can't ";
     "hear you.";
 ];

 [ PGH;
     print "Osric's on the other side ";
     print "of the door. You can't ";
     "get to him.";
 ];
