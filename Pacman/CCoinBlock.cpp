#include "CCoinBlock.h"

using namespace std;

CCoinBlock::CCoinBlock(const float& x, const float& y)
	:mX(x), mY(y)
{
	InitSprite();
}

void CCoinBlock::InitSprite() {
	if (!mTexture.loadFromFile("Game_Resources/Coin/Coin.png")){
		cout << "error loading in coin image" << endl;
	}

	mSprite.setTexture(mTexture);
	mSprite.setScale(0.23391812865, 0.23391812865);
	mSprite.setPosition(mX, mY);
}

void CCoinBlock::Render(sf::RenderTarget* target) {
	target->draw(mSprite);
}