#pragma once

/////////////////////////////////////
///////			HEADERS
/////////////////////////////////////
///Built-in Headers
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
//////////////////////////////////////////////////
//SFML libs
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
//Windows API
#include<Windows.h>
//////////////////////////////////////////////////
///ASCII codes of imp keys
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

//Debug Codes
#define LOG(X) std::cout << x << std::endl