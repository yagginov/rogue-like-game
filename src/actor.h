#ifndef ACTOR_H
#define ACTOR_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/variant/vector2i.hpp>
#include <godot_cpp/variant/vector2.hpp>

#include "atack_type.h"

namespace godot
{

class Actor : public CharacterBody2D {
	GDCLASS(Actor, CharacterBody2D)

protected:
	static void _bind_methods();

private:
    int max_hp;
    int hp;
    size_t index;
    Vector2i positioni;

    double speed;

protected:
    bool is_step_allowed;

public:
	Actor();
    Actor(const size_t p_index);
	~Actor();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;

    bool move(const Vector2i& direction, double delta);
    virtual void atack();
    void take_damage(const int damage);

    void step_is_ended();
    void make_step();

    void set_max_hp(const int p_max_hp);
    int get_max_hp() const;

    void set_speed(const double p_speed);
    double get_speed() const;

    void set_positioni(const Vector2i& p_position);
    Vector2i get_positioni() const;
};

}   // namespace godot


#endif // ACTOR_H 