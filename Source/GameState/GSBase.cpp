#include "GSBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSSetting.h"
#include "GSHelp.h"
#include "GSRecord.h"
#include "GSPause.h"
#include "GSEnd.h"
#include "GSProfile.h"
#include "GSWarningQuit.h"
#include "GSWarningHome.h"
#include "GSGetUserInfo.h"
#include "GSSelectMap.h"
#include "GSSelectCharacter.h"

GSBase* GSBase::createState(GameState stateType)
{
	GSBase* state = nullptr;
	switch (stateType)
	{
	case GameState::INVALID:
		break;
	case GameState::INTRO:
		state = new GSIntro();
		break;
	case GameState::MENU:
		state = new GSMenu();
		break;
	case GameState::PLAY:
		state = new GSPlay();
		break;
	case GameState::SETTING:
		state = new GSSetting();
		break;
	case GameState::RECORD:
		state = new GSRecord();
		break;
	case GameState::HELP:
		state = new GSHelp();
		break;
	case GameState::PAUSE:
		state = new GSPause();
		break;
	case GameState::END:
		state = new GSEnd();
		break;
	case GameState::PROFILE:
		state = new GSProfile();
		break;
	case GameState::WARNING_QUIT:
		state = new GSWarningQuit();
		break;
	case GameState::WARNING_HOME:
		state = new GSWarningHome();
		break;
	case GameState::GET_USER_INFO:
		state = new GSGetUserInfo();
		break;
	case GameState::SELECT_MAP:
		state = new GSSelectMap();
		break;
	case GameState::SELECT_CHARACTER:
		state = new GSSelectCharacter();
		break;
	default:
		break;
	}
	return state;
}