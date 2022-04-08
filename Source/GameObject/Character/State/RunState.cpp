#include "RunState.h"
#include "StateManager.h"

RunState::RunState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

RunState::~RunState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float RunState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void RunState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/run", sprite_sheet, frame_count, 0.1f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void RunState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void RunState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}