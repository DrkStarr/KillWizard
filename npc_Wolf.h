
! ---------------------------------------------------------------------------- !
!       WOLF 12/31/24
!
Object  wolf "wolf"
  with  name 'wolf' 'animal' 'beast' 'ph201',
        describe [;
            if (self.animalDead) {
              print "^The dead wolf lies on ";
              "the ground.";
            }
            rtrue;
        ],
		    before [;
          Attack:
            if (self.animalDead) {
              print "He's already dead. ";
              "Leave him be.";
            }
            KillWolf();
            print "You swing as the wolf jumps ";
            print "at you, and your axe ";
            print "catches his skull. A heavy ";
            print "thud reverberates up your ";
            print "arm. After wiping your axe ";
            print "clean, you realize the tree ";
            "was never felled.";
          Cut:
            if (self.animalDead) {
              print "You could skin this animal, ";
              print "the hide is always worth ";
              print "something, but you ";
              print "don't have time for that ";
              print "tonight. You need to get ";
              "back before Darron arrives.";
            }
            <<Attack self>>;
			    Examine:
            if (self.animalDead) {
              print "The wolf bleeds out on the ";
              print "ground, but it was either ";
              "him or you.";
            }
            self.surpressWolf = true;
            print "The wolf is skinny as if ";
            print "it hasn't had a meal in a ";
            "long time.";
          Burn, Climb, Close, Open, Push, PushDir, Pull, Take, ThrowAt:
            if (self.animalDead) {
              print "He's already dead. ";
              "Leave him be.";
            }
            deadflag = 1;
            print "Stepping towards the wolf, ";
            print "he hesitates, then jumps at ";
            print "you, tearing out your ";
            print "throat and feeding on your ";
            "flesh.";
          Ask, AskFor, AskFor2nd, Talk:
            if (self.animalDead) {
              print "The wolf is dead. ";
              "Leave him be.";
            }
            "You're not Dr. Dolittle.";
        ],
        life [;
          if (self.animalDead) {
            print "The wolf is dead. ";
            "Leave him be.";
          }
          self.surpressWolf = true;
          print "The wolf paces back and ";
          print "forth, looking for the ";
          "right moment to strike.";
        ],
        orders [;
          if (self.animalDead) {
            print "The wolf is dead. ";
            "Leave him be.";
          }
          self.surpressWolf = true;
          print "The wolf paces back and ";
          print "forth, looking for the ";
          "right moment to strike.";
        ],
        firstTime false,
        animalDead false,
        surpressWolf false,
  has   animate;

[ KillWolf;
    score++;
    wolf.animalDead = true;
    wolf.&name-->3 = 'dead';
    give wolf scenery;
    StopDaemon(oldForest);
    iMobTrigger = 0;
    remove sdPint;
    move sdMug to scavengersDen;
    move sdRag to scavengersDen;
];
