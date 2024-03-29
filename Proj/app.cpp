#pragma	once
#include"app.h"

////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////Private Functions
void App::init()
{
	font.loadFromFile("./sansation.ttf");
}

void App::initWindow()
{
	videoMode = sf::VideoMode(1000, 800);
	window = new sf::RenderWindow(videoMode, "App", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

void App::initVar()
{

}

void App::eventUpdate()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			exit(0);
			break;
		case sf::Event::TextEntered:
			Auth::pollEv(&(this->ev));
			break;
		default:
			break;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt))
	{
		ShowWindow(window->getSystemHandle(), SW_MINIMIZE);
	}
}

//For drawing any shapes
template <typename T>
void App::render(T entity)
{
	window->draw(entity);
}

////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////Public Functions
//
//Constructor and destructor
App::App() : appState(AppState::AUTH)
{
	init();
	initWindow();
	initVar();
}
//Destructor
App::~App()
{
	delete window;
}

//Returns if the render window is open
bool App::isRunning()
{
	return window->isOpen();
}

//Updates the app cycle
void App::update()
{
	eventUpdate();
	if (Auth::checkAuth() == true)
	{
		appState = AppState::MENU;
	}
	switch (appState)
	{
	case App::AppState::AUTH:
	{
		switch (Auth::init)
		{
		case false:
			Auth::Authenticate(this->window,this->font);
			break;
		case true:
			Auth::update();
		default:
			break;
		}
		break;
	}
	case App::AppState::MENU:
		switch (Exec::getStarted())
		{
		case false:
			Exec::init(window, &font);
			break;
		case true:
			std::cout << "Exec Update" << std::endl;
			Exec::update();
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

//Renders all the objects
void App::render()
{
	window->clear(sf::Color(59,61,63, 255));

	switch (appState)
	{
	case App::AppState::AUTH:
		Auth::updateRender();
		break;
	case App::AppState::MENU:
		Exec::draw();
		system("cls");
		std::cout << "AppState::Menu" << std::endl;
		break;
	default:
		break;
	}

	window->display();
}