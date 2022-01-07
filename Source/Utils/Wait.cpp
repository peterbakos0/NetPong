#include <thread>
#include <chrono>
#include "Wait.hpp"

using namespace std;
using namespace this_thread;
using namespace chrono;

void Wait(int timeMs)
{
	sleep_for(milliseconds(timeMs));
}
