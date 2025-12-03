
! ---------------------------------------------------------------------------- !
!       ARROWS 8/23/25
!
Object  arrows "cursed arrows" crossroad
  with  name 'arrow' 'arrows' 'curse' 'cursed',
        describe [;
          if (self in crossroad) rtrue;
        ],
        before [;
            Drop:
              if (bow in player) {
                print "They're priceless. You ";
                "don't want to loose them.";
              }
            Give:
              if (second == cyFiend || second == cyDemon || second == cyMephit) {
                print "The demon only smiles. You ";
                "can't reach that far.";
              }
              if (second == slumsPoor) return PPA();
              print "They're priceless. You ";
              "shouldn't give them away.";
            Shoot:
              if (self in player && bow in player) {
                if (second == nothing) {
                  print "You don't want to shoot an ";
                  print "arrow for no reason. You'd ";
                  "be wasting it.";
                }
                <<Shoot bow second>>;
              }
            Insert:
              if (second == kCabinets) {
                if (kitchen.chefDead) {
                  print "You don't need to put ";
                  "that in there.";
                }
                print "With the chef gyrating ";
                print "about, you can't get ";
                "to the cabinets.";
              }
              if (second == dbBloodPedestal) {
                print "The emerald pillar can't ";
                "contain things.";
              }
              if (second == bow) {
                print "You don't need to do that. ";
                print "You'll be ready to shoot ";
                "when the time comes.";
              }
              if (second == dbChasm) {
                print "That would be consumed ";
                "by the void.";
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
                print "You drop the arrows into ";
                print "the cauldron, breaking the ";
                print "necromancer's spell.^^";
                print "~Damn barbarian,~ ";
                "curses the wizard.";
              }
              print "The arrows are useful, but ";
              "not in that way.";
            Examine:
              print "These are cursed arrows. ";
              print "The same used by ";
              print "mercenaries from Zamora";
              if (bow.examineBow) ".";
              bow.examineBow = true;
              print ". Someone paid a lot of ";
              print "money to have Darron ";
              "killed.";
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
        ],
   has  pluralname;
