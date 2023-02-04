#pragma once
#include"directives.h"

//Authentication Class
class Auth {
//Private Members
private:
	//Private Functions
	void initAuth();
	void initShapes();
	void initTexts();
	void render();

	//Private Variables
	sf::RenderWindow *window;
	sf::Font *font;

	sf::RectangleShape pwBg;
	sf::RectangleShape enterBg;
	std::vector<sf::RectangleShape> drawableRect;

	sf::Text enterText;
	sf::Text enterPromptText;


//Protected members
protected:
	//Protected members
	void Authenticate(sf::RenderWindow* window, sf::Font& font);
	void update();
	void updateRender();
	
	//Protected variables
	bool init = false;
};