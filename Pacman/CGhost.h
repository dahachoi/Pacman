#pragma once

#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

enum class BEHAVIOURSTATE{SCATTER = 0, CHASE, FRIGHTENED, EATEN};

class CGhost{
public:
	void SwitchBhvrState(const BEHAVIOURSTATE&);

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget*) = 0;

protected:
	BEHAVIOURSTATE mState = BEHAVIOURSTATE::SCATTER;
	std::string mName;

	//Sprite
	sf::Sprite mGhost;
	sf::Texture mLeftTexture;
	sf::Texture mRightTexture;
	sf::Texture mDownTexture;
	sf::Texture mUpTexture;
	sf::Texture mFrightenedTexture; 

	//Attributes
	float mX;
	float mY;
	float mMovementSpeed = 2;

	sf::Clock mClock;
	sf::Clock mFrightenedClock;
	sf::Time mStoreTime;

	virtual void ScatterState() = 0;
	virtual void ChaseState() = 0;
	void FrightenedState();
	void EatenState();

	virtual void InitSprite() = 0;

	void UpdateBehaviourTime();
	void UpdateSctrChseBhvrTime();
	void UpdateFrightenedBhvrTime();
	void UpdateEatenBhvrTime();
	bool CanSwitch(const sf::Time&);
	
	int mChaseWave = 0;
	bool mStartFrightenedTimer = true;

};

