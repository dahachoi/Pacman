#include "CRedGhost.h"

CRedGhost::CRedGhost() {
	InitSprite();
}

void CRedGhost::Update()
{
}

void CRedGhost::Render(sf::RenderTarget*)
{
}

void CRedGhost::ScatterState()
{
}

void CRedGhost::ChaseState()
{
}

void CRedGhost::InitSprite()
{
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
