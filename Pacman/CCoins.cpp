#include "CCoins.h"

using namespace std;

CCoins::CCoins() :
	xGap(40.f), yGap(40.f)
{
	InitCoins();
}


void CCoins::InitCoins() {
	float x = 20.f;
	float y = 20.f;

	for (int i = 0; i < sketch.size(); ++i) {
		for (int j = 0; j < sketch.size() - 2; ++j) {
			if (sketch[i][j] == 'C')
				mCoins[make_pair(i, j)] = new CCoinBlock(x, y);
			x += xGap;
		}
		x = 20.f;
		y += yGap;
	}
}

bool CCoins::UpdateCollision(const float& x, const float& y) {
	int i = static_cast<int>(y / 40);
	int j = static_cast<int>(x / 40);

	if (sketch[i][j] == 'C') {
		auto it = mCoins.find({ i, j });
		mCoins.erase(it);
		sketch[i][j] = ' ';
		return true;
	}
	return false;
}

void CCoins::Render(sf::RenderTarget* target) {
	for (auto it = mCoins.begin(); it != mCoins.end(); ++it) {
		it->second->Render(target);
	}

}