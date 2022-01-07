#include "ConfigSetter/FileConfigSetter.hpp"
#include "Video/SDLVideo.hpp"
#include "ActionGetter/SDLKeyboardActionGetter.hpp"
#include "Communicator/SocketCommunicator.hpp"
#include "IOSet.hpp"

IOSet::IOSet()
{
	configSetter = new FileConfigSetter();
	video = new SDLVideo();
	actionGetter = new SDLKeyboardActionGetter();
	communicator = new SocketCommunicator();
}
