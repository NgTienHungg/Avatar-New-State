#include "GSHelp.h"

GSHelp::GSHelp()
{
	m_background = new Background();
	m_frame = new RectangleShape();
	m_title = new Text();
	m_current_page = 1;

	m_button_left = new Button();
	m_button_right = new Button();
	m_button_back = new Button();
	m_text_back = new Text();

	// page 1
	m_item_sword = new RectangleShape();
	m_item_heart  = new RectangleShape();
	m_item_mana = new RectangleShape();
	m_item_armor = new RectangleShape();
	m_item_poison = new RectangleShape();
	m_item_coin = new RectangleShape();

	m_text_sword = new Text();
	m_text_heart = new Text();
	m_text_mana = new Text();
	m_text_armor = new Text();
	m_text_poison = new Text();
	m_text_coin = new Text();

	// page 2
	m_bar_mana = new RectangleShape();
	m_bar_shield = new RectangleShape();
	m_text_mana_2 = new Text();
	m_text_shield = new Text();
	m_text_continue = new Text();

	// page 3
	m_text_if_win = new Text();
	m_text_if_lose = new Text();
	m_text_level_and_coin = new Text();
	m_note = new Text();
}

GSHelp::~GSHelp()
{
	if (m_background != nullptr)
		delete m_background;
	if (m_frame != nullptr)
		delete m_frame;
	if (m_title != nullptr)
		delete m_title;
	if (m_button_left != nullptr)
		delete m_button_left;
	if (m_button_right != nullptr)
		delete m_button_right;
	if (m_button_back != nullptr)
		delete m_button_back;
	if (m_text_back != nullptr)
		delete m_text_back;
	if (m_item_sword != nullptr)
		delete m_item_sword;
	if (m_item_heart != nullptr)
		delete m_item_heart;
	if (m_item_mana != nullptr)
		delete m_item_mana;
	if (m_item_armor != nullptr)
		delete m_item_armor;
	if (m_item_poison != nullptr)
		delete m_item_poison;
	if (m_item_coin != nullptr)
		delete m_item_coin;
	if (m_text_sword != nullptr)
		delete m_text_sword;
	if (m_text_heart != nullptr)
		delete m_text_heart;
	if (m_text_mana != nullptr)
		delete m_text_mana;
	if (m_text_armor != nullptr)
		delete m_text_armor;
	if (m_text_poison != nullptr)
		delete m_text_poison;
	if (m_text_coin != nullptr)
		delete m_text_coin;
	if (m_bar_mana != nullptr)
		delete m_bar_mana;
	if (m_bar_shield != nullptr)
		delete m_bar_shield;
	if (m_text_mana_2 != nullptr)
		delete m_text_mana_2;
	if (m_text_shield != nullptr)
		delete m_text_shield;
	if (m_text_continue != nullptr)
		delete m_text_continue;
	if (m_text_if_win != nullptr)
		delete m_text_if_win;
	if (m_text_if_lose != nullptr)
		delete m_text_if_lose;
	if (m_text_level_and_coin != nullptr)
		delete m_text_level_and_coin;
	if (m_note != nullptr)
		delete m_note;
}

GameState GSHelp::getTypeState()
{
	return GameState::HELP;
}

void GSHelp::initBoard()
{
	// frame
	m_frame->setSize(Vector2f(800.f, 660.f));
	m_frame->setTexture(DATA->getTexture("GUI/Frame/level_select"));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(ScreenWidth / 2.f, ScreenHeight / 2.f - 20.f);

	// title
	m_title->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_title->setString("ABOUT");
	m_title->setFillColor(Color(0, 255, 204));
	m_title->setCharacterSize(80);
	m_title->setOutlineThickness(2.f);
	m_title->setOutlineColor(Color::Black);
	m_title->setOrigin(m_title->getGlobalBounds().width / 2.f, m_title->getGlobalBounds().height / 2.f);
	m_title->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + 50.f));
}

