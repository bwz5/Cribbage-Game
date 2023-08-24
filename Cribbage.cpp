// Cribbage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std; 
using namespace sf; 


struct cards {
    //Textures for Cards 
    Texture aceH;
    Texture twoH;
    Texture threeH; 
    Texture fourH; 
    Texture fiveH;
    Texture sixH; 
    Texture sevenH; 
    Texture eightH;
    Texture nineH;
    Texture tenH;
    Texture jackH;
    Texture queenH;
    Texture kingH; 

    Texture aceD;
    Texture twoD;
    Texture threeD;
    Texture fourD;
    Texture fiveD;
    Texture sixD;
    Texture sevenD;
    Texture eightD;
    Texture nineD;
    Texture tenD;
    Texture jackD;
    Texture queenD;
    Texture kingD;

    Texture aceC;
    Texture twoC;
    Texture threeC;
    Texture fourC;
    Texture fiveC;
    Texture sixC;
    Texture sevenC;
    Texture eightC;
    Texture nineC;
    Texture tenC;
    Texture jackC;
    Texture queenC;
    Texture kingC;

    Texture aceS;
    Texture twoS;
    Texture threeS;
    Texture fourS;
    Texture fiveS;
    Texture sixS;
    Texture sevenS;
    Texture eightS;
    Texture nineS;
    Texture tenS;
    Texture jackS;
    Texture queenS;
    Texture kingS;

    //Sprites for cards 
    Sprite aceH2;
    Sprite twoH2;
    Sprite threeH2;
    Sprite fourH2;
    Sprite fiveH2;
    Sprite sixH2;
    Sprite sevenH2;
    Sprite eightH2;
    Sprite nineH2;
    Sprite tenH2;
    Sprite jackH2;
    Sprite queenH2;
    Sprite kingH2;

    Sprite aceD2;
    Sprite twoD2;
    Sprite threeD2;
    Sprite fourD2;
    Sprite fiveD2;
    Sprite sixD2;
    Sprite sevenD2;
    Sprite eightD2;
    Sprite nineD2;
    Sprite tenD2;
    Sprite jackD2;
    Sprite queenD2;
    Sprite kingD2;

    Sprite aceC2;
    Sprite twoC2;
    Sprite threeC2;
    Sprite fourC2;
    Sprite fiveC2;
    Sprite sixC2;
    Sprite sevenC2;
    Sprite eightC2;
    Sprite nineC2;
    Sprite tenC2;
    Sprite jackC2;
    Sprite queenC2;
    Sprite kingC2;

    Sprite aceS2;
    Sprite twoS2;
    Sprite threeS2;
    Sprite fourS2;
    Sprite fiveS2;
    Sprite sixS2;
    Sprite sevenS2;
    Sprite eightS2;
    Sprite nineS2;
    Sprite tenS2;
    Sprite jackS2;
    Sprite queenS2;
    Sprite kingS2;
    
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Cribbage");

    //card backs 
   
 

    //game beginning class
    //should flip a coin for the deal 
    class game { 
    public:
        //beginning 
        bool dealt = false; 
        bool gameStart = false;
        bool coinChoice = false; 

        //handstuff
        bool cribGiven = false; 

        int middleScore = 0; 

        int playerScore = 0; 
        int oppScore = 0; 

        //vector that keeps the current hand 
        vector<Sprite>playerhand;
        //crib vector
        vector<Sprite>crib; 
        //just helps know which cards are selected for the crib 
        vector<int> cribHand = { 0,0,0,0,0,0 };

        // vector for the middle during peg rounds 
        vector <Sprite> middlecards; 
        vector <Sprite> temphand; 

        sf::Texture cardBacktext;

        void displayScore(RenderWindow& window) {
            Texture scoreText; 
            scoreText.loadFromFile("images/scoreback.png"); 

            Sprite scoreSpritePlayer; 
            scoreSpritePlayer.setTexture(scoreText); 
            scoreSpritePlayer.setPosition(10, 10); 
            scoreSpritePlayer.setScale(0.6, 0.35); 

            Sprite scoreSpriteOpp; 
            scoreSpriteOpp.setTexture(scoreText);
            scoreSpriteOpp.setPosition(10, 330);
            scoreSpriteOpp.setScale(0.6, 0.35);

            window.draw(scoreSpriteOpp);
            window.draw(scoreSpritePlayer); 

            Sprite rightNumP;
            Sprite midNumP; 
            Sprite leftNumP;

            Sprite rightNumO;
            Sprite midNumO;
            Sprite leftNumO;

            //show the score of all the players
            int tempP = playerScore;
            int tempO = oppScore; 

            if (tempP < 10) {
                //right sprite draws single digit for P
            }

            if (tempO < 10) {
                //right sprite draws single digit for O
            }
            while (tempP >= 10) { // takes the modulus to get the smallest digit. then when its less <= 10 just make it that 

            }
        }
        

