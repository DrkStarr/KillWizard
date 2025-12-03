
! ---------------------------------------------------------------------------- !
!       MOORS 1/2/25
!
! Down in the cellar is the wine needed to give to the drunk to get the talisman

Object  moors "Moors"
 with   description [;
          if (moorsPillar.broken) {
            print "The fog drifts back to the ";
            print "ground now that the banshees ";
            print "are gone. To the south, the ";
            print "ground gives way to a swamp, ";
            print "while another forest rises ";
            print "to the west. To the east, ";
            "the land flattens out.";
          }
          print "Fog rises off the ground ";
          print "tonight, creating an eerie ";
          print "mist that covers the moors. ";
          print "To the south, the ground ";
          print "gives way to a swamp, while ";
          print "another forest rises to the ";
          print "west. To the east, the land ";
          print "flattens out.^^Banshees ";
          print "swirl around a pillar close ";
          "to the swamp.";
        ],
        s_to [; <<Enter moorsSwamp>>; ],
        e_to [; <<Enter moorsCrossroads>>; ],
        w_to [; <<Enter moorsForest>>; ],
        out_to [; <<Enter moorsCrossroads>>; ],
        before [;
          Listen:
            if (moorsPillar.broken) "It's quiet now on the moors.";
            print "Banshees wail at the top of ";
            print "their lungs, but you hear ";
            print "nothing with the talisman ";
            "on.";
          Smell:
            print "The breeze comes off the ";
            print "swamp, smelling like ";
            print "decaying earth, as if ";
            print "someone had stirred a ";
            "mud puddle.";
        ],
        cant_go [;
          print "You can follow the road ";
          "east or west.";
        ],
  has   light;

RoomObj moorsObj "moors" moors
  with  name 'moors',
        description [;
          <<Look moors>>;
        ];

Object  moorsPillar "pillar" moors
 with   name 'pillar' 'pedestal' 'column' 'stone',
        before [;
          Attack:
            if (self.broken) {
              print "The pillar is already ";
              "in pieces.";
            }
            remove banshees;
            banshees.ghostsGone = true;
            self.broken = true;
            self.&name-->2 = 'rubble';
            give self concealed;
            print "You hit the pillar with your ";
            print "shoulder. It gives slightly, ";
            print "so you slam into it. The ";
            print "column comes crashing down";
            if (rune.pillarBroken == false) {
              move rune to moors;
              print " along with the rune";
            }
            rune.pillarBroken = true;
            print ". The ghosts around you ";
            print "scream out one last time, ";
            print "then burn up in a green ";
            "flame.";
          Climb:
            if (self.broken) {
              print "The pillar is a pile of ";
              print "rubble on the ground. ";
              "There's nothing to climb.";
            }
            print "You try climbing the pillar, ";
            print "grabbing the stone and ";
            print "pulling yourself up. But the ";
            print "rock is wet tonight with the ";
            "fog so thick. You slip off.";
          Examine:
            if (self.broken) {
              print "The pillar is a pile of ";
              "rubble on the ground.";
            }
            print "Ghosts spin around the ";
            print "pillar, screaming out, ";
            print "and trying to drive you ";
            print "away. At the top of the ";
            "pillar rests a large rune.";
          Push:
            if (self.broken) "You don't need to do that.";
            <<Attack self>>;
          Pull:
            if (self.broken) "You don't need to do that.";
            print "You can't pull it towards ";
            print "yourself, but you might be ";
            print "able to lean into it with ";
            "your shoulder.";
          Take, PushDir, Pull:
            if (self.broken) "You don't need to do that.";
            print "The pillar isn't going ";
            "anywhere.";
        ],
        broken false,
   has  static concealed supporter;

OutRch  moorsFog "fog" moors
 with   name 'fog' 'mist',
        before [;
          Examine:
            if (moorsPillar.broken) {
              print "The fog settles back ";
              "in place.";
            }
            print "The fog is thick, and swirls ";
            "around with the angry ghosts.";
        ];

OutRch  moorsSwamp "swamp" moors
 with   name 'swamp' 'marsh',
        before [;
          Examine:
            print "You can't see it, but the ";
            print "smell is strong in this ";
            "part of the moors.";
          Enter:
            print "The moors give way to a ";
            print "swamp in the south. You ";
            print "can follow the road east ";
            "or west.";
        ];

OutRch   moorsForest "forest" moors
  with   name 'forest' 'woods' 'trees',
          before [;
              Examine:
                print "The forest grows thick to ";
                "the west.";
              Enter:
                if (panther.animalGone == false) StartDaemon(forest);
                iMobTrigger = 0;
                PlayerTo(forest,2);
                rtrue;
          ];

OutRch   moorsCrossroads "crossroad" moors
  with   name 'crossroad',
          before [;
              Examine:
                print "The land to the east ";
                print "flattens out, opening ";
                "up to the crossroads.";
              Enter:
                PlayerTo(crossroad,2);
                rtrue;
          ];

OutRch   moorsMoon "moon" moors
  with   name 'moon' 'moonlight' 'sky' 'light',
          before [;
              Examine:
                print "The fog is thick on the ";
                print "moors tonight as ";
                "moonlight stabs the mist.";
              Take, Push, PushDir, Pull:
                "Don't be ridiculous.";
          ];

OutRch  moorsTower "tower"
 with   name 'dark' 'tower',
        before [;
          Examine:
            print "Over the forest to the ";
            if (self in forest) {
              print "north, a tower rises ";
              "above the trees.";
            }
            print "northwest, a tower rises ";
            "above the trees.";
          Enter:
            if (self in forest) {
              print "The tower is far to the ";
              print "north. You need to leave ";
              "the forest.";
            }
            print "The tower is too far away. ";
            "You need to head west.";
        ],
        found_in moors forest;
