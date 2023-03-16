#include "BallScript.h"

void BallScript::startScript() {

}

void BallScript::tickScript(float deltaTime) {



	ComponentHandle<Transform> transform = entity->get<Transform>();

	transform->position += currDir * deltaTime / 2.f;


	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		transform->position += glm::vec2(1., 0.) * deltaTime / 2.f;

		if (transform->position.x > 1000) transform->position.x = 100;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		transform->position += glm::vec2(-1., 0.) * deltaTime / 2.f;

		
	}


	if (transform->position.x < 0 && currDir.x < 0) currDir.x *= -1;
	if (transform->position.x > limits.x && currDir.x > 0) currDir.x *= -1;

	if (transform->position.y < -400 || transform->position.y > 1200) {
		currDir.y *= -1;
		transform->position.y = 350;
	}


	CheckCollisions();

}

void BallScript::CheckCollisions() {

	ComponentHandle<Transform> transform = entity->get<Transform>();
	ComponentHandle<BoxCollider> collider = entity->get<BoxCollider>();

	world->each<BoxCollider>([&](Entity* other_ent, ComponentHandle<BoxCollider> other_collider) {

		if (other_ent->getEntityId() == entity->getEntityId()) {
			return;
		}

		ComponentHandle<Transform> other_transform = other_ent->get<Transform>();

		glm::vec2 p1 = transform->position;
		glm::vec2 p2 = other_transform->position;

		if (p1.x - collider->width / 2 < p2.x + other_collider->width / 2 &&
			p1.x + collider->width / 2 > p2.x - other_collider->width / 2 &&
			p1.y - collider->height / 2 < p2.y + other_collider->height / 2 &&
			p1.y + collider->height / 2 > p2.y - other_collider->height / 2)
		{
			if (other_transform->position.y < transform->position.y && currDir.y < 0) {
				currDir.y *= -1;
			}
			if (other_transform->position.y > transform->position.y && currDir.y > 0) {
				currDir.y *= -1;
			}
			other_collider->collidedWith = true;
		}


	});

}