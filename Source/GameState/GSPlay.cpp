#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_background = new Sprite();
	m_match = new Match();
	m_player = nullptr;
	m_enemy = new Character();
	m_button_pause = new Button();

	m_board_coin = new RectangleShape();
	m_text_coin = new Text();

	m_board_time = new RectangleShape();
	m_text_time = new Text();

	m_notify = new Text();

	m_coin_point = 0;
	m_sword_point = 0;
	m_damage = 0.f;

	m_time_play = 16.f;
	m_current_time_play = 0.f;
	m_time_perform = 0.f;
	m_current_time_perform = 0.f;

	m_is_intro = true;
	m_is_playing = false;
	m_is_performing = false;
	m_is_player_turn = false;
	m_is_started_play = false;
	m_is_stop_game_play = false;
	m_is_player_win = false;
	m_is_continue_next_turn = false;
}

GSPlay::~GSPlay()
{
	if (m_background != nullptr) {
		delete m_background;
	}
	if (m_match != nullptr) {
		delete m_match;
	}
	if (m_player != nullptr) {
		delete m_player;
	}
	if (m_enemy != nullptr) {
		delete m_enemy;
	}
	if (m_button_pause != nullptr) {
		delete m_button_pause;
	}
	if (m_board_coin != nullptr) {
		delete m_board_coin;
	}
	if (m_text_coin != nullptr) {
		delete m_text_coin;
	}
	if (m_board_time != nullptr) {
		delete m_board_time;
	}
	if (m_text_time != nullptr) {
		delete m_text_time;
	}
	if (m_notify != nullptr) {
		delete m_notify;
	}
}

GameState GSPlay::getTypeState()
{
	return GameState::PLAY;
}

void GSPlay::initBoardCoin()
{
	m_board_coin->setTexture(DATA->getTexture("GUI/Image/coin"));
	m_board_coin->setSize(Vector2f(180.f, 60.f));
	m_board_coin->setPosition(Vector2f(185.f, 5.f));

	m_text_coin->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_coin->setCharacterSize(60);
	m_text_coin->setFillColor(Color::Black);
	m_text_coin->setPosition(Vector2f(300.f, 13.f));
}

void GSPlay::initBoardTime()
{
	m_board_time->setTexture(DATA->getTexture("GUI/Image/time"));
	m_board_time->setSize(Vector2f(180.f, 60.f));
	m_board_time->setPosition(Vector2f(1075.f, 5.f));

	m_text_time->setFont(*DATA->getFont("TrulyMadlyDpad"));
	m_text_time->setCharacterSize(60);
	m_text_time->setFillColor(Color::Black);
	m_text_time->setPosition(Vector2f(1190.f, 13.f));
}

void GSPlay::initButtonPause()
{
	m_button_pause->initButton(Vector2f(80.f, 80.f), "setting");
	m_button_pause->setPosition(Vector2f(ScreenWidth - m_button_pause->getSize().x / 2.f - 10.f, m_button_pause->getSize().y / 2.f + 10.f));
	m_button_pause->setFunction([]() { GAMESTATE->changeState(GameState::PAUSE); });
}

void GSPlay::initNotify()
{
	m_notify->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_notify->setString("---> Ready <---");
	m_notify->setCharacterSize(80);
	m_notify->setFillColor(Color(0, 255, 204));
	m_notify->setOutlineThickness(2.f);
	m_notify->setOutlineColor(Color::Black);
	m_notify->setOrigin(m_notify->getGlobalBounds().width / 2.f, m_notify->getGlobalBounds().height / 2.f);
	m_notify->setPosition(NotifyPosition);
}

