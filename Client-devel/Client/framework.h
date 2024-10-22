#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

#define DELETE(x) if(x) delete (x); x = nullptr;
constexpr float PI = 3.14159265f;