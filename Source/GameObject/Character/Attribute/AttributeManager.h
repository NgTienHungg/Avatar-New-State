#pragma once
#include "../Character.h"

class AttributeManager
{
private:
	Character* m_character;
	Vector2f m_position;

	float m_base_attack;
	float m_base_health;
	float m_base_mana;
	float m_base_shield;

	float m_current_heath;
	float m_current_mana;
	float m_current_shield;

	RectangleShape* m_bar_hp_bg;
	RectangleShape* m_logo_hp;
	RectangleShape* m_bar_hp_max;
	RectangleShape* m_bar_hp_current;

	RectangleShape* m_bar_mp_bg;
	RectangleShape* m_logo_mp;
	RectangleShape* m_bar_mp_max;
	RectangleShape* m_bar_mp_current;

	RectangleShape* m_bar_dp_bg;
	RectangleShape* m_logo_dp;
	RectangleShape* m_bar_dp_max;
	RectangleShape* m_bar_dp_current;

public:
	AttributeManager(Character* character);
	~AttributeManager();

	void setPosition(Vector2f position);

	float getBaseAttack();
	float getBaseHealth();

	void resetAttribute();
	void resetMana();
	void resetShield();

	bool isPowerful();
	bool isProtected();
	bool isDead();

	void initAttributeManager(float health, float attack);
	void updateAttributeManager(float health_point, float mana_point, float armor_point);
	void renderAttributeManager(RenderWindow* window);
};