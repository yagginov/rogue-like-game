#ifndef GOD_H
#define GOD_H

#include <godot_cpp/classes/node2d.hpp>


namespace godot {

class God : public Node2D {
	GDCLASS(God, Node2D)

protected:
	static void _bind_methods();

public:
	God();
	~God();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

};

}	// namespace godot

#endif // GOD_H