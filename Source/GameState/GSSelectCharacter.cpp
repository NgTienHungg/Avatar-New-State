#include "GSSelectCharacter.h"

GSSelectCharacter::GSSelectCharacter()
{
	m_background = new Background();
	m_frame = new RectangleShape();
	m_headline = new Text();
	m_character_name = new Text();

	m_select_fire = new RectangleShape();
	m_select_water = new RectangleShape();
	m_select_wind = new RectangleShape();
	m_select_ground = new RectangleShape();

	m_idle_fire = new Animation();
	m_idle_water = new Animation();
	m_idle_wind = new Animation();
	m_idle_ground = new Animation();

	m_atk_fire = new Animation();
	m_atk_water = new Animation();
	m_atk_wind = new Animation();
	m_atk_ground = new Animation();

	m_button_play = new Button();
	m_button_cancel = new Button();

	m_mouse_position = Vector2f(0.f, 0.f);
	m_current_time_click = 0.f;
	m_selection = -1; // chưa chọn
}

GSSelectCharacter::~GSSelectCharacter()
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
	if (m_character_name != nullptr) {
		delete m_character_name;
	}
	if (m_select_fire != nullptr) {
		delete m_select_fire;
	}
	if (m_select_water != nullptr) {
		delete m_select_water;
	}
	if (m_select_wind != nullptr) {
		delete m_select_wind;
	}
	if (m_select_ground != nullptr) {
		delete m_select_ground;
	}
	if (m_idle_fire != nullptr) {
		delete m_idle_fire;
	}
	if (m_idle_water != nullptr) {
		delete m_idle_water;
	}
	if (m_idle_wind != nullptr) {
		delete m_idle_wind;
	}
	if (m_idle_ground != nullptr) {
		delete m_idle_ground;
	}
	if (m_atk_fire != nullptr) {
		delete m_atk_fire;
	}
	if (m_atk_water != nullptr) {
		delete m_atk_water;
	}
	if (m_atk_wind != nullptr) {
		delete m_atk_wind;
	}
	if (m_atk_ground != nullptr) {
		delete m_atk_ground;
	}
	if (m_button_play != nullptr) {
		delete m_button_play;
	}
	if (m_button_cancel != nullptr) {
		delete m_button_cancel;
	}
}

GameState GSSelectCharacter::getTypeState()
{
	return GameState::SELECT_CHARACTER;
}

void GSSelectCharacter::initBoard()
{
	// frame
	m_frame->setTexture(DATA->getTexture("GUI/Frame/level_select"));
	m_frame->setSize(Vector2f(1000.f, 600.f));
	m_frame->setOrigin(m_frame->getSize() / 2.f);
	m_frame->setPosition(Vector2f(ScreenWidth / 2, ScreenHeight / 2) + Vector2f(0.f, -30.f));

	// headline
	m_headline->setString("CHOOSE A WARRIOR");
	m_headline->setFont(*DATA->getFont("Arista20AlternateRegular"));
	m_headline->setCharacterSize(80);
	m_headline->setFillColor(Color(255, 51, 187));
	m_headline->setOutlineThickness(1.5f);
	m_headline->setOutlineColor(Color::Black);
	m_headline->setOrigin(m_headline->getGlobalBounds().width / 2.f, m_headline->getGlobalBounds().height / 2.f);
	m_headline->setPosition(m_frame->getPosition() + Vector2f(0.f, -m_frame->getSize().y / 2.f + m_headline->getCharacterSize() / 2.f));

	// name character
	m_character_name->setFont(*DATA->getFont("LaoutBeautyPersonalUse"));
	m_character_name->setCharacterSize(70);
	m_character_name->setOutlineThickness(1.5f);
	m_character_name->setOutlineColor(Color::Black);
	m_character_name->setPosition(m_headline->getPosition() + Vector2f(0.f, 120.f));
}

