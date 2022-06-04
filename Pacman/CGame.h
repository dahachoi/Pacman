#pragma once
#include <iostream>
#include <ctime>
//#include <windows.h>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "CPacMan.h"
#include "CWalls.h"
#include "CCoins.h"

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
	const unsigned WINDOW_HEIGHT = 920;

	//Game Objects

	CPacMan iPacMan;
	CWalls iWalls;
	CCoins iCoins;

	unsigned mScore;
	int mGainPoints;
	sf::Font mFont;
	sf::Text mTitleText;
	sf::Text mScoreText;
	sf::Text mOnePlayerText;
	sf::Text mLoseGameText;
	sf::Text mWinGameText;

	sf::Clock mOnePlayerTextTimer;
	bool mShowOnePlayerText;

	//PollEvents
	void PollEvents();

	//Functions

	//Initialization Functions
	void InitWindow();
	void InitFont();
	void InitTexts();
	void InitVariables();

	//Update 
	void UpdateGui();
	void UpdatePacMan();
	void UpdateCollision();

	//Render
	void RenderGui();
	void RenderGameOver();
	void RenderBoard();
	void RenderPacMan();
	void RenderWalls();
	void RenderCoins();
};

