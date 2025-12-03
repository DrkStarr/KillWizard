
! ---------------------------------------------------------------------------- !
!       COURTYARD 1/5/25
!
Object  courtyard "Courtyard"
  with  description [;
          if (cyGate.gateOpen) {
            print "Inside the courtyard a ";
            if(cyFiend.headGone) print "black fiend";
            if(cyDemon.headGone) print "red demon";
            if(cyMephit.headGone) print "green mephit";
            print " is pinned to the northern ";
            print "archway. The gate underneath ";
            print "him is open, providing ";
            "access to the castle.";
          }
          print "Inside the courtyard, ";
          print "there's an archway to ";
          print "the north. The yard's ";
          print "walls are smooth, and ";
          print "there's no door out. ";
          print "Underneath the arch, ";
          print "a gate is sealed ";
          print "with a magic barrier.^";
          print "^Three demons are perched ";
          print "at the top of the archway";
          if (self.firstTime) {
            self.firstTime = false;
            print ".";
            rtrue;
          }
          print " - a red demon, a green ";
          print "mephit, and a black fiend. ";
          print "They giggle to themselves ";
          print "as they watch you from on ";
          "high.";
        ],
        daemon [;
          if (self.suppressDemons) {
              self.suppressDemons = false;
          } else {
            iCourtyardTaunt++;
            switch (iCourtyardTaunt) {
              1: print " The creatures cheer as you ";
                 print "hit the ground. ~Sounds like ";
                 print "the big dummy didn't use the ";
                 print "door,~ the red one says.^^~I ";
                 print "bet he can't even see it,~ ";
                 "the green one laughs.";
              3: print "^~Look at him. He can't ";
                 print "solve a simple puzzle,~ the ";
                 "green one taunts.";
              5: print "^~The bigger they are, the ";
                 print "dumber they are,~ the red ";
                 "one laughs.";
              7: print "^The black one snorts, ";
                 print "covering his mouth. ~I'd be ";
                 print "in the next room by now,~ ";
                 "laughs the green one.";
              8: iCourtyardTaunt = 2;
            }
          }
        ],
        n_to [; <<Enter cyGate>>; ],
        in_to [; <<Enter cyGate>>; ],
        u_to [;
          print "You're not getting back up ";
          "there so easily.";
        ],
        out_to [;
          print "You fell into the courtyard. ";
          "There is no way out.";
        ],
		    before [;
          Listen:
            if (cyGate.gateOpen) {
              print "You only hear the howling of ";
              "the wind in the distance.";
            }
            print "The demon's laughter starts ";
            "to grate on your nerves.";
          Smell:
            print "The smell of burning oil ";
            "still lingers in the air.";
		    ],
        cant_go [;
          if (cyGate.gateOpen) {
            print "With the seal broken and the ";
            if(cyFiend.headGone) print "black fiend";
            if(cyDemon.headGone) print "red demon";
            if(cyMephit.headGone) print "green mephit";
            print " dead, the gate to the ";
            "north is open.";
          }
          print "The gate is sealed with ";
          print "magic. There seems to be ";
          "no way out.";
        ],
        firstTime true,
        suppressDemons false,
  has   light;

RoomObj cyObj "courtyard" courtyard
  with  name 'courtyard' 'yard',
        description [;
          <<Look courtyard>>;
        ];

