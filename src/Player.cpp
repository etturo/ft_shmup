#include "../include/Player.hpp"

Player::Player() {
	this->pos.x = BOARD_COLS / 2 - strlen(SPACESHIP) / 2 + (strlen(SPACESHIP) % 2 == 0 ? 0 : -1);
	this->pos.y = BOARD_ROWS - 5;
}

Player::~Player() {
	
}

void Player::update(t_gamestate state)
{
	int new_x = pos.x, new_y = pos.y;

	switch (state.pressed)
	{
		case 258: new_y += 1 ; break;
		case 259: new_y -= 1 ; break;
		case 261: new_x += 1 ; break;
		case 260: new_x -= 1 ; break;
	}

	if (state.pressed == ' '){
		Bullet *bullet = new Bullet(this->pos);
		state.entities.push_back(bullet);
	}

	if (new_x > 0 && new_x < (BOARD_COLS - (int)strlen(SPACESHIP) / 2 + ((int)strlen(SPACESHIP) % 2 == 0 ? -2 : -3)))
		this->pos.x = new_x;
	if (new_y > 0 && new_y < BOARD_ROWS - 1)
		this->pos.y = new_y;
}

void Player::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, SPACESHIP);
}
