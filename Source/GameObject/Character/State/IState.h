#pragma once
#include "../Character.h"
#include "../Animation/Animation.h"

class IState
{
public:
	virtual float getTotalTime() = 0;
	virtual void initState(Vector2i sprite_sheet, int frame_count) = 0;
	virtual void updateState(float delta_time) = 0;
	virtual void renderState(RenderWindow* window) = 0;
};