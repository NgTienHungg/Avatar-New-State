#include "GSSetting.h"

GSSetting::GSSetting()
{
	m_background = new Background();
	m_frame = new RectangleShape();

	m_button_sound = new Button();
	m_button_music = new Button();
	m_button_back = new Button();

	m_text_sound = new Text();
	m_text_music = new Text();
	m_text_back = new Text();
}

GSSetting::~GSSetting()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_frame != nullptr) {
		delete m_frame;
	}
	if (m_button_sound != nullptr) {
		delete m_button_sound;
	}
	if (m_button_music != nullptr) {
		delete m_button_music;
	}
	if (m_button_back != nullptr) {
		delete m_button_back;
	}
	if (m_text_sound != nullptr) {
		delete m_text_music;
	}
	if (m_text_music != nullptr) {
		delete m_text_music;
	}
	if (m_text_back != nullptr) {
		delete m_text_back;
	}
}

GameState GSSetting::getTypeState()
{
	return GameState::SETTING;
}

void GSSetting::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(680.f, 600.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/warning"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f);
}

void GSSetting::initButtonSound()
{
	m_button_sound->initButton(Vector2f(150.f, 70.f), "on");
	m_button_sound->setPosition(m_frame->getPosition() + Vector2f(110.f, -130.f));
	m_button_sound->setFunction([]() { DATA->setAllowSound(true - DATA->isAllowSound()); });

	m_text_sound->setString("SOUND");
	m_text_sound->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_sound->setCharacterSize(70);
	m_text_sound->setFillColor(Color(255, 51, 153));
	m_text_sound->setOutlineThickness(1.f);
	m_text_sound->setOutlineColor(Color::Black);
	m_text_sound->setPosition(m_button_sound->getPosition() + Vector2f(-290.f, -48.f));
}

void GSSetting::initButtonMusic()
{
	m_button_music->initButton(m_button_sound->getSize(), "on");
	m_button_music->setPosition(m_button_sound->getPosition() + Vector2f(0.f, 120.f));
	m_button_music->setFunction([]() { DATA->setAllowMusic(true - DATA->isAllowMusic()); });

	m_text_music->setString("MUSIC");
	m_text_music->setFont(*m_text_sound->getFont());
	m_text_music->setCharacterSize(m_text_sound->getCharacterSize());
	m_text_music->setFillColor(Color(255, 51, 153));
	m_text_music->setOutlineThickness(1.f);
	m_text_music->setOutlineColor(Color::Black);
	m_text_music->setPosition(m_button_music->getPosition() + Vector2f(-290.f, -48.f));
}

void GSSetting::initButtonHome()
{
	m_button_back->initButton(Vector2f(280.f, 90.f), "bar_green");
	m_button_back->setPosition(m_frame->getPosition() + Vector2f(0.f, 120.f));
	m_button_back->setFunction([]() { GAMESTATE->popState(); });

	m_text_back->setString("BACK");
	m_text_back->setCharacterSize(75);
	m_text_back->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_back->setPosition(m_button_back->getPosition() + Vector2f(-75.f, -50.f));
}

void GSSetting::updateButtonSound(float delta_time)
{
	m_button_sound->updateButton(delta_time);

	if (DATA->isAllowSound())
		m_button_sound->setTexture(DATA->getTexture("GUI/Button/on"));
	else
		m_button_sound->setTexture(DATA->getTexture("GUI/Button/off"));
}

void GSSetting::updateButtonMusic(float delta_time)
{
	m_button_music->updateButton(delta_time);

	if (DATA->isAllowMusic())
		m_button_music->setTexture(DATA->getTexture("GUI/Button/on"));
	else
		m_button_music->setTexture(DATA->getTexture("GUI/Button/off"));
}

void GSSetting::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initButtonSound();
	this->initButtonMusic();
	this->initButtonHome();
}

void GSSetting::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	this->updateButtonSound(delta_time);
	this->updateButtonMusic(delta_time);
	m_button_back->updateButton(delta_time);
}

void GSSetting::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);

	window->draw(*m_button_sound);
	window->draw(*m_button_music);
	window->draw(*m_button_back);

	window->draw(*m_text_sound);
	window->draw(*m_text_music);
	window->draw(*m_text_back);
}