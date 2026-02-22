#ifndef BULLET_H
# define BULLET_H

#include "Entity.hpp"
#include "settings.hpp"

class Bullet : public Entity
{
private:
public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win) override;

	void on_collision(Entity *other, t_gamestate &state) override;

	Bullet(Vector2 player_pos);
	~Bullet();
};

class EnemyBullet : public Bullet
{
	private:
	public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win) override;

	void on_collision(Entity *other, t_gamestate &state) override;

	EnemyBullet(Vector2 player_pos);
	~EnemyBullet();
};

#endif