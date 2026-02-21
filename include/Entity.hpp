#ifndef ENTITY_HPP
# define ENTITY_HPP

struct Vector2
{
	int x;
	int y;

	Vector2(int x, int y){
		this->x = x;
		this->y = y;
	}
};

class Entity
{
private:
	int	hp;
	Vector2 pos;

public:
	inline Vector2	get_pos(){return this->pos;};

	Entity();
	~Entity();
};

#endif