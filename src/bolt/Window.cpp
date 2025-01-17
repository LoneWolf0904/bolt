#include "Window.h"

#include <stdexcept>

namespace bolt
{
Window::Window()
{
	// Set window width and height
	int winw = 800;
	int winh = 600;

	// Create a window
	m_raw = SDL_CreateWindow("Engine Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND);


	if(!m_raw)
	{
	 throw std::runtime_error("Failed to create window");
	}

	m_context = SDL_Rend_CreateContext(m_raw);

	if (!m_context)
	{
		throw std::runtime_error("Failed to create rend context");
	}
}

Window::~Window()
{
	// Destroy the window
	SDL_Rend_DeleteContext(m_context);
	SDL_DestroyWindow(m_raw);
	SDL_Quit();
}

rend::ivec2 Window::size() const
{
	int w = 0;
	int h = 0;

	SDL_GetWindowSize(m_raw, &w, &h);
	rend::ivec2 rtn(w, h);
	return rtn;
}

}
