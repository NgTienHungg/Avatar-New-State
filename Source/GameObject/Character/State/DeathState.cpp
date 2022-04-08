#include "DeathState.h"
#include "StateManager.h"

DeathState::DeathState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

DeathState::~DeathState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float DeathState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void DeathState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/death", sprite_sheet, frame_count, 0.13f);
	m_animation->setScale(m_character->getStateManager()->getScale());
	m_animation->setPosition(m_character->getPosition());
}

void DeathState::updateState(float deltaTime)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(deltaTime);
}

void DeathState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}