
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <stdexcept>
#include "Component.h"

namespace bolt
{
	struct SoundSource : Component
	{

		void on_initialize();
	private:
		ALuint bufferId = 0;
		ALuint sourceId = 0;
		void on_tick();
		void load_ogg(const std::string&, std::vector<unsigned char>&, ALenum&, ALsizei&);
	};
}