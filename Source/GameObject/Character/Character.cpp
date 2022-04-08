#include "Character.h"
#include "State/StateManager.h"
#include "Attribute/AttributeManager.h"

Character::Character()
{
	m_state = new StateManager(this);
	m_attribute = new AttributeManager(this);
	m_position = Vector2f(0.f, 0.f);
}

Character::~Character()
{
	if (m_state != nullptr) {
		delete m_state;
	}
	if (m_attribute != nullptr) {
		delete m_attribute;
	}
}

string Character::getName()
{
	return m_name;
}

void Character::setPosition(Vector2f position)
{
	m_position = position;
}

Vector2f Character::getPosition()
{
	return m_position;
}

StateManager* Character::getStateManager()
{
	return m_state;
}

AttributeManager* Character::getAttributeManager()
{
	return m_attribute;
}

void Character::initCharacter(string name, Vector2f position, Vector2f scale, float health, float attack)
{
	m_name = name;
	m_position = position;
	m_state->initStateManager(scale);
	m_attribute->initAttributeManager(health, attack);
}

void Character::updateCharacter(float deltaTime)
{
	m_state->updateStateManager(deltaTime);
}

void Character::renderCharacter(RenderWindow* window)
{
	m_attribute->renderAttributeManager(window);
	m_state->renderStateManager(window);
}