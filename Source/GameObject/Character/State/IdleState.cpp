#include "IdleState.h"
#include "StateManager.h"

IdleState::IdleState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

IdleState::~IdleState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float IdleState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void IdleState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/idle", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void IdleState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void IdleState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}