#include "DynamicButton.h"

DynamicButton::DynamicButton()
{
	m_current_texture = 0;
	m_current_time = 0.f;
	m_frame_time = 0.13f;
}

DynamicButton::~DynamicButton()
{
	for (Texture* texture : m_list_texture) {
		if (texture != nullptr) {
			delete texture;
		}
	}
	m_list_texture.clear();
}

void DynamicButton::initDynamicButton(Vector2f size, string name)
{
	Button::initButton(size, name + "_green");
	m_list_texture.push_back(DATA->getTexture("GUI/Button/" + name + "_green"));
	m_list_texture.push_back(DATA->getTexture("GUI/Button/" + name + "_purple"));
	m_list_texture.push_back(DATA->getTexture("GUI/Button/" + name + "_gray"));
	m_list_texture.push_back(DATA->getTexture("GUI/Button/" + name + "_blue"));
}

void DynamicButton::updateDynamicButton(float delta_time)
{
	m_current_time += delta_time;
	if (m_current_time >= m_frame_time) {
		m_current_time -= m_frame_time;
		m_current_texture = (m_current_texture + 1) % m_list_texture.size();
		this->setTexture(m_list_texture[m_current_texture]);
	}
	this->updateButton(delta_time);
}

void DynamicButton::renderDynamicButton(RenderWindow* window)
{
	this->renderButton(window);
}