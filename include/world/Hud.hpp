#ifndef HUD_HPP
# define HUD_HPP

#include "../core/Settings.hpp"

class Hud
{
private:
public:
	WINDOW *hud;

	Hud(int height, int length);
	~Hud();
};

#endif