#ifndef MENU_HPP
# define MENU_HPP

# include "Settings.hpp"

class Menu
{
private:
public:
	WINDOW *menu;
	Menu(int height, int length);
	~Menu();
};

#endif