#pragma once
#include "CGhost.h"

class CRedGhost : public CGhost
{
public:
	CRedGhost();

	void Update() override;
	void Render(sf::RenderTarget*) override;
private:
	std::string mName = "Blinky";

	void ScatterState() override;
	void ChaseState() override;

	void InitSprite() override;
};

