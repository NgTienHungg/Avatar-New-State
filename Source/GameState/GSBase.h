#pragma once
#include "../GameManager/User.h"
#include "../GameManager/DataManager.h"
#include "../GameManager/GameStateManager.h"
#include "../GameObject/Background/Background.h"
#include "../GameObject/Button/Button.h"
#include "../GameObject/Button/DynamicButton.h"
#include "../GameObject/Text/DynamicText.h"
#include "../GameObject/Match/Match.h"
#include "../GameObject/Character/Character.h"
#include "../GameObject/Character/State/StateManager.h"
#include "../GameObject/Character/Attribute/AttributeManager.h"

class GSBase
{
public:
	// Factory Method - Fatory Pattern
	static GSBase* createState(GameState state_type);

	virtual GameState getTypeState() = 0;

	virtual void initState() = 0;
	virtual void updateState(float delta_time) = 0;
	virtual void renderState(RenderWindow* window) = 0;
};