#include "StrongAttackState.h"
#include "StateManager.h"

StrongAttackState::StrongAttackState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

StrongAttackState::~StrongAttackState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float StrongAttackState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void StrongAttackState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/atk_3", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void StrongAttackState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void StrongAttackState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}