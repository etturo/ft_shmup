#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "settings.hpp"
#include "Bullet.hpp"
#include <ncurses.h>
#include "string.h"

class Player : public Entity
{
private:
	int hp;

public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win) override;

	inline int get_hp(){return this->hp;};
	inline Vector2 get_pos(){return this->pos;};

	inline void set_pos(Vector2 new_pos){this->pos = new_pos;};
	
	inline int is_alive(){return this->hp > 0;};
	void on_collision(Entity* other, t_gamestate &state) override;

	Player();
	~Player();
};

#endif