void GSPlay::introState(float delta_time)
{
	m_match->updateMatch(delta_time);
	m_player->updateCharacter(delta_time);
	m_enemy->updateCharacter(delta_time);

	if (m_player->getPosition() != PlayerPosition) {
		m_player->setPosition(m_player->getPosition() + Vector2f(1.f, 0.f));
	}
	if (m_enemy->getPosition() != EnemyPosition) {
		m_enemy->setPosition(m_enemy->getPosition() + Vector2f(-1.f, 0.f));
	}

	Color color = m_notify->getFillColor();
	int alpha = color.a;
	if (color.a != 0) {
		m_notify->setFillColor(Color(color.r, color.g, color.b, alpha - 1));
		m_notify->setOutlineColor(Color(0, 0, 0, alpha - 1));
		m_notify->move(0.f, -0.4f);
	}

	// finish intro game
	if (m_match->isMatchReady()) {
		m_player->getStateManager()->changeState(CharacterState::IDLE);
		m_enemy->getStateManager()->changeState(CharacterState::IDLE);
		m_player->setPosition(PlayerPosition);
		m_enemy->setPosition(EnemyPosition);
		DATA->stopMusic("intro_gameplay");
		DATA->playMusic("gameplay");
		m_is_intro = false;
		m_is_playing = true;
		m_is_player_turn = true;

		m_notify->setString("---> Your Turn <---");
		m_notify->setFillColor(Color(0, 255, 0, 255));
		m_notify->setOutlineColor(Color(0, 0, 0, 255));
		m_notify->setOrigin(m_notify->getGlobalBounds().width / 2.f, m_notify->getGlobalBounds().height / 2.f);
		m_notify->setPosition(NotifyPosition);
	}
}

void GSPlay::handlePoint() {
	if (m_match->hasPoint()) {
		// finish a match
		m_is_started_play = true;
		float health_point = m_match->getPoints()[0];
		float mana_point = m_match->getPoints()[1];
		float poison_point = m_match->getPoints()[2];
		float armor_point = m_match->getPoints()[4];
		float coin_point = m_match->getPoints()[5];
		m_sword_point += (int)m_match->getPoints()[3];
		
		if (m_is_player_turn) {
			m_coin_point += (int)coin_point;
			m_player->getAttributeManager()->updateAttributeManager(m_player->getAttributeManager()->getBaseHealth() * health_point / 100.f, mana_point, armor_point);
			m_enemy->getAttributeManager()->updateAttributeManager(0, -poison_point / 2.f, -poison_point / 2.f);
		}
		else {
			m_enemy->getAttributeManager()->updateAttributeManager(m_enemy->getAttributeManager()->getBaseHealth() * health_point / 100.f, mana_point, armor_point);
			m_player->getAttributeManager()->updateAttributeManager(0, -poison_point / 2.f, -poison_point / 2.f);
		}
		m_match->resetPoints();
	}

	// finish a turn
	if (m_is_started_play && m_match->isFinishedTurn() && !m_is_performing && m_is_playing) {
		m_is_started_play = false;
		m_current_time_play = 0.f;
		
		// set attack animation
		if (m_sword_point != 0) {
			m_is_playing = false;
			m_is_performing = true;

			CharacterState atk_state, def_state;
			if (m_sword_point == 3) {
				atk_state = CharacterState::ATK_NORMAL;
			}
			else {
				atk_state = CharacterState::ATK_STRONG;
			}

			if (m_is_player_turn) {
				// damage = base_attack * sword_point
				m_damage = m_player->getAttributeManager()->getBaseAttack() * m_sword_point;
				
				if (m_player->getAttributeManager()->isPowerful()) {
					// 100% mana -> isPowerful -> damage x 3
					atk_state = CharacterState::ATK_ULTIMATE;
					m_player->getAttributeManager()->resetMana();
					m_damage *= 3;
				}
				m_player->getStateManager()->changeState(atk_state);
				m_player->setPosition(PlayerAttackPosition);
				m_time_perform = m_player->getStateManager()->getCurrentState()->getTotalTime();

				def_state = CharacterState::HURT;
				if (m_enemy->getAttributeManager()->isProtected()) {
					// 100% defend -> isProtected() -> damage x 0.6
					def_state = CharacterState::DEFEND;
					m_enemy->getAttributeManager()->resetShield();
					m_damage *= 0.6f;
				}
				m_enemy->getStateManager()->changeState(def_state);
			}
			else {
				m_damage = m_enemy->getAttributeManager()->getBaseAttack() * m_sword_point;
				if (m_enemy->getAttributeManager()->isPowerful()) {
					atk_state = CharacterState::ATK_ULTIMATE;
					m_enemy->getAttributeManager()->resetMana();
					m_damage *= 3;
				}
				m_enemy->getStateManager()->changeState(atk_state);
				m_enemy->setPosition(EnemyAttackPosition);
				m_time_perform = m_enemy->getStateManager()->getCurrentState()->getTotalTime();

				def_state = CharacterState::HURT;
				if (m_player->getAttributeManager()->isProtected()) {
					def_state = CharacterState::DEFEND;
					m_player->getAttributeManager()->resetShield();
					m_damage *= 0.6f;
				}
				m_player->getStateManager()->changeState(def_state);
			}
		}
		else {
			// match > 4 item consecutive => continue next turn
			if (m_match->isContinueNextTurn()) {
				m_is_continue_next_turn = true;
			}
			else {
				m_is_player_turn = true - m_is_player_turn;
			}
			m_match->resetTurn();
		}
	}
}

