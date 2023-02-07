#pragma once

#include"auth.h"
#include"app.h"

bool Auth::isPassCorrect()
{
	if (enteredPassStream.str().compare(PASSWORD) == 0)
	{
		auth = true;
		return true;
	}
	else
	{
		return false;
	}
}

void Auth::checkPass()
{
	if (isPassCorrect())
	{
		MessageBox(NULL, L"Authentication Successful", L"Successful", MB_OK);
		enteredPass.setString("");
		enteredPassStream.str("");
	}
	else
	{
		MessageBox(NULL, L"Wrong Password. Please Enter the correct Password", L"Error", MB_OK | MB_ICONERROR);
	}
}

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

	enterBgAlpha.setFillColor(sf::Color::White);
	enterBgAlpha.setSize(sf::Vector2f(150.f, 50.f));
	enterBgAlpha.setPosition(sf::Vector2f(710.f, 350.f));
	enterBgAlpha.setOutlineColor(sf::Color::White);
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

	enteredPass.setFont(*font);
	enteredPass.setCharacterSize(34);
	enteredPass.setFillColor(sf::Color::Black);
	enteredPass.setPosition(205.f, 352.f);
	enteredPass.setStyle(sf::Text::Bold);
	enteredPass.setString("");

	enteredPassStream << "";


	maxChar.setFont(*font);
	maxChar.setCharacterSize(15);
	maxChar.setFillColor(sf::Color::White);
	maxChar.setPosition(200.f, 330.f);
	std::ostringstream tempString; 
	tempString << "Max character should be " << passLimit;
	maxChar.setString(tempString.str());
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
			else
			{
				isEnterTextBoxSelected = false;
			}
			if (enterBg.getGlobalBounds().contains(mousePos))
			{
				checkPass();
			}
		}
	}
	else
	{
		isMousePressedL = false;
	}
	if (enterBg.getGlobalBounds().contains(mousePos))
	{
		enterHovered = true;
	}
	else
	{
		enterHovered = false;
	}
}

void Auth::checkKeyEvents()
{

}

void Auth::updateMousePos()
{
	//Updates the mouse position
	mousePos.x = sf::Mouse::getPosition(*window).x;
	mousePos.y = sf::Mouse::getPosition(*window).y;
}

void Auth::updateTextBox()
{
	//Highlights the box if its selected
	if (isEnterTextBoxSelected)
	{
		pwBg.setOutlineColor(sf::Color::Blue);
		pwBg.setOutlineThickness(3.f);
	}
	else if (!isEnterTextBoxSelected)
	{
		pwBg.setOutlineColor(sf::Color::White);
		pwBg.setOutlineThickness(1.f);
	}
	//Hover Effect on Enter button
	if (enterHovered && (enterBg.getFillColor().a > 200))
	{
		sf::Color tempColor = enterBg.getFillColor();
		enterBg.setFillColor(sf::Color(tempColor.r, tempColor.g, tempColor.b, tempColor.a - 10));
	}
	else if (!enterHovered && (enterBg.getFillColor().a < 255))
	{
		sf::Color tempColor = enterBg.getFillColor();
		enterBg.setFillColor(sf::Color(tempColor.r, tempColor.g, tempColor.b, tempColor.a + 10));
	}
}

void Auth::inputLogic(int charTyped)
{
	//Input logic for the password text box
	std::string tempString = enteredPass.getString().toAnsiString();
	if ((charTyped != DELETE_KEY) && (charTyped != ENTER_KEY) && (charTyped != ESCAPE_KEY))
	{
		enteredPassStream << static_cast<char>(charTyped);
		tempString += "*";
		enteredPass.setString(tempString);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (enteredPassStream.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	else if (charTyped == ENTER_KEY)
	{
		if (isPassCorrect())
		{
			MessageBox(NULL, L"Authentication Successful", L"Successful", MB_OK);
			enteredPass.setString("");
			enteredPassStream.str("");
		}
		else
		{
			MessageBox(NULL, L"Wrong Password. Please Enter the correct Password", L"Error", MB_OK | MB_ICONERROR);
		}
	}
}

//Function for deleting the last char of the text box
void Auth::deleteLastChar()
{
	std::string t = enteredPassStream.str();
	std::string newT = "";
	std::string tempString = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
		tempString += "*";
	}
	enteredPassStream.str("");
	enteredPassStream << newT;
	enteredPass.setString(tempString);
}

void Auth::setSelected()
{
	if (!isEnterTextBoxSelected && (enteredPassStream.str().length() > 0))
	{
		std::string t = enteredPassStream.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += "*";
		}
		enteredPass.setString(newT);
	}
	if (!isEnterTextBoxSelected && (enteredPassStream.str().length() == 0))
	{
		enteredPass.setString("");
	}
}

void Auth::typedOn(sf::Event input)
{
	if (isEnterTextBoxSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if ((enteredPassStream.str().length()) <= passLimit)
			{
				inputLogic(charTyped);
			}
			else if ((enteredPassStream.str().length() > passLimit) && (charTyped == DELETE_KEY))
			{
				deleteLastChar();
			}
			if (charTyped == ESCAPE_KEY)
			{
				isEnterTextBoxSelected = false;
			}
		}
	}
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
	updateTextBox();
	setSelected();
	DEBUG();
}

void Auth::DEBUG()
{
	system("cls");
	std::cout << mousePos.x << " ||||||||| " << mousePos.y << std::endl;
	std::cout << "isMousePressedL: " << isMousePressedL << std::endl;
	std::cout << "isEnterTextBoxSelected: " << isEnterTextBoxSelected << std::endl;
	std::cout << "enterHovered: " << enterHovered << std::endl;
	std::cout << "passBox Front-end: " << enteredPass.getString().toAnsiString() << std::endl;
	std::cout << "passBox Back-end: " << enteredPassStream.str() << std::endl;
}

void Auth::pollEv(sf::Event *tempEvent)
{
	typedOn(*tempEvent);
}

void Auth::updateRender()
{
	switch (init)
	{
	case true:
		window->draw(pwBg);
		window->draw(enterBgAlpha);
		window->draw(enterBg);
		window->draw(enterPromptText);
		window->draw(enteredPass);
		window->draw(maxChar);
		window->draw(enterText);
		break;
	case false:
	default:
		break;
	}
}


bool Auth::checkAuth()
{
	return auth;
}