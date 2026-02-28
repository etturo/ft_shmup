#ifndef ENTITY_HPP
# define ENTITY_HPP

# include "Updatable.hpp"
# include "GameState.hpp"

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

enum EntityType { TYPE_PLAYER, TYPE_ENEMY, TYPE_BULLET, TYPE_ENEMY_BULLET };

class Entity : public Updatable
{
protected:
	long long	delta_time;
public:
	int sprite_height = 1;
	int	sprite_len = 1;
	Vector2 pos;
	EntityType type;
	bool	is_dead = false;

	inline Vector2	get_pos(){return this->pos;};

	virtual void render(WINDOW *win) = 0;

	virtual void on_collision(Entity *other, t_gamestate &state);

	Entity();
	virtual ~Entity();
};

#endif