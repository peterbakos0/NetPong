#include <string>
#include <vector>
#include "../../Utils/String2Bool.hpp"
#include "../../Utils/SplitText.hpp"
#include "../../Utils/ReadFile.hpp"
#include "../../Models/Config.hpp"
#include "FileConfigSetter.hpp"

using namespace std;

void FileConfigSetter::SetConfig()
{
	string plain = ReadFile("Config.txt");
	vector<string> lines = SplitText(plain, '\n');

	for(unsigned i = 0; i < lines.size(); i++)
	{
		string line = lines[i];

		vector<string> pairs = SplitText(line, '=');

		if(pairs.size() < 2)
		{
			continue;
		}

		string key = pairs[0];
		string value = pairs[1];

		if(key == "FPS")
		{
			config.FPS = stoi(value);
		}
		else if(key == "WINDOW_WIDTH")
		{
			config.WINDOW_WIDTH = stoi(value);
		}
		else if(key == "WINDOW_HEIGHT")
		{
			config.WINDOW_HEIGHT = stoi(value);
		}
		else if(key == "ACTION_CONFIRM_KEY_CODE")
		{
			config.ACTION_CONFIRM_KEY_CODE = stoi(value);
		}
		else if(key == "ACTION_QUIT_KEY_CODE")
		{
			config.ACTION_QUIT_KEY_CODE = stoi(value);
		}
		else if(key == "ACTION_MOVE_UP_KEY_CODE")
		{
			config.ACTION_MOVE_UP_KEY_CODE = stoi(value);
		}
		else if(key == "ACTION_MOVE_DOWN_KEY_CODE")
		{
			config.ACTION_MOVE_DOWN_KEY_CODE = stoi(value);
		}
		else if(key == "MINIMUM_WIN_SCORE")
		{
			config.MINIMUM_WIN_SCORE = stoi(value);
		}
		else if(key == "MINIMUM_SCORE_DIFFERENCE")
		{
			config.MINIMUM_SCORE_DIFFERENCE = stoi(value);
		}
		else if(key == "SCORED_WAIT_TIME_MS")
		{
			config.SCORED_WAIT_TIME_MS = stoi(value);
		}
		else if(key == "IS_HOST")
		{
			config.IS_HOST = String2Bool(value);
		}
		else if(key == "IP_ADDRESS")
		{
			config.IP_ADDRESS = value;
		}
		else if(key == "PORT")
		{
			config.PORT = stoi(value);
		}
		else if(key == "PADDLE_GAP")
		{
			config.PADDLE_GAP = stoi(value);
		}
		else if(key == "PADDLE_WIDTH")
		{
			config.PADDLE_WIDTH = stoi(value);
		}
		else if(key == "PADDLE_HEIGHT")
		{
			config.PADDLE_HEIGHT = stoi(value);
		}
		else if(key == "PADDLE_SPEED")
		{
			config.PADDLE_SPEED = stoi(value);
		}
		else if(key == "BALL_DIAMETER")
		{
			config.BALL_DIAMETER = stoi(value);
		}
		else if(key == "BALL_INITIAL_SPEED_X")
		{
			config.BALL_INITIAL_SPEED_X = stoi(value);
		}
		else if(key == "MINIMUM_BALL_INITIAL_SPEED_Y")
		{
			config.MINIMUM_BALL_INITIAL_SPEED_Y = stoi(value);
		}
		else if(key == "MAXIMUM_BALL_INITIAL_SPEED_Y")
		{
			config.MAXIMUM_BALL_INITIAL_SPEED_Y = stoi(value);
		}
		else if(key == "BALL_SPEED_X_BOUNCE_INCREMENT")
		{
			config.BALL_SPEED_X_BOUNCE_INCREMENT = stoi(value);
		}
		else if(key == "BALL_SPEED_Y_BOUNCE_FACTOR")
		{
			config.BALL_SPEED_Y_BOUNCE_FACTOR = stof(value);
		}
		else if(key == "MAXIMUM_BALL_SPEED_X")
		{
			config.MAXIMUM_BALL_SPEED_X = stoi(value);
		}
	}
}
