#include "WeakAttackState.h"
#include "StateManager.h"

WeakAttackState::WeakAttackState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

WeakAttackState::~WeakAttackState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float WeakAttackState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void WeakAttackState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/atk_1", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void WeakAttackState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void WeakAttackState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}