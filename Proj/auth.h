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
	void checkMouseEvents();
	void updateMousePos();
	void DEBUG();

	//Private Variables
	sf::RenderWindow *window;
	sf::Font *font;

	sf::Vector2f mousePos;
	bool isMousePressedL;

	sf::RectangleShape pwBg;
	sf::RectangleShape enterBg;
	std::vector<sf::RectangleShape> drawableRect;

	//Enter button text
	sf::Text enterText;

	//Auth prompt screen text
	sf::Text enterPromptText;

	//Text for Entered Password 
	//and bool is its clicked and selected
	sf::Text enteredPass;
	bool isEnterTextBoxSelected;


//Protected members
protected:
	//Protected members
	void Authenticate(sf::RenderWindow* window, sf::Font& font);
	void update();
	void updateRender();
	
	//Protected variables
	bool init = false;
};