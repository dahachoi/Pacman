#pragma once

#include "CCoinBlock.h"

class CCoins{
public:
	CCoins();

	void Render(sf::RenderTarget*);
private:
	std::vector<std::string> sketch = {
		""
	};

	float xGap;
	float yGap;

	std::vector<CCoinBlock*> mCoins;

	void InitVariables();
	void InitCoins();
};

