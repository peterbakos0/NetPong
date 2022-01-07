#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "../../GameObjects/GameObject.hpp"

class Video
{
public:
	virtual void Start() = 0;
	virtual void Show(GameObject* gameObject) = 0;
	virtual void Clear() = 0;
	virtual void Render() = 0;
};

#endif
