#ifndef PLAYSTATE_H__
#define PLAYSTATE_H__
#include <core/GameStateMgr.h>
#include <core/GameState.h>
#include <world/Tilemap.h>
#include <memory>

class Obj; 

class PlayState : public GameState
{
public:
	Obj* anObject;

	Tilemap* tmap{ nullptr };

public:
	PlayState(GameStateMgr* mgr_);
	virtual ~PlayState();
	void processEvent(std::optional<sf::Event>& e_) override final;

	virtual void input()   override final;
	virtual void update()   override final;
	void updateLate() override final;
	virtual void render()   override final;

};

#endif