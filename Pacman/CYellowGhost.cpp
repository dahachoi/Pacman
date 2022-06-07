#include "CYellowGhost.h"

CYellowGhost::CYellowGhost() {
	InitSprite();
}

void CYellowGhost::Update()
{
}

void CYellowGhost::Render(sf::RenderTarget*)
{

}

void CYellowGhost::ScatterState()
{

}

void CYellowGhost::ChaseState()
{

}

void CYellowGhost::InitSprite() {
	//sf::Sprite mGhost;
	//sf::Texture mLeftTexture;
	//sf::Texture mRightTexture;
	//sf::Texture mDownTexture;
	//sf::Texture mUpTexture;
	//sf::Texture mFrightenedTexture;

	mLeftTexture.loadFromFile(""); //load Image future
	mRightTexture.loadFromFile(""); //load Image future
	mDownTexture.loadFromFile(""); //load Image future
	mUpTexture.loadFromFile(""); //load Image future
	mFrightenedTexture.loadFromFile(""); //load Image future
}
