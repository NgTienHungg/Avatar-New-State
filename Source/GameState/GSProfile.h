#pragma once
#include "GSBase.h"

class GSProfile : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_frame;
	Text* m_title;

	Text* m_name;
	Text* m_level;
	Text* m_coin;

	Button* m_button_back;
	Text* m_text_back;

	RectangleShape* m_link_fb;
	Text* m_text_link_fb;

	RectangleShape* m_link_git;
	Text* m_text_link_git;

	float m_current_time_click;

	void initBoard();
	void initLinkFb();
	void initLinkGit();
	void initUserInfo();
	void initButtonHome();

	void updateLinkFb(float delta_time);
	void updateLinkGit(float delta_time);

public:
	GSProfile();
	~GSProfile();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};