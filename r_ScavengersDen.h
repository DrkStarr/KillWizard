
! ---------------------------------------------------------------------------- !
!       SCAVENGER'S DEN 12/31/24
!
Object  scavengersDen "Scavenger's Den"
  with  description [;
          if (firewood.onFire) {
              print "A small group of strangers ";
              print "crowd in the corner, visibly ";
              print "shocked by what has just ";
              print "happened. Osric stands ";
              print "beside you, still in shock, ";
              print "gazing at your dying friend ";
              print "on the ground.^";
              print "^The front door to the north ";
              print "has been broken open as the ";
              print "storm begins to subside. ";
              print "Darron is sprawled on the ";
              print "ground";
              if (scroll in self && scroll.objectTaken == false) print ", holding on to a scroll";
              print ". The firepit in the center ";
              "of the room burns brightly.";
          }
          print "The Den has a few strangers ";
          print "huddling in the corner ";
          print "tonight. The tables are ";
          print "sticky from spilled ale. ";
          if (firewood.beenCut) {
              if (osric.flintGiven) {
                print "Osric stands besides you.^";
              } else {
                print "Osric stands behind the bar, ";
                print "cleaning a few mugs with a ";
                print "used rag.^";
              }
              if (firewood in sdFirepit) {
                print "^The back door is closed ";
                print "while a storm rages outside. ";
                print "Stacked firewood sits in ";
                "the pit.";
              }
              print "^The back door is closed ";
              print "while a storm ";
              if (self.rainFirstTime) {
                self.rainFirstTime = false;
                print "begins";
              } else print "rages";
              print " outside. A firepit sits in ";
              "the middle of the room.";
          }
          print "Without a barmaid, the mugs ";
          print "you'll be drinking from are ";
          print "used. Osric works behind the ";
          print "bar.^^The back door to the ";
          print "south is ";
          if (sdDoor.hasOpen) {
            print "open. A firepit sits in the ";
            "middle of the room.";
          }
          print "closed. A firepit sits in ";
          "the middle of the room.";
        ],
        daemon [;
          if (player in self && wolf.animalDead && firewood.onFire == false) {
            iDenRain++;
            switch (iDenRain) {
              3: print "^A crack of thunder ";
                 print "erupts outside";
                 if (self.firstTime) {
                   self.firstTime = false;
                   ".";
                 }
                 " again.";
              6: iDenRain=0;
                 print "^You can hear the rain ";
                 print "beating down on the ";
                 "building.";
            }
          }
        ],
        n_to [;
          if (firewood.onFire) return ExitDen();
        ],
        out_to [;
          if (firewood.onFire) return ExitDen();
          if (firewood.beenCut) {
            print "~Please. Start the fire,~ ";
            "Osric reminds you.";
          }
          if (sdDoor.hasOpen == false) {
            sdDoor.hasOpen = true;
            print "(first opening the door)^";
          }
          <<Enter sdDoor>>;
        ],
		    s_to [;
          if (firewood.onFire) "The front door is north.";
          if (firewood.beenCut) {
            print "~Please. Start the fire,~ ";
            "Osric reminds you.";
          }
          <<Enter sdDoor>>;
        ],
        before [;
          Listen:
            if (firewood.onFire) {
              print "The room is quiet except for ";
              "the fire burning in the pit.";
            }
            if (wolf.animalDead) {
              print "Strangers in the corner ";
              print "complain to themselves, ";
              "talking over the rain.";
            }
            print "Strangers in the corner ";
            "complain to themselves.";
          Smell:
            print "The place smells of ";
            "home-cooked food.";
        ],
        cant_go [;
          if (firewood.onFire) "The front door is north.";
          if (wolf.animalDead) {
            print "~Please. Start the fire,~ ";
            "Osric reminds you.";
          }
          print "The back door out of here ";
          "is south.";
        ],
        firstTime true,
        rainFirstTime true,
  has   light;

RoomObj sdObj "den" scavengersDen
  with  name 'scavenger~s' 'scavengers' 'scavenger' 'den',
        description [;
          <<Look scavengersDen>>;
        ];

Object  sdFirepit "firepit" scavengersDen
  with  name 'firepit' 'fire' 'pit' 'fireplace',
        before [;
          Burn:
            if (firewood.onFire) "The wood is already burning.";
            if (flint in player) <<Attack flint>>;
            if (firewood in self) {
                if (self.fireHint) {
                  print "Maybe Osric has some flint ";
                  print "that you could use to start ";
                  "the fire.";
                }
                self.fireHint = true;
                print "If only you had some flint ";
                "to spark against your axe.";
            }
            "There's no wood in the pit.";
          Examine:
            if (firewood in self) {
                if (firewood.onFire) {
                  print "The blaze is already ";
                  print "starting to warm the room ";
                  "on this rainy night.";
                }
                print "The stones are packed in ";
                print "tight, forming a circle ";
                print "around the pit. In the ";
                print "center, the wood is ";
                print "propped up and ready ";
                "to light.";
            }
            print "The stones are packed in ";
            print "tight, forming a circle ";
            print "around the pit. Ash lies ";
            "at the bottom.";
          Take:
            if (firewood.onFire) {
              print "You'd burn yourself. The ";
              "wood is on fire.";
            }
            if (firewood in self) {
              print "You've already stacked the ";
              print "wood. Now you need to light ";
              "the fire.";
            }
            print "There's nothing to take. ";
            print "The pit is in the center ";
            print "of the room, and the ash ";
            "is worthless.";
          Push, Pull, PushDir:
            if (firewood.onFire) {
              print "If you toppled the fire, it ";
              print "would burn the place down. ";
              "No one wants that.";
            }
            print "You can't move the pit. It's ";
            "in the center of the room.";
        ],
        fireHint false,
  has   concealed static container open;

