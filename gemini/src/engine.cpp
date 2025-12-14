#include <stdio.h>
#include <engine.h>
#include <SDL3/SDL.h>
#include <glad/glad.h>

namespace Gemini
{
	Engine::Engine(std::unique_ptr<EngineConfig> config)
	{
		m_config = std::move(config);
	}

	Engine::~Engine()
	{
		SDL_Quit();
	}

	void Engine::Initialize()
	{
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		{
			fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
		}
		m_window = std::make_unique<Graphics::Window>(m_config->window.width, m_config->window.height, m_config->window.title);

		m_isRunning = true;
	}

	void Engine::Run()
	{
		Initialize();

		while (m_isRunning)
		{
			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_EVENT_QUIT)
				{
					m_isRunning = false;
				}
			}

			// Game update and rendering logic would go here
		}
	}
}