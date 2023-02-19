#pragma once
#include "exec.h"

//Private functions
void Exec::initTextBoxes()
{
	textBox = new TextBox(window, font);
	textBox->setPosition(sf::Vector2f(100.f, 100.f));
	textBox->changeTextPos(sf::Vector2f(5.f, 5.f));
	textBox->setSize(sf::Vector2f(400.f, 50.f));
	textBox->setFontSize(29);
	textBoxes.push_back(*textBox);
}

//Public Functions
void Exec::init(sf::RenderWindow* window, sf::Font* font)
{
	this->started = true;
	this->window = window;
	this->font = font;
	initTextBoxes();
}

bool Exec::getStarted()
{
	return started;
}

void Exec::update()
{
	textBox->update();
}

void Exec::pollEvents()
{

}

void Exec::draw()
{
	textBox->draw();
}
