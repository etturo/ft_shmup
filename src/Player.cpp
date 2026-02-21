#include "../include/Player.hpp"

Player::Player() {
	this->pos.x = 0;
	this->pos.y = 0;
}

Player::~Player() {
	
}

void Player::update(t_gamestate state)
{
	switch (state.pressed)
	{
		case 258: this->pos.y += 1 ; break;
		case 259: this->pos.y -= 1 ; break;
		case 261: this->pos.x += 1 ; break;
		case 260: this->pos.x -= 1 ; break;
	}
}

void Player::render(WINDOW *win)
{
	mvwprintw(win, this->pos.y, this->pos.x, "<>");
}
