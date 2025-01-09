
#include <rend/rend.h>

namespace bolt
{
	struct Core;
	struct Window
	{
		Window();
		~Window();
		rend::ivec2 size() const;

	private:
		friend struct bolt::Core;
		SDL_Window* m_raw;
		SDL_RendContext m_context;
	
		Window(const Window* m_copy);
		Window& operator=(const Window& _assign);
};

}