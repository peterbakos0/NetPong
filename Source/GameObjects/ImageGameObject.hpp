#ifndef IMAGEGAMEOBJECT_HPP
#define IMAGEGAMEOBJECT_HPP

#include <string>
#include "GameObject.hpp"

class ImageGameObject : public GameObject
{
public:
	ImageGameObject();

	std::string imageFilePath;
};

#endif