void GSHelp::initPage1()
{
	// sword
	m_item_sword->setSize(Vector2f(50.f, 50.f));
	m_item_sword->setOrigin(m_item_sword->getSize() / 2.f);
	m_item_sword->setTexture(DATA->getTexture("GUI/Piece/sword"));
	m_item_sword->setPosition(m_title->getPosition() + Vector2f(-280.f, 110.f));

	m_text_sword->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_sword->setString(" Damaged by 100% base attack");
	m_text_sword->setCharacterSize(45);
	m_text_sword->setFillColor(Color(133, 173, 173));
	m_text_sword->setOutlineThickness(1.f);
	m_text_sword->setOutlineColor(Color::Black);
	m_text_sword->setOrigin(0.f, m_text_sword->getGlobalBounds().height / 2.f);
	m_text_sword->setPosition(m_item_sword->getPosition() + Vector2f(40.f, -10.f));


	// heart
	m_item_heart->setSize(Vector2f(50.f, 50.f));
	m_item_heart->setOrigin(m_item_heart->getSize() / 2.f);
	m_item_heart->setTexture(DATA->getTexture("GUI/Piece/heart"));
	m_item_heart->setPosition(m_item_sword->getPosition() + Vector2f(0.f, 80.f));

	m_text_heart->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_heart->setString("+5% base health point (HP)");
	m_text_heart->setCharacterSize(45);
	m_text_heart->setFillColor(Color(255, 0, 102));
	m_text_heart->setOutlineThickness(1.f);
	m_text_heart->setOutlineColor(Color::Black);
	m_text_heart->setOrigin(0.f, m_text_heart->getGlobalBounds().height / 2.f);
	m_text_heart->setPosition(m_item_heart->getPosition() + Vector2f(40.f, -10.f));

	// mana
	m_item_mana->setSize(Vector2f(50.f, 50.f));
	m_item_mana->setOrigin(m_item_mana->getSize() / 2.f);
	m_item_mana->setTexture(DATA->getTexture("GUI/Piece/mana"));
	m_item_mana->setPosition(m_item_heart->getPosition() + Vector2f(0.f, 80.f));

	m_text_mana->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_mana->setString("+7% mana point (MP)");
	m_text_mana->setCharacterSize(45);
	m_text_mana->setFillColor(Color(0, 204, 255));
	m_text_mana->setOutlineThickness(1.f);
	m_text_mana->setOutlineColor(Color::Black);
	m_text_mana->setOrigin(0.f, m_text_mana->getGlobalBounds().height / 2.f);
	m_text_mana->setPosition(m_item_mana->getPosition() + Vector2f(40.f, -10.f));

	// armor
	m_item_armor->setSize(Vector2f(50.f, 50.f));
	m_item_armor->setOrigin(m_item_armor->getSize() / 2.f);
	m_item_armor->setTexture(DATA->getTexture("GUI/Piece/armor"));
	m_item_armor->setPosition(m_item_mana->getPosition() + Vector2f(0.f, 80.f));

	m_text_armor->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_armor->setString("+7% defend point (DEF)");
	m_text_armor->setCharacterSize(45);
	m_text_armor->setFillColor(Color(204, 102, 0));
	m_text_armor->setOutlineThickness(1.f);
	m_text_armor->setOutlineColor(Color::Black);
	m_text_armor->setOrigin(0.f, m_text_sword->getGlobalBounds().height / 2.f);
	m_text_armor->setPosition(m_item_armor->getPosition() + Vector2f(40.f, -10.f));

	// poison
	m_item_poison->setSize(Vector2f(50.f, 50.f));
	m_item_poison->setOrigin(m_item_poison->getSize() / 2.f);
	m_item_poison->setTexture(DATA->getTexture("GUI/Piece/poison"));
	m_item_poison->setPosition(m_item_armor->getPosition() + Vector2f(0.f, 80.f));

	m_text_poison->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_poison->setString("-5% MP and -5% DEF of enemy");
	m_text_poison->setCharacterSize(45);
	m_text_poison->setFillColor(Color(0, 230, 0));
	m_text_poison->setOutlineThickness(1.f);
	m_text_poison->setOutlineColor(Color::Black);
	m_text_poison->setOrigin(0.f, m_text_poison->getGlobalBounds().height / 2.f);
	m_text_poison->setPosition(m_item_poison->getPosition() + Vector2f(40.f, -10.f));

	// coin
	m_item_coin->setSize(Vector2f(50.f, 50.f));
	m_item_coin->setOrigin(m_item_coin->getSize() / 2.f);
	m_item_coin->setTexture(DATA->getTexture("GUI/Piece/coin"));
	m_item_coin->setPosition(m_item_poison->getPosition() + Vector2f(0.f, 80.f));

	m_text_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_coin->setString("+1 coin, used for rating");
	m_text_coin->setCharacterSize(45);
	m_text_coin->setFillColor(Color(255, 153, 0));
	m_text_coin->setOutlineThickness(1.f);
	m_text_coin->setOutlineColor(Color::Black);
	m_text_coin->setOrigin(0.f, m_text_coin->getGlobalBounds().height / 2.f);
	m_text_coin->setPosition(m_item_coin->getPosition() + Vector2f(40.f, -10.f));
}

