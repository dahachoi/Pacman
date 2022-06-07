#include "CPinkGhost.h"

CPinkGhost::CPinkGhost(){
	InitSprite();
}

void CPinkGhost::Update()
{
}

void CPinkGhost::Render(sf::RenderTarget*)
{
}

void CPinkGhost::ScatterState()
{
}

void CPinkGhost::ChaseState()
{
}

void CPinkGhost::InitSprite()
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
