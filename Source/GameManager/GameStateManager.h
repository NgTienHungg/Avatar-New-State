#pragma once
#include "Singleton.h"
#include "DataManager.h"

#define GAMESTATE GameStateManager::getInstance()

class GSBase;

enum class GameState
{
	INVALID,
	INTRO,
	MENU,
	PLAY,
	SETTING,
	RECORD,
	HELP,
	PAUSE,
	END,
	PROFILE,
	GET_USER_INFO,
	SELECT_MAP,
	SELECT_CHARACTER,
	WARNING_HOME,
	WARNING_QUIT,
};

class GameStateManager : public Singleton<GameStateManager>
{
private:
	list<GSBase*> m_list_state;
	GSBase* m_next_state;

public:
	GameStateManager();
	~GameStateManager();

	GSBase* getCurrentState();
	GSBase* getNextState();

	void changeState(GameState state_type);
	void changeState(GSBase* next_state);
	void pushState();
	void popState();

	bool needToChangeState();
	bool hasState();
};