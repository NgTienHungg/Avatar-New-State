#pragma once
#include "GSBase.h"

class GSMenu : public GSBase
{
private:
	Background* m_background;
	Text* m_title;
	Text* m_lemma;

	DynamicButton* m_button_play;
	Button* m_button_setting;
	Button* m_button_record;
	Button* m_button_profile;
	Button* m_button_help;
	Button* m_button_quit;

	void initTitle();
	void initButtonPlay();
	void initButtonSetting();
	void initButtonRecord();
	void initButtonProfile();
	void initButtonHelp();
	void initButtonQuit();

public:
	GSMenu();
	~GSMenu();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};