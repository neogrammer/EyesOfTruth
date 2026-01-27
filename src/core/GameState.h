#ifndef GAMESTATE_H__
#define GAMESTATE_H__


#include <SFML/Window/Event.hpp>
#include <optional>
enum class GameStateType
{
	Title,
	Splash,
	Play,
	Pause,
	Count,
	None
};

class GameStateMgr;

class GameState
{
protected:

	bool paused;

	GameStateMgr* owner;
public:
	GameState(GameStateMgr* owner_);
	virtual ~GameState();

	virtual void processEvent(std::optional<sf::Event>& e_) = 0;
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void updateLate() = 0;
	virtual void render() = 0;

};

#endif