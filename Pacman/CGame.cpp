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
	
	if (pacManX== 0.f - mPacMan.getGlobalBounds().width && pacManY == 360.f) {
		iPacMan.setPosition(WINDOW_WIDTH, pacManY);
		return;
	}
	else if (pacManX == WINDOW_WIDTH && pacManY == 360.f) {
		iPacMan.setPosition(0.f - mPacMan.getGlobalBounds().width, pacManX);
		return;
	}

	if (iWalls.UpdateCollision(pacManX, pacManY, iPacMan.GetDir())) {
		iPacMan.setPosition(pacManX, pacManY);
	}

	/*for (auto i : mBlocks) {
		if (mPacMan.getGlobalBounds().intersects(i->GetShape().getGlobalBounds())) {
			switch (iPacMan.GetDir()) {
			case Direction::UP:
				iPacMan.setPosition(i->GetShape().getGlobalBounds().left, i->GetShape().getGlobalBounds().top + i->GetShape().getGlobalBounds().height);
				break;
			case Direction::DOWN:
				iPacMan.setPosition(i->GetShape().getGlobalBounds().left, i->GetShape().getGlobalBounds().top - i->GetShape().getGlobalBounds().height);
				break;
			case Direction::RIGHT:
				iPacMan.setPosition(i->GetShape().getGlobalBounds().left - i->GetShape().getGlobalBounds().width, i->GetShape().getGlobalBounds().top);
				break;
			case Direction::LEFT:
				iPacMan.setPosition(i->GetShape().getGlobalBounds().left + i->GetShape().getGlobalBounds().width, i->GetShape().getGlobalBounds().top);
				break;
			}
			return;
		}
	}*/


	
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
