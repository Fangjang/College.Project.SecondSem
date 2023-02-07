#ifndef APP_H
#define APP_H

#include"auth.h"
#include"exec.h"
//Debug Codes

//App Class
class App : private Auth, private Exec{
private:
	//Private members
	//Private Functions
	void init();
	void initWindow();
	void initVar();
	void eventUpdate();

	template <typename T> void render(T entity);

	//Private variables
	std::string passWord;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Font font;

	//Enum for App state
	enum class AppState {
		AUTH = 0,
		MENU
	};
	AppState appState;

	//Stuct for buttons
	struct Button {
		sf::RectangleShape button;
		std::string toolTip;
	};
	std::vector<Button> buttons;

	//Struct for texts
	struct Text {
		sf::Text text;
		std::string toolTip;
	};
	std::vector<Text> Texts; 

	/////////////////////////////////////////
	//Test Variable
	sf::RectangleShape enterText;
	sf::RectangleShape Enter;
	std::vector<sf::CircleShape> circles;
	//
public:
	//Public members
	//Public Funtions
	App();
	~App();

	bool isRunning();
	void update();
	void render();

	////////////////////////////////////////////
	//Test Funcs
};

#endif // !APP_H