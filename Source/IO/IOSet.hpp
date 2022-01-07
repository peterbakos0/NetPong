#ifndef IOSET_HPP
#define IOSET_HPP

#include "ConfigSetter/ConfigSetter.hpp"
#include "Video/Video.hpp"
#include "ActionGetter/ActionGetter.hpp"
#include "Communicator/Communicator.hpp"

class IOSet
{
public:
	IOSet();

	ConfigSetter* configSetter;
	Video* video;
	ActionGetter* actionGetter;
	Communicator* communicator;
};

#endif
