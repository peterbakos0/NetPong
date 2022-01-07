#include "GetNumberSign.hpp"

int GetNumberSign(int number)
{
	int result = (number > 0) - (number < 0);
	return result;
}
