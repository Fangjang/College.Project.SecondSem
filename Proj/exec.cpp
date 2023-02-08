#include "exec.h"
#pragma once

//Private functions
void Exec::initTextBoxes()
{
	textBox = new TextBox(window, font);
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
