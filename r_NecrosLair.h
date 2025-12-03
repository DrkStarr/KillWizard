
! ---------------------------------------------------------------------------- !
!       NECRO'S LAIR 1/11/25
!
Object  necrosLair "Necromancer's Lair"
  with  description [;
          if (nlCauldron.objectPushed) {
            print "The black cauldron's ";
            print "contents are all over ";
            print "the floor - the evil ";
            print "wizard's spell now broken. ";
          } else {
            print "A black cauldron boils ";
            print "away in the middle of ";
            print "the necromancer's lair - ";
            print "the evil wizard is working ";
            print "up a new spell. ";
          }
          print "Jars line the walls filled ";
          print "with arsenic, belladonna, ";
          print "and death";
          if (self.firstTime) {
            self.firstTime = false;
            print ".^^~So, you think you can ";
            print "kill me?~ the wizard asks ";
            print "as the demon on his shoulder ";
            "whispers into his ear.";
          }
          ".";
        ],
        d_to [;
          <<Enter nlStairway>>;
        ],
        out_to [;
          <<Enter nlStairway>>;
        ],
        daemon [;
          iNecroAttack++;
          if (iNecroAttack==2) {
            if (self.necroPause) {
              print "^The necromancer is about ";
              "to strike.";
            }
            self.necroPause = true;
            print "^The necromancer's hands ";
            "begin to glow white hot.";
          }
          if (iNecroAttack==3) {
            deadflag=1;
            print "^Unleashing a surge of ";
            print "electricity, a bolt shoots ";
            print "out of the wizard's hands, ";
            print "striking you in the chest ";
            print "and throwing you back ";
            print "against the wall. You try ";
            print "to get up, but a second ";
            print "bolt hits you, electrocuting ";
            "you on the spot.";
          }
        ],
		    before [;
          Listen:
            if (noun == nlDemon) {
              if (nlCauldron.objectPushed) {
                print "The ";
                if(cyFiend.headGone) print "demon";
                if(cyDemon.headGone) print "mephit";
                if(cyMephit.headGone) print "fiend";
                print " just watches you from ";
                "his perch.";
              }
              print "You can't hear the ";
              if(cyFiend.headGone) print "demon";
              if(cyDemon.headGone) print "mephit";
              if(cyMephit.headGone) print "fiend";
              " above the boiling cauldron.";
            }
            if (nlCauldron.objectPushed) {
              print "There's electricity in the ";
              "air.";
            }
            print "There's electricity in the ";
            print "air, but all you can hear is ";
            "the bubbling of the cauldron.";
          Smell:
            print "The air smells of arsenic ";
            "from the cauldron.";
		    ],
        cant_go [;
          "The room isn't that big.";
        ],
        firstTime true,
        necroPause false,
  has   light;

RoomObj nlObj "lair" necrosLair
  with  name 'lair' 'room',
        description [;
          <<Look necrosLair>>;
        ];

Object  nlCauldron "cauldron" necrosLair
  with  name 'cauldron' 'kettle' 'pot' 'vat',
        before [;
          Examine:
            print "The black cauldron ";
            if (self.objectPushed) {
              print "lies on ";
              print "its side, with liquid ";
              print "spilled out, extinguishing ";
              "the fire.";
            }
            print "boils ";
            print "over as the wizard works ";
            print "his magic. Conjuring a ";
            print "spell that will turn him ";
            "into a lich.";
          Attack, Push, PushDir:
            if (self.objectPushed) {
              print "You've already spilled the ";
              "cauldron all over the lair.";
            }
            self.objectPushed = true;
            nlStairway.triedDown = true;
            print "You hit the cauldron with ";
            print "your shoulder. Liquid ";
            print "splashes across the floor, ";
            print "but the wizard stays out ";
            if (nlJars.knockedOver || nlArsenic.knockedOver || self.itemIn) "of its way.";
            print "of its way.^^~Damn ";
            print "barbarian,~ you hear the ";
            print "wizard curse, as the ";
            "spell fails.";
          Take, Pull:
            print "You pull the cauldron, ";
            print "burning your hands on the ";
            "metal, but it doesn't budge.";
          Close:
            print "The cauldron has no top. ";
            "You can't close it.";
          Open:
            print "The wide mouth of the ";
            print "cauldron is already ";
            "exposed.";
          ],
          itemIn false,
          objectPushed false,
    has   concealed static container open;

Object  nlDemon "demon" necrosLair
  with  name 'demon' 'mephit' 'fiend',
        before [;
          Attack, Cut, Push, PushDir, Pull, Take:
            print "You have to get through ";
            "the wizard first.";
          Examine:
            print "It's the same ";
            if(cyFiend.headGone) print "red demon";
            if(cyDemon.headGone) print "green mephit";
            if(cyMephit.headGone) print "black fiend";
            print " from the courtyard. He ";
            print "must have made his way up ";
            print "here, informing the wizard ";
            "about you.";
          ],
    has   animate concealed;

Object    nlStairway "stairway" necrosLair
   with   name 'stairs' 'stairway' 'stair',
          before [;
            Enter:
              if (self.triedDown) {
                StopDaemon(necrosLair);
                deadflag=1;
                print "Turning back to go down, the ";
                print "wizard unleashes a surge of ";
                print "electricity. A bolt shoots ";
                print "out of his hands, striking ";
                print "you in the back and throwing ";
                print "you into the wall. You try ";
                print "to get up, but a second bolt ";
                print "hits you, electrocuting you ";
                "on the spot.";
              }
              self.triedDown =  true;
              print "You look down the stairway, ";
              "preparing to step back.";
            Examine:
              print "The stairway leads down to ";
              "the base of the tower.";
            Burn, Climb, Push, PushDir, Pull, Take:
              "You don't need to do that.";
          ],
          triedDown false,
    has   concealed static;

Object    nlJars "jars" necrosLair
   with   name 'jars' 'bottles' 'belladonna',
          before [;
            Burn, Climb:
              "You don't need to do that.";
            Examine:
              print "The assorted jars hold the ";
              "components to make a lich.";
            Attack, Push, PushDir, Pull, Take:
              if (self.knockedOver) {
                print "The jar of belladonna lies ";
                "on the ground.";
              }
              print "You reach out to grab the ";
              print "belladonna, knocking it to ";
              print "the ground";
              if (self.knockedOver == false && nlArsenic.knockedOver == false && nlCauldron.objectPushed == false) {
                self.knockedOver = true;
                nlStairway.triedDown = true;
                return PSB();
              }
              ".";
          ],
          knockedOver false,
    has   concealed static;

Object    nlArsenic "arsenic" necrosLair
   with   name 'arsenic' 'bottle' 'death',
          before [;
            Burn, Climb:
              "You don't need to do that.";
            Examine:
              print "The asenic is a key ";
              print "component for the spell ";
              "the wizard is weaving.";
            Attack, Push, PushDir, Pull, Take:
              if (self.knockedOver) {
                print "The bottle of arsenic lies ";
                "on the ground.";
              }
              print "You reach out to grab the ";
              print "arsenic, knocking it to ";
              print "the ground";
              if (self.knockedOver == false && nlArsenic.knockedOver == false && nlCauldron.objectPushed == false) {
                self.knockedOver = true;
                nlStairway.triedDown = true;
                return PSB();
              }
              ".";
          ],
          knockedOver false,
    has   concealed static;

 [ PSB;
     print ". This wizard will not ";
     print "become a lich.^^~Uh. ";
     print "Stupid barbarian,~ the ";
     "wizard curses.";
 ];
