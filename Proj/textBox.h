#pragma once

#include"directives.h"

class TextBox {
private:
	//Private memebers
	//Private Functions
	void initTextBox();
	void hoverEffect();
	//Render window related varibles
	sf::RenderWindow* window;
	sf::Event *ev;
	sf::Font *font;
	sf::Color colorDefault;
	sf::Color colorHover;
	//Texts Box
	sf::RectangleShape textBg;

	//Texts
	sf::Text textBox;
	std::ostringstream text;

public:
	//Public memebers
	//Public functions
	//COnstructors and destructors
	TextBox(sf::RenderWindow* window, sf::Event* ev, sf::Font* font);
	~TextBox();

};