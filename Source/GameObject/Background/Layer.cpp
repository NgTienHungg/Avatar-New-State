#include "Layer.h"

Layer::Layer()
{
	m_image_1 = new Sprite();
	m_image_2 = new Sprite();
	m_speed = 0.f;
}

Layer::~Layer()
{
	if (m_image_1 != nullptr) {
		delete m_image_1;
	}
	if (m_image_2 != nullptr) {
		delete m_image_2;
	}
}

void Layer::initLayer(string name, float speed)
{
	m_speed = speed;
	Texture* texture = DATA->getTexture("Background/" + name);

	m_image_1->setTexture(*texture);
	m_image_1->setScale(0.75f, 0.75f);
	m_image_1->setOrigin((Vector2f)texture->getSize() / 2.f);
	m_image_1->setPosition(0, ScreenHeight / 2);

	m_image_2->setTexture(*texture);
	m_image_2->setScale(0.75f, 0.75f);
	m_image_2->setOrigin((Vector2f)texture->getSize() / 2.f);
	m_image_2->setPosition(ScreenWidth, ScreenHeight / 2);
}

void Layer::updateLayer(float delta_time)
{
	m_image_1->move(-m_speed * delta_time, 0);
	m_image_2->move(-m_speed * delta_time, 0);
	if (m_image_2->getPosition().x <= ScreenWidth / 2) {
		m_image_1->setPosition(m_image_1->getPosition().x + ScreenWidth, ScreenHeight / 2);
		m_image_2->setPosition(m_image_2->getPosition().x + ScreenWidth, ScreenHeight / 2);
	}
}

void Layer::renderLayer(RenderWindow* window)
{
	window->draw(*m_image_1);
	window->draw(*m_image_2);
}
