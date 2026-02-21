#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Entity.hpp"

class Enemy : public Entity
{
private:
	int hp;

public:
	inline int get_hp(){return this->hp;};
	inline Vector2 get_pos(){return this->get_pos();};

	inline void set_pos(Vector2 new_pos){this->pos = new_pos;};
	
	inline int is_alive(){return this->hp > 0;};


	Enemy();
	~Enemy();
};

#endif