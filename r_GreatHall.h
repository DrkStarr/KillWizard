
! ---------------------------------------------------------------------------- !
!       GREAT HALL 1/9/25
!
Object  greatHall "Great Hall"
  with  description [;
          if (golems.mobDead) {
            print "This hall is barren, but ";
            print "not empty, with a hundred ";
            print "candles in ";
            print "chandeliers lighting it, ";
            print "along with long tables that ";
            print "stretch the length of the ";
            print "room. The doors to the ";
            print "south are ";
            if (ghDoors.hasOpen) {
              print "open. To the east is ";
              "the kitchen.";
            }
            print "closed. To the east is ";
            "the kitchen.";
          }
          if (self.firstTime) {
            print "In front of you is a ";
            print "surreal scene. ";
          }
          print "In the center of a large ";
          print "hall, long tables stretch ";
          print "the room's length. A feast ";
          print "is about to be served in a ";
          print "place full of skeletons, ";
          print "lit by a hundred candles ";
          print "in chandeliers. ";
          print "To the east, the kitchen ";
          print "is open, and you can hear ";
          print "sounds coming from that ";
          print "room. The doors to the ";
          print "south are ";
          if (ghDoors.hasOpen) print "open";
          else print "closed";
          if (self.firstTime) {
            self.firstTime = false;
            print ".^^The skeletons are ";
            print "motionless, the air still, ";
            print "and the talisman glows ";
            "bright blue.";
          }
          ".";
        ],
        e_to [; <<Enter ghKitchen>>; ],
        s_to [; <<Enter ghDoors>>; ],
        out_to [;
          if (ghDoors.hasOpen == false) {
            ghDoors.hasOpen = true;
            print "(first opening the doors)^";
          }
          <<Enter ghDoors>>;
        ],
        in_to [; <<Enter ghKitchen>>; ],
		    before [;
          Listen:
            if (golems.mobDead) {
              print "The place is quiet. Your ";
              "footsteps ring hollow.";
            }
            print "The sound of someone banging ";
            print "on pots can be heard coming ";
            "from the room to the east.";
          Smell:
            if (golems.mobDead) {
              print "The air smells foul, as if ";
              "something dead is close.";
            }
            print "Strangely, the room is ";
            print "filled with the aroma of ";
            print "freshly baked bread, ";
            print "but you don't see any ";
            "food put out.";
		    ],
        cant_go [;
          print "You can go south through ";
          print "the doors, or east into ";
          "the kitchen.";
        ],
        firstTime true,
  has   light;

RoomObj ghObj "hall" greatHall
  with  name 'great' 'hall',
        description [;
          <<Look greatHall>>;
        ];

Object    ghTables "tables" greatHall
   with   name 'long' 'table' 'tables',
          before [;
            Examine:
              print "Long tables run the length ";
              print "of the room";
              if (golems.mobDead) ".";
              print ". Sitting at ";
              print "them, skeletons wait ";
              "motionless for food.";
            Take, Push, PushDir, Pull:
              print "The tables aren't ";
              "going anywhere.";
          ],
    has   concealed static pluralname;

Object    ghDoors "doors" greatHall
   with   name 'doors' 'door',
          before [;
            Close:
              if (self.hasOpen) {
                self.hasOpen = false;
                "You close the doors.";
              }
              "The doors are already closed.";
            Open, Pull:
              if (self.hasOpen) "The doors are already open.";
              self.hasOpen = true;
              "You open the doors.";
            Enter:
              if (self.hasOpen == false) "The doors are closed.";
              PlayerTo(antechamber,2);
              rtrue;
            Examine:
              print "The doors to the south are ";
              if (self.hasOpen) "open.";
              "closed.";
            Take, Push, PushDir:
              print "The doors aren't going ";
              "anywhere.";
          ],
          hasOpen true,
    has   concealed static pluralname;

OutRch    ghKitchen "kitchen" greatHall
   with   name 'kitchen',
          before [;
            Enter:
              if (golems.mobDead == false) {
                if (kitchen.firstTime) StartDaemon(chef);
                print "Leaving the skeletons in ";
                print "the hall, you enter the ";
                print "kitchen.^^";
              }
              PlayerTo(kitchen, 2);
              rtrue;
            Examine:
              print "The kitchen is on the east ";
              print "side of this room";
              if (golems.mobDead) ".";
              print ", identified by the sound ";
              "of clanging pots.";
          ];

OutRch    ghCandles "candles" greatHall
   with   name 'candle' 'candles' 'chandelier' 'chandeliers',
          before [;
            Examine:
              print "The candles give off a ";
              print "strange, dull glow. They ";
              "produce no heat.";
            Take, Push, PushDir, Pull:
              print "You can't reach them ";
              "from here.";
          ],
     has  pluralname;
