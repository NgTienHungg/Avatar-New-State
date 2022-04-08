#include "GSPause.h"

GSPause::GSPause()
{
	m_background = nullptr;
	m_frame = new RectangleShape();
	m_headline = new RectangleShape();

	m_button_sound = new Button();
	m_button_music = new Button();
	m_button_resume = new Button();
	m_button_home = new Button();

	m_text_resume = new Text();
	m_text_home = new Text();
}

GSPause::~GSPause()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_frame != nullptr) {
		delete m_frame;
	}
	if (m_headline != nullptr) {
		delete m_headline;
	}
	if (m_button_sound != nullptr) {
		delete m_button_sound;
	}
	if (m_button_music != nullptr) {
		delete m_button_music;
	}
	if (m_button_resume != nullptr) {
		delete m_button_resume;
	}
	if (m_button_home != nullptr) {
		delete m_button_home;
	}
	if (m_text_resume != nullptr) {
		delete m_text_resume;
	}
	if (m_text_home != nullptr) {
		delete m_text_home;
	}
}

GameState GSPause::getTypeState()
{
	return GameState::PAUSE;
}

void GSPause::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(660.f, 660.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/warning"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f + 10.f);

	// headline
	m_headline->setSize(Vector2f(400.f, 100.f));
	m_headline->setTexture(DATA->getTexture("GUI/Headline/paused"));
	m_headline->setOrigin(m_headline->getSize() / 2.f);
	m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + 5.f));
}

void GSPause::initButtonSound()
{
	m_button_sound->initButton(Vector2f(120.f, 120.f), "sound_on");
	m_button_sound->setPosition(m_headline->getPosition() + Vector2f(-90.f, 200.f));
	m_button_sound->setFunction([]() { DATA->setAllowSound(true - DATA->isAllowSound()); });
}

void GSPause::initButtonMusic()
{
	m_button_music->initButton(m_button_sound->getSize(), "music_on");
	m_button_music->setPosition(m_headline->getPosition() + Vector2f(90.f, 200.f));
	m_button_music->setFunction([]() { DATA->setAllowMusic(true - DATA->isAllowMusic()); });
}

void GSPause::initButtonResume()
{
	// button
	m_button_resume->initButton(Vector2f(300.f, 90.f), "bar_green");
	m_button_resume->setPosition(m_frame->getPosition() + Vector2f(0.f, 20.f));
	m_button_resume->setFunction([]() { GAMESTATE->popState(); });

	// text
	m_text_resume->setString("RESUME");
	m_text_resume->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_resume->setCharacterSize(70);
	m_text_resume->setOrigin(m_text_resume->getGlobalBounds().width / 2.f, m_text_resume->getGlobalBounds().height / 2.f);
	m_text_resume->setPosition(m_button_resume->getPosition() + Vector2f(0.f, -20.f));
}

void GSPause::initButtonHome()
{
	// button
	m_button_home->initButton(m_button_resume->getSize(), "bar_gray");
	m_button_home->setPosition(m_button_resume->getPosition() + Vector2f(0.f, 120.f));
	m_button_home->setFunction([]() { GAMESTATE->changeState(GameState::WARNING_HOME); });

	// text
	m_text_home->setString("HOME");
	m_text_home->setFont(*m_text_resume->getFont());
	m_text_home->setCharacterSize(m_text_resume->getCharacterSize());
	m_text_home->setOrigin(m_text_home->getGlobalBounds().width / 2.f, m_text_home->getGlobalBounds().height / 2.f);
	m_text_home->setPosition(m_button_home->getPosition() + Vector2f(0.f, -20.f));
}

void GSPause::updateButtonSound(float delta_time)
{
	m_button_sound->updateButton(delta_time);
	if (DATA->isAllowSound()) {
		m_button_sound->setTexture(DATA->getTexture("GUI/Button/sound_on"));
	}
	else {
		m_button_sound->setTexture(DATA->getTexture("GUI/Button/sound_off"));
	}
}

void GSPause::updateButtonMusic(float delta_time)
{
	m_button_music->updateButton(delta_time);
	if (DATA->isAllowMusic()) {
		m_button_music->setTexture(DATA->getTexture("GUI/Button/music_on"));
	}
	else {
		m_button_music->setTexture(DATA->getTexture("GUI/Button/music_off"));
	}
}

void GSPause::initState()
{
	m_background = DATA->getBackgroundGP();
	this->initBoard();
	this->initButtonSound();
	this->initButtonMusic();
	this->initButtonResume();
	this->initButtonHome();
}

void GSPause::updateState(float delta_time)
{
	this->updateButtonSound(delta_time);
	this->updateButtonMusic(delta_time);
	m_button_resume->updateButton(delta_time);
	m_button_home->updateButton(delta_time);
}

void GSPause::renderState(RenderWindow* window)
{
	window->draw(*m_background);
	window->draw(*m_frame);
	window->draw(*m_headline);
	
	window->draw(*m_button_sound);
	window->draw(*m_button_music);

	window->draw(*m_button_resume);
	window->draw(*m_text_resume);

	window->draw(*m_button_home);
	window->draw(*m_text_home);
}