        void drawBackground(RenderWindow& window) {
            sf::Texture background;
            background.loadFromFile("images/istockphoto-1092139474-612x612.jpg");

            sf::Sprite backgroundSprite;
            backgroundSprite.setTexture(background);

            window.draw(backgroundSprite); 

        }
        void coinflip(RenderWindow &window) {

            Texture headsT;
            Texture tailsT;
            headsT.loadFromFile("images/headschoice.png");
            tailsT.loadFromFile("images/tailschoice.png"); 

            Sprite headsbutton; Sprite tailsbutton; 
            headsbutton.setTexture(headsT); 
            tailsbutton.setTexture(tailsT); 

            headsbutton.setPosition(100, 150);
            tailsbutton.setPosition(300, 150); 
            window.draw(headsbutton);
            window.draw(tailsbutton); 

            //just to load
            cardBacktext.loadFromFile("images/cardbackred.png");
        }
        // generate random number 
        bool flipanswer(RenderWindow& window, bool headsChoice) {
            bool headsTrump = false; 
            int randomNum = rand(); 
            if (randomNum % 2 == 0) {
                headsTrump = true; 
            }
            if (headsChoice == headsTrump) {
                return true; 
            }
            return false; 
        }
        void displaycoinFlipWin(RenderWindow& window, bool hasWon) {
            if (hasWon) {
                Texture dealWon; 
                dealWon.loadFromFile("images/dealwon.png"); 
                Sprite winSprite; 
                winSprite.setTexture(dealWon); 
                winSprite.setPosition(200, 120); 
                winSprite.setScale(0.6, 0.6); 
                window.draw(winSprite); 
            }
            else {
                Texture dealLost;
                dealLost.loadFromFile("images/deallost.png");
                Sprite lossSprite;
                lossSprite.setTexture(dealLost);
                lossSprite.setPosition(200, 120);
                lossSprite.setScale(0.6, 0.6);
                window.draw(lossSprite);
            }
        }
        

        void deal(RenderWindow& window) {
            playerhand.clear(); 

            float x = 100; float y = 280; 
            for (int i = 0; i < 6; i++) {
                sf::Sprite cardBackSprite;
                cardBackSprite.setTexture(this->cardBacktext);
                cardBackSprite.setPosition(x, y); 
                cardBackSprite.setScale(0.1, 0.1); 
                x += 75; 
                window.draw(cardBackSprite); 
                playerhand.push_back(cardBackSprite); 
            }
        }

        void dealOpponent(RenderWindow& window, int len) {
            float x = 100; float y = 10;
            for (int i = 0; i < len; i++) {
                sf::Sprite cardBackSprite;
                cardBackSprite.setTexture(this->cardBacktext);
                cardBackSprite.setPosition(x, y);
                cardBackSprite.setScale(0.1, 0.1);
                x += 75;
                window.draw(cardBackSprite);
            }
        }

        void drawBoard(RenderWindow& window) {
            Texture boardtext; 
            boardtext.loadFromFile("images/cribbageboard.png"); 
            Sprite boardsprite; 
            boardsprite.setTexture(boardtext); 
            boardsprite.setPosition(20, 150);
            boardsprite.setScale(0.3, 0.3); 
            window.draw(boardsprite); 
        }

        void drawHand(RenderWindow& window) {
            int x = 100; int y = 280; 
            for (int i = 0; i < playerhand.size(); i++) {
                Vector2f temp = playerhand[i].getPosition(); 
                playerhand[i].setPosition(x, temp.y); 
                x += 75; 
                window.draw(playerhand[i]);
            }
        }

        void drawCrib(RenderWindow& window) {
            //draws a face down card and removes two cards from the opponents hand 
            sf::Sprite cardBackSprite;
            cardBackSprite.setTexture(this->cardBacktext);
            cardBackSprite.setPosition(520, 150);
            cardBackSprite.setScale(0.1, 0.1);
            window.draw(cardBackSprite); 
        }
        void playCard(RenderWindow& window, Sprite playedcard) {

        }

    };
    //create the new game 
    game newGame;

    //crib button 
    Texture cribText;
    cribText.loadFromFile("images/cribButton.png");
    Sprite cribSprite;
    cribSprite.setTexture(cribText); 
    cribSprite.setScale(0.3, 0.3); 
    cribSprite.setPosition(485,160);

