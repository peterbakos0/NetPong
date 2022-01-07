#include <cstdlib>
#include "GenerateRandomNumber.hpp"

using namespace std;

int GenerateRandomNumber(int minimum, int maximum)
{
	int result = minimum + (rand() % (maximum - minimum + 1));
	return result;
}
