
! ---------------------------------------------------------------------------- !
!       SCROLL 12/31/24
!
Object  scroll "scroll"
  with  name 'scroll' 'blood' 'parchment' 'letter',
        before [;
          Examine:
            if (self.objectTaken == false) {
              print "The parchment is held ";
              print "tightly in Darron's ";
              "hands.";
            }
            if (self in player) {
              print "The scroll is stained in ";
              print "blood, you can't read it. ";
              "But it's signed, Belkor.";
            }
            print "The scroll lies on ";
            "the ground.";
          Take:
            if (self.objectTaken) rfalse;
            self.objectTaken = true;
            move self to player;
            give self ~concealed;
            print "You pry the scroll out of ";
            print "Darron's cold hand. He ";
            print "doesn't have long.^";
            print "^Looking over the scroll, ";
            print "you can't read it because ";
            print "the parchment is stained ";
            print "with blood. But it's ";
            print "signed, Belkor";
            return PrintReadScroll();
          Read:
            if (self in player) {
              print "The scroll is stained in ";
              print "blood, you can't read it. ";
              "But it's signed, Belkor.";
            }
            move self to player;
            print "(first picking up the ";
            print "scroll)^";
            if (self.objectRead ==  false) {
              print "You pry the scroll out ";
              print "of Darron's cold hand. ";
              print "He doesn't have long.^^";
            }
            self.objectTaken = true;
            give self ~concealed;
            print "The scroll is stained in ";
            print "blood, you can't read it. ";
            print "But it's signed, Belkor";
            return PrintReadScroll();
          Give:
            if (self in player) {
              if (second == wizard) {
                if (self.showNecro) {
                  print "The necromancer laughs ";
                  "at you.";
                }
                iNecroAttack--;
                self.showNecro = true;
                print "The wizard gets a quick look ";
                print "at it, seeing his name at ";
                print "the bottom, ~That's not my ";
                print "handwriting barbarian. ";
                "Prepare to die.~";
              }
              if (second == osric) {
                print "He already knows about the ";
                "necromancer.";
              }
              if (second == darron) {
                print "Your companion isn't even ";
                print "conscious. He's not going ";
                "to take that.";
              }
              if (second == cyFiend || second == cyDemon || second == cyMephit) {
                print "The demon only smiles. You ";
                "can't reach that far.";
              }
              if (second == drunk) return GiveDrunk();
              if (second == slumsPoor) return PPA();
            }
            print "You need to give the scroll ";
            "to someone.";
          Show:
            if (self in player) {
              if (second == wizard) {
                if (self.showNecro) {
                  print "The necromancer laughs ";
                  "at you.";
                }
                iNecroAttack--;
                self.showNecro = true;
                print "The wizard gets a quick ";
                print "look at it, seeing his ";
                print "name at the bottom. ~That's ";
                print "not my handwriting ";
                print "barbarian. Prepare ";
                "to die.~";
              }
              if (second == osric) <<Give self osric>>;
              if (second == darron) <<Give self darron>>;
              if (second == cyFiend || second == cyDemon || second == cyMephit) <<Give self cyFiend>>;
              if (second == drunk) return GiveDrunk();
            }
          Insert:
            if (second == kCabinets) {
              if (kitchen.chefDead) {
                print "You don't need to put that ";
                "in there.";
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
            if (second == sdFirepit) {
              if (self.objectRead ==  false) {
                print "You need to read the ";
                "scroll first.";
              }
              give self ~visited;
              remove self;
              print "You toss the scroll into ";
              print "the flame. It's consumed ";
              "a moment later.";
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
              print "You drop the scroll into ";
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
            print "It doesn't have enough ";
            "force to do any damage.";
        ],
        showNecro false,
        objectRead false,
        objectTaken false,
   has  concealed;

[ PrintReadScroll;
    if (scroll.objectRead) ".";
    osric.knowsNecro = true;
    scroll.objectRead = true;
    print ". Turning to Osric, you ask ";
    print "about the wizard.^^~Belkor ";
    print "is behind this!~ Osric ";
    print "states. ~Will his evil never ";
    print "end? First Seraina, now ";
    print "this. He lives in the dead ";
    print "tower, far to the northwest. ";
    print "He is a powerful ";
    print "necromancer. Beware! I will ";
    print "tend to your friend. It ";
    print "looks like you must ";
    "avenge 'im.~";
];
