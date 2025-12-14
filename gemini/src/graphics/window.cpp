#include <stdio.h>
#include <SDL3/SDL.h>
#include <window.h>

namespace Gemini::Graphics
{
	Window::Window(int width, int height, const char* title)
	{
		m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);

		if (m_window == nullptr)
		{
			fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
			SDL_Quit();
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		m_glContext = SDL_GL_CreateContext(m_window);

		if (m_glContext == nullptr)
		{
			fprintf(stderr, "Failed to create OpenGL context: %s\n", SDL_GetError());
			SDL_DestroyWindow(m_window);
			SDL_Quit();
		}
	}

	Window::~Window()
	{
		SDL_GL_DestroyContext(m_glContext);
		SDL_DestroyWindow(m_window);
	}
}