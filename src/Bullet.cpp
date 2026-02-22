#include "Bullet.hpp"
#include <string.h>

void Bullet::update(t_gamestate &state)
{
	this->delta_time += state.delta_time;

	if (SECONDS(this->delta_time) > 0.05f){
		this->pos.y--;
		this->delta_time = 0;
	}

	if (this->pos.y <= 0){
		this->is_dead = true;
	}
}

void Bullet::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, BULLET);
}

Bullet::Bullet(Vector2 player_pos)
{
	pos.x = player_pos.x + ((int)strlen(SPACESHIP) / 2);
	pos.y = player_pos.y - 1;

	this->delta_time = 0;
	this->is_dead = false;
	this->sprite_len = strlen(BULLET);
}

void Bullet::on_collision(Entity *other, t_gamestate &state){
	(void)state;
	if (other->type == TYPE_ENEMY) {
		this->is_dead = true;
	}
}

Bullet::~Bullet()
{
}
