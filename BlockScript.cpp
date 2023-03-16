#include "BlockScript.h"

void BlockScript::tickScript(float deltaTime) {

	// t + 1segon
	t += deltaTime / 1000;

	//exemple de timer per power ups
	if (timer <= 0) {
		//fas algo
		timer += 10000;
	}
	else {
		timer -= deltaTime;
	}


	//glm::vec2 currDir(-1., 0.);

	ComponentHandle<BoxCollider> collider = entity->get<BoxCollider>();
	ComponentHandle<Transform> transform = entity->get<Transform>();

	if (currDir == glm::vec2(-1., 0)) {
		if (transform->position.x - 50 < 1) {
			transform->position.x = 1000;
		}
	}
	else {
		if (transform->position.x + 50 > 1000) {
			transform->position.x = 50;
		}
	}
		
			

	if (collider->collidedWith) {
		collider->collidedWith = false;
	}

	if(t<20)
	transform->position += currDir * (t/20);
	else {

		transform->position += currDir;
	}

}