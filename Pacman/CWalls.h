#pragma once
#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "CWallBlock.h"

class CWalls{
public:
	CWalls();

	void Render(sf::RenderTarget* target);

	//Helper Functions

	const std::vector<CWallBlock*>& GetBlockVector() const;
private:
	std::vector<std::string> sketch = {
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

	float mCurrPosX;
	float mCurrPosY;
	float mYGap;
	float mXGap;


	std::vector<CWallBlock*> mBlocks;

	//InitFunctions
	void InitVariables();
	void InitWalls();
};

