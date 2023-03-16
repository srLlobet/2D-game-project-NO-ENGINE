#include "RenderSystem.h"

RenderSystem::RenderSystem(int width, int height) {
    projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);

    sr.Init();
}

void RenderSystem::tick(World* world, float deltaTime) 
{
    world->each<Sprite>([&](Entity* ent, ComponentHandle<Sprite> sprite) {


        ComponentHandle<Transform> transform = ent->get<Transform>();

        Texture texture = textureManager.GetTexture(sprite->filepath);
           
        if (sprite->autoSize) {
            sr.DrawSprite(texture, projection, transform->position, texture.GetSize(), transform->rotation, sprite->color, sprite->shaderName);
        }
        else {
            sr.DrawSprite(texture, projection, transform->position, sprite->size, transform->rotation, sprite->color, sprite->shaderName);
        }

        


        if (sprite->shaderName == "scroll") {

            t += deltaTime / 1000;

            sr.shaderScroll->SetFloat("Time", t);


        }

    });
}