#pragma once
#include "../../GameManager/DataManager.h"

class Layer
{
private:
	Sprite* m_image_1;
	Sprite* m_image_2;
	float m_speed;

public:
	Layer();
	~Layer();

	void initLayer(string name, float speed);
	void updateLayer(float delta_time);
	void renderLayer(RenderWindow* window);
};