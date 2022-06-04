#include "CCoinBlock.h"

using namespace std;

CCoinBlock::CCoinBlock(const float& x, const float& y)
	:mX(x), mY(y)
{
	InitSprite();
}

void CCoinBlock::InitSprite() {
	mShape.setRadius(5);
	mShape.setFillColor(sf::Color::Yellow);
	mShape.setOutlineThickness(2.f);
	mShape.setOutlineColor(sf::Color::Black);
	mShape.setOrigin(mShape.getGlobalBounds().width / 2, mShape.getGlobalBounds().height / 2);
	
	mShape.setPosition(sf::Vector2f(mX, mY));
}

void CCoinBlock::Render(sf::RenderTarget* target) {
	target->draw(mShape);
}