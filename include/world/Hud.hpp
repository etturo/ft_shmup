#ifndef HUD_HPP
# define HUD_HPP

#include "Settings.hpp"

class Hud
{
private:
public:
	WINDOW *hud;

	Hud(int height, int length);
	~Hud();
};

#endif