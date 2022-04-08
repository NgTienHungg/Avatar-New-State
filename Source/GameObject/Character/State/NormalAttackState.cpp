#include "NormalAttackState.h"
#include "StateManager.h"

NormalAttackState::NormalAttackState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

NormalAttackState::~NormalAttackState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float NormalAttackState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void NormalAttackState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/atk_2", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void NormalAttackState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void NormalAttackState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}