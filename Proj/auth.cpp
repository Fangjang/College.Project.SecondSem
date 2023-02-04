#pragma once

#include"auth.h"

//Private Fucntions
void Auth::initAuth()
{
	initShapes();
	initTexts();
}

void Auth::initShapes()
{
	//Init password background
	pwBg.setFillColor(sf::Color::White);
	pwBg.setSize(sf::Vector2f(500.f, 50.f));
	pwBg.setPosition(sf::Vector2f(200.f, 350.f));
	pwBg.setOutlineColor(sf::Color::Black);
	pwBg.setOutlineThickness(1.f);

	//Init enterBg background
	enterBg.setFillColor(sf::Color(35, 105, 131, 255));
	enterBg.setSize(sf::Vector2f(150.f, 50.f));
	enterBg.setPosition(sf::Vector2f(710.f, 350.f));
	enterBg.setOutlineColor(sf::Color::White);
}

void Auth::initTexts()
{
	//Init Enter text
	enterText.setFont(*font);
	enterText.setCharacterSize(30);
	enterText.setPosition(sf::Vector2f(enterBg.getPosition().x+25.f, enterBg.getPosition().y+5.f));
	//enterText.setStyle(sf::Text::Bold);
	enterText.setLineSpacing(0.3f);
	enterText.setString("ENTER");

	enterPromptText.setFont(*font);
	enterPromptText.setCharacterSize(45);
	enterPromptText.setPosition(150.f, 200.f);
	enterPromptText.setStyle(sf::Text::Bold);
	enterPromptText.setString("Please enter the password to login");

}

void Auth::render()
{

}

void Auth::checkMouseEvents()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!isMousePressedL)
		{
			isMousePressedL = true;
			if (pwBg.getGlobalBounds().contains(mousePos))
			{
				switch (isEnterTextBoxSelected)
				{
				case true:
					isEnterTextBoxSelected = false;
					break;
				case false:
					isEnterTextBoxSelected = true;
					break;
				default:
					std::cout << "Case err: Auth::checkMouseEvents()" << std::endl;
					break;
				}
			}
			if (enterBg.getGlobalBounds().contains(mousePos))
			{
				MessageBox(NULL, L"Wrong Password. Please Enter the correct Password", L"Error",MB_OK | MB_ICONERROR);
			}
		}
	}
	else
	{
		isMousePressedL = false;
	}
}

void Auth::updateMousePos()
{
	mousePos.x = sf::Mouse::getPosition(*window).x;
	mousePos.y = sf::Mouse::getPosition(*window).y;
}

//Public Functions
void Auth::Authenticate(sf::RenderWindow* window, sf::Font& font)
{
	switch (init)
	{
	case false:
		init = true;
		this->window = window;
		this->font = &font;
		this->isMousePressedL = false;
		this->isEnterTextBoxSelected = false;
		initAuth();
		break;
	case true:
		update();
	default:
		break;
	}
}

void Auth::update()
{
	checkMouseEvents();
	updateMousePos();
	DEBUG();
}

void Auth::DEBUG()
{
	system("cls");
	std::cout << mousePos.x << " ||||||||| " << mousePos.y << std::endl;
	std::cout << "isMousePressedL: " << isMousePressedL << std::endl;
	std::cout << "isEnterTextBoxSelected: " << isEnterTextBoxSelected << std::endl;
}

void Auth::updateRender()
{
	switch (init)
	{
	case true:
		window->draw(pwBg);
		window->draw(enterBg);
		window->draw(enterPromptText);
		window->draw(enterText);
		break;
	case false:
	default:
		break;
	}
}
