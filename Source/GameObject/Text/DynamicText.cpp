#include "DynamicText.h"

DynamicText::DynamicText()
{
	m_index = 0;
	m_current_time = 0.f;
	m_frame_time = 0.12f;
}

DynamicText::~DynamicText()
{
}

void DynamicText::initDynamicText()
{
	m_list_color.push_back(Color(51, 204, 204));
	m_list_color.push_back(Color(0, 204, 255));
	m_list_color.push_back(Color(0, 153, 255));
	m_list_color.push_back(Color(0, 102, 255));
	m_list_color.push_back(Color(51, 102, 255));
	m_list_color.push_back(Color(102, 102, 255));
	m_list_color.push_back(Color(153, 102, 255));
	m_list_color.push_back(Color(204, 51, 255));
	m_list_color.push_back(Color(255, 0, 255));
	m_list_color.push_back(Color(255, 51, 204));
	m_list_color.push_back(Color(255, 51, 153));
	m_list_color.push_back(Color(255, 0, 102));
	m_list_color.push_back(Color(255, 80, 80));
	m_list_color.push_back(Color(255, 102, 0));
	m_list_color.push_back(Color(255, 153, 51));
	m_list_color.push_back(Color(255, 204, 0));
	m_list_color.push_back(Color(255, 255, 0));
	m_list_color.push_back(Color(204, 255, 51));
	m_list_color.push_back(Color(153, 255, 51));
	m_list_color.push_back(Color(102, 255, 51));
	m_list_color.push_back(Color(51, 204, 51));
	m_list_color.push_back(Color(0, 255, 0));
	m_list_color.push_back(Color(0, 255, 153));
	m_list_color.push_back(Color(0, 255, 204));
	this->setFillColor(m_list_color[0]);
}

void DynamicText::updateDynamicText(float delta_time)
{
	m_current_time += delta_time;
	if (m_current_time >= m_frame_time) {
		m_current_time -= m_frame_time;
		m_index = (m_index + 1) % m_list_color.size();
		this->setFillColor(m_list_color[m_index]);
	}
}

void DynamicText::renderDynamicText(RenderWindow* window)
{
	window->draw(*this);
}