void GSPlay::performAnimation(float delta_time)
{
	if (m_is_performing) {
		m_current_time_perform += delta_time;
		// Khi đã perform xong rồi, cho đứng lại 0.05s
		if (m_current_time_perform >= m_time_perform + 0.05f) {
			m_player->setPosition(PlayerPosition);
			m_enemy->setPosition(EnemyPosition);
			m_current_time_perform = 0.f;
			m_is_performing = false;
			m_is_playing = true;

			if (m_player->getAttributeManager()->isDead() || m_enemy->getAttributeManager()->isDead()) {
				m_is_stop_game_play = true;
				DATA->stopMusic("gameplay");
				// Sau khi win, cho 1 khoảng thời gian để perform địch chết
				if (m_player->getAttributeManager()->isDead()) {
					m_player->getStateManager()->changeState(CharacterState::DEATH);
					m_time_perform = m_player->getStateManager()->getCurrentState()->getTotalTime();
					DATA->playSound("lose");
				}
				else {
					m_enemy->getStateManager()->changeState(CharacterState::DEATH);
					m_time_perform = m_enemy->getStateManager()->getCurrentState()->getTotalTime();
					DATA->playSound("win");
				}
				return;
			}
			
			if (m_match->isContinueNextTurn()) {
				m_is_continue_next_turn = true;
			}
			else {
				m_is_player_turn = true - m_is_player_turn;
			}
			m_match->resetTurn();
			return;
		}

		if (m_current_time_perform >= m_time_perform) {
			m_player->getStateManager()->changeState(CharacterState::IDLE);
			m_enemy->getStateManager()->changeState(CharacterState::IDLE);
			if (m_is_player_turn) {
				m_enemy->getAttributeManager()->updateAttributeManager(-m_damage, 0.f, 0.f);
				if (m_enemy->getAttributeManager()->isDead()) {
					m_is_player_win = true;
				}
			}
			else {
				m_player->getAttributeManager()->updateAttributeManager(-m_damage, 0.f, 0.f);
				if (m_player->getAttributeManager()->isDead()) {
					m_is_player_win = false;
				}
			}
			m_damage = 0;
			m_sword_point = 0;
		}
	}
}

void GSPlay::handleWinLose(float delta_time)
{
	if (m_is_stop_game_play) {
		m_current_time_perform += delta_time;
		if (m_current_time_perform <= m_time_perform - 0.08f) {
			// 0.08f: để dừng lại ở frame cuối cùng của animation DeathState.
			m_player->updateCharacter(delta_time);
			m_enemy->updateCharacter(delta_time);
		}
		else if (m_current_time_perform <= m_time_perform + 1.5f) {
			if (m_is_player_win) {
				m_player->updateCharacter(delta_time);
			}
			else {
				m_enemy->updateCharacter(delta_time);
			}
		}
		else {
			DATA->setResultGame(m_is_player_win);
			DATA->setCoinPlay(m_coin_point);
			GAMESTATE->changeState(GameState::END);
		}
	}
}

void GSPlay::handleTimePlay(float delta_time)
{
	if (!m_is_performing && m_is_playing && !m_match->isMoving()) {
		m_current_time_play += delta_time;
		if (m_current_time_play >= m_time_play) {
			m_current_time_play = 0.f;
			m_is_player_turn = true - m_is_player_turn;
		}
		string time_remain = to_string(int(m_time_play - m_current_time_play));
		m_text_time->setString(time_remain);
		m_text_time->setOrigin(m_text_time->getGlobalBounds().width / 2.f, m_text_time->getGlobalBounds().height / 2.f);
	}
}

