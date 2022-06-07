#include "CGhost.h"

void CGhost::SwitchBhvrState(const BEHAVIOURSTATE& newState)
{
	mState = newState;
}

void CGhost::FrightenedState()
{
}

void CGhost::EatenState()
{
}

void CGhost::UpdateBehaviourTime() {
	UpdateFrightenedBhvrTime();
	UpdateEatenBhvrTime();
	UpdateSctrChseBhvrTime();
}
void CGhost::UpdateSctrChseBhvrTime()
{
	if (!CanSwitch(mClock.getElapsedTime())) return;

	sf::Time elapsed = mClock.getElapsedTime();

	switch (mState) {
	case BEHAVIOURSTATE::SCATTER:
	{
		bool change = false;
		if (elapsed.asSeconds() == 7 && mChaseWave <= 2) change = true;
		else if (elapsed.asSeconds() == 5 && mChaseWave >= 2) change = true;

		if (change) {
			mState = BEHAVIOURSTATE::CHASE;
			mChaseWave++;
		}
	}
	break;
		
	case BEHAVIOURSTATE::CHASE:
		if (elapsed.asSeconds() == 20) mState = BEHAVIOURSTATE::SCATTER;
		break;
	}
}

void CGhost::UpdateFrightenedBhvrTime() {
	if (mState != BEHAVIOURSTATE::FRIGHTENED) return;
	
	if (mStartFrightenedTimer) {
		mFrightenedClock.restart();
		mStartFrightenedTimer = false;
		mStoreTime = mClock.getElapsedTime();
	}

	sf::Time elapsed = mFrightenedClock.getElapsedTime();

	if (elapsed.asSeconds() == 8) {
		
	}
	
}

void CGhost::UpdateEatenBhvrTime() {

}


bool CGhost::CanSwitch(const sf::Time& elapsed) {
	return elapsed.asSeconds() == 5 || elapsed.asSeconds() == 7 || elapsed.asSeconds() == 20;
}