#include "non_playable_character.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;


void NPC::_bind_methods() 
{
	
}


NPC::NPC() :
    Actor(0)
{
	// Initialize any variables here.
}

NPC::NPC(const size_t p_index) :
    Actor(p_index)
{
	// Initialize any variables here.
}

NPC::~NPC() 
{
	// Add your cleanup here.
}

void NPC::_ready() 
{

}

void NPC::_process(double delta) 
{

}

void NPC::_physics_process(double delta) 
{
	if (is_step_allowed)
	{
		Vector2i direction = Vector2i(1, 0);
		if (!Actor::move(direction, delta))
		{
			set_positioni(get_positioni() + direction);
			step_is_ended();
		}
	}
}