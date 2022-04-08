#pragma once
#include "../../GameManager/DataManager.h"

class DynamicText : public Text
{
private:
	vector<Color> m_list_color;
	int m_index;
	float m_frame_time;
	float m_current_time;

public:
	DynamicText();
	~DynamicText();

	void initDynamicText();
	void updateDynamicText(float delta_time);
	void renderDynamicText(RenderWindow* window);
};