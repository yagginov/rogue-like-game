#include "main_character.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;



void MC::_bind_methods() 
{
}


MC::MC() :
    Actor(0)
{
	// Initialize any variables here.
	state = States::idle;
}

MC::MC(const size_t p_index) :
    Actor(p_index)
{
	// Initialize any variables here.
	state = States::idle;
}

MC::~MC() 
{
	// Add your cleanup here.
}

void MC::_ready() 
{
	i = Input::get_singleton();

}

void MC::_process(double delta) 
{

}

void MC::_physics_process(double delta) 
{
	if (is_step_allowed)
	{
		set_mouse_position();
		switch(state)
		{
		case States::idle:
			direction = mouse_position - get_positioni();
			if (direction.length() == 1 && i->is_action_just_pressed("ui_select"))
			{
				state = States::move;
			}
			break;

		case States::move:
			if (!Actor::move(direction, delta))
			{
				state = States::idle;
				set_positioni(get_positioni() + direction);
				step_is_ended();
			}
			break;
		}
	}
}

void MC::set_mouse_position()
{
	Vector2i global_mouse_pos = cast_to<Node2D>(this->get_parent())->get_global_mouse_position();
	mouse_position = Vector2i(global_mouse_pos.x >> 4, global_mouse_pos.y >> 4);

}


			/*if (!Engine::get_singleton()->is_editor_hint()) {
        		UtilityFunctions::print(String("mouse_position = "));
				UtilityFunctions::print(mouse_position);
    		}*/