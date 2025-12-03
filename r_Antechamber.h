
! ---------------------------------------------------------------------------- !
!       ANTECHAMBER 1/8/25
!
Object  antechamber "Antechamber"
  with  description [;
          print "This antechamber connects ";
          print "the courtyard to the ";
          print "castle. The gate to the ";
          print "south lets in a bit of ";
          print "moonlight. To the north, ";
          print "a large set of double ";
          print "doors ";
          if (anteDoor.hasOpen) print "is open";
          else {
            if (anteDoor.openFirstTime == false) print "is barely open";
            else print "is closed";
          }
          print ". There's also a painting ";
          print "hanging on the wall";
          if (self.firstTime) {
            self.firstTime = false;
            print ".^^You see your talisman ";
            "begin to glow again.";
          }
          ".";
        ],
        n_to [;
          <<Enter anteDoor>>; ],
        in_to [;
          if (anteDoor.hasOpen == false) {
            anteDoor.hasOpen = true;
            anteDoor.openFirstTime = true;
            print "(first opening the doors)^";
          }
          <<Enter anteDoor>>; ],
        s_to [; <<Enter anteGate>>; ],
        out_to [; <<Enter anteGate>>; ],
		    before [;
          Listen:
            print "This small room is quiet. ";
            print "You don't even hear ";
            print "wildlife with the ";
            "gate open.";
          Smell:
            print "The air starts to smell ";
            print "stagnant and foul as if ";
            "death is in the air.";
		    ],
        cant_go [;
          print "There are doors to the ";
          print "north and a gate to ";
          "the south.";
        ],
        firstTime true,
  has   light;

RoomObj anteObj "antechamber" antechamber
  with  name 'antechamber' 'chamber',
        description [;
          <<Look antechamber>>;
        ];

Object  antePainting "painting" antechamber
 with   name 'painting' 'picture' 'betrayer' 'bar',
        before [;
          Attack, Cut:
            print "It's not a normal painting. ";
            print "It's made from Stygian ";
            print "magic. You're not going to ";
            "be able to damage it.";
          Examine:
            print "This painting portrays a ";
            print "bar where ";
            if (anteOldMan.seenOldMan) print "Osric";
            else print "an old man";
            print " is trying to poison an ";
            print "archer's waterskin. ";
            print "Distracted, the archer ";
            print "talks to a beautiful woman. ";
            print "It's labeled 'Betrayer' and ";
            print "was created by ";
            "Stygian magic.";
          Read:
            print "The bottom of the painting ";
            "reads: Betrayer.";
          Take, Push, PushDir, Pull:
            print "The painting is mounted on ";
            print "the wall and isn't going ";
            "anywhere.";
        ],
   has  concealed static;

Object  anteOldMan "old man" antechamber
 with   name 'old' 'man' 'ph001' 'bartender',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            if (self.seenOldMan) {
              print "With the archer distracted, ";
              print "the bartender reaches out ";
              "for the waterskin.";
            }
            self.seenOldMan = true;
            self.&name-->2 = 'osric';
            print "The bartender has a sinister ";
            print "look on his face. Upon ";
            print "closer inspection, the old ";
            "man is Osric.";
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  anteArcher "archer" antechamber
 with   name 'archer' 'belt',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            print "The archer is distracted ";
            print "as he drools over the ";
            print "woman. A waterskin is ";
            "tied to his belt.";
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  anteWoman "woman" antechamber
 with   name 'woman' 'beautiful',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            print "The woman smiles at the ";
            print "archer, knowing the ";
            print "bartender paid her off. ";
            print "You've never seen her ";
            "before.";
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  anteWaterskin "waterskin" antechamber
 with   name 'waterskin' 'skin',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            print "The bartender reaches out ";
            print "for the waterskin with ill ";
            "intent in his eyes.";
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  antePoison "poison" antechamber
 with   name 'poison' 'vial' 'glass',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            print "The bartender holds a glass ";
            "vial of green liquid.";
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  antePoison2 "poison" antechamber
 with   name 'green' 'liquid',
        before [;
          Attack, Cut:
            <<Attack antePainting>>;
          Examine:
            <<Examine antePoison>>;
          Take, Push, PushDir, Pull:
            <<Take antePainting>>;
        ],
        seenOldMan false,
   has  concealed static;

Object  anteDoor "doors" antechamber
 with   name 'doors' 'door' 'entrance',
        before [;
          Attack, Cut:
            print "You don't need to break ";
            "the doors.";
          Close:
            if (self.hasOpen) {
              self.hasOpen = false;
              print "You close the doors ";
              "to the hall.";
            }
            "The doors are already closed.";
          Open, Pull, Push, PushDir:
            if (self.hasOpen) "The doors are already open.";
            self.hasOpen = true;
            self.openFirstTime = true;
            "You open the doors.";
          Enter:
            if (self.openFirstTime == false) "The door is slightly ajar, you need to open it.";
            if (self.hasOpen == false) "The doors are closed.";
            if (golems.mobDead) {
              print "You walk into the hall.^^";
            } else {
              print "You walk into a hall full ";
              print "of skeletons.^^";
            }
            PlayerTo(greatHall, 2);
            rtrue;
          Examine:
            if (self.hasOpen) {
              print "The doors set in the north ";
              "wall are open.";
            }
            if (self.openFirstTime) {
              print "The doors set in the north ";
              "wall are closed.";
            }
            print "Doors are set into the north ";
            print "wall of this room, with one ";
            print "of them slightly ajar. The ";
            "demons have gone this way.";
          Take, Pull:
            print "The doors aren't going ";
            "anywhere.";
          Close:
            "That's already closed.";
        ],
        hasOpen false,
        openFirstTime false,
   has  concealed static pluralname;

Object  anteGate "gate" antechamber
 with   name 'gate' 'courtyard',
        before [;
          Enter:
            PlayerTo(courtyard,2);
            rtrue;
          Examine:
            print "The gate to the south stands ";
            print "open, letting in a bit of ";
            "light from the courtyard.";
          Take, Pull, Push, PushDir:
            print "The gate isn't ";
            "going anywhere.";
          Open:
            "That's already open.";
          Close:
            print "The magic seal is broken. ";
            "It's not going to close.";
        ],
   has  concealed static;

OutRch  anteMoon "moon" antechamber
 with   name 'moon' 'moonlight' 'sky' 'light',
        before [;
          Examine:
            print "A bit of light from the moon ";
            "shines in from the courtyard.";
          Take:
            "Don't be ridiculous.";
        ];
