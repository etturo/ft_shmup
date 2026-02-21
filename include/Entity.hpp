#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "Updatable.hpp"
# include <ncurses.h>

struct Vector2
{
	int x;
	int y;

	Vector2(){
		this->x = 0;
		this->y = 0;
	}

	Vector2(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Entity : public Updatable
{
protected:
	Vector2 pos;
	long long	delta_time;
public:
	bool	is_dead = false;

	inline Vector2	get_pos(){return this->pos;};

	virtual void render(WINDOW *win) = 0;

	Entity();
	virtual ~Entity();
};

#endif