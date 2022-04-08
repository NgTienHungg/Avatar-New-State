#pragma once
#include "Button.h"
#include <vector>

using namespace std;

class DynamicButton : public Button
{
private:
	vector<Texture*> m_list_texture;
	float m_frame_time;
	float m_current_time;
	int m_current_texture;

public:
	DynamicButton();
	~DynamicButton();

	void initDynamicButton(Vector2f size, string name);
	void updateDynamicButton(float delta_time);
	void renderDynamicButton(RenderWindow* window);
};