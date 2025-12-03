
! ---------------------------------------------------------------------------- !
!       DRAWBRIDGE 1/3/25
!
Object  drawbridge "Drawbridge"
  with  description [;
          if (dbDrawbridge.drawbridgeOpen) {
            print "Before you lies a vast, ";
            print "gaping chasm, its edges ";
            print "shaped by water and dark ";
            print "magic. The drawbridge is ";
            print "down, allowing you to ";
            print "cross the void and enter ";
            print "the tower on the other ";
            print "side. To the south, the ";
            print "forest grows thick.^^Two ";
            print "pillars stand on this side ";
            "of the chasm.";
          }
          print "Before you lies a vast, ";
          print "gaping chasm, its edges ";
          print "shaped by water and dark ";
          print "magic. The drawbridge is ";
          print "up. To the south, the forest ";
          print "grows thick.^^Two pillars ";
          print "stand on this side of the ";
          "chasm.";
        ],
        n_to [; <<Enter dbDrawbridge>>; ],
        in_to [; <<Enter dbDrawbridge>>; ],
		    d_to [; <<Enter dbForest>>; ],
		    s_to [; <<Enter dbForest>>; ],
		    out_to [; <<Enter dbForest>>; ],
		    before [;
          Listen:
            print "Down in the forest, you ";
            print "hear creatures cry out. ";
            "But nothing up here.";
          Smell:
            print "The air is foul, as if ";
            print "death is coming up from ";
            "the chasm below.";
		    ],
        cant_go [;
          if (dbDrawbridge.drawbridgeOpen) {
            print "You can go north into the ";
            print "tower or south, back down ";
            "to the forest.";
          }
          print "You can go south, back down ";
          "to the forest.";
        ],
        firstTime true,
  has   light;

Object  dbBloodPedestal "emerald pillar" drawbridge
  with  name 'pillars' 'emerald' 'green' 'pillar',
        before [;
          Examine:
            print "The emerald pillar stands ";
            print "on the west side of the ";
            if (dbDrawbridge.drawbridgeOpen) {
              print "ramp. A rune is fused into ";
              print "the stone. It looks like ";
              print "an 'M' is burning its way ";
              "into the rock.";
            }
            print "ramp. It is missing the ";
            print "symbol that should be ";
            print "carved into the stone, ";
            print "like the pillar on the ";
            "other side.";
          Attack, Cut:
            print "Made from thick stone, you ";
            "do no damage to the pillar.";
          Take, Push, PushDir, Pull:
            print "It's firmly planted in the ";
            print "ground and isn't going ";
            "anywhere.";
        ],
   has  scenery container open;

Object  dbBlackPedestal "obsidian pillar" drawbridge
  with  name 'pillars' 'obsidian' 'black' 'pillar',
        before [;
          Examine:
            if (dbDrawbridge.drawbridgeOpen) {
              print "The obsidian pillar stands ";
              print "on the east side of the ";
              print "ramp. A symbol is carved ";
              print "into it and seems almost ";
              print "alive as red and yellow ";
              print "streaks run through the ";
              "carved-out 'O.'";
            }
            print "Made from obsidian, the ";
            print "pillar is black as midnight ";
            print "and stands on the east side ";
            print "of the ramp. It has a ";
            print "symbol carved into the ";
            "stone.";
          Attack, Cut:
            print "Made from thick stone, you ";
            "do no damage to the pillar.";
          Take, Push, PushDir, Pull:
            print "It's firmly planted in the ";
            print "ground and isn't going ";
            "anywhere.";
        ],
   has  scenery;

Object  dbDrawbridge "drawbridge" drawbridge
  with  name 'drawbridge' 'bridge',
        before [;
          Open:
            if (self.drawbridgeOpen) "That's already down.";
            print "It's across the chasm, you ";
            "can't reach it.";
          Close:
            if (self.drawbridgeOpen) "You don't need to do that.";
            print "It's across the chasm, you ";
            "can't reach it.";
          Enter:
            if (self.drawbridgeOpen) {
              PlayerTo(gatehouse,2);
              rtrue;
            }
            print "The bridge is up, you'd ";
            "fall into the chasm.";
          Examine:
            print "The drawbridge is ";
            if (self.drawbridgeOpen) {
              print "down, thwarting dark magic ";
              print "and giving access to the ";
              "tower.";
            }
            print "up, sealing off the tower ";
            "from any intruder.";
        ],
        drawbridgeOpen false,
   has  concealed static;

Object  dbORune "symbol" drawbridge
  with  name 'symbol' 'skull' 'letter',
        before [;
          Examine:
            if (dbDrawbridge.drawbridgeOpen) {
              print "The black 'O' pulses with ";
              print "a newfound energy. ";
              print "Streaks of red and yellow ";
              "run through the black stone.";
            }
            print "The lifeless symbol ";
            print "resembles a skull. ";
            print "It's a Germanic version ";
            "of an 'O'.";
          Take, Push, PushDir, Pull:
            print "It's carved into the stone. ";
            print "Only dark, Stygian magic ";
            "can remove it.";
        ],
   has  scenery;

Object  dbRamp "ramp" drawbridge
  with  name 'ramp',
        before [;
          Examine:
            print "The ramp connects the ";
            print "drawbridge to the ground";
            if (dbDrawbridge.drawbridgeOpen) ".";
            print ", but the raised bridge ";
            print "leaves a chasm between ";
            print "you and the tower. The ";
            print "ramp is flanked on either ";
            "side by two pillars.";
        ],
   has  concealed static;

OutRch  dbForest "forest" drawbridge
 with   name 'forest' 'woods' 'trees',
        before [;
          Enter:
            print "You head back down into ";
            print "the forest.^^";
            PlayerTo(forest,2);
            rtrue;
          Examine:
            print "The forest below is dark, ";
            print "almost calm, except for ";
            print "the occasional cry of a ";
            print "wild animal. The woods are ";
            "disturbed tonight.";
        ];

OutRch  dbTower "tower" drawbridge
 with   name 'dark' 'tower',
        before [;
          Enter:
            <<Enter dbDrawbridge>>;
          Examine:
            print "A tower rises before you, ";
            print "its dark stone glinting ";
            "in the moonlight.";
        ];

OutRch  dbChasm "chasm"
 with   name 'chasm' 'abyss' 'void' 'pit',
        before [;
          Enter:
            print "That would be like falling ";
            "into an endless pit.";
          Examine:
            print "Like a black hole, the ";
            print "light from the moon is ";
            print "consumed by the chasm. ";
            print "The depths of the void ";
            "are unknown.";
        ],
        found_in drawbridge gatehouse,
  has   container open;

OutRch  dbMoon "moon"
 with   name 'moon' 'moonlight' 'sky',
        before [;
          Examine:
            print "The moon hangs above the ";
            print "forest, and although it's ";
            print "low in the sky, it provides ";
            "plenty of light.";
          Take, Push, PushDir, Pull:
            "Don't be ridiculous.";
        ],
        found_in drawbridge gatehouse;
