#pragma once

#include "CCoinBlock.h"

class CCoins{
public:
	CCoins();

	void Render(sf::RenderTarget*);
	bool UpdateCollision(const float&, const float&);
private:
	std::vector<std::string> sketch = {
	"                     ",
	"                     ",
	"                     ",
	"  CCCCCCCC CCCCCCCC  ",
	"  C  C   C C   C  C  ",
	"  CCCCCCCCCCCCCCCCC  ",
	"  C  C C     C C  C  ",
	"  CCCC CCC CCC CCCC  ",
	"     C   C C   C     ",
	"     C CCCCCCC C     ",
	"     C C     C C     ",
	"CCCCCCCC     CCCCCCCC",
	"     C C     C C     ",
	"     C CCCCCCC C     ",
	"     C C     C C     ",
	"  CCCCCCCC CCCCCCCC  ",
	"  C  C   C C   C  C  ",
	"  CC CCCCCPCCCCC CC  ",
	"   C C C     C C C   ",
	"  CCCC CCC CCC CCCC  ",
	"  C      C C      C  ",
	"  CCCCCCCCCCCCCCCCC  ",
	"                     ",
	};

	float xGap;
	float yGap;

	std::map<std::pair<int, int>, CCoinBlock*> mCoins;

	void InitCoins();
};

