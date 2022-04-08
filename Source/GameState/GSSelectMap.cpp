#include "GSSelectMap.h"

GSSelectMap::GSSelectMap()
{
	m_background = new Background();
	m_headline = new RectangleShape();
	m_frame = new RectangleShape();

	m_button_back = new Button();
	m_text_back = new Text();

	m_count_map = 9;
	m_list_map.resize(m_count_map + 1, nullptr);
	m_list_text.resize(m_count_map + 1, nullptr);
	for (int i = 1; i <= m_count_map; ++i) {
		m_list_map[i] = new Button();
		m_list_text[i] = new Text();
	}
}

GSSelectMap::~GSSelectMap()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_headline != nullptr) {
		delete m_headline;
	}
	if (m_frame != nullptr) {
		delete m_frame;
	}
	if (m_button_back != nullptr) {
		delete m_button_back;
	}
	if (m_text_back != nullptr) {
		delete m_text_back;
	}
	for (int i = 1; i <= m_count_map; ++i) {
		if (m_list_map[i] != nullptr) {
			delete m_list_map[i];
		}
		if (m_list_text[i] != nullptr) {
			delete m_list_text[i];
		}
	}
	m_list_map.clear();
	m_list_text.clear();
}

GameState GSSelectMap::getTypeState()
{
	return GameState::SELECT_MAP;
}

void GSSelectMap::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(660.f, 640.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/level_select"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f);

	// headline
	m_headline->setSize(Vector2f(540.f, 80.f));
	m_headline->setTexture(DATA->getTexture("GUI/Headline/level_select"));
	m_headline->setOrigin(m_headline->getSize() / 2.f);
	m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + 10.f));
}

void GSSelectMap::initButtonBack()
{
	m_button_back->initButton(Vector2f(260.f, 80.f), "bar_green");
	m_button_back->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().x / 2.f - 15.f));
	m_button_back->setFunction([]() { GAMESTATE->popState(); });

	m_text_back->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_back->setString("BACK");
	m_text_back->setCharacterSize(65);
	m_text_back->setOrigin(m_text_back->getGlobalBounds().width / 2.f, m_text_back->getGlobalBounds().height / 2.f);
	m_text_back->setPosition(m_button_back->getPosition() + Vector2f(0.f, -18.f));
}

void GSSelectMap::initListMap()
{
	for (int i = 1; i <= m_count_map; ++i) {
		m_list_map[i]->initButton(Vector2f(120.f, 120.f), "lock");
		m_list_map[i]->setFunction([]() { GAMESTATE->changeState(GameState::SELECT_CHARACTER); });
	}

	m_list_map[1]->setPosition(m_frame->getPosition() + Vector2f(-170.f, -170.f));
	m_list_map[2]->setPosition(m_frame->getPosition() + Vector2f(0.f, -170.f));
	m_list_map[3]->setPosition(m_frame->getPosition() + Vector2f(+170.f, -170.f));
	m_list_map[4]->setPosition(m_frame->getPosition() + Vector2f(-170.f, 0.f));
	m_list_map[5]->setPosition(m_frame->getPosition() + Vector2f(0.f, 0.f));
	m_list_map[6]->setPosition(m_frame->getPosition() + Vector2f(170.f, 0.f));
	m_list_map[7]->setPosition(m_frame->getPosition() + Vector2f(-170.f, 170.f));
	m_list_map[8]->setPosition(m_frame->getPosition() + Vector2f(0.f, 170.f));
	m_list_map[9]->setPosition(m_frame->getPosition() + Vector2f(170.f, 170.f));

	for (int i = 1; i <= m_count_map; ++i) {
		m_list_text[i]->setFont(*DATA->getFont("AllTheWayToTheSun"));
		m_list_text[i]->setCharacterSize(80);
		m_list_text[i]->setOutlineThickness(1.f);
		m_list_text[i]->setOutlineColor(Color::Black);
		m_list_text[i]->setFillColor(Color(255, 51, 133));
	}
}

void GSSelectMap::updateListMap(float delta_time)
{
	for (int i = 1; i <= m_count_map; ++i) {
		if (USER->getLevel() < i) {
			m_list_map[i]->setTexture(DATA->getTexture("GUI/Button/lock"));
			m_list_text[i]->setString("");
			return;
		}

		if (USER->getLevel() == i)
			m_list_map[i]->setTexture(DATA->getTexture("GUI/Button/round_gray"));
		else
			m_list_map[i]->setTexture(DATA->getTexture("GUI/Button/round_purple"));

		m_list_text[i]->setString(to_string(i));
		m_list_text[i]->setOrigin(m_list_text[i]->getGlobalBounds().width / 2.f, m_list_text[i]->getGlobalBounds().height / 2.f);
		m_list_text[i]->setPosition(m_list_map[i]->getPosition() + Vector2f(0.f, -20.f));

		m_list_map[i]->updateButton(delta_time);
		if (m_list_map[i]->isHandling()) {
			DATA->setMapLevel(i);
		}
	}
}

void GSSelectMap::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initButtonBack();
	this->initListMap();
}

void GSSelectMap::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	m_button_back->updateButton(delta_time);
	this->updateListMap(delta_time);
}

void GSSelectMap::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_headline);

	m_button_back->renderButton(window);
	window->draw(*m_text_back);

	for (int i = 1; i <= m_count_map; i++) {
		m_list_map[i]->renderButton(window);
		window->draw(*m_list_text[i]);
	}
}