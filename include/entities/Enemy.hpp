#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Bullet.hpp"
# include "Entity.hpp"
# include "GameState.hpp"
# include "GameMode.hpp"

int random_between(int min, int max);

class Enemy : public Entity
{
protected:
	int hp;
	long long fire_time;
	const char *sprite;

public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win) override;


	inline int get_hp(){return this->hp;};
	inline Vector2 get_pos(){return this->pos;};

	inline void set_pos(Vector2 new_pos){this->pos = new_pos;};

	void on_collision(Entity* other, t_gamestate &state) override;
	
	inline int is_alive(){return this->hp > 0;};

	Enemy();
	~Enemy();
};

#endif