#pragma once
#include "CWallBlock.h"
#include "Direction.h"

class CWalls{
public:
	CWalls();

	void Render(sf::RenderTarget* target);
	bool UpdateCollision(float&, float&, const Direction&);

	//Helper Functions

private:
	std::vector<std::string> sketch = {
		"                     ",
		"                     ",
		" ################### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #                 # ",
		" # ## # ##### # ## # ",
		" #    #   #   #    # ",
		" #### ### # ### #### ",
		"    # #       # #    ",
		"##### # ## ## # #####",
		"        #   #        ",
		"##### # ##### # #####",
		"    # #       # #    ",
		" #### # ##### # #### ",
		" #        #        # ",
		" # ## ### # ### ## # ",
		" #  #           #  # ",
		" ## # # ##### # # ## ",
		" #    #   #   #    # ",
		" # ###### # ###### # ",
		" #                 # ",
		" ################### "
	};

	float mYGap;
	float mXGap;

	std::vector<CWallBlock*> mBlocks;

	//InitFunctions
	void InitVariables();
	void InitWalls();
};

