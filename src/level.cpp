#include "level.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;


void Level::_bind_methods() 
{
	ClassDB::bind_method(D_METHOD("_step_ended"), &Level::_step_ended);

	ClassDB::bind_method(D_METHOD("get_camera_speed"), &Level::get_camera_speed);
	ClassDB::bind_method(D_METHOD("set_camera_speed", "p_camera_speed"), &Level::set_camera_speed);
	ClassDB::add_property("Level", PropertyInfo(Variant::FLOAT, "camera_speed"), "set_camera_speed", "get_camera_speed");
}


Level::Level() 
{
	// Initialize any variables here.

	i = nullptr;
	mouse_select = nullptr;
	camera = nullptr;

	count_of_steps = 0;

	current_step = true;
	current_obj = -1;

	camera_speed = 200;
}

Level::~Level() 
{
	// Add your cleanup here.
}

void Level::_ready() 
{
    i = Input::get_singleton();
	mouse_select = get_node<Area2D>("MouseSelect");
	camera = get_node<Camera2D>("Camera");

	mc = get_node<MC>("MC");
	mc->connect("step_ended", Callable(this, "_step_ended"));
	for (auto& it : v_npc)
	{
		it->connect("step_ended", Callable(this, "_step_ended"));
	}

	init_queue();
}

void Level::_process(double delta) 
{

}

void Level::_physics_process(double delta) 
{
	set_mouse_position();
	Vector2 input_direction = i->get_vector("ui_left", "ui_right", "ui_up", "ui_down").normalized();

	if (input_direction != Vector2(0.0, 0.0))
	{
		Vector2 camera_position = camera->get_position();
		camera_position = camera_position.move_toward(camera_position + Vector2(camera_speed, camera_speed) * input_direction, delta * camera_speed);
		camera->set_position(camera_position);
	}

	if (current_step)
	{
		if (!queue.size())
		{
			++count_of_steps;
			init_queue();
		}
		else
		{
			current_obj = *queue.begin();
			queue.pop_front();
			current_step = false;

			if (current_obj == -1)
			{
				mc->make_step();
			}
			else
			{
				v_npc[current_obj]->make_step();
			}
		}
	}
	
	
}

Vector2i Level::get_mouse_position()
{
	return mouse_position;
}

void Level::set_mouse_position()
{
	Vector2i global_mouse_pos = get_global_mouse_position();
	mouse_position = Vector2i(global_mouse_pos.x >> 4, global_mouse_pos.y >> 4);
	mouse_select->set_position(Vector2((global_mouse_pos.x & 0xfffffffffffffff0) + 8, (global_mouse_pos.y & 0xfffffffffffffff0) + 8));
}

void Level::init_queue()
{
	queue.push_back(-1);

	for (const auto& it : angry_npc)
	{
		queue.push_back(it);
	}
}

void Level::_step_ended()
{
	current_step = true;
}

void Level::set_camera_speed(const double p_camera_speed)
{
	camera_speed = p_camera_speed;
}
double Level::get_camera_speed() const
{
	return camera_speed;
}