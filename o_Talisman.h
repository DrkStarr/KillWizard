
! ---------------------------------------------------------------------------- !
!       TALISMAN 1/2/25
!

Object  talisman "talisman"
  with  name 'talisman' 'trinket' 'necklace' 'charm',
        before [;
          Examine:
            if (player in grandCorridor) {
              if (golems.mobDead) {
                print "It's hard to see the ";
                print "talisman in the darkness, ";
                "because it's not glowing.";
              }
              print "The talisman glows bright ";
              print "blue, penetrating the ";
              "darkness.";
            }
            if (player in armory) {
              if (golems.mobDead) {
                print "It's hard to see the ";
                print "talisman in the darkness, ";
                "because it's not glowing.";
              }
              print "The talisman glows, but ";
              "not as brightly in here.";
            }
            if (player in stairway || player in necrosLair) {
              if (golems.mobDead) {
                print "Crafted from sinew and ";
                print "twine, the talisman no ";
                "longer glows.";
              }
              print "The talisman glows, but ";
              "not as brightly in here.";
            }
            if (player in greatHall || player in kitchen) {
              if (golems.mobDead) {
                print "With the skeletons gone, ";
                print "the talisman no longer ";
                "glows blue.";
              }
              print "The talisman glows ";
              print "bright blue, like an ";
              "electric fire.";
            }
            if (player in antechamber) {
              if (golems.mobDead) {
                print "The talisman no longer ";
                print "glows blue. All the ";
                print "skeletons have been ";
                "dealt with.";
              }
              print "The talisman glows blue ";
              print "as it hangs around your ";
              "neck.";
            }
            if (player in moors) {
              if (banshees in moors) {
                print "The talisman glows ";
                print "bright blue, like an ";
                "electric fire.";
              }
            }
            print "Crafted from sinew and ";
            print "twine, a web has been ";
            print "woven inside a circle ";
            print "- a ward against the ";
            "undead.";
          Disrobe, Remove:
            print "It's easier to wear it ";
            "than carry it.";
          Give:
            if (second == slumsPoor) return PPA();
            print "You need to give the ";
            "talisman to someone.";
        ];
