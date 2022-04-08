#include "Animation.h"

Animation::Animation()
{
	m_frame_count = 0;
	m_frame_time = 0.f;
	m_current_time = 0.f;
	m_current_frame = Vector2i(0, 0);
}

Animation::~Animation()
{
}

void Animation::calculateRectSize()
{
	m_rect_size.x = getTexture()->getSize().x / m_sprite_sheet.x;
	m_rect_size.y = getTexture()->getSize().y / m_sprite_sheet.y;
	this->setOrigin(m_rect_size.x * 0.5f, m_rect_size.y * 1.f);
}

void Animation::changeFrame()
{
	m_current_frame.x++;
	if (m_current_frame.x == m_sprite_sheet.x) {
		m_current_frame.x = 0;
		m_current_frame.y++;
	}
	if (m_current_frame.y * m_sprite_sheet.x + m_current_frame.x == m_frame_count) {
		m_current_frame = Vector2i(0, 0);
	}
}

void Animation::updateFrame()
{
	m_rect_position.x = m_current_frame.x * m_rect_size.x;
	m_rect_position.y = m_current_frame.y * m_rect_size.y;
	this->setTextureRect(IntRect(m_rect_position, m_rect_size));
}

float Animation::getTotalTime()
{
	return m_frame_time * m_frame_count;
}

void Animation::initAnimation(string name, Vector2i sprite_sheet, int frame_count, float frame_time)
{
	this->setTexture(*DATA->getTexture(name));
	m_sprite_sheet = sprite_sheet;
	m_frame_count = frame_count;
	m_frame_time = frame_time;
	this->calculateRectSize();
	this->updateFrame();
}

void Animation::updateAnimation(float delta_time)
{
	m_current_time += delta_time;
	if (m_current_time >= m_frame_time) {
		m_current_time -= m_frame_time;
		this->changeFrame();
		this->updateFrame();
	}
}

void Animation::renderAnimation(RenderWindow* window)
{
	window->draw(*this);
}