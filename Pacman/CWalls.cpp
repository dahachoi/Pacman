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



bool CWalls::UpdateCollision(float& x, float& y, const Direction& dir) {
	int i = static_cast<int>(y / 40);
	int j = static_cast<int>(x / 40);

	cout << "passed (" << x << ", " << y << ")" << endl;

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
	cout << "checking grid[" << i << "][" << j << "]" << endl;
	bool collided = false;

	if (sketch[i][j] == '#') {
		cout << "is a wall!" << endl << endl;
		collided = true;
		return true;
		//switch (dir) {
		//case Direction::UP:
		//	y = 40.f * float(i + 1); //+ 1
		//	break;
		//case Direction::DOWN:
		//	y = 40.f * float(i - 1); //- 1
		//	break;
		//case Direction::LEFT:
		//	x = 40.f * float(j + 1); //+ 1
		//	break;
		//case Direction::RIGHT:
		//	x = 40.f * float(j - 1);//- 1
		//	break;
		//}
	}

	cout << "Switched pos to grid (" << x << ", " << y << endl<<endl;

	return collided;
}

void CWalls::Render(sf::RenderTarget* target) {
	for (auto i : mBlocks) {
		i->Render(target);
	}
}

const vector<CWallBlock*>& CWalls::GetBlockVector() const {
	return mBlocks;
}