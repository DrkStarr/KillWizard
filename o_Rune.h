
! ---------------------------------------------------------------------------- !
!       RUNE 1/2/25
!
Object  rune "rune" moorsPillar
 with   name 'rune' 'artifact',
        describe [;
          if (dbDrawbridge.drawbridgeOpen) rtrue;
          if (self.pillarBroken == false) rtrue;
          if (self in moors) "^A rune lies on the ground.";
        ],
        before [;
          Examine:
            if (dbDrawbridge.drawbridgeOpen) {
              print "Embedded into the pillar, ";
              print "the 'M' pulses with new ";
              print "life as reds and yellows ";
              "flash through it.";
            }
            if (self.pillarBroken) {
              print "The rune glows as if it ";
              print "has a life of its own. ";
              print "It's a Germanic version ";
              "of an 'M.'";
            }
            print "The rune rests on the pillar ";
            print "as banshees swirl around, ";
            "screaming out in anger.";
          Insert, PutOn, Touch:
            if (self in player) {
              if (second == dbChasm) {
                print "That would be consumed ";
                "by the void.";
              }
              if (second == moorsPillar) {
                print "There's nothing left ";
                "but rubble.";
              }
              if (second == dbBlackPedestal) {
                print "Nothing happens when you ";
                print "touch that to the ";
                "obsidian pillar.";
              }
              if (second == dbBloodPedestal) {
                  if (dbDrawbridge.drawbridgeOpen) {
                    print "The rune is already fused ";
                    print "into the pillar, and the ";
                    print "drawbridge ";
                    "is down.";
                  }
                  dbDrawbridge.drawbridgeOpen = true;
                  move rune to dbBloodPedestal;
                  score++;
                  print "The moment the rune touches ";
                  print "the pillar, the green stone ";
                  print "comes to life, as red ";
                  print "and yellow colors pulsate ";
                  print "up and down. The bridge ";
                  print "creaks as the rune is ";
                  print "pulled into the stone, ";
                  print "fusing the two as ";
                  print "malleable rock ";
                  print "solidifies. Dropping ";
                  print "down a foot, the bridge ";
                  print "shakes for a moment before ";
                  print "slowly lowering itself to ";
                  "the ground.";
              }
            }
          Take, Push, PushDir, Pull:
            if (dbDrawbridge.drawbridgeOpen) {
              print "It's fused into the pillar ";
              "and isn't going anywhere.";
            }
            if (self.pillarBroken == false) {
              print "You can't reach it, it's ";
              "on the top of the pillar.";
            }
          Shoot:
            if (moorsPillar.broken) return PWA();
            if (bow.shootAtRuin) {
              print "You don't want to waste ";
              "another arrow.";
            }
            bow.shootAtRuin = true;
            print "Taking careful aim, you ";
            print "shoot an arrow at the ";
            print "rune. You nail the ";
            print "stone, but the arrow ";
            print "goes flying off. That's ";
            print "not going to knock it ";
            "down.";
          Give:
            if (second == slumsPoor) return PPA();
            print "You need to give the ";
            "rune to someone.";
        ],
        pillarBroken false;
