#include "main_character.h"
#include <godot_cpp/core/class_db.hpp>


using namespace godot;


void MC::_bind_methods() 
{
}


MC::MC() :
    Actor(0)
{
	// Initialize any variables here.
}

MC::MC(const size_t p_index) :
    Actor(p_index)
{
	// Initialize any variables here.
}

MC::~MC() 
{
	// Add your cleanup here.
}

void MC::_ready() 
{

}

void MC::_process(double delta) 
{

}

void MC::_physics_process(double delta) 
{

}