Object  sdAsh "ash" sdFirepit
  with  name 'ash' 'soot',
        before [;
          Burn:
            "That won't light on fire.";
          Examine:
            print "Ash lies at the bottom of ";
            "the stone firepit.";
          Take:
            if (firewood in sdFirepit) {
              print "You've already stacked ";
              print "the wood. You can't get ";
              "to the ash.";
            }
            "The ash is worthless.";
          Push, Pull, PushDir:
            if (firewood in sdFirepit) {
              print "You've already stacked the ";
              print "wood. You can't get to the ";
              "ash.";
            }
            print "There is no need to play ";
            "with the ash.";
        ],
  has   concealed static;

Object  sdDoor "back door" scavengersDen
  with  name 'back' 'door' 'backdoor',
        before [;
          Close:
            if (scroll.objectRead) return POH();
            if (firewood.onFire) "You need to read the scroll.";
            if (firewood.beenCut) "That's already closed.";
            if (self.hasOpen) {
              self.hasOpen = false;
              "You close the back door.";
            }
            "That's already closed.";
          Open:
            if (scroll.objectRead) return POH();
            if (firewood.onFire) "You need to read the scroll.";
            if (firewood.beenCut) {
              print "~It looks like you already ";
              print "got the wood. Now, start ";
              "the fire.~";
            }
            if (self.hasOpen) "That's already open.";
            self.hasOpen = true;
            "You open the back door.";
          Examine:
            if (self.hasOpen) {
              print "The heavy door to the ";
              "backyard is open.";
            }
            print "The heavy door to the ";
            "backyard is closed.";
          Enter:
            if (scroll.objectRead) return POH();
            if (firewood.onFire) "You need to read the scroll.";
            if (firewood.beenCut) return ExitDen();
            if (self.hasOpen == false) "The back door is closed.";
            backDoor.hasOpen = false;
            print "You walk out back, closing ";
            print "the door behind you as ";
            print "your eyes adjust.^^";
            PlayerTo(backyard, 2);
            rtrue;
          Take:
            "The door isn't going anywhere.";
        ],
        hasOpen false,
  has   scenery static;

 [ POH;
    print "~Please, I need to get a ";
    print "handle on all of this,~ ";
    print "Osric says, looking ";
    print "serious, ~Take your business ";
    "somewhere else.~";
 ];

Object  sdBar "bar" scavengersDen
  with  name 'bar',
        before [;
          Attack, Burn:
            print "~What are you doing?~ Osric ";
            "barks, holding his ground.";
          Examine:
            print "The bar sits on the east ";
            print "wall of the tavern";
            if (osric.flintGiven) ".";
            if (wolf.animalDead) {
              print ". Osric cleans up the area. ";
              "At least, it looks like it.";
            }
            print ". Osric pours pints for the ";
            "strangers in the corner.";
          Push, Pull, Take:
            "The bar isn't going anywhere.";
        ],
  has   concealed static;

Object  sdTables "table" scavengersDen
  with  name 'table' 'tables' 'ale',
        before [;
          Attack, Burn:
            print "~Please. Leave the tables ";
            "alone,~ Osric demands.";
          Examine:
            print "The tables are well-built, ";
            print "sturdy, and strong. But ";
            "covered in spilled ale.";
          Push, PushDir, Pull, Take:
            print "~Please. Leave the tables ";
            "in place,~ says Osric.";
        ],
   has  concealed static;

Object  sdChairs "chair" scavengersDen
  with  name 'chair' 'chairs' 'seat' 'seats',
        before [;
          Attack, Burn:
            print "~Please. Leave the chairs ";
            "alone,~ Osric asks.";
          Examine:
            print "Chairs are around every ";
            "table.";
          Push, PushDir, Pull, Take:
            print "~Please. Leave the chairs ";
            "in place,~ says Osric.";
        ],
   has  concealed static;

Object  sdPint "pint" scavengersDen
  with  name 'pint' 'pints' 'mug' 'mugs',
        before [;
          Attack, Burn:
            print "~Please. Head out back and ";
            print "get some wood,~ Osric ";
            "demands.";
          Examine:
            print "Osric prepares pints for the ";
            print "eager strangers that crowd ";
            "out the corner.";
          Push, PushDir, Pull, Take:
            print "~Come on now,~ Osric says, ";
            print "~these ain't for you. Build ";
            print "us a fire and I'll make ";
            "sure you get one.~";
        ],
   has  concealed static;

