#pragma once

#include<iostream>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

#include "ECS.h"
#include "Components.h"

using namespace std;
using namespace ECS;

class Script
{
public:

    Script();

    Script(GLFWwindow* window, World* world,  Entity* entity);

    Script(GLFWwindow* window, World* world, Entity* entity, glm::vec2 currDir);

    virtual void startScript();
    
    virtual void tickScript(float deltaTime);


    void Delete();

protected:
    Entity* entity;
    GLFWwindow* window;
    World* world;
    glm::vec2 currDir;
};