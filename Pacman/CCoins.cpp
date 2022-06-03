#include "CCoins.h"

using namespace std;

CCoins::CCoins() {

}

void CCoins::InitVariables() {

}

void CCoins::InitCoins() {

}

void CCoins::Render(sf::RenderTarget* target) {
	for (auto i : mCoins) {
		i->Render(target);
	}
}