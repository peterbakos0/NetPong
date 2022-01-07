#include "../Helpers/PositionHelper.hpp"
#include "GameObject.hpp"

GameObject::GameObject()
{
	positionHelper = new PositionHelper(this);
}
