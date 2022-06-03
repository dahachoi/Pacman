#include "CWallBlock.h"

using namespace std;

CWallBlock::CWallBlock(const float &x,const float &y)
	: mX(x), mY(y), mColor(sf::Color::Blue)
{
	InitVariables();
	InitShape();
}

void CWallBlock::InitVariables() {
	mSizeX = 40.f;
	mSizeY = 40.f;
}
void CWallBlock::InitShape()
{
	mShape.setSize(sf::Vector2f(mSizeX, mSizeY));
	mShape.setFillColor(mColor);
	mShape.setPosition(mX, mY);
}

void CWallBlock::Render(sf::RenderTarget* target)
{
	target->draw(mShape);
}