#pragma once
#include"directives.h"
#include"textBox.h"
#include"button.h"

class Exec {
private:
	//Private members
	//Private Functions
	void initTextBoxes();
	sf::RenderWindow* window;
	sf::Font* font;

	//Variables
	bool started = false;
	std::vector<TextBox> textBoxes;
	std::vector<Button> buttons;

public:
	//Public members
	void init(sf::RenderWindow* window, sf::Font* font);
	bool getStarted();
	void update();
	void pollEvents();
	void draw();
};