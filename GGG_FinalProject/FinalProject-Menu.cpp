// FinalProject-Menu.cpp
#include "menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace sf;

int page_number = -1;
int mapDecicion = 1;
float offSetX = 0;
float offSetY = 0;
int CoinCount = 0;
bool isDead = false;
bool isWon = false;
bool isKeyFound = false;


const int H = 22;
const int W = 70;

//G = Ground
//W = Wall
//C = Coin to collect
//S = Spike to kill player
//P = Platform
//U = touch to win
//K = Key for win

String TileMapOG1[H] = {

"000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                   0",
"0                                    C                              0",
"0                                 P PP                              0",
"0                               C       C C C                       0",
"0                            C  C       PP  P                       0",
"0                       C    PPPP             S C C                 0",
"0                     PPPP                    PPPPP                 0",
"0          K      C                                                 0",
"0               PPPP         C  C   C    C                          0",
"0              P          SSS SS SSS SSSS SS                    CCCU0",
"0                                                            PPPPPPP0",
"0        C C                                          C C C         0",
"0        PPP                                          PPPPP         0",
"0              C S C                           C   C         C      0",
"0              PPPPP                         SS SSS SSSSS SSS SSS   0",
"0                     C C C                                         0",
"0                       PPP                                         0",
"0                             C C C                                 0",
"0                            PPPP P                                 0",
"0           CCC   S    CCC   S                                      0",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",

};

String TileMapOG2[H] = {

"000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                   0",
"0                                    C                              0",
"0                                 P PP                              0",
"0                               C       C C C                       0",
"0                            C  C       PP  P                       0",
"0                       C    PPPP             S C C                 0",
"0                     PPPP                    PPPPP                 0",
"0          K      C                                                 0",
"0               PPPP         C  C   C    C                          0",
"0              P          SSS SS SSS SSSS SS                    CCCU0",
"0                                                             PPPPPP0",
"0        C C                                          C C C         0",
"0        PPP                                          P   P         0",
"0              C S C                           C   C         C      0",
"0              PPPPP                         S  SS  SSSSS SSS SSS   0",
"0                     C C C                                         0",
"0                       PPP                                         0",
"0                             C C C                                 0",
"0                            P                                      0",
"0           CCC   S    CCC   S                                      0",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
};

String TileMapOG3[H] = {

"000000000000000000000000000000000000000000000000000000000000000000000",
"0          C              C                C                    K   0",
"0                  C            C                               P   0",
"0 PPPPPP PPPP  PPP  PPPP PPP  PPPP P          C              PP     0",
"0                  P                                   PPP          0",
"0            PP        PPP        C              PPP             C  0",
"0                           C                                    P  0",
"0               C           PP      CC       PPP               C    0",
"0      PP               CC    PP     PPPP                      PP   0",
"0               PPP             P                            C      0",
"0                              CC               C         PP        0",
"0          C         PP PP                     PPP                  0",
"0   C         PPP                 PP                  PP            0",
"0   P   C                C                                          0",
"0       P       C  PP          PPP      C                           0",
"0                C        C          PPPPPP        C                0",
"0             PP  PPPP  PPP                P     PPPPP              0",
"0         P                      PP                                 0",
"0     U                                                             0",
"0     P                                                             0",
"0  SSSSSSSSS SSSSSSS SSSSSSSSSSSSSSS SSSSSSSSS SSSSSSSS SSSSSSSSS   0",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",

};

String TileMapOG4[H] = {

"000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                   0",
"0                                    C                              0",
"0                                 P PP                              0",
"0                               C       C C C          K            0",
"0                            C  C       PP  P                       0",
"0                      S    PPPP             S C C  P               0",
"0                     PPPP                    PPPPP                 0",
"0                SC                                                 0",
"0               PPPP         C  C   C    C                          0",
"0      U   P             SSS SS SSS SSSS SS            P       CCC  0",
"0       P                                                    P P P P0",
"0 SCCS    C C                                          C C C        0",
"0 SCCS    PPP                                            P P        0",
"0 SCCS          C S C   P  P  P   P             C   C  P      C     0",
"0 SCCS          PPPPP                         S  SS  SSSSS SSS SSS  0",
"0 SCCS               P     C   C C   C                              0",
"0 SCCS                   C                P                         0",
"0 SCCS                     P  P  P   P   P                          0",
"0  CC                   P C                                         0",
"0       SC CS C   S          C  C                                   0",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",

};

