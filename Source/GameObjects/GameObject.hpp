#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../Models/Position.hpp"
#include "../Models/Size.hpp"
#include "../Models/GameObjectType.hpp"
#include "../Helpers/IPositionHelper.hpp"

class GameObject
{
public:
	GameObject();

	float opacity;
	struct Position position;
	struct Size size;
	GameObjectType type;

	virtual void Start() = 0;
	virtual void Update() = 0;
protected:
	IPositionHelper* positionHelper;
};

#endif
