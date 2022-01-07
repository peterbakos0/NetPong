#include "../GameObjects/GameObject.hpp"
#include "Scene.hpp"

void Scene::StartGameObjects()
{
	for(unsigned i = 0; i < gameObjects.size(); i++)
	{
		GameObject* gameObject = gameObjects[i];
		gameObject->Start();
	}
}

void Scene::UpdateGameObjects()
{
	for(unsigned i = 0; i < gameObjects.size(); i++)
	{
		GameObject* gameObject = gameObjects[i];
		gameObject->Update();
	}
}
