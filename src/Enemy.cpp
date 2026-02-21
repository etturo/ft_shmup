#include "Enemy.hpp"

Enemy::Enemy() {
	this->hp = 1;
	this->pos.x = 0;
	this->pos.y = 0;
}

Enemy::~Enemy() {
}

void Enemy::update(t_gamestate state) {
	(void)state;
	this->pos.x -= 1;
	if (this->pos.x < 0)
		this->hp = 0;
}

void Enemy::render(WINDOW *win) {
	mvwaddch(win, this->pos.y, this->pos.x, 'X');
}
