#pragma once

#include"directives.h"
#include"textBox.h"	

//Private Fucntions
void TextBox::initTextBox()
{
	textBox.setFillColor(sf::Color::White);
	textBox.setCharacterSize(16);
	textBox.setString("Text Here");
}

void TextBox::hoverEffect()
{

}



//Public Functions
TextBox::TextBox(sf::RenderWindow* window, sf::Event* ev, sf::Font* fnt, sf::Color )
{
	this->window = window;
	this->ev = ev;
	this->font = font;
	initTextBox();
}

TextBox::~TextBox()
{
	delete window;
	delete ev;
	delete font;
}
