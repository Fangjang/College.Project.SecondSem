#pragma once
#include"directives.h"

//Authentication Class
class Auth {
//Private Members
private:
	std::string PASSWORD = "fangjang";
	//Private Functions
	bool isPassCorrect();
	void checkPass();
	void initAuth();
	void initShapes();
	void initTexts();
	void render();
	void checkMouseEvents();
	void checkKeyEvents();
	void updateMousePos();
	void updateTextBox();
	void inputLogic(int charTyped);
	void deleteLastChar();
	void setSelected();
	void typedOn(sf::Event input);
	void DEBUG();

	//Private Variables
	sf::RenderWindow *window;
	sf::Font *font;

	sf::Vector2f mousePos;
	bool isMousePressedL;

	sf::RectangleShape pwBg;
	sf::RectangleShape enterBg;
	sf::RectangleShape enterBgAlpha;
	bool enterHovered = false;;
	std::vector<sf::RectangleShape> drawableRect;

	//Enter button text
	sf::Text enterText;

	//Auth prompt screen text
	sf::Text enterPromptText;

	//Text for Entered Password 
	//and bool is its clicked and selected
	sf::Text enteredPass;
	std::ostringstream enteredPassStream;
	bool isEnterTextBoxSelected;
	int passLimit = 34;

//Protected members
protected:
	//Protected members
	void Authenticate(sf::RenderWindow* window,sf::Font& font);
	void update();
	void pollEv(sf::Event *tempEvent);
	void updateRender();
	
	//Protected variables
	bool init = false;
};