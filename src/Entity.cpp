#include "../include/Entity.hpp"

Entity::Entity() {
}

void Entity::on_collision(Entity *other, t_gamestate &state) {
	(void)other;
	(void)state;
}

Entity::~Entity() {

}