void GSSelectCharacter::initAnimationFire()
{
	m_select_fire->setSize(Vector2f(120.f, 160.f));
	m_select_fire->setOrigin(60.f, 160.f);
	m_select_fire->setFillColor(Color::Transparent);
	m_select_fire->setPosition(m_frame->getPosition() + Vector2f(-360.f, 120.f));

	USER->setCharacter(1); // gọi tới Nhân vật để lấy Scale
	m_idle_fire->initAnimation("FireKnight/idle", Vector2i(3, 2), 6, 0.1f);
	m_idle_fire->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_idle_fire->setPosition(m_select_fire->getPosition());

	m_atk_fire->initAnimation("FireKnight/atk_1", Vector2i(4, 3), 11, 0.1f);
	m_atk_fire->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_atk_fire->setPosition(m_select_fire->getPosition());
}

void GSSelectCharacter::initAnimationWater()
{
	m_select_water->setSize(Vector2f(120.f, 160.f));
	m_select_water->setOrigin(60.f, 160.f);
	m_select_water->setFillColor(Color::Transparent);
	m_select_water->setPosition(m_frame->getPosition() + Vector2f(-120.f, 120.f));

	USER->setCharacter(2);
	m_idle_water->initAnimation("WaterPriestess/idle", Vector2i(3, 3), 8, 0.1f);
	m_idle_water->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_idle_water->setPosition(m_select_water->getPosition());

	m_atk_water->initAnimation("WaterPriestess/atk_1", Vector2i(3, 3), 7, 0.12f);
	m_atk_water->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_atk_water->setPosition(m_select_water->getPosition());
}

void GSSelectCharacter::initAnimationWind()
{
	m_select_wind->setSize(Vector2f(120.f, 160.f));
	m_select_wind->setOrigin(60.f, 160.f);
	m_select_wind->setFillColor(Color::Transparent);
	m_select_wind->setPosition(m_frame->getPosition() + Vector2f(120.f, 120.f));

	USER->setCharacter(3);
	m_idle_wind->initAnimation("WindHashashin/idle", Vector2i(3, 3), 8, 0.1f);
	m_idle_wind->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_idle_wind->setPosition(m_select_wind->getPosition());

	m_atk_wind->initAnimation("WindHashashin/atk_1", Vector2i(3, 3), 8, 0.1f);
	m_atk_wind->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_atk_wind->setPosition(m_select_wind->getPosition());
}

void GSSelectCharacter::initAnimationGround()
{
	m_select_ground->setSize(Vector2f(120.f, 160.f));
	m_select_ground->setOrigin(60.f, 160.f);
	m_select_ground->setFillColor(Color::Transparent);
	m_select_ground->setPosition(m_frame->getPosition() + Vector2f(360.f, 120.f));

	USER->setCharacter(4);
	m_idle_ground->initAnimation("GroundMonk/idle", Vector2i(3, 2), 5, 0.1f);
	m_idle_ground->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_idle_ground->setPosition(m_select_ground->getPosition());

	m_atk_ground->initAnimation("GroundMonk/atk_1", Vector2i(4, 3), 12, 0.11f);
	m_atk_ground->setScale(USER->getCharacter()->getStateManager()->getScale());
	m_atk_ground->setPosition(m_select_ground->getPosition());
}

void GSSelectCharacter::initButton()
{
	// play button
	m_button_play->initButton(Vector2f(120.f, 120.f), "play_gray");
	m_button_play->setPosition(m_frame->getPosition() + Vector2f(-150.f, m_frame->getSize().y / 2.f));
	m_button_play->setFunction([]() { GAMESTATE->changeState(GameState::PLAY); });

	// cancel button
	m_button_cancel->initButton(Vector2f(120.f, 120.f), "exit");
	m_button_cancel->setPosition(m_frame->getPosition() + Vector2f(150.f, m_frame->getSize().y / 2.f));
	m_button_cancel->setFunction([]() { GAMESTATE->popState(); });
}

