#pragma once
#include "CGhost.h"

class CPinkGhost : public CGhost
{
public:
	CPinkGhost();

	void Update() override;
	void Render(sf::RenderTarget*) override;
private:
	std::string mName = "Pinky";

	void ScatterState() override;
	void ChaseState() override;

	void InitSprite() override;
};

