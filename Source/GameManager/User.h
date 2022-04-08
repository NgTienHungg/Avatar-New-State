#pragma once
#include "Singleton.h"
#include "../GameObject/Character/Animation/Animation.h"
#include "../GameObject/Character/Character.h"

#define USER User::getInstance()

class User : public Singleton<User>
{
private:
	string m_user_name;
	int m_level;
	int m_coin;

	Character* m_character_fire;
	Character* m_character_water;
	Character* m_character_wind;
	Character* m_character_ground;

	int m_type_character;

public:
	User();
	~User();

	void initUser(string name, int level, int coin);

	string getName();

	void setCharacter(int type);
	Character* getCharacter();

	int getLevel();
	void setLevel(int level);

	int getCoin();
	void setCoin(int coin);
};