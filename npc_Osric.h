
! ---------------------------------------------------------------------------- !
!       OSRIC 12/31/24
!

Object  osric "Osric" scavengersDen
  with  name 'osric' 'bartender' 'man',
        describe [;
            rtrue;
        ],
        before [ w1;
          Attack, Burn, Push:
            print "You don't want to hurt ";
            "your friend.";
          AskFor:
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'flint':
                if (firewood.beenCut) return GiveFlint();
              'wood':
                if (firewood.beenCut) {
                  print "~Thanks for getting some. ";
                  print "Now, please build the ";
                  "fire.~";
                }
                print "~There's plenty of firewood ";
                "out back.~";
            }
            if (firewood.onFire) return AfterTheFire();
            if (firewood.beenCut) {
              print "~We can talk after the fire ";
              "is built,~ says Osric.";
            }
            print "~Don't worry about that,~ ";
            print "Osric says. ~Head out back ";
            print "and gather some wood for ";
            "the fire.~";
          Examine:
            if (scroll.objectRead) {
              print "Osric looks at your friend. ";
              print "He knows that he must try ";
              "to save him.";
            }
            if (firewood.onFire) {
              print "Osric stands beside you, ";
              print "still in shock by what ";
              "just happened.";
            }
            if (self.flintGiven) {
              print "Osric stands beside you, ";
              print "waiting for you to start ";
              "the fire.";
            }
            if (firewood.beenCut) {
              print "Osric cleans a couple of ";
              "mugs using an old rag.";
            }
            print "Osric is a burly man with ";
            print "a thick grey beard. He ";
            print "smiles as you look over ";
            "at him.";
          Talk:
            if (firewood.onFire && scroll.objectRead == false) "~Mitra. What happened?~";
            print "Try using the verbs ASK or ";
            print "TELL. ie. ASK ABOUT ";
            if (firewood.onFire) "BELKOR.";
            "FIRE.";
        ],
        life [ w1;
          Answer:
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'goodbye','bye','ciao':
                if (scroll.objectRead) {
                  print "~Avenge your friend, ";
                  print "and be careful with ";
                  "that necromancer.~";

                }
                if (firewood.onFire) "~Mitra. What happened?~";
                if (firewood.beenCut) {
                  print "~Finish what you started. ";
                  "Make the fire.~";
                }
                print "~You just got 'ere. Please ";
                "make a fire.~";
              'sorry':
                "Osric grimly nods.";
              'yes','yeah','yea':
                if (firewood.onFire) "Osric grimly nods.";
                "He smiles in agreement.";
              'no':
                "He stares at you blankly.";
            }
          Ask:
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'axe', 'ax':
                if (firewood.onFire) return AfterTheFire();
                if (firewood.beenCut) {
                  print "~The blacksmith from Yaralet ";
                  print "is making me another. I'm ";
                  "not worried about that one.~";
                }
                if (backyard.firstTime) {
                  print "~Go ahead and keep it. ";
                  print "It's rusted anyway. But ";
                  print "make sure to cut down ";
                  "some wood.~";
                }
                print "~There's an axe out back. ";
                "You are going to need it.~";
              'blacksmith':
                if (firewood.onFire) return AfterTheFire();
                print "~There's a blacksmith over ";
                print "in Yaralet. He should be ";
                print "done with my new axe by ";
                print "the next time he comes ";
                "around.~";
              'harvest', 'crop', 'crops':
                if (firewood.onFire) return AfterTheFire();
                print "~The harvest was bad last ";
                print "year. Not only did the crops ";
                print "fail after the necromancer ";
                print "came through, but a lot of ";
                print "people got sick, including ";
                "Seraina.~";
              'storm':
                if (firewood.onFire) return AfterTheFire();
                if (firewood.beenCut) {
                  print "~Sounds like a rough one ";
                  print "tonight, but we can talk ";
                  "after the fire is built.~";
                } else {
                  print "~Looks like a mean one is ";
                  "starting roll in.~";
                }
              'yaralet':
                if (firewood.onFire) return AfterTheFire();
                print "~It's three leagues east. ";
                print "The blacksmith from there ";
                "stops by every two moons.~";
              'backyard', 'yard', 'back':
                if (firewood.onFire) return AfterTheFire();
                print "~I've cut down a lot of ";
                print "trees to keep this place ";
                print "warm. Could you go out ";
                "there and help me?~";
              'conan':
                if (firewood.onFire) return AfterTheFire();
                print "~The name sounds familiar. ";
                print "A few Cimmerians pass ";
                print "through 'ere, look at you, ";
                "but I don't know 'im.~";
              'darron', 'companion', 'friend', 'darren':
                if (scroll.objectRead) {
                  print "~I'll see if I can treat ";
                  print "your friend. He looks ";
                  print "rough. But now you need to ";
                  "avenge this crime.~";
                }
                if (firewood.onFire) "~Mitra. What happened?~";
                print "~Your friend from Shem? ";
                print "I would watch that one if ";
                "I were you.~";
              'grimes':
                if (firewood.onFire) return AfterTheFire();
                print "~What? That old grouch that ";
                print "works the farm? He won't ";
                "spend any coin in here.~";
              'farm':
                if (firewood.onFire) return AfterTheFire();
                print "~You don't want to go out ";
                print "there. They say strange ";
                "things about Grimes.~";
              'belkor', 'necro', 'necromancer', 'wizard':
                if (self.knowsNecro) {
                  print "~I am sorry you must ";
                  print "face 'im. I'll see what ";
                  print "I can do for your friend. ";
                  print "Pay 'im back for all he's ";
                  "done.~";
                }
                if (firewood.onFire) return AfterTheFire();
                print "~Belkor? Hm. He's a twisted ";
                print "one. Came through 'ere and ";
                print "sized us all up. Then he ";
                print "took over the tower. It ";
                print "didn't take long. I'm ";
                print "sure Shem let 'im get ";
                "through.~";
              'cimmeria', 'cimmerians', 'north':
                if (firewood.onFire) return AfterTheFire();
                print "~It's a long way through ";
                "Aquilonia to get up there.~";
              'aquilonia', 'flower':
                if (firewood.onFire) return AfterTheFire();
                print "~What? The Flower of the ";
                print "West? Too many nobles live ";
                "in Poitain for my tates.~";
              'poitain':
                if (firewood.onFire) return AfterTheFire();
                print "~That town is too ";
                print "civilized. They wouldn't ";
                print "want someone like me ";
                "around.~";
              'nobles':
                if (firewood.onFire) return AfterTheFire();
                print "~No nobles live in Khalir. ";
                print "This is a poor town, but ";
                print "the people are ";
                "good-hearted.~";
              'dead', 'tower':
                if (self.knowsNecro) {
                  print "~The dead tower is an ";
                  print "abhorrent thing. It lies ";
                  print "to the northwest of this ";
                  "town. Go with God's speed.~";
                }
                if (firewood.onFire) return AfterTheFire();
                print "~The dead tower is an ";
                print "abhorrent thing. The ";
                print "necromancer has twisted it. ";
                print "People whisper of how he ";
                "killed the count.~";
              'peace':
                "~It's tentative at best.~";
              'flint':
                if (firewood.beenCut) return GiveFlint();
              'food':
                if (firewood.onFire) return AfterTheFire();
                if (firewood.beenCut) {
                  print "~I have some warming in the ";
                  print "back. Start the fire, and ";
                  "we can have some.~";
                }
                print "~I have some warming in the ";
                print "back. Get some wood, and we ";
                "can have some.~";
              'bar':
                if (firewood.onFire) return AfterTheFire();
                if (firewood.beenCut) {
                  print "~Not a lot of people are ";
                  print "'ere tonight, but I don't ";
                  print "mind. I'm getting too old ";
                  "for this type of work.";
                }
                print "~Not a lot of people are ";
                print "'ere tonight, but I don't ";
                print "mind. I'm getting too old ";
                print "for this type of work. ";
                print "Go out back and grab some ";
                "wood. We can talk then.~";
              'border':
                if (firewood.onFire) return AfterTheFire();
                print "~The border between Shem ";
                print "and Koth has always been ";
                print "dangerous, even with the ";
                print "marriage to the Princess. ";
                print "Political ties might bind, ";
                print "but the hatred between us ";
                "is real.~";
              'barmaid', 'maid':
                if (self.knowsNecro) {
                  print "~Don't worry about 'er. ";
                  print "You must avenge your ";
                  "brother in arms.~";
                }
                if (firewood.onFire) return AfterTheFire();
                print "~She's has been gone six ";
                print "moons now. I'm never going ";
                print "to get this place in ";
                "shape.~";
              'hate', 'hatred', 'hating':
                if (firewood.onFire) return AfterTheFire();
                print "~Don't judge me for hating ";
                print "Shem. They have spilt more ";
                "blood than you know.~";
              'hyboria':
                if (firewood.onFire) return AfterTheFire();
                print "~Hyboria? What is that? ";
                "Some sort of disease?~";
              'seraina', 'wife':
                if (self.knowsNecro) {
                  print "~Don't worry about 'er. You ";
                  print "must avenge your brother ";
                  "in arms.~";
                }
                if (firewood.onFire) return AfterTheFire();
                if (self.knowSeraina) {
                  print "You should respect his ";
                  "wishes.";
                }
                self.knowSeraina = true;
                print "~You don't remember Seraina? ";
                print "She was my wife. She didn't ";
                print "last long after the ";
                print "necromancer showed up. I ";
                print "buried 'er out back at the ";
                print "end of the harvest. I ";
                print "really hate to talk about ";
                print "it. Please. Don't ";
                "bring 'er up.~";
              'grave', 'headstone':
                if (firewood.onFire) return AfterTheFire();
                if (self.knowGrave) {
                  print "You should respect his ";
                  "wishes.";
                }
                self.knowGrave = true;
                print "~That's Seraina's. I hate ";
                print "to talk about it. Please ";
                "don't bring it up again.~";
              'strangers', 'customers', 'people':
                if (self.knowsNecro) {
                  print "~Don't worry about 'em. You ";
                  print "must avenge your brother ";
                  "in arms.~";
                }
                if (firewood.onFire) "~Mitra. What happened?~";
                print "~I don't know who they are, ";
                print "but they look like they ";
                print "come from Stygia if you ";
                "ask me.~";
              'scavenger^s', 'den', 'tavern', 'inn':
                if (firewood.onFire) return AfterTheFire();
                print "~I have to admit, this ";
                print "place isn't much. It's ";
                print "really gone downhill";
                if (self.knowDen) ". I can't keep up with it.~";
                self.knowDen = true;
                print " since I lost Seraina. I ";
                "can't keep up with it.~";
              'wood', 'firewood', 'fire','pit','firepit':
                if (firewood in sdFirepit) return GiveFlint();
                if (firewood.beenCut) {
                  print "~Good job, my friend. Now, ";
                  print "go ahead and build the ";
                  "fire.~";
                }
                print "~Yes. There is plenty of ";
                print "wood in the back. Cut ";
                print "some down so you can ";
                "build a fire.~";
              'pint', 'pints', 'mug', 'mugs','beer','ale','mead','booze':
                if (firewood.onFire) return AfterTheFire();
                if (firewood.beenCut) {
                  print "~I'll pour us some, give ";
                  "me a minute to clean up.~";
                }
                print "~These ain't for you,~ ";
                print "Osric says. ~Build us a ";
                print "fire and I'll make sure ";
                "you get one.~";
              'count':
                if (firewood.onFire) return AfterTheFire();
                print "~The count was a fair man. ";
                print "His taxes were reasonable. ";
                print "That's no way to go. We ";
                print "might not have to pay taxes ";
                print "anymore, but there's no one ";
                print "to help us if we get ";
                print "raided. Shem knows we are ";
                "weak.~";
              'raids', 'raid':
                if (firewood.onFire) return AfterTheFire();
                print "~Shem has raided Koth for ";
                print "as long as I lived. We have ";
                print "peace now since the ";
                print "Princess married that ";
                print "snake, but who knows how ";
                "long that will last.~";
              'snake', 'eshelon':
                if (firewood.onFire) return AfterTheFire();
                print "~Prince Eshelon? I'll spit ";
                print "on his grave when this is ";
                "over.~";
              'yasmela':
                if (firewood.onFire) return AfterTheFire();
                print "~She's going to be the ";
                "downfall of all of Koth.~";
              'princess', 'marriage':
                if (firewood.onFire) return AfterTheFire();
                print "~Everyone knows Shem has ";
                print "married into Koth. Yasmela ";
                print "is a slut. Daughter of the ";
                print "king or not. Sleeping with ";
                print "that snake. Hm. You must ";
                print "hear nothing up in the ";
                "north.~";
              'me', 'self':
                if (firewood.onFire) return AfterTheFire();
                print "~It's been over a year since ";
                print "I've seen you. Putting on a ";
                print "few extra pounds,~ Osric ";
                "laughs.";
              'himself', 'osric', 'bartender', 'news':
                if (firewood.onFire) return AfterTheFire();
                print "~I've seen better days in ";
                print "Khalir. Seraina passed ";
                print "after the necromancer ";
                print "showed up. Something ";
                print "happened at the tower. ";
                print "Rumor has it, he killed ";
                print "the guards and murdered ";
                "the count.~";
              'guard', 'guards':
                if (firewood.onFire) return AfterTheFire();
                print "~I heard the guards in that ";
                print "tower didn't stand a ";
                print "chance. They say a fireball ";
                "killed 'em all.~";
              'khalir', 'town', 'village', 'place':
                if (firewood.onFire) return AfterTheFire();
                print "~Things haven't been good, ";
                print "since the necromancer came. ";
                print "Seraina died afterwards, ";
                print "and I haven't been able ";
                "to keep up since.~";
              'koth':
                if (firewood.onFire) return AfterTheFire();
                print "~What? The soil you're on? ";
                print "I've called Koth home my ";
                "entire life.~";
              'eastern', 'shem':
                if (firewood.onFire) return AfterTheFire();
                print "~I know your friend comes ";
                print "from Shem, but I don't ";
                print "trust 'im,~ Osric states. ";
                print "~I don't trust any of 'em. ";
                print "I've seen 'em come up from ";
                print "the border and raid us one ";
                "too many times.~";
              'stygia':
                if (firewood.onFire) return AfterTheFire();
                print "~Stygia is far to the ";
                print "south,~ says Osric. ~They ";
                print "say dark magic is worked ";
                print "down there. More than just ";
                print "warlocks, but necros and ";
                print "liches. It's a powerful ";
                "form of evil.~";
              'south':
                if (firewood.onFire) return AfterTheFire();
                print "~Shem is just to the south, ";
                print "but then you run into the ";
                "hot sands of Stygia.~";
              'desert', 'sands', 'sand':
                if (firewood.onFire) return AfterTheFire();
                print "~The Stygian desert is no ";
                "place for man to live.~";
              'evil':
                if (firewood.onFire) return AfterTheFire();
                print "~The evils of Stygia have ";
                print "made their way up here. ";
                print "Look at the necromancer. ";
                "Shem would let 'im through.~";
              'magic', 'dark':
                if (firewood.onFire) return AfterTheFire();
                print "~I know nothing about magic, ";
                print "but Belkor tainted this ";
                print "place. The crops failed ";
                "during the last harvest.~";
              'warlock', 'warlocks':
                if (firewood.onFire) return AfterTheFire();
                print "~Warlocks don't travel ";
                print "through Koth. They're ";
                print "killed on site, even ";
                "in Shem.~";
              'necros':
                if (firewood.onFire) return AfterTheFire();
                print "~Look at Belkor. He came up ";
                print "from down south. I'm sure ";
                print "Shem let 'im through to ";
                print "plague us with a ";
                "necromancer.~";
              'lich', 'liches':
                if (firewood.onFire) return AfterTheFire();
                print "~The liches possess the ";
                print "most powerful magic. Born ";
                print "from warlocks that have ";
                "crossed over into undeath.~";
              'wolf', 'wolves':
                if (firewood.onFire) return AfterTheFire();
                if (wolf.animalDead) {
                  print "~You don't have to worry ";
                  print "about the wolves anymore. ";
                  print "But the forest still ";
                  "isn't safe.~";
                }
                print "~There's dangerous wildlife ";
                print "out there for sure. You'll ";
                print "have to fight it off, but ";
                print "that shouldn't be a problem ";
                "for someone like you.~";
              'old', 'forest', 'trees', 'woods':
                if (firewood.onFire) return AfterTheFire();
                print "~The forest behind 'ere is ";
                "older than Khalir itself.~";
              'mercenary':
                if (firewood.onFire) return AfterTheFire();
                print "~Mercenaries drift through ";
                print "'ere now and then. Look at ";
                "yourself.~";
              'zamora':
                if (firewood.onFire) return AfterTheFire();
                if (self.askZamora) {
                  print "~Like I said, I've never ";
                  "been there.~";
                }
                self.askZamora = true;
                print "~What about Zamora? I've ";
                print "never been down there,~ ";
                print "Osric says, shifting ";
                "around some mugs.";
            }
            if (firewood.onFire) return AfterTheFire();
            if (firewood.beenCut) {
              print "~We can talk after the ";
              print "fire is built,~ says ";
              "Osric.";
            }
            print "~Don't worry about that,~ ";
            print "Osric says. ~Head out back ";
            print "and gather some wood for ";
            "the fire.~";
          Tell:
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'belkor', 'necro', 'necromancer', 'scroll', 'friend', 'companion', 'darron', 'note', 'parchment':
                if  (scroll.objectRead) {
                  self.knowsNecro = true;
                  print "~If Belkor is behind this, ";
                  print "know you have a grueling ";
                  print "task ahead. None dare ";
                  print "approach the necromancer. ";
                  print "They say one touch and ";
                  "he'll melt off your flesh.~";
                }
            }
            if (firewood.onFire) {
              print "Osric doesn't seem to ";
              "understand.";
            }
            if (firewood.beenCut) {
              print "~We can talk after the fire ";
              "is built,~ says Osric.";
            }
            print "~Don't worry about that,~ ";
            print "Osric says. ~Head out back ";
            print "and gather some wood for ";
            "the fire.~";
          default:
            if (firewood.onFire) return AfterTheFire();
            if (firewood.beenCut) {
              print "~We can talk after the fire ";
              "is built,~ says Osric.";
            }
            print "~Don't worry about that,~ ";
            print "Osric says. ~Head out back ";
            print "and gather some wood for ";
            "the fire.~";
        ],
        orders [;
          default:
            if (scroll.objectRead) {
              print "~I'll see if I can treat ";
              print "your friend. He looks ";
              print "rough. But now you need ";
              "to avenge this crime.~";
            }
            if (firewood.onFire) "~Mitra. What happened?~";
            "Osric mumbles something under his breath.";
        ],
        knowDen false,
        askNecro false,
        askZamora false,
        knowGrave false,
        knowsNecro false,
        flintGiven false,
        knowSeraina false,
  has   animate proper;

[ GiveFlint;
    if (osric.knowsNecro) {
      print "~Don't worry about that. ";
      print "You must avenge your ";
      "brother in arms.~";
    }
    if (firewood.onFire) "~Mitra. What happened?~";
    if (osric.flintGiven) "~Now let's see some flames.~";
    osric.flintGiven = true;
    move flint to player;
    print "~Oh, yes. How forgetful of ";
    print "me. You'll need this piece ";
    print "of flint to start the ";
    print "fire,~ he says, walking ";
    print "over.^^Osric hands you a ";
    "chipped piece of flint.";
];

[ AfterTheFire;
    if (osric.knowsNecro) {
      print "~Don't worry about that. You ";
      print "must avenge your brother ";
      "in arms.~";
    }
    "~Mitra. What happened?~";
];
