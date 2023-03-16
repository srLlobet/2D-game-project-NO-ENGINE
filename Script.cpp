#include "Script.h"

Script::Script()
{
}

Script::Script(GLFWwindow* window, World* world, Entity* entity) {
	this->window = window;
	this->entity = entity;
	this->world = world;
}

Script::Script(GLFWwindow* window, World* world, Entity* entity, glm::vec2 currDir) {
	this->window = window;
	this->entity = entity;
	this->world = world;
	this->currDir = currDir;
}



void Script::startScript()
{
	
}

void Script::tickScript(float deltaTime)
{

}


void Script::Delete() {
	delete this;
}