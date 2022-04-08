#include "User.h"
#include "../GameObject/Character/Attribute/AttributeManager.h"

User::User()
{
	m_level = 1;
	m_coin = 0;

	m_type_character = 3;
	m_character_fire = new Character();
	m_character_water = new Character();
	m_character_wind = new Character();
	m_character_ground = new Character();

	m_user_name = "Ng Tien Hung";
}

User::~User()
{
	if (m_character_fire != nullptr) {
		delete m_character_fire;
	}
	if (m_character_water != nullptr) {
		delete m_character_water;
	}
	if (m_character_wind != nullptr) {
		delete m_character_wind;
	}
	if (m_character_ground != nullptr) {
		delete m_character_ground;
	}
}

void User::initUser(string name, int level, int coin)
{
	m_user_name = name;
	m_level = level;
	m_coin = coin;

	m_character_fire->getAttributeManager()->setPosition(Vector2f(160.f, 150.f));
	m_character_water->getAttributeManager()->setPosition(Vector2f(160.f, 150.f));
	m_character_wind->getAttributeManager()->setPosition(Vector2f(160.f, 150.f));
	m_character_ground->getAttributeManager()->setPosition(Vector2f(160.f, 150.f));

	float health = 1000.f, attack = 80.f;
	m_character_fire->initCharacter("FireKnight", PlayerPosition, Vector2f(3.2f, 3.2f), health, attack);
	m_character_water->initCharacter("WaterPriestess", PlayerPosition, Vector2f(3.4f, 3.4f), health, attack);
	m_character_wind->initCharacter("WindHashashin", PlayerPosition, Vector2f(3.5f, 3.5f), health, attack);
	m_character_ground->initCharacter("GroundMonk", PlayerPosition, Vector2f(3.8f, 3.8f), health, attack);
}

Character* User::getCharacter()
{
	Character* character = nullptr;
	switch (m_type_character)
	{
	case 1:
		character = m_character_fire;
		break;
	case 2:
		character = m_character_water;
		break;
	case 3:
		character = m_character_wind;
		break;
	case 4:
		character = m_character_ground;
		break;
	}
	return character;
}

void User::setCharacter(int type)
{
	m_type_character = type;
}

string User::getName()
{
	return m_user_name;
}

int User::getLevel()
{
	return m_level;
}

void User::setLevel(int level)
{
	m_level = level;
}

int User::getCoin()
{
	return m_coin;
}

void User::setCoin(int coin)
{
	m_coin = coin;
	if (m_coin < 0) m_coin = 0;
}