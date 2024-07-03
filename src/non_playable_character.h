#ifndef NON_PLAYABLE_CHARACTER_H
#define NON_PLAYABLE_CHARACTER_H

#include "actor.h"

namespace godot
{

class NPC : public Actor {
	GDCLASS(NPC, Actor)

protected:
	static void _bind_methods();
    
public:
	NPC();
    NPC(const size_t p_index);
	~NPC();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

};

}   // namespace godot


#endif // NON_PLAYABLE_CHARACTER_H 