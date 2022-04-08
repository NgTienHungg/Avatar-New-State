#include "DefendState.h"
#include "StateManager.h"

DefendState::DefendState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

DefendState::~DefendState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float DefendState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void DefendState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/defend", sprite_sheet, frame_count, 0.25f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void DefendState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void DefendState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}