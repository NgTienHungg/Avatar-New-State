#pragma once
#include "../../../GameManager/DataManager.h"

class Animation : public Sprite
{
private:
	Vector2i m_sprite_sheet;
	int m_frame_count;
	float m_frame_time;

	Vector2i m_rect_position;
	Vector2i m_rect_size;
	Vector2i m_current_frame;
	float m_current_time;
	
	void calculateRectSize();
	void changeFrame();
	void updateFrame();

public:
	Animation();
	~Animation();

	float getTotalTime();

	void initAnimation(string name, Vector2i sprite_sheet, int frame_count, float frame_time);
	void updateAnimation(float delta_time);
	void renderAnimation(RenderWindow* window);
};