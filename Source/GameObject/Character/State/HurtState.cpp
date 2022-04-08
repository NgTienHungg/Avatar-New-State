#include "HurtState.h"
#include "StateManager.h"

HurtState::HurtState(Character* character)
{
	m_character = character;
	m_animation = new Animation();
}

HurtState::~HurtState()
{
	if (m_animation != nullptr) {
		delete m_animation;
	}
}

float HurtState::getTotalTime()
{
	return m_animation->getTotalTime();
}

void HurtState::initState(Vector2i sprite_sheet, int frame_count)
{
	m_animation->initAnimation(m_character->getName() + "/hurt", sprite_sheet, frame_count, 0.3f);
	m_animation->setScale(m_character->getStateManager()->getScale());
}

void HurtState::updateState(float delta_time)
{
	m_animation->setPosition(m_character->getPosition());
	m_animation->updateAnimation(delta_time);
}

void HurtState::renderState(RenderWindow* window)
{
	m_animation->renderAnimation(window);
}