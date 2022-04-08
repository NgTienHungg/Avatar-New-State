#include "AttributeManager.h"

AttributeManager::AttributeManager(Character* character)
{
	m_character = character;

	m_base_attack = 0.f;
	m_base_health = 0.f;
	m_base_mana = 100.f;
	m_base_shield = 100.f;

	m_current_heath = 0.f;
	m_current_mana = 0.f;
	m_current_shield = 0.f;

	m_bar_hp_bg = new RectangleShape();
	m_logo_hp = new RectangleShape();
	m_bar_hp_max = new RectangleShape();
	m_bar_hp_current = new RectangleShape();

	m_bar_mp_bg = new RectangleShape();
	m_logo_mp = new RectangleShape();
	m_bar_mp_max = new RectangleShape();
	m_bar_mp_current = new RectangleShape();

	m_bar_dp_bg = new RectangleShape();
	m_logo_dp = new RectangleShape();
	m_bar_dp_max = new RectangleShape();
	m_bar_dp_current = new RectangleShape();
}

AttributeManager::~AttributeManager()
{
	if (m_bar_hp_bg != nullptr) {
		delete m_bar_hp_bg;
	}
	if (m_logo_hp != nullptr) {
		delete m_logo_hp;
	}
	if (m_bar_hp_max != nullptr) {
		delete m_bar_hp_max;
	}
	if (m_bar_hp_current != nullptr) {
		delete m_bar_hp_current;
	}
	if (m_bar_mp_bg != nullptr) {
		delete m_bar_mp_bg;
	}
	if (m_logo_mp != nullptr) {
		delete m_logo_mp;
	}
	if (m_bar_mp_max != nullptr) {
		delete m_bar_mp_max;
	}
	if (m_bar_mp_current != nullptr) {
		delete m_bar_mp_current;
	}
	if (m_bar_dp_bg != nullptr) {
		delete m_bar_dp_bg;
	}
	if (m_logo_dp != nullptr) {
		delete m_logo_dp;
	}
	if (m_bar_dp_max != nullptr) {
		delete m_bar_dp_max;
	}
	if (m_bar_dp_current != nullptr) {
		delete m_bar_dp_current;
	}
}

void AttributeManager::setPosition(Vector2f position)
{
	m_position = position;
}

float AttributeManager::getBaseAttack()
{
	return m_base_attack;
}

float AttributeManager::getBaseHealth()
{
	return m_base_health;
}

void AttributeManager::resetAttribute()
{
	m_current_heath = m_base_health;
	m_current_mana = 30.f;
	m_current_shield = 30.f;
}

void AttributeManager::resetMana()
{
	m_current_mana = 0;
}

void AttributeManager::resetShield()
{
	m_current_shield = 0;
}

bool AttributeManager::isPowerful()
{
	return m_current_mana == m_base_mana;
}

bool AttributeManager::isProtected()
{
	return m_current_shield == m_base_shield;
}

bool AttributeManager::isDead()
{
	return m_current_heath == 0;
}

