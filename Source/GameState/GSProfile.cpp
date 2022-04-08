#include "GSProfile.h"
#include <windows.h>
#include <shellapi.h>

GSProfile::GSProfile()
{
	m_background = new Background();
	m_frame = new RectangleShape();
	m_title = new Text();

	m_name = new Text();
	m_level = new Text();
	m_coin = new Text();

	m_button_back = new Button();
	m_text_back = new Text();

	m_link_fb = new RectangleShape();
	m_text_link_fb = new Text();

	m_link_git = new RectangleShape();
	m_text_link_git = new Text();

	m_current_time_click = 0.f;
}

GSProfile::~GSProfile()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_frame != nullptr) {
		delete m_frame;
	}
	if (m_title != nullptr) {
		delete m_title;
	}
	if (m_name != nullptr) {
		delete m_name;
	}
	if (m_level != nullptr) {
		delete m_level;
	}
	if (m_coin != nullptr) {
		delete m_coin;
	}
	if (m_button_back != nullptr) {
		delete m_button_back;
	}
	if (m_text_back != nullptr) {
		delete m_text_back;
	}
	if (m_link_fb != nullptr) {
		delete m_link_fb;
	}
	if (m_text_link_fb != nullptr) {
		delete m_text_link_fb;
	}
	if (m_link_git != nullptr) {
		delete m_link_git;
	}
	if (m_text_link_git != nullptr) {
		delete m_text_link_git;
	}
}

GameState GSProfile::getTypeState()
{
	return GameState::PROFILE;
}

void GSProfile::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(700.f, 700.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/paused"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f - 20.f);

	// title
	m_title->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_title->setString("PROFILE");
	m_title->setFillColor(Color(0, 255, 204));
	m_title->setCharacterSize(80);
	m_title->setOutlineThickness(2.f);
	m_title->setOutlineColor(Color::Black);
	m_title->setOrigin(m_title->getGlobalBounds().width / 2.f, m_title->getGlobalBounds().height / 2.f);
	m_title->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + 110.f));
}

void GSProfile::initLinkFb()
{
	// frame
	m_link_fb->setSize(Vector2f(330.f, 40.f));
	m_link_fb->setFillColor(Color::Transparent);
	m_link_fb->setOrigin(m_link_fb->getSize() / 2.f);
	m_link_fb->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().y / 2.f - 220.f));

	// link
	m_text_link_fb->setFont(*DATA->getFont("EmotionEngineItalic"));
	m_text_link_fb->setString("Facebook: NgTienHungg");
	m_text_link_fb->setFillColor(Color::Black);
	m_text_link_fb->setCharacterSize(35);
	m_text_link_fb->setOrigin(m_text_link_fb->getGlobalBounds().width / 2.f, m_text_link_fb->getGlobalBounds().height / 2.f);
	m_text_link_fb->setPosition(m_link_fb->getPosition() + Vector2f(0.f, -10.f));
}

void GSProfile::initLinkGit()
{
	// frame
	m_link_git->setSize(Vector2f(280.f, 40.f));
	m_link_git->setFillColor(Color::Transparent);
	m_link_git->setOrigin(m_link_git->getSize() / 2.f);
	m_link_git->setPosition(m_link_fb->getPosition() + Vector2f(0.f, 50.f));

	// link
	m_text_link_git->setFont(*DATA->getFont("EmotionEngineItalic"));
	m_text_link_git->setString("Github: NgTienHungg");
	m_text_link_git->setFillColor(Color::Black);
	m_text_link_git->setCharacterSize(35);
	m_text_link_git->setOrigin(m_text_link_git->getGlobalBounds().width / 2.f, m_text_link_git->getGlobalBounds().height / 2.f);
	m_text_link_git->setPosition(m_link_git->getPosition() + Vector2f(0.f, -10.f));
}

