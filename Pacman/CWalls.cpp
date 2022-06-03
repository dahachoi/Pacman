#include "CWalls.h"

using namespace std;

CWalls::CWalls()
{
	InitVariables();
	InitWalls();
}

void CWalls::InitVariables() {
	mXGap = 40.f;
	mYGap = 40.f;
}

void CWalls::InitWalls() {
	float mCurrPosX = 0.f;
	float mCurrPosY = 0.f;

	for (int i = 0; i < sketch.size(); ++i) {
		for (int j = 0; j < sketch.size(); ++j) {
			if (sketch[i][j] == '#') {
				mBlocks.push_back(new CWallBlock(mCurrPosX, mCurrPosY));
			}
			mCurrPosX += mXGap;
		}
		mCurrPosX = 0.0;
		mCurrPosY += mYGap;
	}
}



bool CWalls::UpdateCollision(float& x, float& y, const Direction& dir) {
	int i = static_cast<int>(y / 40);
	int j = static_cast<int>(x / 40);

	switch (dir) {
	case Direction::RIGHT:
		j++;
		break;
	case Direction::DOWN:
		i++;
		break;
	case Direction::LEFT:
		j--;
		break;
	case Direction::UP:
		i--;
		break;
	}

	if (sketch[i][j] == '#') return true;

	return false;
}

void CWalls::Render(sf::RenderTarget* target) {
	for (auto i : mBlocks) {
		i->Render(target);
	}
}
