#include "menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace sf;


//this is in additional .cpp file
menu::menu(float width, float hight)
{
	if (!font.loadFromFile("arial.ttf")) {}

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1))); //this line is incorrect

	//options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Red);
	mainMenu[1].setString("Maps");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1) * 1.5)); //this line is incorrect

	//exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Red);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1) * 2)); //this line is incorrect

	mainMenuSelected = 0;
	optionsMenuSelected = 0;

	//map1
	optionsMenu[0].setFont(font);
	optionsMenu[0].setFillColor(Color::Blue);
	optionsMenu[0].setString("Map 1");
	optionsMenu[0].setCharacterSize(50);
	optionsMenu[0].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1)));

	//map2
	optionsMenu[1].setFont(font);
	optionsMenu[1].setFillColor(Color::Red);
	optionsMenu[1].setString("Map 2");
	optionsMenu[1].setCharacterSize(50);
	optionsMenu[1].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1) * 1.5));

	//map3
	optionsMenu[2].setFont(font);
	optionsMenu[2].setFillColor(Color::Red);
	optionsMenu[2].setString("Map 3");
	optionsMenu[2].setCharacterSize(50);
	optionsMenu[2].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1) * 2));

	//map4
	optionsMenu[3].setFont(font);
	optionsMenu[3].setFillColor(Color::Red);
	optionsMenu[3].setString("Map 4");
	optionsMenu[3].setCharacterSize(50);
	optionsMenu[3].setPosition(Vector2f(width / 2 - 50, hight / (MENUSIZE + 1) * 2.5));

}
menu::~menu()
{

}

void menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void menu::draw2(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(optionsMenu[i]);
	}
}

void menu::moveDown()
{
	if (mainMenuSelected + 1 <= MENUSIZE) //check if not on the last item in the list (aka exit){
	{
		mainMenu[mainMenuSelected].setFillColor(Color::Red); //change the color when it is selected

		mainMenuSelected++; //moves to the next item
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}//end if
		mainMenu[mainMenuSelected].setFillColor(Color::Blue); //change selected color
	}

	if (optionsMenuSelected + 1 <= OPTIONMENUSIZE) //check if not on the last item in the list (aka exit){
	{
		optionsMenu[optionsMenuSelected].setFillColor(Color::Red); //change the color when it is selected

		optionsMenuSelected++; //moves to the next item
		if (optionsMenuSelected == 4)
		{
			optionsMenuSelected = 0;
		}//end if
		optionsMenu[optionsMenuSelected].setFillColor(Color::Blue); //change selected color
	}
}

void menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1) //check if not on the last item in the list (aka exit){
	{
		mainMenu[mainMenuSelected].setFillColor(Color::Red); //change the color when it is selected

		mainMenuSelected--; //moves to the next item
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}//end if
		mainMenu[mainMenuSelected].setFillColor(Color::Blue); //change selected color
	}

	if (optionsMenuSelected + 1 >= -1) //check if not on the last item in the list (aka exit){
	{
		optionsMenu[optionsMenuSelected].setFillColor(Color::Red); //change the color when it is selected

		optionsMenuSelected--; //moves to the next item
		if (optionsMenuSelected == -1)
		{
			optionsMenuSelected = 3;
		}//end if
		optionsMenu[optionsMenuSelected].setFillColor(Color::Blue); //change selected color
	}
}

