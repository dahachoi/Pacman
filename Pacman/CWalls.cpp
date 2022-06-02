#include "CWalls.h"

using namespace std;

CWalls::CWalls()
{
	InitVariables();
	InitWalls();
}

void CWalls::InitVariables() {
	mCurrPosX = 0.f;
	mCurrPosY = 0.f;
	mXGap = 40.f;
	mYGap = 40.f;
}

void CWalls::InitWalls() {
	
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

	cout << "size of mBlocks" << mBlocks.size() << endl;
}

void CWalls::Render(sf::RenderTarget* target) {
	for (auto i : mBlocks) {
		i->Render(target);
	}
}

const vector<CWallBlock*>& CWalls::GetBlockVector() const {
	return mBlocks;
}