#include "CCyanGhost.h"

CCyanGhost::CCyanGhost() {
	InitSprite();
}

void CCyanGhost::Update()
{
}

void CCyanGhost::Render(sf::RenderTarget*)
{
}

void CCyanGhost::ScatterState()
{
}

void CCyanGhost::ChaseState()
{
}

void CCyanGhost::InitSprite(){
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