    //play button 
    Texture playText; 
    playText.loadFromFile("images/playButton.png"); 
    Sprite playSprite; 
    playSprite.setTexture(playText); 
    playSprite.setScale(0.3, 0.3);
    playSprite.setPosition(500, 260);

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            //checks if a game has been started 
            if (!newGame.coinChoice) {
                window.clear();
                newGame.drawBackground(window);
                newGame.coinflip(window);
                window.display();
                newGame.coinChoice = true;
            }
            //detects for mouse clicks 
            if (Mouse::isButtonPressed(Mouse::Left) && newGame.coinChoice && !newGame.dealt) {
                //for beginning of the game 
                if (newGame.gameStart == false) {
                    bool headsChoice = true;
                    Vector2i mousepos = Mouse::getPosition();
                    if (mousepos.x >= 300 && mousepos.x <= 550) {
                        if (mousepos.y >= 150) {

                            headsChoice = false;
                        }
                    } 
                    bool winFlip = newGame.flipanswer(window, headsChoice);
                    window.clear();
                    newGame.drawBackground(window);
                    newGame.displaycoinFlipWin(window, winFlip);
                    window.display();
                    newGame.gameStart = true;
                    for (int i = 0; i < 10000; i++) {
                        cout << "stall" << endl;
                    }
                    // now deal the cards 
                    window.clear();
                    newGame.drawBackground(window);
                    newGame.deal(window);
                    newGame.dealOpponent(window, 6);
                    newGame.drawBoard(window); 
                    newGame.displayScore(window); 
                    window.display();
                    for (int i = 0; i < 10000; i++) {
                        cout << "stall2" << endl;
                    }
                    newGame.dealt = true;
                }
            }
            if (Mouse::isButtonPressed(Mouse::Left) && !newGame.cribGiven){
                Vector2i mousepos = Mouse::getPosition(window); 
                for (int i = 0; i < 6; i++) {
                    if (count(newGame.cribHand.begin(), newGame.cribHand.end(), 1) == 2) {
                        continue;
                    }
                    Vector2f cardpos = newGame.playerhand[i].getPosition(); 
                    if (mousepos.x >= cardpos.x && mousepos.x <= cardpos.x + 75) {
                        if (mousepos.y >= cardpos.y && mousepos.y < 400) {
                            //raise the cards up 
                            newGame.playerhand[i].setPosition(cardpos.x, cardpos.y - 30);
                            newGame.cribHand[i] = 1; 
                            window.clear();
                            newGame.drawBackground(window); 
                            newGame.drawBoard(window); 
                            newGame.displayScore(window); 
                            newGame.dealOpponent(window, 6); 
                            newGame.drawHand(window); 
                            window.draw(cribSprite); 
                            window.display(); 
                        }
                    }
                }
                if ((mousepos.x >= 485 && mousepos.x <= 570)&& (mousepos.y >= 160 && mousepos.y <= 200)) {
                   /// put the cards in the crib
                    if (count(newGame.cribHand.begin(), newGame.cribHand.end(), 1) == 2) {
                        cout << "CRIB" << endl;
                        vector<Sprite> temp; 
                        for (int i = 0; i < 6; i++) {
                            if (newGame.cribHand[i] == 0) {
                                temp.push_back(newGame.playerhand[i]); 
                            }
                            else {
                                newGame.crib.push_back(newGame.playerhand[i]); 
                            }
                        }
                        newGame.playerhand.clear(); 
                        newGame.playerhand = temp; 
                        window.clear();
                        newGame.drawBackground(window);
                        newGame.drawBoard(window);
                        newGame.displayScore(window);
                        newGame.dealOpponent(window, 4);
                        newGame.drawHand(window);
                        newGame.drawCrib(window);
                        window.display();
                        newGame.cribGiven = true; 
                        //makes the temp hand the same for the game 
                        newGame.temphand = newGame.playerhand; 
                    } 
                }
            }
            if (Mouse::isButtonPressed(Mouse::Left) && newGame.cribGiven) {
                Vector2i mousepos = Mouse::getPosition(window);
                for (int i = 0; i < newGame.playerhand.size(); i++) {
                    Vector2f cardpos = newGame.playerhand[i].getPosition();
                    if (mousepos.x >= cardpos.x && mousepos.x <= cardpos.x + 75) {
                        if (mousepos.y >= cardpos.y && mousepos.y < 400) {
                            //raise the cards up 
                            newGame.playerhand[i].setPosition(cardpos.x, cardpos.y - 30);
                            window.clear();
                            newGame.drawBackground(window);
                            newGame.drawBoard(window);
                            newGame.displayScore(window);
                            newGame.dealOpponent(window, 4);
                            newGame.drawHand(window);
                            newGame.drawCrib(window);
                            window.draw(playSprite); 
                            window.display();
                        }
                    }
                }
                //make a copy of both hands and then put that into the middle 
                // push the middle cards into a vector 
                if ((mousepos.x >= 500 && mousepos.x <= 570) && (mousepos.y >= 260 && mousepos.y <= 300)) {
                    for (int i = 0; i < newGame.temphand.size(); i++) {
                        Vector2f cardpos = newGame.temphand[i].getPosition();
                        if (cardpos.y != 280) {
                            
                            //play it and push it to the vector, then remove it from the player hand 
                            newGame.middlecards.push_back(newGame.temphand[i]); 
                            newGame.temphand.erase(newGame.temphand.begin() + i, newGame.temphand.begin() + i + 1);
                            break; 
                        }
                    }
                    window.clear();
                    newGame.drawBackground(window);
                    newGame.drawBoard(window);
                    newGame.displayScore(window);
                    newGame.dealOpponent(window, 4);
                    newGame.drawHand(window); // have to draw a new hand now 
                    newGame.drawCrib(window);
                    window.draw(playSprite);
                    window.display();
                }
            }

        }
        
        
        
    }

    return 0;
}
