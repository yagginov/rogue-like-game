#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H

#include "actor.h"

namespace godot
{

class MC : public Actor {
	GDCLASS(MC, Actor)

protected:
	static void _bind_methods();
    
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