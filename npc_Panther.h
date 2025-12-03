
! ---------------------------------------------------------------------------- !
!       PANTHER 8/22/25 - BEAR 1/3/25
!
Object  panther "panther" forest
  with  name 'black' 'panther' 'animal' 'cat',
        describe [;
            if (self.animalDead) {
              print "^The dead panther lies on ";
              "the ground.";
            }
            if (self.firstTime) {
              self.firstTime = false;
              self.surpressPanther = true;
              print "^A sleek black panther ";
              print "emerges between the trees, ";
              print "its yellow eyes fixed ";
              "on you.";
            }
            self.surpressPanther = true;
            print "^The panther stares you ";
            print "down, waiting for the ";
            "right moment to attack.";
        ],
		    before [;
          Attack, Cut:
            if (self.animalDead) {
              print "She's already dead. ";
              "Leave her be.";
            }
            score++;
            self.animalDead = true;
            StopDaemon(forest);
            print "You charge the panther, ";
            print "swinging your axe with all ";
            print "you've got. It cuts into ";
            print "her neck, a lucky blow, and ";
            print "she roars before dropping ";
            print "to the ground, bleeding out ";
            print "before you. The way north ";
            "is now open.";
          Shoot:
            if (self.animalDead == false) {
              if (self.shootAt) {
                print "You missed her the first ";
                print "time. You'd only fail at ";
                "a second attempt.";
              }
              self.shootAt = true;
              self.surpressPanther = true;
              print "You let an arrow loose, but ";
              print "the panther jumps out of ";
              print "the way. Growling, she ";
              "repositions herself.";
            }
            return PAD();
			    Examine:
            if (self.animalDead) {
              print "You think it was either ";
              print "your survival or hers. ";
              print "There couldn't be another ";
              print "way around. At least ";
              print "that's what you tell ";
              "yourself.";
            }
            self.surpressPanther = true;
            print "The panther is larger than ";
            print "you, angry, and about to ";
            "pounce.";
          Burn, Climb, Close, Open, Push, PushDir, Pull, Take, ThrowAt:
            if (self.animalDead) "She's dead. Leave her be.";
            deadflag = 1;
            print "Stepping towards the ";
            print "panther, she doesn't ";
            print "hesitate, swiping at you ";
            print "and then plunging her ";
            print "teeth into your flesh. ";
            print "You cry out, but no one ";
            "is going to save you.";
          Ask, AskFor, AskFor2nd, Talk:
            if (self.animalDead) {
              print "The panther is dead. ";
              "Leave her be.";
            }
            "You're not Dr. Dolittle.";
        ],
        life [;
          if (self.animalDead) {
            print "The panther is dead. ";
            "Leave her be.";
          }
          self.surpressPanther = true;
          print "The panther stares you ";
          print "down, waiting for the ";
          "right moment to attack.";
        ],
        orders [;
          if (self.animalDead) {
            print "The panther is dead. ";
            "Leave her be.";
          }
          self.surpressPanther = true;
          print "The panther stares you ";
          print "down, waiting for the ";
          "right moment to attack.";
        ],
        shootAt false,
        firstTime true,
        animalDead false,
        animalGone false,
        surpressPanther false,
  has   animate female;
