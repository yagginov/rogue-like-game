#include "enemy.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;


void Enemy::_bind_methods() 
{
}


Enemy::Enemy() :
    NPC(0)
{
	// Initialize any variables here.
	state = States::idle;
}

Enemy::Enemy(const size_t p_index) :
    NPC(p_index), atack_type()
{
	// Initialize any variables here.
	state = States::idle;
}

Enemy::~Enemy() 
{
	// Add your cleanup here.
}

void Enemy::_ready() 
{

}

void Enemy::_process(double delta) 
{

}

void Enemy::_physics_process(double delta) 
{
	if (is_step_allowed)
	{
		Vector2i direction = Vector2i(0, 1);
		if (!Actor::move(direction, delta))
		{
			set_positioni(get_positioni() + direction);
			step_is_ended();
		}
	}
}

