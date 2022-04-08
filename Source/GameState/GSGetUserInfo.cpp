#include "GSGetUserInfo.h"
#include <ctype.h>

GSGetUserInfo::GSGetUserInfo()
{
	m_background = new Background();
	m_board = new RectangleShape();
	m_headline = new Text();
	m_rule = new Text();
	m_remind = new DynamicText();
	m_name_display = new Text();

	m_name_enter = "";
	char c = '!';
	m_is_typing = false;
}

GSGetUserInfo::~GSGetUserInfo()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_board != nullptr) {
		delete m_board;
	}
	if (m_headline != nullptr) {
		delete m_headline;
	}
	if (m_rule != nullptr) {
		delete m_rule;
	}
	if (m_remind != nullptr) {
		delete m_remind;
	}
	if (m_name_display != nullptr) {
		delete m_name_display;
	}
}

GameState GSGetUserInfo::getTypeState()
{
	return GameState::GET_USER_INFO;
}

void GSGetUserInfo::loadUserInfo()
{
	vector<pair<string, pair<int, int>>> users = DATA->readRecordFile();
	for (auto i : users) {
		if (m_name_enter == i.first) {
			string name = i.first;
			int level = i.second.first;
			int coin = i.second.second;
			USER->initUser(name, level, coin);
			return;
		}
	}
	USER->initUser(m_name_enter, 1, 0);
}

void GSGetUserInfo::initBoard()
{
	// frame
	m_board->setTexture(DATA->getTexture("GUI/Frame/level_select"));
	m_board->setSize(Vector2f(800.f, 500.f));
	m_board->setOrigin(m_board->getSize() / 2.f);
	m_board->setPosition(Vector2f(ScreenWidth / 2, ScreenHeight / 2));

	// headline
	m_headline->setString("ENTER YOUR NAME");
	m_headline->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_headline->setCharacterSize(80);
	m_headline->setFillColor(Color(0, 255, 204));
	m_headline->setOutlineThickness(2.f);
	m_headline->setOutlineColor(Color::Black);
	m_headline->setOrigin(m_headline->getGlobalBounds().width / 2.f, m_headline->getGlobalBounds().height / 2.f);
	m_headline->setPosition(m_board->getPosition() + Vector2f(0.f, -m_board->getSize().y / 2.f + m_headline->getCharacterSize() / 2.f));
}

void GSGetUserInfo::initText()
{
	// rule
	m_rule->setString("(Your name must has 6-12 characters from a-z, A-Z or 0-9)");
	m_rule->setFont(*DATA->getFont("EmotionEngineItalic"));
	m_rule->setCharacterSize(25);
	m_rule->setFillColor(Color::Black);
	m_rule->setOrigin(m_rule->getGlobalBounds().width / 2.f, m_rule->getGlobalBounds().height / 2.f);
	m_rule->setPosition(m_board->getPosition() + Vector2f(0.f, m_board->getSize().y / 2.f - 60.f));

	// user name
	m_name_display->setString("_ _ _ _ _ _");
	m_name_display->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_name_display->setCharacterSize(80);
	m_name_display->setOutlineThickness(1.f);
	m_name_display->setOutlineColor(Color::Black);
	m_name_display->setFillColor(Color(255, 26, 117));
	m_name_display->setOrigin(m_name_display->getGlobalBounds().width / 2.f, m_name_display->getGlobalBounds().height / 2.f);
	m_name_display->setPosition(m_board->getPosition() + Vector2f(0.f, 40.f));

	// remind
	m_remind->initDynamicText();
	m_remind->setString("Press Enter to start game!");
	m_remind->setCharacterSize(40);
	m_remind->setFont(*DATA->getFont("EmotionEngineItalic"));
	m_remind->setFillColor(Color(0, 255, 0));
	m_remind->setOutlineThickness(1.f);
	m_remind->setOutlineColor(Color::Black);
	m_remind->setOrigin(m_remind->getGlobalBounds().width / 2.f, m_remind->getGlobalBounds().height / 2.f);
	m_remind->setPosition(m_name_display->getPosition() + Vector2f(0.f, 40.f));
}

void GSGetUserInfo::updateEnterText()
{
	// enter user name
	if (APP->getEvent().type == Event::TextEntered && !m_is_typing) {
		m_char_enter = APP->getEvent().text.unicode;
		m_is_typing = true;
		return;
	}

	if (APP->getEvent().type == Event::KeyReleased && m_is_typing) {
		m_is_typing = false;
		if (isalnum(m_char_enter) || m_char_enter == ' ') {
			if (m_name_enter.length() < 12) {
				m_name_enter.push_back(m_char_enter);
			}
		}
		else if (m_char_enter == 8 && !m_name_enter.empty()) {
			// keyboard: backspace
			m_name_enter.pop_back();
		}
		else if (m_char_enter == 13) {
			// keyboard: enter
			if (m_name_enter.length() >= 6) {
				this->loadUserInfo();
				GAMESTATE->changeState(GameState::MENU);
			}
		}
	}
}

void GSGetUserInfo::updateUserName()
{
	if (m_name_enter.empty()) {
		m_name_display->setString("_ _ _ _ _ _");
	}
	else {
		m_name_display->setString(m_name_enter);
	}
	m_name_display->setOrigin(m_name_display->getGlobalBounds().width / 2.f, m_name_display->getGlobalBounds().height / 2.f);
	m_name_display->setPosition(m_board->getPosition() + Vector2f(0.f, -1.f * m_name_display->getCharacterSize() / 2.f));
}

void GSGetUserInfo::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initText();
}

void GSGetUserInfo::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	this->updateEnterText();
	this->updateUserName();
	if (m_name_enter.length() >= 6) {
		m_remind->updateDynamicText(delta_time);
	}
}

void GSGetUserInfo::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_board);
	window->draw(*m_headline);
	window->draw(*m_name_display);
	window->draw(*m_rule);

	if (m_name_enter.length() >= 6) {
		window->draw(*m_remind);
	}
}