#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL3/SDL.h>

namespace Gemini::Graphics {

	class Window {
	public:
		Window(int width, int height, const char* title);
		~Window();
	private:
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
	};

}
#endif // __WINDOW_H__