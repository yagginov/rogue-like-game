#include "actor.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;


void Actor::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("get_max_hp"), &Actor::get_max_hp);
	ClassDB::bind_method(D_METHOD("set_max_hp", "p_max_hp"), &Actor::set_max_hp);
	ClassDB::add_property("Actor", PropertyInfo(Variant::INT, "max_hp"), "set_max_hp", "get_max_hp");

    ClassDB::bind_method(D_METHOD("get_speed"), &Actor::get_speed);
	ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Actor::set_speed);
	ClassDB::add_property("Actor", PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ClassDB::bind_method(D_METHOD("get_positioni"), &Actor::get_positioni);
	ClassDB::bind_method(D_METHOD("set_positioni", "p_position"), &Actor::set_positioni);
	ClassDB::add_property("Actor", PropertyInfo(Variant::VECTOR2I, "positioni"), "set_positioni", "get_positioni");

    ClassDB::bind_method(D_METHOD("step_is_ended"), &Actor::step_is_ended);
    ClassDB::bind_method(D_METHOD("make_step"), &Actor::make_step);

    ADD_SIGNAL(MethodInfo("dead", PropertyInfo(Variant::INT, "index")));
    ADD_SIGNAL(MethodInfo("step_ended"));
}


Actor::Actor() 
{
	// Initialize any variables here.
    max_hp = 3;
    hp = max_hp;
    index = 0;
    is_step_allowed = false;

    speed = 200;
}

Actor::Actor(const size_t p_index):
index(p_index) 
{
	// Initialize any variables here.
    max_hp = 3;
    hp = max_hp;

    is_step_allowed = false;

    speed = 200;
}

Actor::~Actor() 
{
	// Add your cleanup here.
}

void Actor::_ready() 
{
    
}

void Actor::_process(double delta) 
{

}

void Actor::_physics_process(double delta) 
{

}

bool Actor::move(const Vector2i& direction, double delta)
{
    Vector2 pos = get_position();
    Vector2 to_pos = Vector2((positioni.x + direction.x) * 16 + 8, (positioni.y + direction.y) * 16 + 8);
    
    pos = pos.move_toward(to_pos, speed * delta);
    set_position(pos);

    if (pos == to_pos)
    {
        return false;
    }
    return true;

}

void Actor::atack()
{

}

void Actor::take_damage(const int damage)
{
    hp -= damage;
    if (hp <= 0)
    {
        hp = 0;
        emit_signal("dead", index);
    }
}

void Actor::step_is_ended()
{
    is_step_allowed = false;
    emit_signal("step_ended");
}

void Actor::make_step()
{
    is_step_allowed = true;
}

void Actor::set_max_hp(const int p_max_hp)
{
    max_hp = p_max_hp;
}

int Actor::get_max_hp() const
{
    return max_hp;
}

void Actor::set_speed(const double p_speed)
{
    speed = p_speed;
}

double Actor::get_speed() const
{
    return speed;
}

void Actor::set_positioni(const Vector2i& p_position)
{
    positioni = p_position;
    set_position(Vector2(positioni.x * 16 + 8, positioni.y * 16 + 8));
}

Vector2i Actor::get_positioni() const
{
    return positioni;
}