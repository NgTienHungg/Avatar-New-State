#pragma once
#include "../../GameManager/Application.h"
#include "../../GameManager/DataManager.h"
#include <functional>

class Button : public RectangleShape
{
private:
	Vector2f m_size;
	function<void()> m_function;
	bool m_is_handling;
	float m_current_time_click;

public:
	Button();
	~Button();

	bool isHandling();
	void setFunction(function<void()> function);

	void initButton(Vector2f size, string name);
	void updateButton(float delta_time);
	void renderButton(RenderWindow* window);
};