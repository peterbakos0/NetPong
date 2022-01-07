#include <string>
#include "String2Bool.hpp"

using namespace std;

bool String2Bool(string str)
{
	bool result = false;

	if(str == "true")
	{
		result = true;
	}

	return result;
}