Object  cyGate "gate" courtyard
 with   name 'gate' 'entrance',
        before [;
          Attack:
            if (self.gateOpen) "That's already open.";
            courtyard.suppressDemons = true;
            if (second == axe) {
              print "You swing your axe as hard ";
              print "as you can, but it bounces ";
              print "off the gate.^^~Sounds like ";
              print "he's going to dull his ";
              print "blade, he will,~ the red ";
              "one smirks.";
            }
            print "You try hitting the gate ";
            print "with your fists. It doesn't ";
            print "give.^^~Running out of ";
            "ideas,~ the green one laughs.";
          Cut:
            if (self.gateOpen) "That's already open.";
            courtyard.suppressDemons = true;
            print "You swing your axe as hard ";
            print "as you can, but it bounces ";
            print "off the gate.^^~Sounds like ";
            print "he's going to dull his ";
            print "blade, he will,~ the red ";
            "one smirks.";
          Open:
            if (self.gateOpen) "That's already open.";
            print "The gate has been locked by ";
            print "the necromancer's magic. His ";
            "guardians watch over it.";
          Enter:
            if (self.gateOpen) {
              PlayerTo(antechamber, 2);
              rtrue;
            }
            print "The gate's closed. Locked ";
            print "by magic, it shimmers in ";
            "the night.";
          Examine:
            if (self.gateOpen) {
              print "Since you killed the ";
              if(cyFiend.headGone) print "black fiend";
              if(cyDemon.headGone) print "red demon";
              if(cyMephit.headGone) print "green mephit";
              print ", the spell on the gate was ";
              print "broken, and the devils were ";
              print "driven away. It stands open, ";
              print "allowing you to go deeper ";
              "into the tower.";
            }
            print "The gate sits under the ";
            print "arch, but there's no way ";
            print "to control it. It's ";
            print "sealed by the power ";
            "of the necromancer.";
          Push, PushDir:
            if (self.gateOpen) "The gate's already open.";
            courtyard.suppressDemons = true;
            print "You try to push the gate ";
            print "open.^^~Good luck opening ";
            print "it that way,~ the green ";
            "one smiles.";
          Climb:
            print "There's nothing to grab ";
            print "onto. You can't pull ";
            "yourself up.";
          Take, Pull:
            if (self.gateOpen) {
              print "The gate isn't going ";
              "anywhere.";
            }
            courtyard.suppressDemons = true;
            print "You try pulling on the gate. ";
            print "It doesn't budge.^^~He ";
            print "thinks he's strong enough ";
            print "to pull open the gate,~ ";
            "the green one chuckles.";
          Close:
            if (self.gateOpen) {
              print "The magic seal is broken. ";
              "It's not going to close.";
            }
            "That's already closed.";
        ],
        gateOpen false,
        firstTime true,
   has  concealed static;

Object  cyDoor "door" courtyard
  with  name 'door' 'doors',
        before [;
          default:
            print "You can't see any such thing";
            if (self.lookedAt) ".";
            self.lookedAt = true;
            courtyard.suppressDemons = true;
            print ".^^~See I told you,~ laughs ";
            "the mephit again.";
        ],
        lookedAt false,
   has  concealed static;

Object  cyTower "tower" courtyard
  with  name 'tower' 'foundation',
        before [;
          Attack, Cut:
            print "This foundation is thick, ";
            print "and you're not going to ";
            "do any damage.";
          Examine:
            print "The tower rises above you, ";
            print "its dark stone glistening ";
            print "in the moonlight. The only ";
            "way in is through the gate.";
          Enter:
            <<Enter cyGate>>;
          Take, Pull, Push, PushDir:
            print "The tower isn't going ";
            "anywhere.";
          Climb:
            print "There's no way up. The stone ";
            print "is wet tonight, and you'd ";
            "only slip off.";
          Open:
            print "You can't do that. ";
            "Try OPEN GATE.";
          Close:
            print "You can't do that. ";
            "Try CLOSE GATE.";
        ],
   has  concealed static;

Object  cyArchway "archway" courtyard
  with  name 'arch' 'archway',
        before [;
          Enter:
            <<Enter cyGate>>;
          Examine:
            if (cyGate.gateOpen) {
              print "You scarred the archway ";
              print "when you hit it with the ";
              print "arrow, killing the ";
              if(cyFiend.headGone) print "black fiend";
              if(cyDemon.headGone) print "red demon";
              if(cyMephit.headGone) print "green mephit";
              print " and frightening the other ";
              print "two away. However, your bow ";
              print "broke. Luckily, you still ";
              "have your axe.";
            }
            print "An archway leads into the ";
            print "tower on the courtyard's ";
            print "north side - closed by a ";
            print "gate. Guarded by three ";
            print "demons, the creatures laugh ";
            print "and taunt anyone trying to ";
            "get it.";
          Climb:
            print "There's nothing to grab ";
            print "onto. You can't pull ";
            "yourself up.";
          Take, Push, PushDir, Pull:
            print "The archway isn't going ";
            "anywhere.";
        ],
   has  concealed static;

