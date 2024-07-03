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


namespace godot {

class Level : public Node2D {
	GDCLASS(Level, Node2D)

protected:
	static void _bind_methods();

private:
    MC* mc;
    Vector<NPC*> v_npc;
	HashSet<int> angry_npc;

	List<int> queue;

    Input *i;
	Vector2i mouse_position;
	Area2D* mouse_select;

	

	bool current_step;
	int current_obj;
	size_t count_of_steps;

public:
	Level();
	~Level();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

	Vector2i get_mouse_position();
	void set_mouse_position();
	void init_queue();
	void _step_ended();

};

}	// namespace godot

#endif // LEVEL_H