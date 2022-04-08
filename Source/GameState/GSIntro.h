#pragma once
#include "GSBase.h"

class GSIntro : public GSBase
{
private:
	RectangleShape* m_logo;
	RectangleShape* m_background;
	RectangleShape* m_shadow;

	float m_logo_time;
	float m_intro_time;
	float m_current_time;

public:
	GSIntro();
	~GSIntro();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};