void AttributeManager::initAttributeManager(float health, float attack)
{
	m_base_attack = attack;
	m_base_health = health;
	this->resetAttribute();

	Vector2f size_bar_bg = Vector2f(60.f, 400.f);
	Vector2f size_logo = Vector2f(45.f, 45.f);
	Vector2f size_bar = Vector2f(40.f, 320.f);

	// Health
	m_bar_hp_bg->setTexture(DATA->getTexture("GUI/Image/bar_background"));
	m_bar_hp_bg->setSize(size_bar_bg);
	m_bar_hp_bg->setOrigin(size_bar_bg.x / 2.f, 0.f);
	m_bar_hp_bg->setPosition(m_position);

	m_logo_hp->setTexture(DATA->getTexture("GUI/Image/health"));
	m_logo_hp->setSize(size_logo);
	m_logo_hp->setOrigin(size_logo.x / 2.f, 0.f);
	m_logo_hp->setPosition(m_bar_hp_bg->getPosition() + Vector2f(0.f, 10.f));

	m_bar_hp_max->setTexture(DATA->getTexture("GUI/Image/bar_max"));
	m_bar_hp_max->setSize(size_bar);
	m_bar_hp_max->setOrigin(size_bar.x / 2.f, size_bar.y);
	m_bar_hp_max->setPosition(m_bar_hp_bg->getPosition() + Vector2f(0.f, size_bar_bg.y - 15.f));

	m_bar_hp_current->setTexture(DATA->getTexture("GUI/Image/bar_health"));
	m_bar_hp_current->setSize(size_bar);
	m_bar_hp_current->setPosition(m_bar_hp_max->getPosition());

	// Mana
	m_bar_mp_bg->setTexture(DATA->getTexture("GUI/Image/bar_background"));
	m_bar_mp_bg->setSize(size_bar_bg);
	m_bar_mp_bg->setOrigin(size_bar_bg.x / 2.f, 0.f);
	m_bar_mp_bg->setPosition(m_bar_hp_bg->getPosition() + Vector2f(size_bar_bg.x + 20.f, 0.f));

	m_logo_mp->setTexture(DATA->getTexture("GUI/Image/mana"));
	m_logo_mp->setSize(size_logo);
	m_logo_mp->setOrigin(size_logo.x / 2.f, 0.f);
	m_logo_mp->setPosition(m_bar_mp_bg->getPosition() + Vector2f(0.f, 10.f));

	m_bar_mp_max->setTexture(DATA->getTexture("GUI/Image/bar_max"));
	m_bar_mp_max->setSize(size_bar);
	m_bar_mp_max->setOrigin(size_bar.x / 2.f, size_bar.y);
	m_bar_mp_max->setPosition(m_bar_mp_bg->getPosition() + Vector2f(0.f, size_bar_bg.y - 15.f));

	m_bar_mp_current->setTexture(DATA->getTexture("GUI/Image/bar_mana"));
	m_bar_mp_current->setSize(size_bar);
	m_bar_mp_current->setPosition(m_bar_mp_max->getPosition());

	// Shield
	m_bar_dp_bg->setTexture(DATA->getTexture("GUI/Image/bar_background"));
	m_bar_dp_bg->setSize(size_bar_bg);
	m_bar_dp_bg->setOrigin(size_bar_bg.x / 2.f, 0.f);
	m_bar_dp_bg->setPosition(m_bar_mp_bg->getPosition() + Vector2f(size_bar_bg.x + 20.f, 0.f));

	m_logo_dp->setTexture(DATA->getTexture("GUI/Image/shield"));
	m_logo_dp->setSize(size_logo);
	m_logo_dp->setOrigin(size_logo.x / 2.f, 0.f);
	m_logo_dp->setPosition(m_bar_dp_bg->getPosition() + Vector2f(0.f, 10.f));

	m_bar_dp_max->setTexture(DATA->getTexture("GUI/Image/bar_max"));
	m_bar_dp_max->setSize(size_bar);
	m_bar_dp_max->setOrigin(size_bar.x / 2.f, size_bar.y);
	m_bar_dp_max->setPosition(m_bar_dp_bg->getPosition() + Vector2f(0.f, size_bar_bg.y - 15.f));

	m_bar_dp_current->setTexture(DATA->getTexture("GUI/Image/bar_shield"));
	m_bar_dp_current->setSize(size_bar);
	m_bar_dp_current->setPosition(m_bar_dp_max->getPosition());
}

void AttributeManager::updateAttributeManager(float health_point, float mana_point, float shield_point)
{
	m_current_heath += health_point;
	if (m_current_heath > m_base_health) {
		m_current_heath = m_base_health;
	}
	else if (m_current_heath <= 0) {
		m_current_heath = 0;
	}

	m_current_mana += mana_point;
	if (m_current_mana > m_base_mana) {
		m_current_mana = m_base_mana;
	}
	else if (m_current_mana <= 0) {
		m_current_mana = 0;
	}

	m_current_shield += shield_point;
	if (m_current_shield > m_base_shield) {
		m_current_shield = m_base_shield;
	}
	else if (m_current_shield <= 0) {
		m_current_shield = 0;
	}
}

void AttributeManager::renderAttributeManager(RenderWindow* window)
{
	m_bar_hp_current->setSize(Vector2f(40.f, m_bar_hp_max->getSize().y * m_current_heath / m_base_health));
	m_bar_hp_current->setOrigin(m_bar_hp_current->getSize().x/2.f, m_bar_hp_current->getSize().y);

	m_bar_mp_current->setSize(Vector2f(40.f, m_bar_mp_max->getSize().y * m_current_mana / m_base_mana));
	m_bar_mp_current->setOrigin(m_bar_mp_current->getSize().x / 2.f, m_bar_mp_current->getSize().y);
	
	m_bar_dp_current->setSize(Vector2f(40.f, m_bar_dp_max->getSize().y * m_current_shield / m_base_shield));
	m_bar_dp_current->setOrigin(m_bar_dp_current->getSize().x / 2.f, m_bar_dp_current->getSize().y);

	window->draw(*m_bar_hp_bg);
	window->draw(*m_logo_hp);
	window->draw(*m_bar_hp_max);
	window->draw(*m_bar_hp_current);

	window->draw(*m_bar_mp_bg);
	window->draw(*m_logo_mp);
	window->draw(*m_bar_mp_max);
	window->draw(*m_bar_mp_current);

	window->draw(*m_bar_dp_bg);
	window->draw(*m_logo_dp);
	window->draw(*m_bar_dp_max);
	window->draw(*m_bar_dp_current);
}