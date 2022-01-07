#include <algorithm>
#include "ClampNumber.hpp"

using namespace std;

int ClampNumber(int number, int minimum, int maximum)
{
	int result = number;

	result = min(result, maximum);
	result = max(result, minimum);

	return result;
}
