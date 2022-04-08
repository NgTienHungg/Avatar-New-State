#include "GSIntro.h"

GSIntro::GSIntro()
{
	m_logo = new RectangleShape();
	m_background = new RectangleShape();
	m_shadow = new RectangleShape();

	m_logo_time = 2.f;
	m_intro_time = 3.f;
	m_current_time = 0.f;
}

GSIntro::~GSIntro()
{
	if (m_logo != nullptr) {
		delete m_logo;
	}
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_shadow != nullptr) {
		delete m_shadow;
	}
}

GameState GSIntro::getTypeState()
{
	return GameState::INTRO;
}

void GSIntro::initState()
{
	// logo
	m_logo->setTexture(DATA->getTexture("Background/logo"));
	m_logo->setSize(Vector2f(ScreenHeight, ScreenHeight) * 0.75f);
	m_logo->setOrigin(m_logo->getSize() / 2.f);
	m_logo->setPosition(ScreenWidth / 2, ScreenHeight / 2);

	// background
	m_background->setTexture(DATA->getTexture("Background/intro"));
	m_background->setSize(Vector2f(ScreenWidth, ScreenHeight));
	m_background->setFillColor(Color::Transparent);

	// shadow
	m_shadow->setFillColor(Color(0, 0, 0, 0));
	m_shadow->setSize(Vector2f(ScreenWidth, ScreenHeight));
}

void GSIntro::updateState(float delta_time)
{
	m_current_time += delta_time;
	if (m_current_time >= m_logo_time + m_intro_time) {
		GAMESTATE->changeState(GameState::GET_USER_INFO);
		return;
	}
	if (m_current_time < 0.75f) {
		m_logo->setFillColor(Color(255, 255, 255, 255));
		m_background->setFillColor(Color::Transparent);
		m_shadow->setFillColor(Color::Transparent);
	}
	else if (m_current_time >= 0.75f && m_current_time < 2.f) {
		float alpha = 255 * (m_current_time - 0.75f) / 1.5f;
		m_shadow->setFillColor(Color(0, 0, 0, (Uint8)alpha));
		if (m_current_time >= 1.9f) {
			DATA->playMusic("background");
		}
	}
	else if (m_current_time >= 2.f && m_current_time < 3.f) {
		m_background->setFillColor(Color(255, 255, 255, 255));
		m_logo->setFillColor(Color::Transparent);
		m_shadow->setFillColor(Color::Transparent);
	}
	else {
		float alpha = 255 * (m_current_time - 2.f - 1.f) / 2.f;
		m_shadow->setFillColor(Color(0, 0, 0, (Uint8)alpha));
	}
}

void GSIntro::renderState(RenderWindow* window)
{
	window->draw(*m_background);
	window->draw(*m_logo);
	window->draw(*m_shadow);
}