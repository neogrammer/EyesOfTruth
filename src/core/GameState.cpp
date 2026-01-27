#include <core/GameState.h>
#include <core/GameStateMgr.h>
GameState::GameState(GameStateMgr* owner_)
	: paused{false}
	, owner{owner_}
{
}

GameState::~GameState()
{
	owner = nullptr;
}
