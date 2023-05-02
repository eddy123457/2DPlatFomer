#include "mainMenu.h"

//this is in additional .cpp file
Menu::Menu(float width, float hight)
{
	if (!font.loadFromFile("arial.ttf")) {}

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(sf::Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, hight / (mainMenu + 1))); //this line is incorrect

	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(width / 2 - 50, hight / (mainMenu + 1) * 2)); //this line is incorrect

	//exit
	mainMenu[2].setFont(font);
	mainMenu[2].setColor(sf::Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(sf::Vector2f(width / 2 - 50, hight / (mainMenu + 1) * 3)); //this line is incorrect

	mainMenuSelected = 0;
}
Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void Menu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu) //check if not on the last item in the list (aka exit){
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White); //change the color when it is selected

		mainMenuSelected++; //moves to the next item
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}//end if
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue); //change selected color
	}
}

void Menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1) //check if not on the last item in the list (aka exit){
	{
		mainMenu[mainMenuSelected].setColor(sf::Color::White); //change the color when it is selected

		mainMenuSelected--; //moves to the next item
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}//end if
		mainMenu[mainMenuSelected].setColor(sf::Color::Blue); //change selected color
	}
}