void GSProfile::initUserInfo()
{
	// name
	m_name->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_name->setString("ID: " + USER->getName());
	m_name->setCharacterSize(60);
	m_name->setFillColor(Color(230, 0, 115));
	m_name->setOutlineThickness(1.f);
	m_name->setOutlineColor(Color::Black);
	m_name->setOrigin(0.f, m_name->getGlobalBounds().height / 2.f);
	m_name->setPosition(m_frame->getPosition() + Vector2f(-170.f, -130.f));

	// level
	m_level->setString("Level: " + to_string(USER->getLevel()));
	m_level->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_level->setCharacterSize(60);
	m_level->setFillColor(Color(102, 255, 51));
	m_level->setOutlineThickness(1.f);
	m_level->setOutlineColor(Color::Black);
	m_level->setOrigin(0.f, m_level->getGlobalBounds().height / 2.f);
	m_level->setPosition(m_name->getPosition() + Vector2f(0.f, 75.f));

	// coin
	m_coin->setString("Coin: " + to_string(USER->getCoin()));
	m_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_coin->setCharacterSize(60);
	m_coin->setFillColor(Color(255, 204, 0));
	m_coin->setOutlineThickness(1.f);
	m_coin->setOutlineColor(Color::Black);
	m_coin->setOrigin(0.f, m_coin->getGlobalBounds().height / 2.f);
	m_coin->setPosition(m_level->getPosition() + Vector2f(0.f, 75.f));
}

void GSProfile::initButtonHome()
{
	// button
	m_button_back->initButton(Vector2f(260.f, 80.f), "bar_green");
	m_button_back->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().y / 2.f - 10.f));
	m_button_back->setFunction([]() { GAMESTATE->popState(); });

	// text
	m_text_back->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_back->setString("BACK");
	m_text_back->setCharacterSize(70);
	m_text_back->setOrigin(m_text_back->getGlobalBounds().width / 2.f, m_text_back->getGlobalBounds().height / 2.f);
	m_text_back->setPosition(m_button_back->getPosition() + Vector2f(0.f, -20.f));
}

void GSProfile::updateLinkFb(float delta_time)
{
	Vector2f pos = (Vector2f)Mouse::getPosition(*APP->getWindow());
	if (m_link_fb->getGlobalBounds().contains(pos)) {
		m_text_link_fb->setFillColor(Color(255, 0, 102));
		if (Mouse::isButtonPressed(Mouse::Left)) {
			m_current_time_click += delta_time;
			if (m_current_time_click >= ClickTime) {
				m_current_time_click = 0.f;
				ShellExecute(0, 0, L"https://www.facebook.com/NgTienHungg/", 0, 0, SW_SHOW);
			}
		}
		else {
			m_current_time_click = 0.f;
		}
	}
	else {
		m_text_link_fb->setFillColor(Color::Black);
	}
}

void GSProfile::updateLinkGit(float delta_time)
{
	Vector2f pos = (Vector2f)Mouse::getPosition(*APP->getWindow());
	if (m_link_git->getGlobalBounds().contains(pos)) {
		m_text_link_git->setFillColor(Color(255, 0, 102));
		if (Mouse::isButtonPressed(Mouse::Left)) {
			m_current_time_click += delta_time;
			if (m_current_time_click >= ClickTime) {
				m_current_time_click = 0.f;
				ShellExecute(0, 0, L"https://github.com/NgTienHungg", 0, 0, SW_SHOW);
			}
		}
		else {
			m_current_time_click = 0.f;
		}
	}
	else {
		m_text_link_git->setFillColor(Color::Black);
	}
}

void GSProfile::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initLinkFb();
	this->initLinkGit();
	this->initUserInfo();
	this->initButtonHome();
}

void GSProfile::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	m_button_back->updateButton(delta_time);
	this->updateLinkFb(delta_time);
	this->updateLinkGit(delta_time);
}

void GSProfile::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_title);

	window->draw(*m_text_link_fb);
	window->draw(*m_text_link_git);

	window->draw(*m_name);
	window->draw(*m_level);
	window->draw(*m_coin);

	m_button_back->renderButton(window);
	window->draw(*m_text_back);
}
