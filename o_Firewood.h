
! ---------------------------------------------------------------------------- !
!       WOOD 12/31/24
!
Object  firewood "wood"
  with  name 'logs' 'wood' 'dead' 'log',
        short_name [;
            print "some ";
        ],
		    before [;
          Burn:
            if (firewood.onFire) "The wood is already burning.";
            if (flint in player) <<Attack flint>>;
            if (firewood in sdFirepit) {
                if (sdFirepit.fireHint) {
                  print "Maybe Osric has some flint ";
                  print "that you could use to ";
                  "start the fire.";
                }
                sdFirepit.fireHint = true;
                print "If only you had some flint ";
                "to spark against your axe.";
            }
            if (player in scavengersDen) {
              print "You need to put it in the ";
              "firepit first.";
            }
            "You need to get inside first.";
          Cut:
            "It's already chopped up.";
			    Examine:
            if (self.onFire) {
              print "The wood has caught fire and ";
              print "is heating the room, while ";
              "embers below pile up.";
            }
            if (self in sdFirepit) {
              print "The wood is dry and will ";
              print "burn through the night. ";
              print "You have propped it up ";
              print "like a tent, so it can ";
              "breathe when lit.";
            }
            print "The wood is dry and will ";
            "burn through the night.";
          Insert:
            if (second == sdFirepit) {
              if (self.onFire) {
                print "You'd burn yourself. ";
                "The wood is on fire.";
              }
              if (self.fireReady) {
                print "The wood is already in the ";
                print "pit. You just need ";
                print "something to start ";
                "the fire.";
              }
              self.fireReady = true;
              self.&name-->3 = 'tent';
              move self to sdFirepit;
              print "Using your axe, you shave ";
              print "off some of the dead wood ";
              print "to create kindling. Once ";
              print "you have a small pile, you ";
              print "stack the wood around it, ";
              print "forming something like a ";
              print "small tent so the fire can ";
              "breathe.";
            }
          Take:
            if (self.onFire) {
              print "You'd burn yourself. ";
              "The wood is on fire.";
            }
            if (self in sdFirepit) {
              print "You've already stacked ";
              "the wood.";
            }
          Give:
            if (second == osric) {
              print "~I'm finishing up here. ";
              "Please. Build the fire.~";
            }
            if (second == sdStrangers) {
              print "The strangers look blankly ";
              print "at you for a moment, then ";
              "return to their conversation.";
            }
            print "You need to give the ";
            "firewood to someone.";
        ],
        onFire false,
        beenCut false,
        fireReady false,
  has   proper;
