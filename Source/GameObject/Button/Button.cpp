#include "Button.h"

Button::Button()
{
	m_is_handling = false;
	m_current_time_click = 0.f;
}

Button::~Button()
{
}

bool Button::isHandling()
{
	return m_is_handling;
}

void Button::setFunction(function<void()> function)
{
	m_function = function;
}

void Button::initButton(Vector2f size, string name)
{
	m_size = size;
	this->setSize(m_size);
	this->setOrigin(m_size / 2.f);
	this->setTexture(DATA->getTexture("GUI/Button/" + name));
}

void Button::updateButton(float delta_time)
{
	if (this->getGlobalBounds().contains((Vector2f)Mouse::getPosition(*APP->getWindow()))) {
		this->setSize(m_size * 1.1f);
		this->setOrigin(this->getSize() / 2.f);
	}
	else {
		this->setSize(m_size);
		this->setOrigin(m_size / 2.f);
	}

	if (Mouse::isButtonPressed(Mouse::Left)) {
		m_is_handling = false;
		if (this->getGlobalBounds().contains((Vector2f)Mouse::getPosition(*APP->getWindow()))) {
			m_current_time_click += delta_time;
			if (m_current_time_click >= ClickTime) {
				DATA->playSound("click");
				m_current_time_click = 0.f;
				m_function();
				m_is_handling = true;
			}
		}
		else {
			m_current_time_click = 0.f;
		}
	}
}

void Button::renderButton(RenderWindow* window)
{
	window->draw(*this);
}