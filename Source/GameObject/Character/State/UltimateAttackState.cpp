#include "UltimateAttackState.h"
#include "StateManager.h"

UltimateAttackState::UltimateAttackState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

UltimateAttackState::~UltimateAttackState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float UltimateAttackState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void UltimateAttackState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/atk_sp", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void UltimateAttackState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void UltimateAttackState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}