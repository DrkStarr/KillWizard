
! ---------------------------------------------------------------------------- !
!       POUCH 11/7/25
!
Object  pouch "pouch"
  with  name 'coin' 'coins' 'pouch' 'gold',
        before [;
          Give:
            if (second == drunk) {
              drunk.talkedTo = false;
              if (iDrunkResponse==0) iDrunkResponse=1;
              print "~No. Nothing like that. ";
              print "Some wine. You know, ";
              "from the farm.~";
            }
            if (second == slumsPoor) {
              give self ~visited;
              remove self;
              print "The poor take the pouch, ";
              print "as it vanishes amongst ";
              print "their rags instantly. ";
              print "They smile. Then hold ";
              "out their hands again.";
            }
            if (second == wizard) {
              if (self.wizGive) {
                print "The wizard just laughs ";
                "at you.";
              }
              self.wizGive = true;
              print "~You break into my home and ";
              print "try to pay me off? Prepare ";
              "to die.~";
            }
            print "You don't want to do that. ";
            print "This is blood money - paid ";
            "with your friends life.";
          Show:
            if (second == drunk) {
              drunk.talkedTo = false;
              if (iDrunkResponse==0) iDrunkResponse=1;
              print "~No. Nothing like that. Some ";
              print "wine. You know, from the old ";
              "farm.~";
            }
            if (second == slumsPoor) {
              print "The poor watch you with ";
              "detest in their eyes.";
            }
            if (second == wizard) {
              if (self.wizGive) {
                print "The wizard just laughs ";
                "at you.";
              }
              self.wizGive = true;
              print "~You break into my home and ";
              print "try to pay me off? Prepare ";
              "to die.~";
            }
          Drop, Open:
            print "You don't want to do that. ";
            print "This is blood money - paid ";
            "with your friends life.";
          Close:
            "The pouch is already closed.";
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
                print "You drop the pouch into ";
                print "the cauldron, breaking the ";
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
              print "touch that to the ";
              "obsidian pillar.";
            }
            if (second == dbBloodPedestal) {
              print "Nothing happens when you ";
              print "touch that to the ";
              "emerald pillar.";
            }
          ThrowAt:
            if (second == banshees) {
              print "They are nothing more ";
              "than mist.";
            }
            if (second == rune && rune in moorsPillar) {
                print "It's heavy, but not that ";
                print "heavy. It's not going to ";
                "knock that off the pillar.";
            }
            if (second == slumsPoor) {
              give self ~visited;
              remove self;
              print "You toss the pouch to ";
              print "the poor as it ";
              print "vanishes amongst ";
              print "their rags instantly. ";
              print "They smile. Then hold ";
              "out their hands again.";
            }
            if (second == drunk) {
              print "You have no reason to ";
              "hurt the man.";
            }
            print "It's heavy, but not that ";
            print "heavy. It's not going to ";
            "do any real damage.";
          Examine:
            print "This must be a pouch full ";
            print "of Aquilonian coins. It's ";
            "heavy for its size.";
      ],
      wizGive false;
