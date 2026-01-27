#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <core/GameStateMgr.h>

#include <string>
#include <core/Cfg.h>
#include <memory>
extern sf::RenderWindow gWnd;
extern sf::ContextSettings gWndSettings;

extern sf::Vector2f mpos;

extern unsigned int gWW;
extern unsigned int gWH;

extern bool gWndFull;

extern float gTime;
extern float gPrevTime;

extern sf::View gameView;

extern std::unique_ptr<GameStateMgr> gStateMgr;

namespace wndw
{
	extern void CreateWindow(std::string title_, unsigned int w_, unsigned int h_);
	
}