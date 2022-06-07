#pragma once
#include "CGhost.h"

class CCyanGhost : public CGhost
{
public:
	CCyanGhost();

	void Update() override;
	void Render(sf::RenderTarget*) override;
private:
	std::string mName = "Inky";

	void ScatterState() override;
	void ChaseState() override;

	void InitSprite() override;
};

