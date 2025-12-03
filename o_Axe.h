
! ---------------------------------------------------------------------------- !
!       AXE 12/31/24
!
Object  axe "axe" backyard
  with  name 'axe' 'ax' 'rust',
        short_name [;
            print "an ";
        ],
        describe [;
          if (self in courtyard) rtrue;
        ],
        before [;
            Drop:
              if (wolf.animalDead) {
                print "The axe saved your life ";
                print "once. You don't want to ";
                "lose it.";
              }
              if (player in oldForest && wolf in oldForest) "That could end poorly.";
              print "How else are you going to ";
              "chop down the wood?";
            Give:
              if (second == cyFiend || second == cyDemon || second == cyMephit) {
                print "The demon only smiles. You ";
                "can't reach that far.";
              }
              if (second == slumsPoor) return PPA();
              if (second == darron) {
                print "Your companion isn't even ";
                print "conscious. He's not going ";
                "to take that.";
              }
              if (wolf.animalDead) {
                print "The axe saved your life ";
                print "once. You don't want to ";
                "lose it.";
              }
              if (second == osric) {
                if (firewood.onFire) return AfterTheFire();
                print "~Keep it. You're going to ";
                print "need it to chop down the ";
                "wood.~";
              }
              if (player in oldForest && wolf in oldForest) {
                print "You would die without ";
                "a weapon.";
              }
              print "How else are you going to ";
              "chop down the wood?";
            Show:
              if (second == slumsPoor) return PPA();
              if (second == darron) {
                print "Your companion isn't even ";
                print "conscious. He's not going ";
                "to take that.";
              }
              if (second == osric) {
                if (firewood.onFire) return AfterTheFire();
                if (wolf.animalDead) {
                  print "~Go ahead and keep it. ";
                  print "It's rusted anyway. I'm ";
                  "getting a new one.~";
                }
                print "~Keep it. You're going to ";
                print "need it to chop down the ";
                "wood.~";
              }
            ThrowAt:
              if (second == wizard || second == nlDemon || second == rune) "Your aim is not that good.";
              if (bow in player) {
                print "If you want to hit something ";
                "at a distance, try the bow.";
              }
              if (second == crow || second == drunk) "Your aim is not that good.";
              if (wolf.animalDead) {
                print "The axe saved your life ";
                print "once. You don't want to ";
                "lose it.";
              }
              if (second == wolf) {
                print "If you miss, it would ";
                "end poorly.";
              }
              print "You don't want to throw it. ";
              print "How else are you going to ";
              "chop down the wood?";
            Insert:
              if (second == kCabinets) {
                if (kitchen.chefDead) {
                  print "You don't need to put that ";
                  "in there.";
                }
                print "With the chef gyrating ";
                print "about, you can't get ";
                "to the cabinets.";
              }
              if (second == dbChasm) {
                print "That would be consumed by ";
                "the void.";
              }
              if (second == dbBloodPedestal) {
                print "The emerald pillar can't ";
                "contain things.";
              }
              if (second == sdFirepit && firewood.onFire) {
                print "There's no need to burn it. ";
                "It saved your life once.";
              }
              if (second == nlCauldron) {
                print "How else are you going to ";
                "kill the wizard?";
              }
              if (wolf.animalDead) {
                print "The axe saved your life ";
                print "once. You don't want to ";
                "lose it.";
              }
              print "The axe is useful, but not ";
              "in that way.";
            Examine:
              print "It's a short-hand axe that's ";
              print "rusted from exposure to the ";
              "elements.";
            PutOn:
              if (second == moorsPillar) {
                print "You can't put things on top ";
                "of that.";
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
        ],
  has   proper;
