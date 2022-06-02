#include "CPacMan.h"

using namespace std;

CPacMan::CPacMan() {
	InitVariables();
	InitPacMan();
}

void CPacMan::InitVariables() {
	//Sprite
	mX = 0.f;
	mY = 0.f;

	eDir = Direction::RIGHT;
	mPacManOpenTexture = &mPacManOpenRightTexture;
	mPacManHalfOpenTexture = &mPacManHalfOpenRightTexture;

	mWidth = 40;
	mHeight = 40;

	mMovementSpeed = 2;	
	goingVerticle = false;
	stopped = false;

	mCurrMovementX = 0.f;
	mCurrMovementY = 0.f;
	mNewMovementX = 0.f;
	mNewMovementY = 0.f;

	mMouthCycleTimer = 0;
	mOpeningMouth = false;
}

void CPacMan::InitPacMan() {
	//Closed
	mPacManClosedTexture.loadFromFile("Game_Resources/PacMan/PacMan_Closed.png");
	//Left
	mPacManOpenLeftTexture.loadFromFile("Game_Resources/PacMan/PacMan_OpenLeft.png");
	mPacManHalfOpenLeftTexture.loadFromFile("Game_Resources/PacMan/PacMan_HalfOpenLeft.png");
	//Right
	mPacManOpenRightTexture.loadFromFile("Game_Resources/PacMan/PacMan_OpenRight.png");
	mPacManHalfOpenRightTexture.loadFromFile("Game_Resources/PacMan/PacMan_HalfOpenRight.png");
	//Up
	mPacManOpenUpTexture.loadFromFile("Game_Resources/PacMan/PacMan_OpenUp.png");
	mPacManHalfOpenUpTexture.loadFromFile("Game_Resources/PacMan/PacMan_HalfOpenUp.png");
	//Down
	mPacManOpenDownTexture.loadFromFile("Game_Resources/PacMan/PacMan_OpenDown.png");
	mPacManHalfOpenDownTexture.loadFromFile("Game_Resources/PacMan/PacMan_HalfOpenDown.png");

	//Set Smooth
	mPacManClosedTexture.setSmooth(true);
	//Left
	mPacManOpenLeftTexture.setSmooth(true);
	mPacManHalfOpenLeftTexture.setSmooth(true);
	//Right
	mPacManOpenRightTexture.setSmooth(true);
	mPacManHalfOpenRightTexture.setSmooth(true);
	//Up
	mPacManOpenUpTexture.setSmooth(true);
	mPacManHalfOpenUpTexture.setSmooth(true);
	//Down
	mPacManOpenDownTexture.setSmooth(true);
	mPacManHalfOpenDownTexture.setSmooth(true);
	


	mPacMan.setTexture(mPacManOpenLeftTexture);
	mPacMan.setScale(0.1f, 0.1f);
	cout << "After scaled : " << mPacMan.getGlobalBounds().width << ", " << mPacMan.getGlobalBounds().height << endl;
}

const sf::Sprite& CPacMan::GetShape() const {
	return mPacMan;
}

const Direction& CPacMan::GetDir() const {
	return eDir;
}
//Functions

void CPacMan::setPosition(const float& x, const float& y) {
	mX = x;
	mY = y;
	mPacMan.setPosition(sf::Vector2f(mX, mY));
}

void CPacMan::cycleMouthMovement() {
	if (mPacMan.getTexture() == mPacManOpenTexture) {
		mPacMan.setTexture(*mPacManHalfOpenTexture);
		mOpeningMouth = false;
	} 
	else if (mPacMan.getTexture() == mPacManHalfOpenTexture && !mOpeningMouth) {
		mPacMan.setTexture(mPacManClosedTexture);
	}
	else if (mPacMan.getTexture() == mPacManHalfOpenTexture && mOpeningMouth) {
		mPacMan.setTexture(*mPacManOpenTexture);
	}
	else { //else has to be texture == closed, and not openingMouth
		mPacMan.setTexture(*mPacManHalfOpenTexture);
		mOpeningMouth = true;
	}

}
void CPacMan::UpdateDirectionTexture() {
	switch (eDir) {
	case Direction::DOWN:
		mPacManOpenTexture = &mPacManOpenDownTexture;
		mPacManHalfOpenTexture = &mPacManHalfOpenDownTexture;
		break;
	case Direction::UP:
		mPacManOpenTexture = &mPacManOpenUpTexture;
		mPacManHalfOpenTexture = &mPacManHalfOpenUpTexture;
		break;
	case Direction::RIGHT:
		mPacManOpenTexture = &mPacManOpenRightTexture;
		mPacManHalfOpenTexture = &mPacManHalfOpenRightTexture;
		break;
	case Direction::LEFT:
		mPacManOpenTexture = &mPacManOpenLeftTexture;
		mPacManHalfOpenTexture = &mPacManHalfOpenLeftTexture;
		break;
	}
}

void CPacMan::UpdateMouthCycle(){
	mMouthCycleTimer++;
	if (mMouthCycleTimer == 8) {
		cycleMouthMovement();
		mMouthCycleTimer = 0;
	}
	//setPosition(mX + mMovementSpeed, mY);
}
//Input, collision

void CPacMan::UpdateInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		mNewMovementX = 0.f;
		mNewMovementY = -mMovementSpeed;
		goingVerticle = true;
		eDir = Direction::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		mNewMovementX = -mMovementSpeed;
		mNewMovementY = 0.f;
		goingVerticle = false;
		eDir = Direction::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mNewMovementX = 0.f;
		mNewMovementY = mMovementSpeed;
		goingVerticle = true;
		eDir = Direction::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		mNewMovementX = mMovementSpeed;
		mNewMovementY = 0.f;
		goingVerticle = false;
		eDir = Direction::RIGHT;
	}
}

void CPacMan::UpdateMove() {
	float x = static_cast<float>(mPacMan.getGlobalBounds().left);
	float y = static_cast<float>(mPacMan.getGlobalBounds().top);

	if (fmod(x, 40) == 0.0 && fmod(y, 40) == 0.0) {
		UpdateDirectionTexture();
		mCurrMovementX = mNewMovementX;
		mCurrMovementY = mNewMovementY;
	}

	//if (goingVerticle && mNewMovementX == 0) {
	//	UpdateDirectionTexture();
	//	mCurrMovementX = mNewMovementX;
	//	mCurrMovementY = mNewMovementY;
	//}
	//if (!goingVerticle && mNewMovementY == 0) {
	//	UpdateDirectionTexture();
	//	mCurrMovementX = mNewMovementX;
	//	mCurrMovementY = mNewMovementY;
	//}
	mPacMan.move(mCurrMovementX, mCurrMovementY);
}


//Update and Render
void CPacMan::Update(const sf::RenderTarget* target) {
	//Movement
	UpdateInput();
	UpdateMove();

	UpdateMouthCycle();
}

void CPacMan::Render(sf::RenderTarget* target) {
	target->draw(mPacMan);
}