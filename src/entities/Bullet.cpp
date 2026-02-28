#include "Bullet.hpp"

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
	this->type = TYPE_BULLET;
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

void EnemyBullet::update(t_gamestate &state)
{
	this->delta_time += state.delta_time;

	if (SECONDS(this->delta_time) > 0.05f){
		this->pos.y++;
		this->delta_time = 0;
	}

	if (this->pos.y <= 0){
		this->is_dead = true;
	}
}

void EnemyBullet::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, ENEMY_BULLET);
}

void EnemyBullet::on_collision(Entity *other, t_gamestate &state)
{
	(void)state;
	if (other->type == TYPE_PLAYER) {
		this->is_dead = true;
	}
}

EnemyBullet::EnemyBullet(Vector2 enemy_pos) : Bullet(enemy_pos)
{
	pos.x = enemy_pos.x + ((int)strlen(ENEMY) / 2);
	pos.y = enemy_pos.y + 1;

	this->delta_time = 0;
	this->is_dead = false;
	this->sprite_len = strlen(ENEMY_BULLET);
	this->type = TYPE_ENEMY_BULLET;
}

EnemyBullet::~EnemyBullet()
{
}
