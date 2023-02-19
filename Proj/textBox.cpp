#pragma once

#include"directives.h"
#include"textBox.h"	

//Private Fucntions
//Initializes the text box
void TextBox::initTextBox()
{
	textBg.setFillColor(sf::Color::White);
	textBg.setSize(sf::Vector2f(150.f, 60.f));
}

//Initializes the text
void TextBox::initText()
{
	textFront.setFont(*font);
	textFront.setFillColor(sf::Color::Black);
	textFront.setCharacterSize(16);
	textFront.setString("Text Here");
	textFront.setString("Text Here");

	text = "Text Here";
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
	mosPos.x = sf::Mouse::getPosition(*window).x;
	mosPos.y = sf::Mouse::getPosition(*window).y;
	std::cout << mosPos.x << " \\\ " << mosPos.y << std::endl;
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
	delete this->window;
	delete this->ev;
	delete this->font;
}

void TextBox::update()
{
	updateMosPos();
	clickEvents();
}

//Sets the position for the text box
void TextBox::setPosition(sf::Vector2f pos)
{
	this->textBg.setPosition(pos);
	this->textFront.setPosition(pos);
}

//Changes the position of the text relative to the text box
void TextBox::changeTextPos(sf::Vector2f dist)
{
	textFront.setPosition(this->textFront.getPosition() + dist);
}

//Sets the size for the text box
void TextBox::setSize(sf::Vector2f size)
{
	this->textBg.setSize(size);
}

//sets font size for the text box
void TextBox::setFontSize(unsigned int fontSize)
{
	this->textFront.setCharacterSize(fontSize);
}

//Sets the background color for the textbox
void TextBox::setTextBoxColor(sf::Color color)
{
	this->textBg.setFillColor(color);
}

//sets the text color for the text
void TextBox::setTextColor(sf::Color color)
{
	this->textFront.setFillColor(color);
}

//Return the position of the text box
sf::Vector2f TextBox::getPosition()
{
	return textBg.getPosition();
}

void TextBox::draw()
{
	window->draw(textBg);
	window->draw(textFront);
}