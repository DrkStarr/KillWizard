
! ---------------------------------------------------------------------------- !
!       CHEF 1/9/25
!

Object  chef "chef" kitchen
  with  name 'chef' 'cook' 'skeleton',
        describe [;
          rtrue;
        ],
        before [;
          Attack, Burn, Cut, Push:
            if (kitchen.chefDead) {
              print "The skeleton lies on the ";
              print "ground. He's no longer ";
              "animated.";
            }
            print "You don't want to make him ";
            print "angry. He's already working ";
            "hard enough.";
          Examine:
            if (kitchen.chefDead) {
              print "The skeleton lies on top of ";
              print "broken plates that are ";
              "scattered across the floor.";
            }
            self.suppressChef = true;
            print "The chef jerks around ";
            print "frantically as he searches ";
            print "for ingredients. You get ";
            print "the feeling that he's never ";
            "going to find them.";
          Ask, AskFor, Talk:
            if (kitchen.chefDead) {
              print "If he was dead when you ";
              print "walked in, he's twice as ";
              print "gone now. You're not going ";
              print "to hold a conversation ";
              "with him.";
            }
            print "He's undead, and you're not ";
            print "going to hold a ";
            "conversation with him.";
          Take:
            if (kitchen.chefDead) "You don't need him.";
            print "You can't grab onto him. ";
            print "He's gyrating all over ";
            "the place.";
        ],
        daemon [;
          if (player in kitchen) {
            if (self.suppressChef) {
              self.suppressChef = false;
            } else {
              iChefMovement++;
              if (iChefMovement >= 2) {
                iChefMovement = 0;
                print "^The chef flails around for ";
                print "a moment, then turns back ";
                "round the other way.";
              } else {
                print "^Desperately, the chef ";
                print "searches through the ";
                print "cabinets but finds nothing, ";
                "slamming them closed.";
              }
            }
          }
        ],
        life [;
          default:
            if (kitchen.chefDead) {
              print "The skeleton lies on the ";
              print "ground. He's no longer ";
              "animated.";
            }
            self.suppressChef = true;
            print "The chef flails around ";
            print "erratically. You can't ";
            "get close.";
        ],
        orders [;
          if (kitchen.chefDead) {
            print "The skeleton has stopped ";
            print "moving and lies among a ";
            "pile of broken plates.";
          }
          "The chef pays you no mind.";
        ],
        suppressChef false,
  has   animate;
