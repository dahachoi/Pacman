#pragma once
#include "CGhost.h"

class CYellowGhost : public CGhost
{
public:
	CYellowGhost();

	void Update() override;
	void Render(sf::RenderTarget*) override;
private:
	std::string mName = "Clyde";

	void ScatterState() override;
	void ChaseState() override;

	void InitSprite() override;
};

