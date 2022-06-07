#include "CGame.h"
using namespace std;

//Constructor & Destructor
CGame::CGame() {
	cout << "loading game..." << "\n\n";
	InitVariables();
	InitFont();
	InitTexts();
	//InitWindow();
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
	mScore = 0;
	mGainPoints = 10;
	
	mShowOnePlayerText = true;
}

void CGame::OpenWindow() {
	InitWindow();
}

void CGame::InitWindow() {
	mVideoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	mWindow = new sf::RenderWindow(mVideoMode, "PacMan", sf::Style::Close | sf::Style::Titlebar);
	mWindow->setFramerateLimit(144);
}

void CGame::InitFont() {
	mFont.loadFromFile("Game_Resources/Fonts/emulogic.ttf");
}

void CGame::InitTexts() {

	mTitleText.setFont(mFont);
	mTitleText.setCharacterSize(35);
	mTitleText.setString("PAC-MAN");
	mTitleText.setPosition(WINDOW_WIDTH/2.f, 40.f);


	mOnePlayerText.setFont(mFont);
	mOnePlayerText.setCharacterSize(25);
	mOnePlayerText.setString("1UP");
	mOnePlayerText.setPosition(115.f, 0.f);

	mScoreText.setFont(mFont);
	mScoreText.setCharacterSize(25);
	mScoreText.setString("0");
	mScoreText.setPosition(180.f, 30.f);

	mLoseGameText.setFont(mFont);
	mLoseGameText.setCharacterSize(100);
	mLoseGameText.setFillColor(sf::Color::Red);
	mLoseGameText.setString("You Lose!");
	mLoseGameText.setOrigin(mLoseGameText.getGlobalBounds().width / 2, mLoseGameText.getGlobalBounds().height / 2);
	mLoseGameText.setPosition(float(WINDOW_WIDTH / 2), float((WINDOW_HEIGHT - 80) / 2));

	mWinGameText.setFont(mFont);
	mWinGameText.setCharacterSize(100);
	mWinGameText.setFillColor(sf::Color::Green);
	mWinGameText.setString("You Win!");
	mWinGameText.setOrigin(mWinGameText.getGlobalBounds().width / 2, mWinGameText.getGlobalBounds().height / 2);
	mWinGameText.setPosition(float(WINDOW_WIDTH / 2), float((WINDOW_HEIGHT - 80) / 2));
}

//Update
void CGame::UpdateGui() {
	mScoreText.setString(to_string(mScore));

	sf::Time onePlayerElapsed = mOnePlayerTextTimer.getElapsedTime();

	if (onePlayerElapsed.asMilliseconds() >= 240) {
		mShowOnePlayerText = !mShowOnePlayerText;
		mOnePlayerTextTimer.restart();
	}
}

void CGame::UpdatePacMan() {
	iPacMan.Update(mWindow);
}

//Render
void CGame::RenderGui() {
	mWindow->draw(mTitleText);
	if (mShowOnePlayerText) mWindow->draw(mOnePlayerText);
	mWindow->draw(mScoreText);
}

void CGame::RenderGameOver() {
	if (mScore == 1850) mWindow->draw(mWinGameText);
	else mWindow->draw(mLoseGameText);
}

void CGame::RenderPacMan() {
	iPacMan.Render(mWindow);
}

void CGame::RenderWalls() {
	iWalls.Render(mWindow);
}
void CGame::RenderBoard() {
	RenderWalls();
	RenderCoins();
	RenderPacMan();

}

void CGame::RenderCoins() {
	iCoins.Render(mWindow);
}

void CGame::UpdateCollision() {
	sf::Sprite mPacMan = iPacMan.GetShape();
	float pacManX = mPacMan.getGlobalBounds().left;
	float pacManY = mPacMan.getGlobalBounds().top;
	
	//teleport from side of screen to the other side of screen.
	if (pacManX <= 0) {
		if (pacManX == 0) {
			iCoins.UpdateCollision(pacManX, pacManY);
		}
		if (pacManX == -mPacMan.getGlobalBounds().width && pacManY == 440.f) {
			iPacMan.setPosition(float(WINDOW_WIDTH), pacManY);
		}
		return;
	}
	if (pacManX == WINDOW_WIDTH && pacManY == 440.f) {
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
		if (iCoins.UpdateCollision(pacManX, pacManY)) {
			mScore += mGainPoints;
			if (mScore == 1850) mEndGame = true;
		}
	}

}

//Game Update & Render

void CGame::Update() {
	PollEvents();
	UpdateGui();
	if (!mEndGame) {
		UpdatePacMan();
		UpdateCollision();
	}
}

void CGame::Render() {
	mWindow->clear();
	RenderGui();
	RenderBoard();
	if (mEndGame) RenderGameOver();

	mWindow->display();
}
