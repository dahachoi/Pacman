#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class CWallBlock
{
public:
	CWallBlock(const float& x,const float& y);

	void Render(sf::RenderTarget*);
private:
	sf::RectangleShape mShape;
	sf::Color mColor;
	
	//pos
	float mX;
	float mY;

	//size
	float mSizeX;
	float mSizeY;

	void InitVariables();
	void InitShape();
};

