#pragma once
#include "DataManager.h"
#include "GameStateManager.h"

#define APP Application::getInstance()

class Application : public Singleton<Application>
{
private:
	RenderWindow* m_window;
	Event m_event;
	Clock m_clock;

	void initApp();
	void updateApp(float delta_time);
	void renderApp();

public:
	Application();
	~Application();

	RenderWindow* getWindow();
	Event getEvent();

	void runApp();
};