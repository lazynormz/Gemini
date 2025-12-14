#include <engine.h>

int main()
{
	Gemini::Engine engine(std::make_unique<Gemini::EngineConfig>(Gemini::EngineConfig {
		.window = {
			.width = 1280,
			.height = 720,
			.title = "My Gemini Game"
		}
	}));

	engine.Run();

	return 0;
}