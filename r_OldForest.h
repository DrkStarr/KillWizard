
! ---------------------------------------------------------------------------- !
!       OLD FOREST 12/31/24
!
Object  oldForest "Old Forest"
  with  description [;
          print "The forest is thick, full of ";
          print "trees, and an earthy smell ";
          print "that makes its way in from ";
          print "the swamp";
          if (wolf.animalDead == false) {
            print ". Shadows dart past the ";
            print "corner of your eyes";
          }
          print ". The tavern sits on an ";
          print "incline to the north";
          if (wolf.animalDead) {
            print ".^^The thin wolf lies on ";
            "the ground, dead.";
          }
          ".";
        ],
        daemon [;
          if (wolf in self && wolf.animalDead == false) {
            if (wolf.surpressWolf) {
              wolf.surpressWolf = false;
            } else {
              iMobTrigger++;
              switch (iMobTrigger) {
                2: if (wolf.firstTime) {
                     print "^The wolf paces back and ";
                     print "forth, looking for the ";
                     "right moment to attack.";
                   }
                   wolf.firstTime = true;
                   print "^A wolf paces back and ";
                   print "forth, looking for the ";
                   "right moment to attack.";

                3: iMobTrigger = 1;
                   if (wolf.firstTime) {
                     print "^The wolf stands before ";
                     "you, mouth open, salivating.";
                   }
                   wolf.firstTime = true;
                   print "^A wolf stands before ";
                   "you, mouth open, salivating.";
              }
            }
          }
        ],
		    n_to [; <<Enter oldForestTavern>>; ],
        u_to [; <<Enter oldForestTavern>>; ],
        out_to [; <<Enter oldForestTavern>>; ],
		    before [;
          Listen:
            if (wolf.animalDead) {
              print "It's quiet. ";
              print "Not far now, you ";
              print "hear thunder roll over ";
              "the hills.";
            }
            if (wolf in self) {
              wolf.surpressWolf = true;
              print "The wolf growls at you, ";
              "looking for his next meal.";
            }
            print "A rustling can be heard ";
            print "behind you - always ";
            "behind you.";
          Smell:
            print "The air smells like decaying ";
            print "earth, as if someone had ";
            "stirred a mud puddle.";
		    ],
        cant_go [;
          if (firewood.beenCut) {
            print "Do you want to get eaten by ";
            print "wolves? Don't go straying ";
            "off.";
          }
          print "You need to find firewood. ";
          "Don't go straying off.";
        ],
  has   light;

RoomObj oldForestObj "forest" oldForest
  with  name 'old' 'forest' 'woods',
        description [;
          <<Look oldForest>>;
        ];

