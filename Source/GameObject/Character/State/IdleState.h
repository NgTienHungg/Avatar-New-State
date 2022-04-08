#pragma once
#include "IState.h"

class IdleState : public IState
{
private:
	Character* m_character;
	Animation* m_animation;

public:
	IdleState(Character* character);
	~IdleState();

	float getTotalTime();

	void initState(Vector2i sprite_sheet, int frame_count);
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};