#pragma once
#include "../../GameManager/DataManager.h"

class StateManager;
class AttributeManager;

class Character
{
private:
	string m_name;
	Vector2f m_position;
	StateManager* m_state;
	AttributeManager* m_attribute;

public:
	Character();
	~Character();

	string getName();
	StateManager* getStateManager();
	AttributeManager* getAttributeManager();

	void setPosition(Vector2f position);
	Vector2f getPosition();

	void initCharacter(string name, Vector2f position, Vector2f scale, float health, float attack);
	void updateCharacter(float deltaTime);
	void renderCharacter(RenderWindow* window);
};