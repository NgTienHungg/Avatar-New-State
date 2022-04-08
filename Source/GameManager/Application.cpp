#include "Application.h"
#include "../GameState/GSBase.h"

Application::Application()
{
	m_window = new RenderWindow();
	m_event = Event();
	m_clock = Clock();
}

Application::~Application()
{
	if (m_window != nullptr) {
		delete m_window;
	}
}

RenderWindow* Application::getWindow()
{
	return m_window;
}

Event Application::getEvent()
{
	return m_event;
}

void Application::initApp()
{
	m_window = new RenderWindow(VideoMode(ScreenWidth, ScreenHeight), TitleGame, Style::Close);
	m_window->setFramerateLimit(60);
	m_window->setVerticalSyncEnabled(false);

	GAMESTATE->changeState(GameState::INTRO);
}

void Application::updateApp(float delta_time)
{
	if (GAMESTATE->needToChangeState()) {
		GAMESTATE->pushState();
	}
	GAMESTATE->getCurrentState()->updateState(delta_time);
	DATA->updateMusic();
}

void Application::renderApp()
{
	m_window->clear(Color::Black);
	GAMESTATE->getCurrentState()->renderState(m_window);
	m_window->display();
}

void Application::runApp()
{
	this->initApp();
	while (m_window->isOpen()) {
		float delta_time = m_clock.restart().asSeconds();
		while (m_window->pollEvent(m_event)) {
			if (m_event.type == Event::Closed) {
				m_window->close();
			}
		}
		this->updateApp(delta_time);
		this->renderApp();
	}
}