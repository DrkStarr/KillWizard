
! ---------------------------------------------------------------------------- !
!       BOW 8/22/25
!
Object  bow "bow" crossroad
  with  name 'bow' 'ph001',
        describe [;
          if (self in courtyard) {
            print "^You can see a broken ";
            "bow here.";
          }
          if (self in crossroad) rtrue;
        ],
        before [;
            Drop:
              if (self.brokenBow) {
                print "The bow is broken. ";
                "It's useless.";
              }
              print "This makes for a great ";
              print "weapon. You don't want to ";
              "loose it.";
            Give:
              if (self.brokenBow) {
                print "The bow is broken. ";
                "It's useless.";
              }
              if (second == cyFiend || second == cyDemon || second == cyMephit) {
                print "The demon only smiles. You ";
                "can't reach that far.";
              }
              if (second == slumsPoor) return PPA();
              print "This makes for a great ";
              print "weapon. You shouldn't give ";
              "it away.";
            Shoot:
              if (self.brokenBow) {
                print "The bow is broken. ";
                "It's useless.";
              }
              if (arrows in player) {
                if (second == cyFiend) {
                  cyFiend.headGone = true;
                  remove cyDemon;
                  remove cyMephit;
                  print "Pulling the string back on ";
                  print "the bow, you shoot an arrow ";
                  print "at the fiend. The bow was ";
                  print "damaged when you fell into ";
                  print "the courtyard, and breaks ";
                  print "as the fiend tries to dodge ";
                  print "the arrow";
                  return KillDemon();
                }
                if (second == cyDemon || second == cyArchway) {
                  cyDemon.headGone = true;
                  remove cyFiend;
                  remove cyMephit;
                  print "Pulling the string back on ";
                  print "the bow, you shoot an arrow ";
                  print "at the demon. The bow was ";
                  print "damaged when you fell into ";
                  print "the courtyard, and breaks ";
                  print "as the demon cries out, ";
                  print "hearing the arrow";
                  return KillDemon();
                }
                if (second == cyMephit) {
                  cyMephit.headGone = true;
                  remove cyFiend;
                  remove cyDemon;
                  print "Pulling the string back on ";
                  print "the bow, you shoot an arrow ";
                  print "at the mephit. The bow was ";
                  print "damaged when you fell into ";
                  print "the courtyard, and breaks ";
                  print "as the mephit cries out, ";
                  print "trying to dodge the arrow";
                  return KillDemon();
                }
                if (second == cyGate) {
                  print "That's not going to open ";
                  "the gate.";
                }
                if (second == rune) {
                  if (moorsPillar.broken) return PWA();
                  if (bow.shootAtRuin) {
                    print "You don't want to waste ";
                    "another arrow.";
                  }
                  bow.shootAtRuin = true;
                  print "Taking careful aim, you ";
                  print "shoot an arrow at the ";
                  print "rune. You nail the stone, ";
                  print "but the arrow goes ";
                  print "flying off. That's not ";
                  "going to knock it down.";
                }
                if (second == moorsPillar) {
                  if (moorsPillar.broken) return PWA();
                  print "An arrow would bounce off ";
                  print "the stone. Maybe there's ";
                  "another way.";
                }
                if (second == panther) <<Shoot panther>>;
                if (second == banshees) {
                  print "They are no more than mist. ";
                  "There's nothing to shoot.";
                }
                if (second == scarecrow) <<Shoot scarecrow>>;
                if (second == crow) return KillCrow();
                if (second == drunk) <<Shoot drunk>>;
                if (player in courtyard) {
                  print "I think you wanted to say ";
                  print "'shoot something'. Please ";
                  "try again.";
                }
                if (player in moors && banshees.ghostsGone == false) {
                  print "I think you wanted to say ";
                  print "'shoot something'. Please ";
                  "try again.";
                }
                if (player in farm && crow.animalDead == false) {
                  print "I think you wanted to say ";
                  print "'shoot something'. Please ";
                  "try again.";
                }
                if (player in fields && scarecrow.mobDead == false) {
                  print "I think you wanted to say ";
                  print "'shoot someone'. Please ";
                  "try again.";

                }
                if (player in forest && panther.animalDead == false) {
                  print "I think you wanted to say ";
                  print "'shoot something'. Please ";
                  "try again.";
                }
                return PWA();
              }
              "You have no arrows to shoot.";
            Examine:
              if (self.brokenBow) {
                print "The bow broke when you fell ";
                print "into the courtyard - then ";
                print "snapped when you shot the ";
                if(cyFiend.headGone) print "fiend";
                if(cyDemon.headGone) print "demon";
                if(cyMephit.headGone) print "mephit";
                print ". Now it lies on the ";
                "ground, useless.";
              }
              print "This high-power bow boasts ";
              print "a unique design featuring a ";
              print "high-gloss finish with a ";
              print "demonic pattern carved ";
              print "into the wood. A symbol ";
              print "used by the mercenaries ";
              print "of Zamora";
              if (self.examineBow) ".";
              self.examineBow = true;
              print ". Someone paid a lot of ";
              print "money to have Darron ";
              "killed.";
            Insert, PutOn:
              if (self.brokenBow) {
                print "The bow is broken. ";
                "It's useless.";
              }
              if (second == moorsPillar) {
                print "You can't put things on ";
                "top of that.";
              }
              if (second == dbBlackPedestal) {
                print "Nothing happens when you ";
                print "touch that to the ";
                "obsidian pillar.";
              }
              if (second == dbBloodPedestal) {
                print "Nothing happens when you ";
                print "touch that to the ";
                "emerald pillar.";
              }
              if (second == dbChasm) {
                print "That would be consumed by ";
                "the void.";
              }
              print "The bow is useful, but not ";
              "in that way.";
            default:
              if (self.brokenBow) {
                print "The bow is broken. ";
                "It's useless.";
              }
        ],
        examineBow false,
        brokenBow false,
        shootAtRuin false;

[ KillDemon;
    score++;
    remove cyDemons;
    bow.brokenBow = true;
    bow.&name-->1 = 'broken';
    move bow to courtyard;
    cyGate.gateOpen = true;
    StopDaemon(courtyard);
    print ". You nail him, pinning him ";
    print "to the wall. Unfortunately, ";
    print "the bow is now useless.^";
    print "^The gate opens as the two ";
    "other demons fly through it.";
];
