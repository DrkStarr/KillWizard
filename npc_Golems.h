
! ---------------------------------------------------------------------------- !
!       GOLEMS 1/11/25
!
Object  golems "golems" stairway
  with  name 'golem' 'golems' 'monsters' 'mobs',
        describe [;
          rtrue;
        ],
        daemon [;
          iGolemMovement++;
          if (iGolemMovement == 1) {
            print "^Feeling your presence, the ";
            print "two golems before you wake ";
            print "up. They are guardians for ";
            "the wizard.";
          }
          if (iGolemMovement == 2 && player in stairway) {
            print "^The golems lumber around a ";
            print "bit, slowly closing in on ";
            "you.";
          }
          if (iGolemMovement == 3) {
            if (player in stairway) return DeathByGolem();
            else {
              move self to grandCorridor;
              if (player in grandCorridor) {
                print "^Thundering up the corridor ";
                print "the golems step out of the ";
                "darkness, pursuing you.";
              }
            }
          }
          if (iGolemMovement == 4 && player in grandCorridor) {
            print "^The golems shift around ";
            print "once more, closing in on ";
            "you.";
          }
          if (iGolemMovement == 5 && player in grandCorridor) return DeathByGolem();
        ],
		    before [;
          Attack, Cut:
            if (self.mobDead) {
              print "But there's only a pile ";
              "of dust.";
            }
            deadflag = 1;
            print "You step forward, swinging ";
            print "at one of the golems. You ";
            print "connect with the axe, but ";
            print "nothing happens to the ";
            print "stone. The other golem slams ";
            print "into you a moment later, ";
            print "crushing you between the ";
            "two.";
			    Examine:
            if (self.mobDead) {
              print "The golems now are nothing ";
              "more than a pile of dust.";
            }
            print "Made from stone, the golems ";
            print "have been animated by ";
            print "Belkor to protect his ";
            "inner lair.";
          Burn, Climb, Close, Open, Push, PushDir, Pull, Take, ThrowAt:
            if (self.mobDead) {
              print "But there's only a pile of ";
              "dust.";
            }
            deadflag = 1;
            print "Stepping towards one of the ";
            print "golems, he doesn't ";
            print "hesitate. ";
            print " Grabbing you with ";
            print "both arms, he pulls you in, ";
            print "while the other slams into ";
            print "him, crushing you between ";
            "the two.";
          Ask, AskFor, AskFor2nd, Talk:
            if (self.mobDead) {
              print "But there's only a pile ";
              "of dust.";
            }
            print "Although they are animated, ";
            "they will not talk.";
        ],
        life [;
          if (self.mobDead) {
            print "But there's only a pile ";
            "of dust.";
          }
          print "You don't want to get that ";
          print "close. The golem will ";
          "strike.";
        ],
        orders [;
          if (self.mobDead) {
            print "But there's only a pile ";
            "of dust.";
          }
          print "They're not going to listen ";
          print "to you. They only listen to ";
          "Belkor.";
        ],
        mobDead false,
        startedMovement false,
  has   animate pluralname;

[ DeathByGolem;
    deadflag = 1;
    print "^Standing there, the golems ";
    print "don't hesitate. One ";
    print "grabs you with both ";
    print "arms, pulling you in, while ";
    print "the other slams into him, ";
    print "crushing you between the ";
    "two.";
];
