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

}

void Auth::render()
{

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

}

void Auth::updateRender()
{
	switch (init)
	{
	case true:
		window->draw(pwBg);
		window->draw(enterBg);
		window->draw(enterText);
		break;
	case false:
	default:
		break;
	}
}
