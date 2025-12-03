
! ---------------------------------------------------------------------------- !
!       WIZARD 1/11/25
!

Object  wizard "necromancer" necrosLair
  with  name 'belkor' 'necro' 'wizard' 'necromancer',
        before [;
          Attack, Cut:
            deadflag = 2;
            score++;
            wizard.mobDead = true;
            print "You lunge at the wizard ";
            print "with the axe in hand. He ";
            print "fires off a lightning bolt ";
            print "but misses as you catch ";
            print "him in the side with the ";
            print "weapon. Belkor cries out ";
            print "as you hit him again, this ";
            print "time in the heart, ";
            print "ensuring the deed is done.^";
            return WizardsEnd();
          Examine:
            print "The wizard smiles at you ";
            print "with hands that glow, ";
            "ready to strike.";
          Burn, Climb, Push, PushDir, Pull, Take:
            deadflag=1;
            print "You try to make it around ";
            print "the cauldron, but the ";
            print "wizard shoots a surge of ";
            print "electricity out of his ";
            print "hands, striking you in ";
            print "the chest and throwing ";
            print "you back against the wall. ";
            print "Dazed, you try to get back ";
            print "on your feet, but a second ";
            print "bolt hits you, ";
            print "electrocuting you ";
            "on the spot.";
          ThrowAt:
            print "The wizard just laughs ";
            "at you.";
        ],
        life [ w1;
          Ask:
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'scroll', 'stuff':
                if (scroll.showNecro) {
                  print "The wizard just laughs ";
                  "at you.";
                }
                scroll.showNecro = true;
                iNecroAttack--;
                print "He hesitats for a moment, ";
                print "so you show him the ";
                print "scroll.^^The wizard gets ";
                print "a quick look at it, seeing ";
                print "his name at the bottom. ";
                print "~That's not my handwriting ";
                "barbarian. Prepare to die.~";
            }
            print "The wizard just laughs ";
            "at you.";
        ],
        orders [;
          print "The wizard just laughs ";
          "at you.";
        ],
        mobDead false,
   has  animate concealed;

 [ WizardsEnd;
     print "^After finding your way out ";
     print "of the tower, you head ";
     print "straight back to the ";
     print "Scavenger's Den. Upon ";
     print "your arrival, Osric informs ";
     print "you that Darron has passed ";
     print "away. You share the details ";
     print "of how you eliminated the ";
     print "necromancer. Osric smiles ";
     print "slyly to himself and buys ";
     print "you a round, thanking you ";
     print "for killing the wizard. ";
     print "Belkor no longer has any ";
     "influence over Khalir.";
 ];
