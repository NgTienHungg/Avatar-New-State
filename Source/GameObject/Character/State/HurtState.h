#pragma once
#include "IState.h"

class HurtState : public IState
{
private:
	Character* m_character;
	Animation* m_animation;

public:
	HurtState(Character* character);
	~HurtState();

	float getTotalTime();

	void initState(Vector2i sprite_sheet, int frame_count);
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};