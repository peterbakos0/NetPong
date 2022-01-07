#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "../GameObjects/GameObject.hpp"

class Scene
{
public:
	std::vector<GameObject*> gameObjects;

	virtual void Start() = 0;
	virtual void Update() = 0;
protected:
	void StartGameObjects();
	void UpdateGameObjects();
};

#endif
