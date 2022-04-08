#pragma once
#include "GSBase.h"

class GSGetUserInfo : public GSBase
{
private:
	Background* m_background;
	RectangleShape* m_board;
	Text* m_headline;
	Text* m_rule;
	DynamicText* m_remind;
	Text* m_name_display;

	string m_name_enter;
	char m_char_enter;
	bool m_is_typing;

	void loadUserInfo();

	void initBoard();
	void initText();

	void updateEnterText();
	void updateUserName();

public:
	GSGetUserInfo();
	~GSGetUserInfo();

	GameState getTypeState();

	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};