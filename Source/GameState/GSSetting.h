#pragma once
#include "GSBase.h"

class GSSetting : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_frame;

	Button* m_button_sound;
	Text* m_text_sound;

	Button* m_button_music;
	Text* m_text_music;

	Button* m_button_back;
	Text* m_text_back;

	void initBoard();
	void initButtonSound();
	void initButtonMusic();
	void initButtonHome();

	void updateButtonSound(float delta_time);
	void updateButtonMusic(float delta_time);

public:
	GSSetting();
	~GSSetting();

	GameState getTypeState();
	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};