String TileMap[H] = {

"000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                   0",
"0                                    C                              0",
"0                                 P PP                              0",
"0                               C       C C C                       0",
"0                            C  C       PP  P                       0",
"0                       C    PPPP             S C C                 0",
"0                     PPPP                    PPPPP                 0",
"0          K      C                                                 0",
"0               PPPP         C  C   C    C                          0",
"0              P          SSS SS SSS SSSS SS                    CCCU0",
"0                                                            PPPPPPP0",
"0        C C                                          C C C         0",
"0        PPP                                          PPPPP         0",
"0              C S C                           C   C         C      0",
"0              PPPPP                         SS SSS SSSSS SSS SSS   0",
"0                     C C C                                         0",
"0                       PPP                                         0",
"0                             C C C                                 0",
"0                            PPPP P                                 0",
"0           CCC   S    CCC   S                                      0",
"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",

};




class Player {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	// creates a rectangle around the sprite
	Player(Texture& image)
	{
		sprite.setTexture(image);
		sprite.setScale(0.5f, 0.5f);
		rect = FloatRect(1 * 32, 1 * 32, 36, 47);

		dx = dy = 0.1;
		currentFrame = 0;
	}

	//movement bases on FPS
	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);

		if (!onGround)
			dy = dy + 0.0005 * time;

		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += 0.005 * time;
		if (currentFrame > 6)
			currentFrame -= 6;

		if (dx > 0)
			sprite.setTextureRect(IntRect(72 * int(currentFrame), 0, 72, 93));
		if (dx < 0)
			sprite.setTextureRect(IntRect(72 * int(currentFrame) + 72, 0, -72, 93));


		sprite.setPosition(rect.left - offSetX, rect.top - offSetY);

		dx = 0;
	}


	//gravity and collision function
	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'B' || TileMap[i][j] == 'G' || TileMap[i][j] == 'P' || TileMap[i][j] == '0')
				{
					if ((dx > 0) && (dir == 0))
						rect.left = j * 32 - rect.width;
					if ((dx < 0) && (dir == 0))
						rect.left = j * 32 + 32;
					if ((dy > 0) && (dir == 1))
					{
						rect.top = i * 32 - rect.height;
						dy = 0;
						onGround = true;
					}
					if ((dy < 0) && (dir == 1))
					{
						rect.top = i * 32 + 32;
						dy = 0;
					}
				}

				if (TileMap[i][j] == 'C')
				{
					TileMap[i][j] = ' ';
					CoinCount++;
				}

				if (TileMap[i][j] == 'S')
				{
					isDead = true;
				}

				if (TileMap[i][j] == 'U')
				{
					if (isKeyFound == true)
						isWon = true;
				}

				if (TileMap[i][j] == 'K')
				{
					TileMap[i][j] = ' ';
					isKeyFound = true;	
				}

			}

	}
};

