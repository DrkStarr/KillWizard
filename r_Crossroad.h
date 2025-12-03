
! ---------------------------------------------------------------------------- !
!       CROSSROAD 1/1/25
!
Object  crossroad "Crossroad"
 with   description [;
          print "Crows hang in the air. There ";
          print "are fields to the east, ";
          print "while the land gradually ";
          print "turns into marsh to the ";
          print "west. A mountain range lies ";
          print "to the north, and the ";
          print "village gate is situated ";
          "to the south.";
        ],
        n_to [; <<Enter crossroadMountain>>; ],
        s_to [; <<Enter crossroadGate>>; ],
        e_to [; <<Enter crossroadField>>; ],
        w_to [; <<Enter crossroadMarsh>>; ],
        in_to [; <<Enter crossroadGate>>; ],
        before [;
          Listen:
            print "Crows above caw, waiting ";
            "to feed.";
          Smell:
            print "Plenty of fresh air blows ";
            print "around you, but ";
            print "occasionally, a hint of ";
            print "urine drifts in from the ";
            "village.";
        ],
        cant_go [;
          print "You can follow the road east ";
          print "or west or head south, back ";
          "to the village.";
        ],
  has   light;

RoomObj crossroadObj "crossroad" crossroad
  with  name 'crossroad' 'crossroads',
        description [;
          <<Look crossroad>>;
        ];

Object  crossroadArcher "archer" crossroad
 with   name 'man' 'archer' 'mercenary',
        describe [;
          if (bow in crossroad && arrows in crossroad) {
            print "^A man lies dead on the ";
            print "ground, with a bow and ";
            "some arrows next to him.";
          }
          if (bow in crossroad) {
            print "^A man lies dead on the ";
            print "ground, with a bow next ";
            "to him.";
          }
          if (arrows in crossroad) {
            print "^A man lies dead on the ";
            print "ground, with some arrows ";
            "next to him.";
          }
          print "^A man lies dead on the ";
          print "ground. He holds a ";
          print "waterskin tightly in his ";
          "hand.";
        ],
        before [;
          Examine:
            print "Pain is etched into the ";
            print "archer's face. He's ";
            print "crumpled over on the ";
            print "ground, tightly clutching ";
            print "a waterskin";
            if (bow in crossroad && arrows in crossroad) {
              print ". A bow and some arrows lie ";
              "next to him.";
            }
            if (bow in crossroad) ". A bow lies next to him.";
            if (arrows in crossroad) {
              print ". Some arrows lie next ";
              "to him.";
            }
            ".";
          Burn, Climb, Cut, Take, Talk, Push, PushDir, Pull:
            return PAD();
          Search:
            if (self.searchArcher) {
              print "You find nothing more on ";
              "the archer.";
            }
            self.searchArcher = true;
            move pouch to player;
            print "You search the dead man, ";
            print "going through his pockets, ";
            print "finding a pouch of coins. ";
            print "This is half the payment ";
            "for killing Darron.";
        ],
        life [;
          return PAD();
        ],
        orders [;
          return PAD();
        ],
        firstTime true,
        searchArcher false,
   has  animate;

Object  crossroadSkin "waterskin" crossroad
 with   name 'water' 'skin' 'waterskin',
        before [;
          Examine:
            print "The archer grasps the ";
            print "waterskin tightly. It ";
            print "looks like something ";
            "was in his drink.";
          Drink, Take, Close, Open, Push, Pull, PushDir:
            print "You think twice. The ";
            print "archer is holding the ";
            print "waterskin with a death ";
            print "grip. It must have been ";
            "the last thing he drank.";
        ],
   has  concealed static;

Object  crossroadGate "gate" crossroad
 with   name 'gate' 'entrance' 'door' 'village',
        before [;
          Enter:
            print "You walk down the road ";
            print "to the village.^^";
            PlayerTo(slums, 2);
            rtrue;
          Examine:
            print "The gate is open, giving you ";
            print "access to the village of ";
            "Khalir.";
          Open, Push, Pull:
            "The gate is already open.";
          Close:
            "You don't need to do that.";
          Take:
            print "The gate isn't going ";
            "anywhere.";
        ],
   has  concealed static;

OutRch  crossroadMarsh "marsh" crossroad
 with   name 'marsh' 'moors' 'fog' 'swamp',
        before [;
          Enter:
            if (talisman in player) {
              if (banshees in moors) {
                print "Banshees scream and shout, ";
                print "but you hear nothing at ";
                print "all. The talisman glows ";
                print "blue.^^";
              }
              PlayerTo(moors, 2);
              rtrue;
            }
            print "As you try to step into the ";
            print "moors, banshees scream, ";
            print "enraged that someone would ";
            print "trample on hallowed ground. ";
            print "They whip around you in a ";
            print "frenzy. You have no talisman ";
            print "to ward them off. After ";
            print "another deafening shout, ";
            print "you return to the ";
            "crossroads.";
          Examine:
            print "Tonight, the moon catches a ";
            print "glint of fog rising off the ";
            print "moors";
            if (banshees.ghostsGone) ".";
            print ", but you feel an evil ";
            print "presence in that ";
            "darkness.";
        ];

OutRch  crossroadMountain "mountain" crossroad
 with   name 'mountain' 'mountains' 'range',
        before [;
          Enter:
            print "The mountains are far ";
            print "to the north. You can ";
            print "follow the road east or ";
            print "west or head south, back ";
            "to the village.";
          Examine:
            print "The mountains are in ";
            print "the distance. They're ";
            print "the southern tip of the ";
            print "Karpash Mountains, and ";
            print "they stand between you ";
            "and Corinthia.";
        ],
  has   pluralname;

OutRch  crossroadField "fields" crossroad
 with   name 'fields' 'vines' 'grapes' 'trellis',
        before [;
          Enter:
            print "You walk for a bit before ";
            print "leaving the tower behind ";
            print "you and reach a large ";
            print "field of grapes.^^";
            if (scarecrow.mobDead == false) StartDaemon(fields);
            PlayerTo(fields, 2);
            rtrue;
          Examine:
            print "Fields cultivating grapes ";
            print "with vines wrapped in ";
            "trellises lie to the east.";
        ],
   has  pluralname;

 OutRch   crossroadCrows "crows" crossroad
   with   name 'crow' 'crows' 'bird' 'birds',
          before [;
              Examine:
                print "The birds fly above ";
                print "you, waiting for their ";
                "next meal.";
              Shoot:
                if (bow in player) {
                  print "You don't need to shoot ";
                  print "them. You'd only waste ";
                  "an arrow.";
                }
          ],
    has   pluralname;

OutRch   crossroadMoon "moon"
   with   name 'moon' 'moonlight' 'sky' 'light',
          before [;
              Examine:
                print "The moon is almost full ";
                print "tonight. It looks large ";
                print "as it hangs low in the sky";
                if (self.seenMoon) ".";
                self.seenMoon = true;
                print ", but you know it won't ";
                print "truly be full for two ";
                "more nights.";
              Take, Push, PushDir, Pull:
                "Don't be ridiculous.";
          ],
          seenMoon false,
          found_in slums crossroad fields farm;
