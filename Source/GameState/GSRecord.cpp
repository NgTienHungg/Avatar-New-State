#include "GSRecord.h"

GSRecord::GSRecord()
{
	m_background = new Background();
	m_frame = new RectangleShape();
	m_headline = new RectangleShape();

	m_logo_1 = new RectangleShape();
	m_name_1 = new Text();
	m_level_1 = new Text();
	m_coin_1 = new Text();

	m_logo_2 = new RectangleShape();
	m_name_2 = new Text();
	m_level_2 = new Text();
	m_coin_2 = new Text();

	m_logo_3 = new RectangleShape();
	m_name_3 = new Text();
	m_level_3 = new Text();
	m_coin_3 = new Text();

	m_button_back = new Button();
	m_text_back = new Text();
}

GSRecord::~GSRecord()
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
	if (m_logo_1 != nullptr) {
		delete m_logo_1;
	}
	if (m_name_1 != nullptr) {
		delete m_name_1;
	}
	if (m_level_1 != nullptr) {
		delete m_level_1;
	}
	if (m_coin_1 != nullptr) {
		delete m_coin_1;
	}
	if (m_logo_2 != nullptr) {
		delete m_logo_2;
	}
	if (m_name_2 != nullptr) {
		delete m_name_2;
	}
	if (m_level_2 != nullptr) {
		delete m_level_2;
	}
	if (m_coin_2 != nullptr) {
		delete m_coin_2;
	}
	if (m_logo_3 != nullptr) {
		delete m_logo_3;
	}
	if (m_name_3 != nullptr) {
		delete m_name_3;
	}
	if (m_level_3 != nullptr) {
		delete m_level_3;
	}
	if (m_coin_3 != nullptr) {
		delete m_coin_3;
	}
	if (m_button_back != nullptr) {
		delete m_button_back;
	}
	if (m_text_back != nullptr) {
		delete m_text_back;
	}
}

GameState GSRecord::getTypeState()
{
	return GameState::RECORD;
}

void GSRecord::initDataRecord()
{
	m_list_user = DATA->readRecordFile();
	bool is_find = false;
	for (int i = 0; i < (int)m_list_user.size(); ++i) {
		if (m_list_user[i].first == USER->getName()) {
			string name = USER->getName();
			int level = USER->getLevel();
			int coin = USER->getCoin();
			m_list_user[i] = { name, {level, coin} };
			is_find = true;
			break;
		}
	}
	if (!is_find) {
		string name = USER->getName();
		int level = USER->getLevel();
		int coin = USER->getCoin();
		m_list_user.push_back({ name, {level, coin} });
	}

	// sort
	for (int i = 0; i < (int)m_list_user.size(); ++i) {
		for (int j = i + 1; j < (int)m_list_user.size(); ++j) {
			if (m_list_user[i].second.first < m_list_user[j].second.first) {
				// compare level
				swap(m_list_user[i], m_list_user[j]);
			}
			else if (m_list_user[i].second.first == m_list_user[j].second.first) {
				if (m_list_user[i].second.second < m_list_user[j].second.second) {
					// compare coin
					swap(m_list_user[i], m_list_user[j]);
				}
			}
		}
	}
	if (m_list_user.size() > 3) {
		m_list_user.resize(3);
	}
	DATA->writeRecordFile(m_list_user);
}

void GSRecord::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(700.f, 700.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/rank"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f);

	// headline
	m_headline->setSize(Vector2f(400.f, 80.f));
	m_headline->setTexture(DATA->getTexture("GUI/Headline/hi-score"));
	m_headline->setOrigin(m_headline->getSize() / 2.f);
	m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f));
}

void GSRecord::initRank1()
{
	// logo
	m_logo_1->setSize(Vector2f(90.f, 90.f));
	m_logo_1->setTexture(DATA->getTexture("GUI/Image/gold medal"));
	m_logo_1->setOrigin(m_logo_1->getSize() / 2.f);
	m_logo_1->setPosition(m_frame->getPosition() + Vector2f(-135.f, -177.f));

	// name
	m_name_1->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_name_1->setString(m_list_user[0].first);
	m_name_1->setCharacterSize(40);
	m_name_1->setFillColor(Color(230, 0, 115));
	m_name_1->setOutlineThickness(1.f);
	m_name_1->setOutlineColor(Color::Black);
	m_name_1->setOrigin(0.f, m_name_1->getGlobalBounds().height / 2.f);
	m_name_1->setPosition(m_logo_1->getPosition() + Vector2f(85.f, 20.f));

	// level
	m_level_1->setString("Level: " + to_string(m_list_user[0].second.first));
	m_level_1->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_level_1->setFillColor(Color::Black);
	m_level_1->setOrigin(0.f, m_level_1->getGlobalBounds().height / 2.f);
	m_level_1->setPosition(m_logo_1->getPosition() + Vector2f(120.f, -55.f));

	// coin
	m_coin_1->setString("Coin: " + to_string(m_list_user[0].second.second));
	m_coin_1->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_coin_1->setFillColor(Color::Black);
	m_coin_1->setOrigin(0.f, m_coin_1->getGlobalBounds().height / 2.f);
	m_coin_1->setPosition(m_logo_1->getPosition() + Vector2f(120.f, -25.f));
}

