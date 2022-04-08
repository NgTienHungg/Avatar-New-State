#pragma once
#include "GSBase.h"

class GSPause : public GSBase
{
private:
	Sprite* m_background;
	RectangleShape* m_headline;
	RectangleShape* m_frame;

	Button* m_button_sound;
	Button* m_button_music;

	Button* m_button_resume;
	Text* m_text_resume;

	Button* m_button_home;
	Text* m_text_home;

	void initBoard();
	void initButtonSound();
	void initButtonMusic();
	void initButtonResume();
	void initButtonHome();

	void updateButtonSound(float delta_time);
	void updateButtonMusic(float delta_time);

public:
	GSPause();
	~GSPause();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};