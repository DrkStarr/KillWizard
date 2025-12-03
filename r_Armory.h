
! ---------------------------------------------------------------------------- !
!       ARMORY 1/11/25
!

Object  armory "Armory"
 with   description [;
          print "The armory contained a ";
          print "garrison's worth of ";
          print "equipment, but now only ";
          print "one stand remains. The ";
          print "wizard killed all the ";
          print "soldiers when he took ";
          print "over the tower. The exit ";
          print "west leads to the corridor";
          if (golems.startedMovement) {
            golems.startedMovement = false;
            if (iGolemMovement >= 4) {
              print ".^^Hiding here, you wait a ";
              print "moment, and hear the golems ";
              print "return to their post.^";
            } else {
              print ".^^Hiding here, you wait a ";
              print "moment. The golems stop, ";
              print "and then you listen to them ";
              print "return to their post.^";
            }
            iGolemMovement = 0;
            rtrue;
          }
          ".";
        ],
        w_to [; <<Enter armCorridor>>; ],
        out_to [; <<Enter armCorridor>>; ],
        before [;
          Listen:
            if (golems.mobDead) {
              print "The place is quiet. Your ";
              "footsteps ring hollow.";
            }
            print "You hear the undead beat on ";
            "the door to the west.";
          Smell:
            print "This room smells stale and ";
            print "old. Dust has filled this ";
            "place.";
        ],
        cant_go [;
          print "It's not that big. You can ";
          "head back out to the west.";
        ],
  has   light;

RoomObj armObj "armory" armory
  with  name 'armory',
        description [;
          <<Look armory>>;
        ];

OutRch  armStand "stand" armory
  with  name 'armor' 'stand' 'platemail',
        before [;
          Attack, Cut:
            return PKE();
          Examine:
            print "The armor stand holds a set ";
            print "of full platemail. It leans ";
            print "against the far wall of the ";
            "armory.";
          Take:
            print "The armor is the only thing ";
            print "left from the garrison that ";
            print "once protected this place. ";
            print "You don't need it. You're ";
            "quicker in the loincloth.";
          Burn, Climb, Close, Enter, Insert, Open, Push, PushDir, Pull, ThrowAt:
            "You don't need to do that.";
        ];

OutRch  armCorridor "corridor" armory
 with   name 'corridor' 'exit',
        before [;
          Enter:
            PlayerTo(grandCorridor, 2);
            rtrue;
          Examine:
            print "The corridor lies west";
            if (golems.mobDead) {
              print ". An eerie silence blankets ";
              "the place.";
            }
            print ", and you can hear skeletons ";
            print "banging on the door from ";
            "there.";
        ];
