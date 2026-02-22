#include "Enemy.hpp"

Enemy::Enemy() {
	this->hp = 1;
	this->pos.x = random_between(strlen(ENEMY), BOARD_COLS - strlen(ENEMY));
	this->pos.y = 1;
}

Enemy::~Enemy() {
}

int random_between(int min, int max){
	return (min + (((rand() % 100) / 100) + max - min));
}

void Enemy::update(t_gamestate &state) {
	(void)state;
	this->pos.x -= 1;
	if (this->pos.x < 0)
		this->hp = 0;
}

void Enemy::render(WINDOW *win) {
	mvwprintw(win, this->pos.y, this->pos.x, ENEMY);
}