void GSPlay::handleNotify()
{
	if (m_current_time_play == 0.f && !m_is_performing && !m_is_stop_game_play) {
		if (m_is_player_turn) {
			m_notify->setString("---> Your Turn <---");
			if (m_is_continue_next_turn) {
				m_notify->setString("---> Continue <---");
				m_is_continue_next_turn = false;
			}
			m_notify->setFillColor(Color(0, 255, 0, 255));
		}
		else {
			m_notify->setString("--> Enemy Turn <--");
			if (m_is_continue_next_turn) {
				m_notify->setString("---> Continue <---");
				m_is_continue_next_turn = false;
			}
			m_notify->setFillColor(Color(255, 0, 102, 255));
		}
		m_notify->setOutlineColor(Color(0, 0, 0, 255));
		m_notify->setOrigin(m_notify->getGlobalBounds().width / 2.f, m_notify->getGlobalBounds().height / 2.f);
		m_notify->setPosition(NotifyPosition);
		return;
	}

	Color color = m_notify->getFillColor();
	int alpha = color.a;
	if (color.a != 0) {
		m_notify->setFillColor(Color(color.r, color.g, color.b, alpha - 1));
		m_notify->setOutlineColor(Color(0, 0, 0, alpha - 1));
		m_notify->move(0.f, -0.4f);
	}
}

void GSPlay::initState()
{
	// stop music in menu state
	DATA->stopMusic("background");
	DATA->playMusic("intro_gameplay");

	// Background
	ifstream fin("Data/FileData/level_" + to_string(DATA->getMapLevel()) + ".txt");
	string f_background; fin >> f_background;
	m_background->setTexture(*DATA->getTexture("Background/" + f_background));
	m_background->setScale(0.75f, 0.75f);
	DATA->setBackgroundGP(m_background);

	// Match
	m_match->initMatch();

	// Player
	m_player = USER->getCharacter();
	m_player->getStateManager()->changeState(CharacterState::RUN);
	m_player->setPosition(Vector2f(0.f, ScreenHeight));
	m_player->getAttributeManager()->resetAttribute();
	m_player->getAttributeManager()->setPosition(Vector2f(160.f, 150.f));

	// Enemy
	string f_enemy; fin >> f_enemy;
	float f_scale, f_health, f_attack;
	fin >> f_scale >> f_health >> f_attack;
	m_enemy->getStateManager()->changeState(CharacterState::RUN);
	m_enemy->getAttributeManager()->setPosition(Vector2f(1120.f, 150.f));
	m_enemy->initCharacter(f_enemy, Vector2f(ScreenWidth, ScreenHeight), Vector2f(-f_scale, f_scale), f_health, f_attack);
	fin.close();

	// UI
	this->initBoardCoin();
	this->initBoardTime();
	this->initButtonPause();
	this->initNotify();
}

void GSPlay::updateState(float delta_time)
{
	if (m_is_intro) {
		this->introState(delta_time);
		return;
	}
	if (m_is_stop_game_play) {
		this->handleWinLose(delta_time);
		return;
	}
	if (!m_is_performing) {
		if (m_is_player_turn)
			m_match->updateMatch(delta_time);
		else
			m_match->updateBot(delta_time);
	}
	this->handleTimePlay(delta_time);
	this->handlePoint();
	this->performAnimation(delta_time);
	m_player->updateCharacter(delta_time);
	m_enemy->updateCharacter(delta_time);
	this->handleNotify();

	m_text_coin->setString(to_string(m_coin_point));
	m_text_coin->setOrigin(m_text_coin->getGlobalBounds().width / 2.f, m_text_coin->getGlobalBounds().height / 2.f);
	m_button_pause->updateButton(delta_time);
}

void GSPlay::renderState(RenderWindow* window)
{
	window->draw(*m_background);
	window->draw(*m_board_coin);
	window->draw(*m_text_coin);
	window->draw(*m_board_time);
	window->draw(*m_text_time);
	window->draw(*m_notify);
	m_match->renderMatch(window);
	m_player->renderCharacter(window);
	m_enemy->renderCharacter(window);
	m_button_pause->renderButton(window);
}