OutRch  cyFiend "black fiend" courtyard
 with   name 'black' 'fiend' 'mouth',
        before [;
          Examine:
            if(self.headGone) return PDM();
            courtyard.suppressDemons = true;
            print "The black fiend plays with ";
            print "his hands, smiling to ";
            print "himself.^^~I think he likes ";
            print "you,~ the green mephit ";
            "laughs.";
          Ask, AskFor, AskFor2nd, Talk:
            if(self.headGone) return PDP();
            print "The black fiend covers ";
            "its mouth.";
          Shoot:
            if (self.headGone) {
              print "You already killed the ";
              "black fiend.";
            }
            self.headGone = true;
            remove cyDemon;
            remove cyMephit;
            print "Pulling the string back on ";
            print "the bow, you shoot an arrow ";
            print "at the fiend. The bow was ";
            print "damaged when you fell into ";
            print "the courtyard, and breaks ";
            print "as the fiend tries to dodge ";
            print "the arrow";
            return KillDemon();
        ],
        life [;
          default: return PBF();
        ],
        orders [;
          default: return PBF();
        ],
        headGone false,
   has  animate;

OutRch  cyDemon "red demon" courtyard
 with   name 'red' 'demon' 'eyes',
        before [;
          Examine:
            if(self.headGone) return PDM();
            print "The red demon squints. He's ";
            print "blind. But smiles to himself ";
            print "with an evil grin, even ";
            "though he can't see.";
          Ask, AskFor, AskFor2nd, Talk:
            if(self.headGone) return PDP();
            courtyard.suppressDemons = true;
            print "~Talk, talk, talk. Blah, ";
            print "blah, blah,~ the demon ";
            "laughs to himself.";
          Shoot:
            if (self.headGone) {
              print "You already killed the ";
              "red demon.";
            }
            self.headGone = true;
            remove cyFiend;
            remove cyMephit;
            print "Pulling the string back on ";
            print "the bow, you shoot an arrow ";
            print "at the demon. The bow was ";
            print "damaged when you fell into ";
            print "the courtyard, and breaks ";
            print "as the demon cries out, ";
            print "hearing the arrow";
            return KillDemon();
        ],
        life [;
          default: return PRD();
        ],
        orders [;
          default: return PRD();
        ],
        headGone false,
   has  animate;

OutRch  cyMephit "green mephit" courtyard
 with   name 'green' 'mephit' 'ears',
        before [;
          Examine:
            if(self.headGone) return PDM();
            print "The green mephit hunches ";
            print "down atop the archway, ";
            print "resting his head in his ";
            print "hands, with long fingers ";
            "reaching up to his ears.";
          Ask, AskFor, AskFor2nd, Talk:
            if(self.headGone) return PDP();
            courtyard.suppressDemons = true;
            print "The green mephit sits there, ";
            print "giggling. Like he didn't ";
            "hear you.";
          Shoot:
            if (self.headGone) {
              print "You already killed the ";
              "green mephit.";
            }
            self.headGone = true;
            remove cyFiend;
            remove cyDemon;
            print "Pulling the string back on ";
            print "the bow, you shoot an arrow ";
            print "at the mephit. The bow was ";
            print "damaged when you fell into ";
            print "the courtyard, and breaks ";
            print "as the mephit cries out, ";
            print "trying to dodge the arrow";
            return KillDemon();
        ],
        life [;
          default: return PGM();
        ],
        orders [;
          default: return PGM();
        ],
        headGone false,
   has  animate;

OutRch  cyDemons "demons" courtyard
 with   name 'demons' 'creatures' 'devils' 'guardians',
        before [;
          Examine:
            print "Three guardians watch you, ";
            print "resting on the archway and ";
            print "out of reach. The black one ";
            print "taps the green one on the ";
            print "shoulder, pointing to you. ";
            "The red one laughs.";
        ],
   has  pluralname;

[ PDM;
    print "The ";
    if(cyFiend.headGone) print "black fiend";
    if(cyDemon.headGone) print "red demon";
    if(cyMephit.headGone) print "green mephit";
    print " is pinned to the archway. ";
    print "You nailed him with the ";
    print "arrow, sticking him to ";
    "the wall.";
];

 [ PDP;
     print "The demon's pinned to the ";
     print "archway. Dead, he isn't ";
     "going to say anything.";
 ];


  [ PBF;
      if (cyFiend.headGone) {
        print "The black fiend is no ";
        "longer alive.";
      }
      print "The black fiend covers ";
      "its mouth.";
  ];

  [ PRD;
      if (cyDemon.headGone) {
        print "The red demon is no ";
        "longer alive.";
      }
      print "The red demon stares at ";
      print "you, blind, with fire in ";
      "his eyes.";
  ];

  [ PGM;
      if (cyMephit.headGone) {
        print "The green mephit is no ";
        "longer alive.";
      }
      print "The green mephit snickers, ";
      print "paying no attention to ";
      "you at all.";

  ];
