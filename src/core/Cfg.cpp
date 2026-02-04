#include <core/ResourceManager.h>
#include "globals.h"

ResourceManager<sf::Texture, int> Cfg::textures = {};
ResourceManager<sf::Font, int> Cfg::fonts = {};
ResourceManager<sf::Music, int> Cfg::music = {};
ResourceManager<sf::SoundBuffer, int> Cfg::sounds = {};


void Cfg::Initialize()
{
    initTextures();
    initFonts();
    initMusic();
    initSounds();
}

void Cfg::initMusic()
{
}

void Cfg::initSounds()
{
}

void Cfg::initTextures()
{
    textures.load((int)Textures::Tileset1, "Assets/textures/Tiles.png");
}


void Cfg::initFonts()
{
    fonts.load((int)Fonts::Font1, "Assets/fonts/bubbly.ttf");
}