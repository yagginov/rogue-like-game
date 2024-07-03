#ifndef LEVEL_H
#define LEVEL_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/templates/vector.hpp>

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

public:
	Level();
	~Level();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

};

}	// namespace godot

#endif // LEVEL_H