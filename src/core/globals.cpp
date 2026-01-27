#include "globals.h"

sf::RenderWindow gWnd = {};
sf::ContextSettings gWndSettings = { sf::ContextSettings{} };
unsigned int gWW = {};
unsigned int gWH = {};
sf::Vector2f mpos = {};
bool gWndFull = false;

sf::View gameView = {};

float gTime = 0.f;
float gPrevTime = 0.f;



std::unique_ptr<GameStateMgr> gStateMgr{ std::make_unique<GameStateMgr>() };


void wndw::CreateWindow(std::string title_, unsigned int w_, unsigned int h_)
{
	gWW = w_;
	gWH = h_;
	gWndSettings.antiAliasingLevel = 8;
	if (gWndFull == true)
		gWnd.create(sf::VideoMode{ {gWW,gWH},32U }, title_, sf::Style::None, sf::State::Fullscreen, gWndSettings);
	else if (gWndFull == false)
		gWnd.create(sf::VideoMode{ {gWW,gWH},32U }, title_, sf::Style::None, sf::State::Windowed, gWndSettings);
	gameView = gWnd.getDefaultView();
}