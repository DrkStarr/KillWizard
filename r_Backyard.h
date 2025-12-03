! ---------------------------------------------------------------------------- !
!       BACKYARD 12/31/24
!
Object  backyard "Backyard"
  with  description [;
          print "A thick forest surrounds ";
          print "this tavern, which once ";
          print "had a backyard full of ";
          print "trees. ";
          if (self.firstTime == false) {
            self.firstTime = true;
            print "The innkeeper cut them ";
            print "down to keep his place ";
            print "warm. ";
          }
          print "The moon illuminates the ";
          print "forest to the south, and ";
          print "you feel there are eyes ";
          print "down there watching you. ";
          print "The door to the north is ";
          if (backDoor.hasOpen) "open.";
          "closed.";
        ],
		    n_to  [; <<Enter backTavern>>; ],
        in_to  [;
          if (backDoor.hasOpen == false) {
            backDoor.hasOpen = true;
            print "(first opening the door)^";
          }
          <<Enter backTavern>>; ],
        d_to [; <<Enter backForest>>; ],
        s_to [; <<Enter backForest>>; ],
		    e_to  [; <<Enter backGrave>>; ],
        before [;
          Listen:
            if (firewood.beenCut) {
              print "You listen to thunder roll ";
              "over the hills.";
            }
            print "Faintly, you hear dogs ";
            "baying at the moon.";
          Smell:
            print "The air smells like decaying ";
            print "earth, as if someone had ";
            "stirred a mud puddle.";
        ],
        cant_go [;
          if (firewood in player) {
            print "You need to bring the ";
            "firewood inside.";
          }
          print "You need to find firewood. ";
          "Don't go straying off.";
        ],
        firstTime false,
  has   light;

RoomObj backObj "backyard" backyard
  with  name 'back' 'yard' 'backyard',
        description [;
          <<Look backyard>>;
        ];

Object  backTavern "tavern" backyard
 with   name 'tavern' 'building' 'inn',
        before [;
          Enter, Open:
            if (backDoor.hasOpen == false) "The door is closed.";
            if (firewood in player) {
              StartDaemon(scavengersDen);
              sdDoor.hasOpen = false;
              print "The storm starts to break, ";
              print "so you close the door ";
              print "behind you.^^";
            }
            PlayerTo(scavengersDen,2);
            rtrue;
          Examine:
            print "The tavern sits up on a ";
            print "hill overlooking the ";
            print "forest below. Off the ";
            print "side of the building ";
            if (self.seenHeadstone) {
              "there's a headstone.";
            }
            self.seenHeadstone = true;
            "you notice a headstone.";
        ],
        seenHeadstone false,
   has  concealed static;

Object  backDoor "door" backyard
 with   name 'door' 'backdoor',
        before [;
          Enter:
            <<Enter backTavern>>;
          Close:
            if (self.hasOpen) {
              self.hasOpen = false;
              print "You close the door to ";
              "the tavern.";
            }
            "That's already closed.";
          Open:
            if (self.hasOpen) "That's already open.";
            self.hasOpen = true;
            print "You open the door to ";
            "the tavern.";
          Examine:
            print "The door to the tavern is ";
            if (self.hasOpen) "open.";
            "closed.";
        ],
        hasOpen true,
   has  concealed static;

Object  backGrave "grave" backyard
 with   name 'grave' 'headstone' 'stone' 'word',
        before [;
          Examine:
            print "A headstone rests on a mound ";
            print "of dirt on the east side of ";
            print "the building. Something's ";
            "carved into the stone.";
          Go, Enter:
            print "There's no need to go over ";
            "to the grave.";
          Dig, Push, Pull, Take, PushDir:
            "Don't disrespect the dead.";
          Read:
            print "One word is crudely chiseled ";
            "into the headstone: Seraina.";
        ],
   has  concealed static;

Object  backDirt "dirt" backyard
 with   name 'dirt' 'earth',
        before [;
          Examine:
            <<Examine backGrave>>;
          Go, Enter:
            <<Enter backGrave>>;
          Dig, Push, Pull, Take, PushDir:
            <<Push backGrave>>;
        ],
   has  concealed static;

OutRch  backMoon "moon" backyard
 with   name 'moon' 'storm' 'sky' 'light',
        before [;
          Examine:
            if (firewood.beenCut) {
              print "A storm has covered the ";
              print "moon, though shafts of ";
              print "light pierce the opaque ";
              "clouds.";
            }
            crossroadMoon.seenMoon = true;
            print "The moon is almost full ";
            print "tonight. It looks large as ";
            print "it hangs low in the sky, ";
            print "but you know it won't ";
            print "truly be full for two more ";
            print "nights. In the distance, a ";
            "storm is rolling in.";
          Take, Push, PushDir, Pull:
            "Don't be ridiculous.";
        ];

OutRch  backForest "forest" backyard
  with  name 'tree' 'trees' 'forest' 'woods',
        before [;
          Enter:
            PlayerTo(oldForest,2);
            rtrue;
          Examine:
            print "The forest is dark and ";
            print "foreboding. Anything ";
            "could be down there.";
        ];

OutRch  backForest2 "forest" backyard
  with  name 'wood',
        before [;
          Enter:
            <<Enter backForest>>;
          Examine:
            <<Examine backForest>>;
        ];

OutRch  backEyes "eyes" backyard
  with  name 'eyes' 'eye',
        before [;
          Attack, Burn, Climb, Close, Cut, Enter, Examine, Insert, Open, Push, PushDir, Pull, Take, ThrowAt:
            print "You can't see the eyes. ";
            print "You just feel them upon ";
            "you.";
        ],
  has   pluralname;