void GSHelp::initPage2()
{
	// mana
	m_bar_mana->setSize(Vector2f(440.f, 80.f));
	m_bar_mana->setTexture(DATA->getTexture("GUI/Image/frame_mana"));
	m_bar_mana->setOrigin(m_bar_mana->getSize() / 2.f);
	m_bar_mana->setPosition(m_title->getPosition() + Vector2f(0.f, 110.f));

	m_text_mana_2->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_mana_2->setString("Ultimate attack state, x300% damage\nin the next attack turn");
	m_text_mana_2->setCharacterSize(35);
	m_text_mana_2->setFillColor(Color(51, 204, 255));
	m_text_mana_2->setOutlineThickness(1.f);
	m_text_mana_2->setOutlineColor(Color::Black);
	m_text_mana_2->setOrigin(0.f, m_text_mana_2->getGlobalBounds().height / 2.f);
	m_text_mana_2->setPosition(m_bar_mana->getPosition() + Vector2f(-260.f, 75.f));

	// shield
	m_bar_shield->setSize(Vector2f(440.f, 60.f));
	m_bar_shield->setTexture(DATA->getTexture("GUI/Image/frame_shield"));
	m_bar_shield->setOrigin(m_bar_shield->getSize() / 2.f);
	m_bar_shield->setPosition(m_bar_mana->getPosition() + Vector2f(0.f, 180.f));

	m_text_shield->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_shield->setString("Protected state, reduce 60% damage of\nenemy in the next attack turn");
	m_text_shield->setCharacterSize(35);
	m_text_shield->setFillColor(Color(102, 153, 153));
	m_text_shield->setOutlineThickness(1.f);
	m_text_shield->setOutlineColor(Color::Black);
	m_text_shield->setOrigin(0.f, m_text_shield->getGlobalBounds().height / 2.f);
	m_text_shield->setPosition(m_bar_shield->getPosition() + Vector2f(-260.f, 70.f));

	// continue
	m_text_continue->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_continue->setString("If you can match 3 more pieces of the same type\nduring your turn, you will continue on the next turn");
	m_text_continue->setCharacterSize(35);
	m_text_continue->setFillColor(Color(0, 255, 0));
	m_text_continue->setOutlineThickness(1.f);
	m_text_continue->setOutlineColor(Color::Black);
	m_text_continue->setOrigin(0.f, m_text_continue->getGlobalBounds().height / 2.f);
	m_text_continue->setPosition(m_text_shield->getPosition() + Vector2f(-85.f, 110.f));
}

void GSHelp::initPage3()
{
	// win
	m_text_if_win->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_if_win->setString("If you win a new map you will level up\nIf you win, you will get the coins in this game");
	m_text_if_win->setCharacterSize(35);
	m_text_if_win->setFillColor(Color(0, 255, 0));
	m_text_if_win->setOutlineThickness(1.f);
	m_text_if_win->setOutlineColor(Color::Black);
	m_text_if_win->setOrigin(0.f, m_text_if_win->getGlobalBounds().height / 2.f);
	m_text_if_win->setPosition(m_title->getPosition() + Vector2f(-320.f, 130.f));

	// lose
	m_text_if_lose->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_if_lose->setString("If you lose, your level does not change,\nbut you will lose the coins you get in this game");
	m_text_if_lose->setCharacterSize(35);
	m_text_if_lose->setFillColor(Color(255, 0, 102));
	m_text_if_lose->setOutlineThickness(1.f);
	m_text_if_lose->setOutlineColor(Color::Black);
	m_text_if_lose->setOrigin(0.f, m_text_if_lose->getGlobalBounds().height / 2.f);
	m_text_if_lose->setPosition(m_text_if_win->getPosition() + Vector2f(0.f, 110.f));

	// coin
	m_text_level_and_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_level_and_coin->setString("Levels and coins used for ranking");
	m_text_level_and_coin->setCharacterSize(35);
	m_text_level_and_coin->setFillColor(Color(255, 153, 51));
	m_text_level_and_coin->setOutlineThickness(1.f);
	m_text_level_and_coin->setOutlineColor(Color::Black);
	m_text_level_and_coin->setOrigin(0.f, m_text_level_and_coin->getGlobalBounds().height / 2.f);
	m_text_level_and_coin->setPosition(m_text_if_lose->getPosition() + Vector2f(0.f, 100.f));

	// note
	m_note->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_note->setString("You can log in with the username of the\nplayer in the ranking to play their account");
	m_note->setCharacterSize(35);
	m_note->setFillColor(Color(255, 0, 255));
	m_note->setOutlineThickness(1.f);
	m_note->setOutlineColor(Color::Black);
	m_note->setOrigin(0.f, m_note->getGlobalBounds().height / 2.f);
	m_note->setPosition(m_text_level_and_coin->getPosition() + Vector2f(0.f, 100.f));
}