int main()
{
	while (true)
	{
		//main menu
		float videoWidth, videoHeight;
		videoWidth = 1920;
		videoHeight = 1080;

		menu mainMenu(videoWidth, videoHeight);
		menu options(videoWidth, videoHeight);
		RenderWindow window(VideoMode(videoWidth, videoHeight), "Green Boi in Space");

		Font font2;
		if (!font2.loadFromFile("KOMIKAP_.ttf"))
			return EXIT_FAILURE;
		Text GameTitleText("Green Boi in Space", font2, 50);
		GameTitleText.setPosition(730, 150);
		GameTitleText.setFillColor(Color::Red);

		//BACKGROUND
		Texture background;
		if (!background.loadFromFile("MenuBackground.jpg"))
			return EXIT_FAILURE;
		Sprite backgroundSprite(background);

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					page_number = 2;
					window.close();
				}
				if (event.type == Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						mainMenu.moveUp();
						break;
					}
					else if (event.key.code == Keyboard::Down)
					{
						mainMenu.moveDown();
						break;
					}
					else if (event.key.code == Keyboard::Return)
					{
						if (mainMenu.mainMenuPressed() == 0)
						{
							window.close();
							page_number = 0;
						}
						if (mainMenu.mainMenuPressed() == 1)
						{
							window.close();
							page_number = 1;
						}
						if (mainMenu.mainMenuPressed() == 2)
						{
							window.close();
							page_number = 2;
						}
					}
				}
			}

			window.clear();
			window.draw(backgroundSprite);
			mainMenu.draw(window);
			window.draw(GameTitleText);
			window.display();
		}
		if (page_number == 0)
		{
			RenderWindow window_playGame(VideoMode(600, 600), "Game");

			Texture playerTexture;
			if (!playerTexture.loadFromFile("p1_walk.png"))
				return EXIT_FAILURE;

			Texture* groundTexture = new Texture;
			if (!groundTexture->loadFromFile("metal.png"))
				return EXIT_FAILURE;

			Texture* wallTexture = new Texture;
			if (!wallTexture->loadFromFile("WallToUse.png"))
				return EXIT_FAILURE;

			Texture* coinTexture = new Texture;
			if (!coinTexture->loadFromFile("GoldenCoin.png"))
				return EXIT_FAILURE;

			Texture* spinnerTexture = new Texture;
			if (!spinnerTexture->loadFromFile("spinner.png"))
				return EXIT_FAILURE;

			Texture* platformTexture = new Texture;
			if (!platformTexture->loadFromFile("beam.png"))
				return EXIT_FAILURE;

			Texture* winFlagTexture = new Texture;
			if (!winFlagTexture->loadFromFile("flagRed.png"))
				return EXIT_FAILURE;

			Texture transparentkeyTexture;
			if (!transparentkeyTexture.loadFromFile("KeyNotFound.png"))
				return EXIT_FAILURE;
			Sprite keyDisplaySprite;
			keyDisplaySprite.setTexture(transparentkeyTexture);
			keyDisplaySprite.setScale(0.6f, 0.6f);
			keyDisplaySprite.setPosition(0, 85);

			Texture keyFoundTexture2;
			if (!keyFoundTexture2.loadFromFile("KeyFound.png"))
				return EXIT_FAILURE;

			Texture* keyFoundTexture = new Texture;
			if (!keyFoundTexture->loadFromFile("KeyFound.png"))
				return EXIT_FAILURE;

			Texture* background2 = new Texture;
			if (!background2->loadFromFile("gameBackground.png"))
				return EXIT_FAILURE;
			RectangleShape backgroundSprite2;
			backgroundSprite2.setTexture(background2);
			backgroundSprite2.setSize(Vector2f(600, 600));

			

			Font font;
			if (!font.loadFromFile("KOMIKAP_.ttf"))
				return EXIT_FAILURE;
			Text amountOfCoins(std::to_string(CoinCount), font, 50);
			amountOfCoins.setPosition(0, 20);

			Text endMessage(" ", font, 30);
			endMessage.setFillColor(Color::Red);
			endMessage.setPosition(10, 150);

			float currentFrame = 0;

			Player playerSprite(playerTexture);

			Clock clock;
			Clock CountDownClock;
			int timeLeft = 120;
			int timeElapsed = 120;
			Text finalCountDown(" ", font, 50);
			finalCountDown.setPosition(250, 0);
			Time time2;
			

			RectangleShape rectangle(Vector2f(32, 32));

			if (mapDecicion == 1)
			{
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < W; j++)
					{
						TileMap[i][j] = TileMapOG1[i][j];
					}
				}
			}
			else if (mapDecicion == 2)
			{
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < W; j++)
					{
						TileMap[i][j] = TileMapOG2[i][j];
					}
				}
			}
			else if (mapDecicion == 3)
			{
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < W; j++)
					{
						TileMap[i][j] = TileMapOG3[i][j];
					}
				}
			}
			else if (mapDecicion == 4)
			{
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < W; j++)
					{
						TileMap[i][j] = TileMapOG4[i][j];
					}
				}
			}
			
			while (window_playGame.isOpen())
			{
				if (isWon == false)
				{		
					
					if (timeElapsed > 0)
					{
						time2 = CountDownClock.getElapsedTime();
						timeElapsed = timeLeft - time2.asSeconds();
						//timeLeft -= time2.asSeconds();
						finalCountDown.setString(std::to_string(timeElapsed));
					}
					if (timeElapsed == 0)
						isDead = true;
					if (isDead == false)
					{
						float time = clock.getElapsedTime().asMicroseconds();
						clock.restart();

						time = time / 700;

						if (time > 20) time = 20;

						Event event;
						while (window_playGame.pollEvent(event))
						{
							if (event.type == Event::Closed)
							{
								page_number = -1;
								window_playGame.close();
							}
						}

						if (Keyboard::isKeyPressed(Keyboard::Left))
						{
							playerSprite.dx = -0.1;
						}

						if (Keyboard::isKeyPressed(Keyboard::Right))
						{
							playerSprite.dx = 0.1;
						}

						if (Keyboard::isKeyPressed(Keyboard::Up))
						{
							if (playerSprite.onGround)
							{
								playerSprite.dy = -0.35;
								playerSprite.onGround = false;
							}
						}

						playerSprite.update(time);

						if (playerSprite.rect.left > 300)
							offSetX = playerSprite.rect.left - 300;
						offSetY = playerSprite.rect.top - 200;

						window_playGame.clear();
						window_playGame.draw(backgroundSprite2);


						for (int i = 0; i < H; i++)
							for (int j = 0; j < W; j++)
							{
								if (TileMap[i][j] == 'B')
									rectangle.setTexture(wallTexture);
								else if (TileMap[i][j] == 'G')
									rectangle.setTexture(groundTexture);
								else if (TileMap[i][j] == 'C')
									rectangle.setTexture(coinTexture);
								else if (TileMap[i][j] == 'S')
									rectangle.setTexture(spinnerTexture);
								else if (TileMap[i][j] == '0')
									rectangle.setTexture(wallTexture);
								else if (TileMap[i][j] == 'P')
									rectangle.setTexture(platformTexture);
								else if (TileMap[i][j] == 'U')
									rectangle.setTexture(winFlagTexture);
								else if (TileMap[i][j] == 'K')
									rectangle.setTexture(keyFoundTexture);
								else if (TileMap[i][j] == ' ')
									continue;

								rectangle.setPosition(j * 32 - offSetX, i * 32 - offSetY);
								window_playGame.draw(rectangle);
							}

						window_playGame.draw(playerSprite.sprite);
						amountOfCoins.setString(std::to_string(CoinCount));
						if (isKeyFound == false)
							window_playGame.draw(keyDisplaySprite);
						else
						{
							keyDisplaySprite.setTexture(keyFoundTexture2);
							window_playGame.draw(keyDisplaySprite);
						}
						window_playGame.draw(amountOfCoins);
						window_playGame.draw(finalCountDown);
						
						window_playGame.display();
					}
					else
					{
						if (timeElapsed <= 0)
						{
							window_playGame.clear();
							endMessage.setString("YOU ARE OUT OF TIME \nCOINS COLLECTED: " + std::to_string(CoinCount) + "\nBETTER LUCK NEXT TIME" + "\nPress Esc TO GO TO MAIN MENU");
							window_playGame.draw(endMessage);
							window_playGame.display();
							if (Keyboard::isKeyPressed(Keyboard::Escape))
							{
								page_number = -1;
								isDead = false;
								isWon = false;
								isKeyFound = false;
								CoinCount = 0;
								offSetX = 0;
								offSetY = 0;
								CountDownClock.restart();
								window_playGame.close();
							}
						}
						else
						{
							window_playGame.clear();
							endMessage.setString("YOU ARE DEAD \nCOINS COLLECTED: " + std::to_string(CoinCount) + "\nBETTER LUCK NEXT TIME" + "\nPress Esc TO GO TO MAIN MENU");
							window_playGame.draw(endMessage);
							window_playGame.display();
							if (Keyboard::isKeyPressed(Keyboard::Escape))
							{
								page_number = -1;
								isDead = false;
								isWon = false;
								isKeyFound = false;
								CoinCount = 0;
								offSetX = 0;
								offSetY = 0;
								CountDownClock.restart();
								window_playGame.close();
							}
						}
					}
				}
				else
				{
					window_playGame.clear();
					endMessage.setFillColor(Color::Yellow);
					endMessage.setString("YOU HAVE WON \nCOINS COLLECTED: " + std::to_string(CoinCount) + "\nPress Esc TO GO TO MAIN MENU");
					window_playGame.draw(endMessage);
					window_playGame.display();
					if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
						page_number = -1;
						isDead = false;
						isWon = false;
						isKeyFound = false;
						CoinCount = 0;
						offSetX = 0;
						offSetY = 0;
						CountDownClock.restart();
						window_playGame.close();
					}
				}
			}
	
		}
		if (page_number == 1)
		{
			//options menu 
			RenderWindow window_gameOpt(VideoMode(videoWidth, videoHeight), "Maps");

			while (window_gameOpt.isOpen())
			{
				Event event;
				while (window_gameOpt.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window_gameOpt.close();

					if (event.type == Event::KeyReleased)
					{
						if (event.key.code == Keyboard::Up)
						{
							options.moveUp();
							break;
						}
						else if (event.key.code == Keyboard::Down)
						{
							options.moveDown();
							break;
						}
						else if (event.key.code == Keyboard::Return)
						{
							if (options.optionsMenuPressed() == 0)
							{
								mapDecicion = 1;
								window_gameOpt.close();
							}
							if (options.optionsMenuPressed() == 1)
							{
								mapDecicion = 2;
								window_gameOpt.close();
							}
							if (options.optionsMenuPressed() == 2)
							{
								mapDecicion = 3;
								window_gameOpt.close();
							}
							if (options.optionsMenuPressed() == 3)
							{
								mapDecicion = 4;
								window_gameOpt.close();
							}
						}
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					break;
				}

				window_gameOpt.clear();
				window_gameOpt.draw(backgroundSprite);
				options.draw2(window_gameOpt);
				window_gameOpt.display();
			}
		}
		if (page_number == 2)
		{
			//exit
			break;
		}
	}
	return 0;

}

