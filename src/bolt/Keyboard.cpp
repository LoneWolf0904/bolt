#include "Keyboard.h"

namespace bolt
{
	bool Keyboard::isKey(int key)
	{
		for (int i = 0; i < keys.size(); ++i)
		{
			if (keys[i] == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::isKeyPressed(int key)
	{
		for (int i = 0; i < pressedKeys.size(); ++i)
		{
			if (pressedKeys[i] == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::isKeyReleased(int key)
	{
		for (int i = 0; i < releasedKeys.size(); ++i)
		{
			if (releasedKeys[i] == key)
			{
				return true;
			}
		}
		return false;
	}
}