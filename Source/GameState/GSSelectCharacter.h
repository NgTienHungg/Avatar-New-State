#pragma once
#include "GSBase.h"

class GSSelectCharacter : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_frame;
	Text* m_headline;
	Text* m_character_name;

	RectangleShape* m_select_fire;
	RectangleShape* m_select_water;
	RectangleShape* m_select_wind;
	RectangleShape* m_select_ground;

	Animation* m_idle_fire;
	Animation* m_idle_water;
	Animation* m_idle_wind;
	Animation* m_idle_ground;

	Animation* m_atk_fire;
	Animation* m_atk_water;
	Animation* m_atk_wind;
	Animation* m_atk_ground;

	Button* m_button_play;
	Button* m_button_cancel;

	Vector2f m_mouse_position;
	float m_current_time_click;
	int m_selection;

	void initBoard();
	void initAnimationFire();
	void initAnimationWater();
	void initAnimationWind();
	void initAnimationGround();
	void initButton();

	void updateCharacterName();
	void updateButtonPlay(float delta_time);

	void updateView(int type, RectangleShape* select, Animation* idle, Animation* atk, float delta_time);
	void renderView(int type, RectangleShape* select, Animation* idle, Animation* atk, RenderWindow* window);

public:
	GSSelectCharacter();
	~GSSelectCharacter();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};