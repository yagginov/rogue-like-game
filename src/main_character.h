#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node2d.hpp>

#include "actor.h"

namespace godot
{

class MC : public Actor {
	GDCLASS(MC, Actor)

private:
	enum States
	{
		idle = 0,
		move = 1,
		atack = 2
	};

protected:
	static void _bind_methods();
    
private:
	Input *i;
	Vector2i mouse_position;
	Vector2i direction;
	States state;

	void set_mouse_position();

public:
	MC();
    MC(const size_t p_index);
	~MC();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;
};

}   // namespace godot


#endif // MAIN_CHARACTER_H 