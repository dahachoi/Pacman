#pragma once
#include <iostream>
#include <ctime>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "CPacMan.h"
#include "CWalls.h"

class CGame {
public:
	CGame();
	~CGame();

	//Check Game Running
	const bool Running() const;
	//Game Update & Render
	void Update();
	void Render();
private:
	//Window
	sf::RenderWindow* mWindow;
	sf::VideoMode mVideoMode;
	sf::Event mEv;
	bool mEndGame;

	//21wx21h square blocks, times by 40
	//40x40 blocks
	const unsigned WINDOW_WIDTH = 840;
	const unsigned WINDOW_HEIGHT = 840;

	//Game Objects

	CPacMan iPacMan;
	CWalls iWalls;

	//PollEvents
	void PollEvents();

	//Functions

	//Initialization Functions
	void InitWindow();
	void InitVariables();
	void InitPacMan();

	//Update 
	void UpdatePacMan();
	void UpdateCollision();

	//Render
	void RenderBoard();
	void RenderPacMan();
	void RenderWalls();
};

