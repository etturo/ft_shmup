#include "../include/Player.hpp"

Player::Player() {
	this->pos.x = BOARD_COLS / 2 - strlen(SPACESHIP) / 2 + (strlen(SPACESHIP) % 2 == 0 ? 0 : -1);
	this->pos.y = BOARD_ROWS - 5;
	this->sprite_len = strlen(SPACESHIP);
}

Player::~Player() {
}

void Player::update(t_gamestate &state)
{
	int new_x = pos.x, new_y = pos.y;

	switch (state.pressed)
	{
		case 258: new_y += 1 ; break;
		case 259: new_y -= 1 ; break;
		case 261: new_x += 1 ; break;
		case 260: new_x -= 1 ; break;
	}
	
	if (state.pressed == 32)
		state.spawn_list.push_back(new Bullet(this->pos));

	if (new_x > 0 && new_x < (BOARD_COLS - (int)strlen(SPACESHIP) / 2 + ((int)strlen(SPACESHIP) % 2 == 0 ? -2 : -3)))
		this->pos.x = new_x;
	if (new_y > MAX_HEIGHT && new_y < BOARD_ROWS - 1)
		this->pos.y = new_y;
}

void Player::on_collision(Entity* other, t_gamestate &state) {
	if (other->type == TYPE_ENEMY || other->type == TYPE_ENEMY_BULLET) {
		state.lives -= 1;
	}
}


void Player::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, SPACESHIP);
}
