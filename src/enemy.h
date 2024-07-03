#ifndef ENEMY_H
#define ENEMY_H

#include "non_playable_character.h"
#include "atack_type.h"

namespace godot
{

class Enemy : public NPC {
	GDCLASS(Enemy, NPC)

private:

    enum States
    {
        idle = 0,
        move = 1,
        rotate = 2
    };

protected:
	static void _bind_methods();
    
private:
	Vector2i direction;
	States state;
    lehit::AtackType atack_type;

public:
	Enemy();
    Enemy(const size_t p_index);
	~Enemy();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;
};

}   // namespace godot


#endif // ENEMY_H 