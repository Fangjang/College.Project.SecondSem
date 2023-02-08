#pragma once

#include"directives.h"

class TextBox {
private:
	//Private memebers
	//Private Functions
	void initTextBox();
	void initText();
	void clickEvents();
	void updateMosPos();
	//Render window related varibles
	sf::RenderWindow* window;
	sf::Event *ev;
	sf::Font *font;

	//Variables
	bool mouseClicked = false;
	bool selected = false;
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	sf::Vector2f mosPos;

	//Texts Box
	sf::RectangleShape textBg;
	//Texts
	sf::Text textFront;
	std::string text;

public:
	//Public memebers
	//Public functions
	//COnstructors and destructors
	TextBox(sf::RenderWindow* window, sf::Font* font);
	~TextBox();

	void update();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	void draw();
};