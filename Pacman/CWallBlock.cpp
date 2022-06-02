#include "CWallBlock.h"

using namespace std;

CWallBlock::CWallBlock(float x, float y)
	: mX(x), mY(y), mColor(sf::Color::Blue)
{
	InitVariables();
	InitBlock();
}

void CWallBlock::InitVariables() {
	mSizeX = 40.f;
	mSizeY = 40.f;
}
void CWallBlock::InitBlock()
{
	mShape.setSize(sf::Vector2f(mSizeX, mSizeY));
	mShape.setFillColor(mColor);
	mShape.setPosition(mX, mY);
}

void CWallBlock::Render(sf::RenderTarget* target)
{
	target->draw(mShape);
}

sf::RectangleShape CWallBlock::GetShape() const {
	return mShape;
}