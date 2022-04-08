#pragma once
#include "GSBase.h"

class GSWarningQuit : public GSBase
{
protected:
	Background* m_background;
	RectangleShape* m_frame;
	RectangleShape* m_headline;

	Text* m_message;

	Button* m_button_accept;
	Button* m_button_cancel;

	void initBoard();
	void initButton();
	void initMessage();

public:
	GSWarningQuit();
	~GSWarningQuit();

	GameState getTypeState();
	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};