Object  sdMug "mugs"
  with  name 'mug' 'mugs',
        before [;
          Attack, Burn:
            if (osric.knowsNecro) {
              print "~You must avenge your ";
              "brother in arms.~";
            }
            if (firewood.onFire) "~Mitra. What happened?~";
            if (osric.flintGiven) {
              print "~Wait. It's time to see ";
              "some flames.~";
            }
            print "~Please. Buid us a fire ";
            "already,~ Osric demands.";
          Examine:
            if (osric.flintGiven) {
              print "The mugs rest on the bar. ";
              "Empty.";
            }
            print "Osric cleans a few mugs ";
            print "using a dirty rag like ";
            "you feared.";
          Push, PushDir, Pull, Take:
            if (osric.knowsNecro) {
              print "~You must avenge your ";
              "brother in arms.~";
            }
            if (firewood.onFire) "~Mitra. What happened?~";
            if (osric.flintGiven) {
              print "~Wait. It's time to see ";
              "some flames.~";
            }
            print "~These aren't full,~ Osric ";
            print "says, ~Build us a fire ";
            "and I'll get you one.~";
        ],
   has  concealed static;

Object  sdRag "rag"
  with  name 'used' 'rag',
        before [;
          Attack, Burn:
            <<Attack sdMug>>;
          Examine:
            "The rag is brown. Dark brown.";
          Take, Push, Pull:
            print "You don't want to touch that ";
            "thing. You really don't.";
        ],
   has  concealed static;

[ ExitDen;
    if (scroll.objectRead) {
      StopDaemon(scavengersDen);
      print "Stepping through the broken ";
      print "door, the rain lets up. You ";
      print "nod to Osric as he looks at ";
      print "Darron, wondering what to ";
      print "do next.^^";
      PlayerTo(slums,2);
      rtrue;
    }
    if (firewood.onFire) "You need to read the scroll.";
    print "~Please. Start the fire,~ ";
    "Osric reminds you.";
];

Object  sdStrangers "strangers" scavengersDen
  with  name 'strangers' 'stranger' 'people' 'group',
        before [;
          AskFor, AskFor2nd:
            if (firewood.onFire) {
              print "The strangers stand in the ";
              print "corner, worried, and pay ";
              "you no mind.";
            }
            print "The strangers keep to ";
            print "themselves, talking in an ";
            "odd dialect.";
          Attack, Burn, Cut:
            return PKE();
          Examine, Push, PushDir, Pull:
            if (firewood.onFire) {
              print "The strangers stand in the ";
              print "corner, worried about what ";
              "happened.";
            }
            print "The strangers keep to ";
            print "themselves, talking in an ";
            "odd dialect.";
          Climb, Take:
            print "You don't need to anger ";
            "the strangers.";
          Talk:
            if (firewood.onFire) {
              print "You can't understand their ";
              "language, anyway.";
            }
            print "The strangers keep to ";
            print "themselves. You can't ";
            print "understand their language, ";
            "anyway.";
        ],
        life [;
          Ask:
            if (firewood.onFire) {
              print "You can't understand their ";
              "language, anyway.";
            }
            print "The strangers keep to ";
            print "themselves. You can't ";
            print "understand their language, ";
            "anyway.";
          default:
            if (firewood.onFire) {
              print "The strangers stand in the ";
              print "corner, worried, and pay ";
              "you no mind.";
            }
            print "The strangers keep to ";
            print "themselves. They crowd ";
            "the corner.";
        ],
        orders [;
          if (firewood.onFire) {
            print "The strangers stand in the ";
            print "corner, worried, and pay ";
            "you no mind.";
          }
          print "The strangers keep to ";
          "themselves.";
        ],
  has   animate concealed proper pluralname;

Object  sdArrows "arrow"
  with  name 'black' 'arrow' 'poison',
        before [;
          Examine:
            print "It's a cursed arrow - ";
            print "probably coated in ";
            print "poison. Only a mercenary ";
            "would use such a weapon.";
          Attack, Cut, Take, Push, PushDir, Pull:
            print "That's not going to help ";
            print "Darron, and you would cut ";
            "yourself on the poison tip.";
        ],
  has   concealed static;

Object  sdFrontDoor "front door"
  with  name 'front' 'door' 'frontdoor',
        before [;
          Close:
            print "There's no door to close. ";
            print "It broke into pieces when ";
            "Darron fell through it.";
          Open:
            print "There's no door to open. ";
            print "It broke into pieces when ";
            "Darron fell through it.";
          Examine:
            print "The door broke open when ";
            print "Darron fell through. Now it ";
            "allows in the rain.";
          Enter:
            return ExitDen();
          Take:
            print "The door isn't going ";
            "anywhere.";
        ],
  has   scenery static;
