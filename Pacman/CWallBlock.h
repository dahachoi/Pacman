#pragma once
#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class CWallBlock
{
public:
	CWallBlock(float x, float y);

	void Render(sf::RenderTarget*);
	sf::RectangleShape GetShape() const;
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
	void InitBlock();
};