void GSSelectCharacter::updateCharacterName()
{
	if (m_selection == 1) {
		m_character_name->setString("Fire Knight");
		m_character_name->setFillColor(Color(255, 0, 0));
	}
	else if (m_selection == 2) {
		m_character_name->setString("Water Priestess");
		m_character_name->setFillColor(Color(26, 209, 255));
	}
	else if (m_selection == 3) {
		m_character_name->setString("Wind Hashashin");
		m_character_name->setFillColor(Color(0, 255, 204));
	}
	else if (m_selection == 4) {
		m_character_name->setString("Ground Monk");
		m_character_name->setFillColor(Color(153, 102, 51));
	}
	m_character_name->setOrigin(m_character_name->getGlobalBounds().width / 2.f, m_character_name->getGlobalBounds().height / 2.f);
}

void GSSelectCharacter::updateButtonPlay(float delta_time)
{
	if (m_selection != -1) {
		m_button_play->updateButton(delta_time);
		if (m_button_play->isHandling()) {
			USER->setCharacter(m_selection);
		}
	}
}

void GSSelectCharacter::updateView(int type, RectangleShape* select, Animation* idle, Animation* atk, float delta_time)
{
	// Nếu chưa chọn nhân vật
	if (m_selection == -1) {
		if (select->getGlobalBounds().contains(m_mouse_position)) {
			atk->updateAnimation(delta_time);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				m_current_time_click += delta_time;
				if (m_current_time_click >= ClickTime) {
					DATA->playSound("click");
					m_current_time_click = 0.f;
					m_selection = type;
					m_button_play->setTexture(DATA->getTexture("GUI/Button/play_green"));
				}
			}
			else {
				m_current_time_click = 0.f;
			}
		}
		else {
			idle->updateAnimation(delta_time);
		}
		return;
	}
	if (m_selection == type) {
		atk->updateAnimation(delta_time);
	}
	else {
		idle->updateAnimation(delta_time);
		if (select->getGlobalBounds().contains(m_mouse_position)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				m_current_time_click += delta_time;
				if (m_current_time_click >= ClickTime) {
					DATA->playSound("click");
					m_current_time_click = 0.f;
					m_selection = type;
				}
			}
			else {
				m_current_time_click = 0.f;
			}
		}
	}
}

void GSSelectCharacter::renderView(int type, RectangleShape* select, Animation* idle, Animation* atk, RenderWindow* window)
{
	// Chưa chọn nhân vật
	if (m_selection == -1) {
		if (select->getGlobalBounds().contains(m_mouse_position)) {
			atk->renderAnimation(window);
		}
		else {
			idle->renderAnimation(window);
		}
	}
	else {
		if (m_selection == type) {
			atk->renderAnimation(window);
		}
		else {
			idle->renderAnimation(window);
		}
	}
}

void GSSelectCharacter::initState()
{
	m_background->initBackground();
	this->initBoard();
	this->initAnimationFire();
	this->initAnimationWater();
	this->initAnimationWind();
	this->initAnimationGround();
	this->initButton();
}

void GSSelectCharacter::updateState(float delta_time)
{
	m_background->updateBackground(delta_time);
	this->updateCharacterName();
	m_mouse_position = (Vector2f)Mouse::getPosition(*APP->getWindow());
	
	updateView(1, m_select_fire, m_idle_fire, m_atk_fire, delta_time);
	updateView(2, m_select_water, m_idle_water, m_atk_water, delta_time);
	updateView(3, m_select_wind, m_idle_wind, m_atk_wind, delta_time);
	updateView(4, m_select_ground, m_idle_ground, m_atk_ground, delta_time);

	this->updateButtonPlay(delta_time);
	m_button_cancel->updateButton(delta_time);
}

void GSSelectCharacter::renderState(RenderWindow* window)
{
	m_background->renderBackground(window);
	window->draw(*m_frame);
	window->draw(*m_headline);
	window->draw(*m_character_name);
	
	window->draw(*m_select_fire);
	window->draw(*m_select_water);
	window->draw(*m_select_wind);
	window->draw(*m_select_ground);

	renderView(1, m_select_fire, m_idle_fire, m_atk_fire, window);
	renderView(2, m_select_water, m_idle_water, m_atk_water, window);
	renderView(3, m_select_wind, m_idle_wind, m_atk_wind, window);
	renderView(4, m_select_ground, m_idle_ground, m_atk_ground, window);

	m_button_play->renderButton(window);
	m_button_cancel->renderButton(window);
}