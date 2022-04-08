#include "GSMenu.h"

GSMenu::GSMenu()
{
	m_background = new Background();
	m_title = new Text();
	m_lemma = new Text();
	m_button_play = new DynamicButton();
	m_button_setting = new Button();
	m_button_record = new Button();
	m_button_profile = new Button();
	m_button_help = new Button();
	m_button_quit = new Button();
}

GSMenu::~GSMenu()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_title != nullptr) {
		delete m_title;
	}
	if (m_lemma != nullptr) {
		delete m_lemma;
	}
	if (m_button_play != nullptr) {
		delete m_button_play;
	}
	if (m_button_setting != nullptr) {
		delete m_button_setting;
	}
	if (m_button_record != nullptr) {
		delete m_button_record;
	}
	if (m_button_profile != nullptr) {
		delete m_button_profile;
	}
	if (m_button_help != nullptr) {
		delete m_button_help;
	}
	if (m_button_quit != nullptr) {
		delete m_button_quit;
	}
}

GameState GSMenu::getTypeState()
{
	return GameState::MENU;
}

void GSMenu::initTitle()
{
	// title
	m_title->setString("Avatar");
	m_title->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_title->setCharacterSize(220);
	m_title->setFillColor(Color(0, 255, 204));
	m_title->setOutlineThickness(5.f);
	m_title->setOutlineColor(Color::Black);
	m_title->setOrigin(m_title->getGlobalBounds().width / 2.f, m_title->getGlobalBounds().height / 2.f);
	m_title->setPosition(ScreenWidth / 2.f, ScreenHeight / 16.f);

	// lemma
	m_lemma->setString("The New State");
	m_lemma->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_lemma->setCharacterSize(100);
	m_lemma->setFillColor(Color(0, 255, 204));
	m_lemma->setOutlineThickness(4.f);
	m_lemma->setOutlineColor(Color::Black);
	m_lemma->setOrigin(m_lemma->getGlobalBounds().width / 2.f, m_lemma->getGlobalBounds().height / 2.f);
	m_lemma->setPosition(m_title->getPosition() + Vector2f(0.f, 170.f));
}

void GSMenu::initButtonPlay()
{
	m_button_play->initDynamicButton(Vector2f(200.f, 200.f), "play");
	m_button_play->setPosition(ScreenWidth / 2, ScreenHeight / 2 + m_button_play->getSize().y / 4);
	m_button_play->setFunction([]() { GAMESTATE->changeState(GameState::SELECT_MAP); });
}

void GSMenu::initButtonRecord()
{
	m_button_record->initButton(Vector2f(110.f, 110.f), "record");
	m_button_record->setPosition(ScreenWidth / 2, ScreenHeight - m_button_record->getSize().y);
	m_button_record->setFunction([]() { GAMESTATE->changeState(GameState::RECORD); });
}

void GSMenu::initButtonProfile()
{
	m_button_profile->initButton(m_button_record->getSize(), "profile");
	m_button_profile->setPosition(m_button_record->getPosition() + Vector2f(-180.f, 0.f));
	m_button_profile->setFunction([]() { GAMESTATE->changeState(GameState::PROFILE); });
}

void GSMenu::initButtonSetting()
{
	m_button_setting->initButton(m_button_record->getSize(), "setting");
	m_button_setting->setPosition(m_button_profile->getPosition() + Vector2f(-180.f, 0.f));
	m_button_setting->setFunction([]() { GAMESTATE->changeState(GameState::SETTING); });
}

void GSMenu::initButtonHelp()
{
	m_button_help->initButton(m_button_record->getSize(), "help");
	m_button_help->setPosition(m_button_record->getPosition() + Vector2f(180.f, 0.f));
	m_button_help->setFunction([]() { GAMESTATE->changeState(GameState::HELP); });
}

void GSMenu::initButtonQuit()
{
	m_button_quit->initButton(m_button_record->getSize(), "exit");
	m_button_quit->setPosition(m_button_help->getPosition() + Vector2f(180.f, 0.f));
	m_button_quit->setFunction([]() { GAMESTATE->changeState(GameState::WARNING_QUIT); });
}

void GSMenu::initState()
{
	m_background->initBackground();
	this->initTitle();
	this->initButtonPlay();
	this->initButtonRecord();
	this->initButtonProfile();
	this->initButtonSetting();
	this->initButtonHelp();
	this->initButtonQuit();
}

void GSMenu::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	m_button_play->updateDynamicButton(delta_time);
	m_button_setting->updateButton(delta_time);
	m_button_profile->updateButton(delta_time);
	m_button_record->updateButton(delta_time);
	m_button_help->updateButton(delta_time);
	m_button_quit->updateButton(delta_time);
}

void GSMenu::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_title);
	window->draw(*m_lemma);
	m_button_play->renderDynamicButton(window);
	m_button_setting->renderButton(window);
	m_button_profile->renderButton(window);
	m_button_record->renderButton(window);
	m_button_help->renderButton(window);
	m_button_quit->renderButton(window);
}