void GSRecord::initRank2()
{
	if (m_list_user.size() < 2) return;
	// logo
	m_logo_2->setSize(Vector2f(90.f, 90.f));
	m_logo_2->setTexture(DATA->getTexture("GUI/Image/silver medal"));
	m_logo_2->setOrigin(m_logo_2->getSize() / 2.f);
	m_logo_2->setPosition(m_logo_1->getPosition() + Vector2f(0.f, 152.f));

	// name
	m_name_2->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_name_2->setString(m_list_user[1].first);
	m_name_2->setCharacterSize(40);
	m_name_2->setFillColor(Color(230, 0, 115));
	m_name_2->setOutlineThickness(1.f);
	m_name_2->setOutlineColor(Color::Black);
	m_name_2->setOrigin(0.f, m_name_2->getGlobalBounds().height / 2.f);
	m_name_2->setPosition(m_logo_2->getPosition() + Vector2f(85, 20.f));

	// level
	m_level_2->setString("Level: " + to_string(m_list_user[1].second.first));
	m_level_2->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_level_2->setFillColor(Color::Black);
	m_level_2->setOrigin(0.f, m_level_2->getGlobalBounds().height / 2.f);
	m_level_2->setPosition(m_logo_2->getPosition() + Vector2f(120.f, -55.f));

	// coin
	m_coin_2->setString("Coin: " + to_string(m_list_user[1].second.second));
	m_coin_2->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_coin_2->setFillColor(Color::Black);
	m_coin_2->setOrigin(0.f, m_coin_2->getGlobalBounds().height / 2.f);
	m_coin_2->setPosition(m_logo_2->getPosition() + Vector2f(120.f, -25.f));
}

void GSRecord::initRank3()
{
	if (m_list_user.size() < 3) return;
	// logo
	m_logo_3->setSize(Vector2f(90.f, 90.f));
	m_logo_3->setTexture(DATA->getTexture("GUI/Image/bronze medal"));
	m_logo_3->setOrigin(m_logo_3->getSize() / 2.f);
	m_logo_3->setPosition(m_logo_2->getPosition() + Vector2f(0.f, 152.f));

	// name
	m_name_3->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_name_3->setString(m_list_user[2].first);
	m_name_3->setCharacterSize(40);
	m_name_3->setFillColor(Color(230, 0, 115));
	m_name_3->setOutlineThickness(1.f);
	m_name_3->setOutlineColor(Color::Black);
	m_name_3->setOrigin(0.f, m_name_3->getGlobalBounds().height / 2.f);
	m_name_3->setPosition(m_logo_3->getPosition() + Vector2f(85, 20.f));

	// level
	m_level_3->setString("Level: " + to_string(m_list_user[2].second.first));
	m_level_3->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_level_3->setFillColor(Color::Black);
	m_level_3->setOrigin(0.f, m_level_3->getGlobalBounds().height / 2.f);
	m_level_3->setPosition(m_logo_3->getPosition() + Vector2f(120.f, -55.f));

	// coin
	m_coin_3->setString("Coin: " + to_string(m_list_user[2].second.second));
	m_coin_3->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_coin_3->setFillColor(Color::Black);
	m_coin_3->setOrigin(0.f, m_coin_3->getGlobalBounds().height / 2.f);
	m_coin_3->setPosition(m_logo_3->getPosition() + Vector2f(120.f, -25.f));
}

void GSRecord::initButtonHome()
{
	// button
	m_button_back->initButton(Vector2f(300.f, 80.f), "bar_green");
	m_button_back->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().y / 2.f - 15.f));
	m_button_back->setFunction([]() { GAMESTATE->popState(); });

	// text
	m_text_back->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_back->setString("BACK");
	m_text_back->setCharacterSize(70);
	m_text_back->setOrigin(m_text_back->getGlobalBounds().width / 2.f, m_text_back->getGlobalBounds().height / 2.f);
	m_text_back->setPosition(m_button_back->getPosition() + Vector2f(0.f, -20.f));
}

void GSRecord::renderRank1(RenderWindow* window)
{
	window->draw(*m_logo_1);
	window->draw(*m_name_1);
	window->draw(*m_level_1);
	window->draw(*m_coin_1);
}

void GSRecord::renderRank2(RenderWindow* window)
{
	if (m_list_user.size() < 2) return;
	window->draw(*m_logo_2);
	window->draw(*m_name_2);
	window->draw(*m_level_2);
	window->draw(*m_coin_2);
}

void GSRecord::renderRank3(RenderWindow* window)
{
	if (m_list_user.size() < 3) return;
	window->draw(*m_logo_3);
	window->draw(*m_name_3);
	window->draw(*m_level_3);
	window->draw(*m_coin_3);
}

void GSRecord::initState()
{
	m_background->initBackground();
	this->initDataRecord();
	this->initBoard();
	this->initRank1();
	this->initRank2();
	this->initRank3();
	this->initButtonHome();
}

void GSRecord::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	m_button_back->updateButton(delta_time);
}

void GSRecord::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_headline);
	this->renderRank1(window);
	this->renderRank2(window);
	this->renderRank3(window);
	m_button_back->renderButton(window);
	window->draw(*m_text_back);
}