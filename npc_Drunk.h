
! ---------------------------------------------------------------------------- !
!       DRUNK 12/31/24
!

Object  drunk "drunk" slums
  with  name 'drunk' 'guy' 'man' 'bum',
        article [;
          print "the";
        ],
        describe [;
          print "^A man staggers around the ";
          "entrance of the tavern.";
        ],
        before [ w1;
          AskFor:
            if (self.talkedTo) {
              self.talkedTo = false;
              return DrunkResponse();
            }
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'talisman', 'ward', 'item':
                slumsDen.knowAboutDrink = true;
                print "~I'll make a trade. It might ";
                print "be the last thing I own, but ";
                print "I'll take anything to drink? ";
                print "You know, I gotta stop these ";
                "shakes.~";
              'drink', 'booze', 'cure':
                slumsDen.knowAboutDrink = true;
                print "~I thought you had some. I'm ";
                "sure you can help a guy out.~";
            }
            return DrunkResponse();
          Attack, Burn, Cut:
            return PKE();
          Shoot:
            if (bow in player) {
              if (arrows in player) {
                print "You have no reason to hurt ";
                print "the man. Killing him for ";
                print "the talisman would be a ";
                "bit much.";
              }
              print "How are you going to hit ";
              print "him. You don't have any ";
              "arrows.";
            }
          Examine:
            print "The man staggers around, ";
            print "hands shaking, almost ";
            print "tripping over himself. In ";
            print "his right hand, he clutches ";
            print "a talisman - the last ";
            "valuable item he owns.";
          Climb, Take:
            print "You don't need to anger ";
            "the man.";
          Push, Pull, PushDir:
            print "There's no need to start ";
            "a fight.";
        ],
        life [ w1;
          Answer:
            if (self.talkedTo) {
              self.talkedTo = false;
              return DrunkResponse();
            }
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'yes','yeah','yea':
                "~Please. Hand it over.~";
              default:
                "~Help a guy out, would you?~";
            }
          Ask:
            if (self.talkedTo) {
              self.talkedTo = false;
              return DrunkResponse();
            }
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'drink', 'booze', 'cure':
                slumsDen.knowAboutDrink = true;
                print "~It's been a while since ";
                print "I've had anything to drink. ";
                "Times are tough, you know.~";
              'wine':
                slumsDen.knowAboutDrink = true;
                print "~Oh yeah. The sweet stuff. ";
                print "If you can find some, I'm ";
                "sure I can help you out.~";
              'old','man','grimes':
                print "~He loves seeing me suffer, ";
                print "but he'll get his";
                if (self.askedGrimes) " one day.~";
                self.askedGrimes = true;
                print ". He works the fields ";
                print "during the day, but we ";
                print "never see his wife anymore. ";
                print "They say he killed her ";
                print "and buried her in ";
                "the cellar.~";
              'talisman', 'ward', 'item', 'trinket', 'charm':
                slumsDen.knowAboutDrink = true;
                print "~It's magic I tell you. ";
                print "Worth its weight in gold. ";
                print "But I'll trade it for ";
                print "something to drink. You ";
                "know, to end these shakes.~";
              'shakes':
                slumsDen.knowAboutDrink = true;
                print "~Sometimes the tremors can ";
                print "be bad. They come on with ";
                print "the sweats, but a drink ";
                "would cure 'em.~";
              'farm':
                print "~Yeah. There's a farm to ";
                print "the east";
                if (self.askedGrimes) ".~";
                print ". Old Man Grimes ";
                "would never help me out.~";
              'wife':
                if (self.askedWife) {
                  print "~Look. Don't ask. Do you ";
                  "have anything to drink?~";
                }
                self.askedWife = true;
                print "~What? Grimes's wife? I've ";
                print "heard bad things about him ";
                "and her. Don't ask.~";
              'poor':
                print "~They're always here. No ";
                print "matter what you do, you'll ";
                "never get rid of them.~";
              'den', 'scavenger', 'scavengers', 'scavenger~s', 'tavern', 'inn':
                print "~They don't like me in ";
                print "there. The bartender won't ";
                "even let me in anymore.~";
              'osric', 'bartender':
                print "~Osric is a pain. If you're ";
                print "not paying, you'd better ";
                print "have a good reason to be ";
                print "there. He's thrown me out ";
                "more than once.~";
              'belkor', 'necro', 'necromancer':
                return DrunkRespNecro();
              default:
                return DrunkResponse();
            }
          Tell:
            if (self.talkedTo) {
              self.talkedTo = false;
              return DrunkResponse();
            }
            wn = consult_from;
            w1 = NextWord();
            switch (w1) {
              'den', 'scavenger', 'scavengers', 'scavenger~s', 'tavern', 'inn':
                if (iDrunkResponse==0) iDrunkResponse=1;
                print "~No. They don't like me. ";
                print "Osric chases me out every ";
                "time.~";
              'belkor', 'necro', 'necromancer':
                return DrunkRespNecro();
              default:
                return DrunkResponse();
            }
          default:
            return DrunkResponse();
        ],
        orders [;
          default: return DrunkResponse();
        ],
        askedGrimes false,
        askedWife false,
        askNecro false,
        talkedTo true,
   has  animate;

 [ DrunkResponse;
      slumsDen.knowAboutDrink = true;
      iDrunkResponse++;
      if (iDrunkResponse>3) iDrunkResponse=2;
      switch(iDrunkResponse) {
          1: print "The man stumbles about. ";
             print "~Hey,~ he calls out, ";
             print "~anything to cure these ";
             print "shakes? I'd love some wine ";
             print "from the farm. I ";
             print "haven't had a drink in ";
             "ages.~";
          2: print "~You know, I'm not feeling ";
             print "good,~ the man says, ";
             print "bumbling around. ~Maybe a ";
             "little booze would help.~";
      }
      print "~If only you had something ";
      print "to help stop these shakes, ";
      print "maybe I could return the ";
      print "favor,~ the man says, ";
      "struggling.";
 ];

 [ DrunkRespNecro;
      if (drunk.askNecro) "~No. Don't call him forth.~";
      drunk.askNecro = true;
      if (iDrunkResponse==0) iDrunkResponse=1;
      print "~Oh. Don't mention his ";
      print "name. His power is great. ";
      "Don't call him forth.~";
 ];

 [ GiveDrunk;
      slumsDen.knowAboutDrink = true;
      print "~No. Not that. Do you have ";
      print "anything to drink. I know ";
      print "it'll help with these ";
      "shakes.~";
 ];
