#ifndef LEVEL_H
#define LEVEL_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/camera2d.hpp>

#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/templates/hash_set.hpp>

#include "main_character.h"
#include "non_playable_character.h"
#include "enemy.h"


namespace godot {

class Level : public Node2D {
	GDCLASS(Level, Node2D)

protected:
	static void _bind_methods();

private:
    MC* mc;
    Vector<NPC*> v_npc;
	HashSet<int> angry_npc;
	
	Vector2i mouse_position;

	List<int> queue;
	bool current_step;
	size_t count_of_steps;
    
	Input *i;
	Area2D* mouse_select;
	Camera2D* camera;

	double camera_speed;

private:
	void set_mouse_position();
	void init_queue();

public:
	Level();
	~Level();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

	void _step_ended();

	void set_camera_speed(const double p_camera_speed);
	double get_camera_speed() const;

};

}	// namespace godot

#endif // LEVEL_H