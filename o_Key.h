
! ---------------------------------------------------------------------------- !
!       KEY 1/2/25
!

Object  key "key" farm
  with  name 'key' 'rusty' 'dirty' 'iron',
        describe [;
            if (crow.animalDead == false) rtrue;
        ],
        before [;
          Examine:
            if (self in farm) {
              if (crow.animalDead) {
                print "The key fell when you killed ";
                print "the crow. It lies on the ";
                "ground.";
              }
              crow.seenKey = true;
              print "The key looks like it's ";
              print "stuck in the bird's ";
              "talon. It's out of reach.";
            }
            print "The key is rusty, forged ";
            print "from iron, and covered ";
            "in a bit of dirt.";
          Insert:
            if (second == kCabinets) {
              if (kitchen.chefDead) {
                print "You don't need to put ";
                "that in there.";
              }
              print "With the chef gyrating ";
              print "about, you can't get to ";
              "the cabinets.";
            }
            if (second == dbChasm) {
              print "That would be consumed by ";
              "the void.";
            }
            if (second == dbBloodPedestal) {
              print "The emerald pillar can't ";
              "contain things.";
            }
            if (second == nlCauldron) {
              if (nlCauldron.itemIn) {
                print "You have already broken ";
                "the spell.";
              }
              if (nlCauldron.objectPushed) {
                print "You spilled the cauldron ";
                print "already. The spell is ";
                "broken.";
              }
              give self ~visited;
              remove self;
              nlCauldron.itemIn = true;
              print "You drop the key into the ";
              print "cauldron, breaking the ";
              print "necromancer's spell.^^";
              print "~Damn barbarian,~ ";
              "curses the wizard.";
            }
          PutOn:
            if (second == moorsPillar) {
              print "You can't put things on ";
              "top of that.";
            }
            if (second == dbBlackPedestal) {
              print "Nothing happens when you ";
              print "touch that to the obsidian ";
              "pillar.";
            }
            if (second == dbBloodPedestal) {
              print "Nothing happens when you ";
              print "touch that to the emerald ";
              "pillar.";
            }
          Give:
            if (second == cyFiend || second == cyDemon || second == cyMephit) {
              print "The demon only smiles. You ";
              "can't reach that far.";
            }
            if (second == drunk) return GiveDrunk();
            if (second == slumsPoor) return PPA();
            print "You need to give the key ";
            "to someone.";
          Take:
            if (crow.animalDead == false) {
              print "The bird holds the key up ";
              print "in the tree. It's out of ";
              "reach.";
            }
          ThrowAt:
            if (second == banshees) {
              print "They are nothing more ";
              "than mist.";
            }
            print "It doesn't have enough force ";
            "to do any damage.";
        ];
