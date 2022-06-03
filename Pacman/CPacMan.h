#pragma once
#include <iostream>
#include <math.h>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "Direction.h"

class CPacMan{
public:
	CPacMan();

	//Functions
	void setPosition(const float&, const float&);
	const sf::Sprite& GetShape() const;
	const Direction& GetCurrDir() const;
	const Direction& GetQuedDir() const;
	const void StopPacMan();
	const void SwitchDirection();

	void Update(const sf::RenderTarget*);
	void Render(sf::RenderTarget*);
private:
	//Sprite
	sf::Sprite mPacMan;
	
	float mWidth;
	float mHeight;

	Direction mCurrDir;
	Direction mQuedDir;
	//pacman textures
	sf::Texture mPacManClosedTexture;

	//Left
	sf::Texture mPacManOpenLeftTexture;
	sf::Texture mPacManHalfOpenLeftTexture;
	//Right
	sf::Texture mPacManOpenRightTexture;
	sf::Texture mPacManHalfOpenRightTexture;
	//Up
	sf::Texture mPacManOpenUpTexture;
	sf::Texture mPacManHalfOpenUpTexture;
	//Down
	sf::Texture mPacManOpenDownTexture;
	sf::Texture mPacManHalfOpenDownTexture;

	//Current
	sf::Texture* mPacManOpenTexture;
	sf::Texture* mPacManHalfOpenTexture;

	//Position
	float mX;
	float mY;
	//MovementSpeed
	float mMovementSpeed;

	float mMovementX;
	float mMovementY;

	//Logic Helpers
	const int mMouthCycleTimerMax = 1; //40/5, 40pixels is the amount of pixels it needs to travel, within 5 frames
	int mMouthCycleTimer;
	bool mOpeningMouth;

	//Initialization Functions
	void InitPacMan();
	void InitVariables();

	//Functions
	void cycleMouthMovement();
	void UpdateDirectionTexture();

	void UpdateMouthCycle();
	void UpdateInput();
	void UpdateMove();
};

