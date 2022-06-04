#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class CCoinBlock{
public:
	CCoinBlock(const float& x,const float& y);
	
	void Render(sf::RenderTarget*);
private:
	sf::CircleShape mShape;
	sf::Texture mTexture;

	float mX;
	float mY;

	void InitSprite();
};

