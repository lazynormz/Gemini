#pragma once

#include <memory>
#include <window.h>

namespace Gemini 
{
	struct EngineConfig
	{
		struct WindowConfig
		{
			int width = 800;
			int height = 600;
			const char* title = "Gemini Engine";
		} window;
	};

	class Engine
	{
	public:
		Engine(std::unique_ptr<EngineConfig> config);
		~Engine();
		void Run();

	private: // Methods
		void Initialize();

	private: // Members
		std::unique_ptr<Graphics::Window> m_window;
		std::unique_ptr<SDL_GLContext> m_glContext;
		std::unique_ptr<EngineConfig> m_config;

		bool m_isRunning = false;
	};
}
