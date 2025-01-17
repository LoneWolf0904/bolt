
#include <iostream>
#include <vector>

namespace bolt
{
	struct Core;

	// struct keyboard handles input
	struct Keyboard
	{
	public:
		
		// checks if a key is currently being pressed
		bool isKey(int key);

		// checks if key was just being pressed in the current frame
		bool isKeyPressed(int key);

		// checks if key was just released in the current frame
		bool isKeyReleased(int key);

	private:
		friend struct bolt::Core;
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;

	};
}
