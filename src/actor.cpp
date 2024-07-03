#include "actor.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;


void Actor::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("get_max_hp"), &Actor::get_max_hp);
	ClassDB::bind_method(D_METHOD("set_max_hp", "p_max_hp"), &Actor::set_max_hp);
	ClassDB::add_property("Actor", PropertyInfo(Variant::FLOAT, "max_hp"), "set_max_hp", "get_max_hp");

    ClassDB::bind_method(D_METHOD("get_position"), &Actor::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "p_position"), &Actor::set_position);
	ClassDB::add_property("Actor", PropertyInfo(Variant::VECTOR2I, "position"), "set_position", "get_position");

    ADD_SIGNAL(MethodInfo("dead", PropertyInfo(Variant::INT, "index")));
}


Actor::Actor() 
{
	// Initialize any variables here.
    max_hp = 3;
    hp = max_hp;
    index = 0;
}

Actor::Actor(const size_t p_index):
index(p_index) 
{
	// Initialize any variables here.
    max_hp = 3;
    hp = max_hp;
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

void Actor::move(const Vector2i& direction)
{

}

void Actor::atack(const lehit::AtackType& atack_type)
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

void Actor::set_max_hp(const int p_max_hp)
{
    max_hp = p_max_hp;
}

int Actor::get_max_hp() const
{
    return max_hp;
}

void Actor::set_position(const Vector2i& p_position)
{
    position = p_position;
}

Vector2i Actor::get_position() const
{
    return position;
}