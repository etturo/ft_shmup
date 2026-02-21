#include "Bullet.hpp"
#include <string.h>

void Bullet::update(t_gamestate state)
{
	pos.y++;
	if (pos.y <= 0){
		state.entities.remove(this);
		delete(this);
	}
}

void Bullet::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, BULLET);
}

Bullet::Bullet(Vector2 player_pos)
{
	pos.x = player_pos.x - (int)strlen(SPACESHIP) / 2 + ((int)strlen(SPACESHIP) % 2 == 0 ? -2 : -3);
	pos.y = player_pos.y + 1;
}

Bullet::~Bullet()
{
}
