#include "Enemy.hpp"

Enemy::Enemy() {
	this->hp = 1;
	this->pos.x = random_between(5, BOARD_COLS - 5);
	this->pos.y = 1;
	this->delta_time = 0;
	sprite_len = strlen(ENEMY);
}

Enemy::~Enemy() {
}

int random_between(int min, int max){
	return (min + (rand() % (max - min + 1)));
}

void Enemy::update(t_gamestate &state) {
	this->delta_time += state.delta_time;

	if (SECONDS(this->delta_time) > 0.15f){
		this->pos.y += 1;
		this->delta_time = 0;
	}
	if (this->pos.y >= BOARD_ROWS)
		this->hp--;
	if (this->hp <= 0)
		this->is_dead = true;
}

void Enemy::on_collision(Entity* other, t_gamestate &state) {
	if (other->type == TYPE_BULLET) {
		this->is_dead = true;
		state.score += 100;
	}
	if (other->type == TYPE_PLAYER) {
		this->is_dead = true;
	}
}
void Enemy::render(WINDOW *win) {
	mvwprintw(win, this->pos.y, this->pos.x, ENEMY);
}
