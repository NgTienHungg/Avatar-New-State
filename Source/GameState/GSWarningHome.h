#pragma once
#include "GSWarningQuit.h"

class GSWarningHome : public GSBase
{
private:
	Sprite* m_background;
	RectangleShape* m_frame;
	RectangleShape* m_headline;

	Button* m_button_accept;
	Button* m_button_cancel;
	
	Text* m_message;

	void initBoard();
	void initButton();
	void initMessage();

public:
	GSWarningHome();
	~GSWarningHome();

	GameState getTypeState();
	void initState();
	void updateState(float delta_time);
	void renderState(RenderWindow* window);
};