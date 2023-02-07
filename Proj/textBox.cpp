#pragma once

#include"directives.h"
#include"textBox.h"	

//Private Fucntions
//Initializes the text box
void TextBox::initTextBox()
{
	textBg.setFillColor(sf::Color::White);
	textBg.setSize(sf::Vector2f(60.f, 100.f));
}

//Initializes the text
void TextBox::initText()
{
	textBox.setFont(*font);
	textBox.setFillColor(sf::Color::Black);
	textBox.setCharacterSize(16);
	textBox.setString("Text Here");
	textBox.setString("Text Here");

	text.str() = "Text Here";
}

//Checks for the mouse click events
void TextBox::clickEvents()
{
	//Checks if the mouse has clicked the text box
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!mouseClicked)
		{
			mouseClicked = true;
			if (textBg.getGlobalBounds().contains(mosPos))
			{
				switch (selected)
				{
				case true:
					selected = false;
					break;
				case false:
					selected = true;
					break;
				default:
					std::cout << "Case err: TextBox::clickText()" << std::endl;
					break;
				}
			}
			else
			{
				selected = false;
			}
		}
	}
	else
	{
		mouseClicked = false;
	}
	//Highlights the box if its selected i.e clicked on
	if (selected)
	{
		textBg.setOutlineColor(sf::Color::Blue);
		textBg.setOutlineThickness(3.f);
	}
	else if (!selected)
	{
		textBg.setOutlineColor(sf::Color::White);
		textBg.setOutlineThickness(1.f);
	}
}

void TextBox::updateMosPos()
{
	mosPos.x = sf::Mouse::getPosition().x;
	mosPos.y = sf::Mouse::getPosition().y;
}

//Public Functions
//Constructor
TextBox::TextBox(sf::RenderWindow* window, sf::Font* fnt)
{
	this->window = window;
	this->font = fnt;
	initTextBox();
	initText();
}

//Destructor
TextBox::~TextBox()
{

}

void TextBox::update()
{
	updateMosPos();
	clickEvents();
}

//Sets the position for the text box
void TextBox::setPosition(sf::Vector2f pos)
{

}

//Return the position of the text box
sf::Vector2f TextBox::getPosition()
{
	return textBg.getPosition();
}

void TextBox::draw()
{
	window->draw(textBg);
	window->draw(textBox);
}