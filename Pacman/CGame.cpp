#include "CGame.h"
using namespace std;

//Constructor & Destructor
CGame::CGame() {
	InitVariables();
	InitWindow();
	InitPacMan();
}

CGame::~CGame() {
	delete mWindow;
}

//PollEvents and Check running

void CGame::PollEvents() {
	while (mWindow->pollEvent(mEv)) {
		switch (mEv.type) {
		case sf::Event::Closed:
			mWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (mEv.key.code == sf::Keyboard::Escape)
				mWindow->close();
			break;
		}
	}
}

const bool CGame::Running() const {
	return mWindow->isOpen();
}

//Initialization Functions
void CGame::InitVariables() {
	mEndGame = false;
}

void CGame::InitWindow() {
	mVideoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	mWindow = new sf::RenderWindow(mVideoMode, "PacMan", sf::Style::Close | sf::Style::Titlebar);
	mWindow->setFramerateLimit(144);
}

void CGame::InitPacMan() {
	iPacMan.setPosition(400.f, 600.f);
}

//Update and Render Other
void CGame::UpdatePacMan() {
	iPacMan.Update(mWindow);
}

void CGame::RenderPacMan() {
	iPacMan.Render(mWindow);
}

void CGame::RenderWalls() {
	iWalls.Render(mWindow);
}
void CGame::RenderBoard() {
	RenderWalls();
	RenderPacMan();
}

void CGame::UpdateCollision() {
	sf::Sprite mPacMan = iPacMan.GetShape();
	float pacManX = mPacMan.getGlobalBounds().left;
	float pacManY = mPacMan.getGlobalBounds().top;
	
	//teleport from side of screen to the other side of screen.
	if (pacManX <= 0) {
		if (pacManX == -mPacMan.getGlobalBounds().width && pacManY == 360.f) {
			iPacMan.setPosition(WINDOW_WIDTH, pacManY);
		}
		return;
	}
	if (pacManX == WINDOW_WIDTH && pacManY == 360.f) {
		iPacMan.setPosition(-mPacMan.getGlobalBounds().width, pacManY);
		return;
	}
	
	//collision with wall
	if (fmod(pacManX, 40) == 0.0 && fmod(pacManY, 40) == 0.0) {
		if (!iWalls.UpdateCollision(pacManX, pacManY, iPacMan.GetQuedDir())) {
			iPacMan.SwitchDirection();
		}
		else if (iWalls.UpdateCollision(pacManX, pacManY, iPacMan.GetCurrDir())) {
			iPacMan.StopPacMan();
		}
		//iPacMan.setPosition(pacManX, pacManY);
	}
	

}

//Game Update & Render
void CGame::Update() {
	PollEvents();

	if (!mEndGame) {
		UpdatePacMan();
		UpdateCollision();
	}
	
}

void CGame::Render() {
	mWindow->clear();
	RenderBoard();

	mWindow->display();
}
