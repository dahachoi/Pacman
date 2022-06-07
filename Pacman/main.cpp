#include "CGame.h"

using namespace std;

int main() {
	srand(static_cast<unsigned>(time(0)));

	CGame iGame;

	sf::sleep(sf::milliseconds(1000));
	
	cout << "Done!" << endl;
	iGame.OpenWindow();

	while (iGame.Running()) {
		iGame.Update();
		iGame.Render();
	}	

	return 0;
}