#include "Boss.hpp"

void Boss::update(t_gamestate &state)
{
	this->delta_time += state.delta_time;
	this->fire_time += state.delta_time;

	if (SECONDS(this->delta_time) > 1.5f){
		this->pos.y += 1;

		if (dir == 1 && move <= 2)
		{
			this->pos.x++;
			move++;
			if (move == 2){
				dir = -1;
				move = 0;
			}
		}
		else if (dir == -1 && move <= 3)
		{
			this->pos.x--;
			move++;
			if (move == 3){
				dir = 1;
				move = 0;
			}
		}

		this->delta_time = 0;
	}

	if (SECONDS(this->fire_time) > 0.3f){
		Vector2 second_cannon;
		second_cannon.x = this->pos.x + 14;
		second_cannon.y = this->pos.y;
		state.spawn_list.push_back(new EnemyBullet(this->pos));
		state.spawn_list.push_back(new EnemyBullet(second_cannon));
		this->fire_time = 0;
	}

	if (this->hp <= 0 && this->pos.y >= BOARD_ROWS)
		this->is_dead = true;
}

void Boss::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, "%s", this->sprite);
}

void Boss::on_collision(Entity* other, t_gamestate &state) {
	if (other->type == TYPE_BULLET) {
		this->hp--;
	}
	if (other->type == TYPE_PLAYER) {
		this->is_dead = true;
	}
}

Boss::Boss()
{
	this->hp = 1;
	this->pos.x = (BOARD_COLS / 2) - strlen(BOSS) / 2 - 1;
	this->pos.y = 1;
	this->delta_time = 0;
	this->fire_time = 0;
	this->sprite = BOSS;
	sprite_len = strlen(ENEMY);
	this->type = TYPE_ENEMY;
	this->dir = 1;
	this->move = 0;
}

Boss::~Boss()
{
}
