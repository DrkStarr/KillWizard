
! ---------------------------------------------------------------------------- !
!       CROW 1/2/25
!

Object  crow "crow" farm
  with  name 'crow' 'carrion' 'bird' 'talon',
        before [;
          Attack, Cut:
            print "He's up in the tree. You ";
            "can't reach him from here.";
          Examine:
            self.seenKey = true;
            print "The crow sits in the tree, ";
            print "laughing at you with a ";
            print "primitive caw. For some ";
            print "reason, the bird holds a ";
            "key in its talon.";
          Burn, Climb, Close, Insert, Open, Push, PushDir, Pull, Take:
            print "The bird is up in the tree. ";
            "You can't reach him.";
          Shoot:
            if (bow in player) {
              if (arrows in player) {
                if (self.animalDead == false) return KillCrow();
                return PAD();
              }
              print "How are you going to hit ";
              print "him. You don't have any ";
              "arrows.";
            }
            print "What are you going to shoot ";
            print "him with? You don't have a ";
            "bow.";
          Take:
            print "He's up in the tree. You ";
            "can't reach him from here.";
          default:
            "The bird just laughs at you.";
        ],
        life [;
          default:
            "The bird just laughs at you.";
        ],
        orders [;
          "The bird just laughs at you.";
        ],
        away false,
        seenKey false,
        animalDead false,
   has  animate concealed;

Object  deadCrow "dead crow"
  with  name 'crow' 'carrion' 'bird' 'dead',
        before [;
          Examine:
            print "The crow is dead. He's ";
            print "nothing more than scrap ";
            "meat at this point.";
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
              remove self;
              nlCauldron.itemIn = true;
              print "You drop the dead crow into ";
              print "the cauldron, breaking the ";
              print "necromancer's spell.^^";
              print "~Damn barbarian,~ ";
              "curses the wizard.";
            }
          Give:
            if (second == panther) return GiveCrow();
            if (second == banshees) {
              print "Who knows who you should ";
              print "give it to? But it's not ";
              "going to be them.";
            }
            if (second == crossroadArcher) {
              print "Who knows who you should ";
              print "give it to? But it's not ";
              "going to be him.";
            }
            if (second == drunk) {
              print "~Ew. No. Why are you even ";
              "carrying that?~";
            }
            print "Who knows who you should ";
            print "give it to? But it's not ";
            "going to be that.";
          ThrowAt:
            if (second == panther) return GiveCrow();
          Drop:
            if (player in forest && panther.animalGone == false) return GiveCrow();
            rfalse;
          Take:
            if (self in player) "You already have him.";
            move self to player;
            "Taken.";
          default:
            return PAD();
        ],
        life [;
          default:
            return PAD();
        ],
        orders [;
          return PAD();
        ],
   has  animate;

[ KillCrow;
    score++;
    remove crow;
    move deadCrow to farm;
    move key to farm;
    StopDaemon(farm);
    StopDaemon(farmTree);
    crow.away = false;
    crow.animalDead = true;
    print "Pulling back on the bow, ";
    print "you let the arrow fly, ";
    print "watching it strike the bird ";
    print "in his chest. The crow caws ";
    print "one last time before he ";
    print "hits the ground, releasing ";
    "the key.";
];

[ GiveCrow;
    score++;
    give deadCrow ~visited;
    remove deadCrow;
    remove panther;
    StopDaemon(forest);
    panther.animalGone = true;
    print "Dropping the crow to the ";
    print "ground, the panther watches ";
    print "you while sniffing it. ";
    print "Grabbing it between her ";
    print "teeth, she almost nods ";
    print "before darting back into ";
    print "the forest. The way north ";
    "is now open.";
];
