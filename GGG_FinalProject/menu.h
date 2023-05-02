#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <vector>

#define MENUSIZE 3
#define OPTIONMENUSIZE 4
using namespace std;
using namespace sf;
//this is in .h file
class menu
{
public:
	menu(float width, float hight);
	void draw(RenderWindow& window);
	void draw2(RenderWindow& window);
	void moveUp();
	void moveDown();
	
	int mainMenuPressed()
	{
		return mainMenuSelected;
	}

	int optionsMenuPressed()
	{
		return optionsMenuSelected;
	}

	~menu();
private:
	int mainMenuSelected, optionsMenuSelected;
	Font font;
	Text mainMenu[MENUSIZE], optionsMenu[OPTIONMENUSIZE];
};

