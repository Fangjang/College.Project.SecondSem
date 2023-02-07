#include "exec.h"
#pragma once

//Private functions
void Exec::initTextBoxes()
{
	textBoxes.push_back(TextBox(this->window, this->font));
}

//Public Functions
void Exec::init(sf::RenderWindow* window, sf::Font* font)
{
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
	for (auto& i : textBoxes)
	{
		i.update();
	}
}

void Exec::pollEvents()
{

}

void Exec::draw()
{
	for (auto& i : textBoxes)
	{
		i.draw();
	}
}