Object  oldForestTree "tree" oldForest
  with  name 'tree' 'dead' 'maple' 'wood',
        before [;
          Attack, Cut:
            if (firewood in player) {
              print "You've already gathered the ";
              print "firewood and need to bring ";
              "it back to the tavern.";
            }
            if (axe in player) {
              if (wolf.animalDead) {
                move firewood to player;
                self.&name-->3 = 'ph001';
                firewood.beenCut = true;
                print "You cut into the dead wood ";
                print "once more. This time, the ";
                print "tree falls, and you're able ";
                print "to collect wood without any ";
                print "incident. In the ";
                print "distance, the storm grows ";
                "louder.";
              }
              if (wolf in oldForest) {
                deadflag = 1;
                print "You ignore the wolf, trying ";
                print "to cut into the wood again. ";
                print "As you swing the axe and ";
                print "strike the tree a second ";
                print "time, the wolf jumps at you, ";
                print "tearing out your throat ";
                "and feeding on your flesh.";
              }
              move wolf to oldForest;
              self.beenCut = true;
              StartDaemon(oldForest);
              print "You find a dead tree and ";
              print "swing your axe. It cuts deep ";
              print "into the wood with a solid ";
              print "crack. And then something ";
              print "jumps at you. Quickly, you ";
              print "dodge.^^Landing on his feet, ";
              print "a thin wolf stands in front ";
              "of you.";
            }
            print "You can't cut into the wood ";
            "with your bare hands.";
          Examine:
            print "Surrounded by twisted ";
            print "maples, you notice that some ";
            print "of them are dead, making for ";
            print "excellent firewood";
            if (firewood.beenCut) ".";
            if (self.beenCut) {
              print ". You've already cut into ";
              print "one, but you must complete ";
              "the task.";
            }
            ".";
          Push:
            if (firewood in player) {
              print "You have all the firewood ";
              "you need.";
            }
            if (wolf in oldForest && wolf.animalDead == false) "The wolf blocks your way.";
            if (self.beenCut) {
              print "Though the tree has been ";
              print "cut, it is still firmly ";
              print "rooted in the dirt, and ";
              print "even you can't push it ";
              "over.";
            }
            print "The maple tree is rooted in ";
            print "the dirt, and even you ";
            "can't push it over.";
          Take, Pull:
            if (firewood.beenCut) {
              print "You have all the firewood ";
              "you need.";
            }
            if (wolf in oldForest && wolf.animalDead == false) "The wolf blocks your way.";
            if (self.beenCut) {
              print "Though the tree has been ";
              print "cut, it remains rooted in ";
              print "the dirt, and even you can't ";
              print "pull it out of the ground. ";
              "The job's not done.";
            }
            print "The maple tree is rooted ";
            print "in the dirt, and even you ";
            print "can't pull it out of the ";
            "ground.";
          Climb:
            print "Even though you are big, ";
            print "you are agile enough to ";
            print "climb the tree. But ";
            if (wolf in oldForest && wolf.animalDead == false) {
              print "that's not the way to deal ";
              "with the wolf.";
            }
            print "you would achieve nothing ";
            "by this.";
          ],
          beenCut false,
    has   scenery static;

Object  oldForestTrees "trees" oldForest
  with  name 'twisted' 'trees' 'maples',
        before [;
          Attack, Cut:
            <<Cut oldForestTree>>;
          Examine:
            <<Examine oldForestTree>>;
          Push:
            <<Push oldForestTree>>;
          Take, Pull:
            <<Take oldForestTree>>;
          Climb:
            print "Even though you are big, ";
            print "you are agile enough to ";
            print "climb the trees. But you ";
            print "would achieve nothing by ";
            "this.";
          ],
    has   concealed static pluralname;

OutRch    oldForestTavern "tavern" oldForest
   with   name 'small' 'tavern' 'inn' 'hill',
          before [;
            Enter:
              if (wolf in oldForest && wolf.animalDead==false) {
                  deadflag = 1;
                  print "Trying to get away, the wolf ";
                  print "jumps you, tearing out your ";
                  print "throat and feeding on your ";
                  "flesh.";
              }
              print "You walk up the hill to ";
              print "the tavern.^^";
              PlayerTo(backyard,2);
              rtrue;
            Examine:
              "The small tavern is up the hill.";
          ],
    has   concealed static;

 OutRch   oldForestMoon "moon" oldForest
   with   name 'moon' 'storm' 'sky',
          before [;
            Examine:
              print "The forest surrounding you ";
              print "obscures the moon, which ";
              print "is already covered by thick ";
              print "storm clouds";
              if (wolf.animalDead) {
                print ". You should get inside ";
                "before getting wet.";
              }
              ".";

            Take, Push, PushDir, Pull:
              "Don't be ridiculous.";
          ];

OutRch  oldForestSwamp "swamp" oldForest
 with   name 'swamp' 'marsh',
        before [;
          Examine:
            print "You can't see it, but the ";
            print "smell is strong down here ";
            "in the woods.";
          Enter:
            print "It's too hard to enter the ";
            print "swamp. The old forest is ";
            "thick.";
        ];
