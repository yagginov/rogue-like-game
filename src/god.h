#ifndef GOD_H
#define GOD_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/templates/vector.hpp>

#include "level.h"


namespace godot {

class God : public Node2D {
	GDCLASS(God, Node2D)

protected:
	static void _bind_methods();

private:
	Vector<Level*> levels;

public:
	God();
	~God();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

};

}	// namespace godot

#endif // GOD_H