
! ---------------------------------------------------------------------------- !
!       FLINT 12/31/24
!

Object  flint "flint"
  with  name 'flint' 'chip' 'chipped',
        short_name [;
            print "some ";
        ],
        before [;
          Attack:
            if (firewood.onFire) {
              print "Instead, you conserve ";
              "the flint.";
            }
            firewood.onFire = true;
            remove sdAsh;
            move sdArrows to scavengersDen;
            move darron to scavengersDen;
            move scroll to scavengersDen;
            move sdFrontDoor to scavengersDen;
            print "You strike the flint with ";
            print "the back end of the axe. ";
            print "Sparks go flying, so you ";
            print "do it one more time. The ";
            print "kindling catches, and a ";
            print "small flame begins to grow ";
            print "as you blow on it.^";
            print "^You watch flames leap up. ";
            print "The fire takes off, and ";
            print "Osric sits down at your ";
            print "side. ~You know it has ";
            print "been a long time, Cimm...~^";
            print "^-^^With a crack of ";
            print "thunder, the front door ";
            print "gives. A body comes crashing ";
            print "through. Darron hits the ";
            print "ground with an arrow ";
            print "protruding from his chest. ";
            print "He clings to a scroll, ";
            print "as he bleeds out in front ";
            print "of the entrance. Osric ";
            print "stands in shock, his jaw ";
            print "wide open. The strangers ";
            print "back up. As you rise, you ";
            print "can't believe what your ";
            "eyes see.";
          Examine:
            print "It's a small rock that will ";
            print "spark when struck against ";
            "the axe.";
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
              print "That would be consumed ";
              "by the void.";
            }
            if (second == dbBloodPedestal) {
              print "The emerald pillar can't ";
              "contain things.";
            }
            if (second == sdFirepit) {
              if (firewood.onFire) {
                give self ~visited;
                remove self;
                print "You throw the flint into ";
                print "the pit. It bounces once, ";
                print "and then it's lost in the ";
                "fire.";
              }
              "It doesn't belong in there.";
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
              print "You drop the flint into ";
              print "the cauldron, breaking the ";
              print "necromancer's spell.^^";
              print "~Damn barbarian,~ ";
              "curses the wizard.";
            }
            print "The flint is useful, but ";
            "not in that way.";
          PutOn:
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
          Give:
            if (second == cyFiend || second == cyDemon || second == cyMephit) {
              print "The demon only smiles. You ";
              "can't reach that far.";
            }
            if (second == osric) {
              if (firewood.onFire) return AfterTheFire();
              print "~Keep it. Consider it a ";
              "souvenir from the Den.~";
            }
            if (second == darron) {
              print "Your companion isn't even ";
              print "conscious. He's not going ";
              "to take that.";
            }
            if (second == drunk) return GiveDrunk();
            if (second == slumsPoor) return PPA();
            print "You need to give the flint ";
            "to someone.";
          Show:
            if (second == cyFiend || second == cyDemon || second == cyMephit) "The demon only smiles.";
            if (second == osric) {
              if (firewood.onFire) return AfterTheFire();
              print "~Keep it. Consider it a ";
              "souvenir from the Den.~";
            }
            if (second == darron) {
              print "Your companion isn't even ";
              print "conscious. He isn't going ";
              "to see it.";
            }
          ThrowAt:
            if (second == banshees) {
              print "They are nothing more ";
              "than mist.";
            }
            print "It doesn't have enough force ";
            "to do any damage.";
        ],
  has   proper;
