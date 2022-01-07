#ifndef OLINE_HPP
#define OLINE_HPP

#include "ImageGameObject.hpp"

class OLine : public ImageGameObject
{
public:
	OLine();

	void Start() override;
	void Update() override;
};

#endif
