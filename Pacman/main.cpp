#include "CGame.h"

using namespace std;

int main() {
	srand(static_cast<unsigned>(time(0)));

	CGame iGame;

	while (iGame.Running()) {
		iGame.Update();
		iGame.Render();
	}

	cout << "laptop was here!" << endl;
	return 0;
}