void GSHelp::initButton()
{
	// left
	m_button_left->initButton(Vector2f(80.f, 80.f), "left");
	m_button_left->setPosition(m_frame->getPosition() + Vector2f(-m_frame->getSize().x / 2.f + 5.f, 0.f));
	m_button_left->setFunction([]() {});

	// right
	m_button_right->initButton(Vector2f(80.f, 80.f), "right");
	m_button_right->setPosition(m_frame->getPosition() + Vector2f(m_frame->getSize().x / 2.f - 5.f, 0.f));
	m_button_right->setFunction([]() {});

	// back
	m_button_back->initButton(Vector2f(250.f, 80.f), "bar_green");
	m_button_back->setPosition(m_frame->getPosition() + Vector2f(0.f, m_frame->getSize().y / 2.f - 5.f));
	m_button_back->setFunction([]() { GAMESTATE->popState(); });

	m_text_back->setString("BACK");
	m_text_back->setCharacterSize(60);
	m_text_back->setFont(*DATA->getFont("AllTheWayToTheSun"));
	m_text_back->setOrigin(m_text_back->getGlobalBounds().width / 2.f, m_text_back->getGlobalBounds().height / 2.f);
	m_text_back->setPosition(m_button_back->getPosition() + Vector2f(0.f, -17.f));
}

void GSHelp::updateButton(float delta_time)
{
	m_button_back->updateButton(delta_time);
	if (m_current_page == 1) {
		m_button_right->updateButton(delta_time);
		if (m_button_right->isHandling()) {
			m_current_page++;
		}
	}
	else if (m_current_page == 2) {
		m_button_left->updateButton(delta_time);
		m_button_right->updateButton(delta_time);
		if (m_button_left->isHandling()) {
			m_current_page--;
		}
		if (m_button_right->isHandling()) {
			m_current_page++;
		}
	}
	else if (m_current_page == 3) {
		m_button_left->updateButton(delta_time);
		if (m_button_left->isHandling()) {
			m_current_page--;
		}
	}
}

void GSHelp::renderPage1(RenderWindow* window)
{
	if (m_current_page != 1) return;
	window->draw(*m_item_sword);
	window->draw(*m_text_sword);
	window->draw(*m_item_heart);
	window->draw(*m_text_heart);
	window->draw(*m_item_mana);
	window->draw(*m_text_mana);
	window->draw(*m_item_armor);
	window->draw(*m_text_armor);
	window->draw(*m_item_poison);
	window->draw(*m_text_poison);
	window->draw(*m_item_coin);
	window->draw(*m_text_coin);

	m_button_left->setTexture(DATA->getTexture("GUI/Button/left_lock"));
	window->draw(*m_button_left);

	m_button_right->setTexture(DATA->getTexture("GUI/Button/right"));
	window->draw(*m_button_right);
}

void GSHelp::renderPage2(RenderWindow* window)
{
	if (m_current_page != 2) return;
	window->draw(*m_bar_mana);
	window->draw(*m_text_mana_2);
	window->draw(*m_bar_shield);
	window->draw(*m_text_shield);
	window->draw(*m_text_continue);

	m_button_left->setTexture(DATA->getTexture("GUI/Button/left"));
	window->draw(*m_button_left);

	m_button_right->setTexture(DATA->getTexture("GUI/Button/right"));
	window->draw(*m_button_right);
}

void GSHelp::renderPage3(RenderWindow* window)
{
	if (m_current_page != 3) return;
	window->draw(*m_text_if_win);
	window->draw(*m_text_if_lose);
	window->draw(*m_text_level_and_coin);
	window->draw(*m_note);

	m_button_left->setTexture(DATA->getTexture("GUI/Button/left"));
	window->draw(*m_button_left);

	m_button_right->setTexture(DATA->getTexture("GUI/Button/right_lock"));
	window->draw(*m_button_right);
}

void GSHelp::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initPage1();
	this->initPage2();
	this->initPage3();
	this->initButton();
}

void GSHelp::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	this->updateButton(delta_time);
}

void GSHelp::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_title);

	m_button_back->renderButton(window);
	window->draw(*m_text_back);

	this->renderPage1(window);
	this->renderPage2(window);
	this->renderPage3(window);
}