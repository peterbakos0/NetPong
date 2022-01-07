#ifndef FILECONFIGSETTER_HPP
#define FILECONFIGSETTER_HPP

#include "ConfigSetter.hpp"

class FileConfigSetter : public ConfigSetter
{
public:
	void SetConfig() override;
};

#endif
