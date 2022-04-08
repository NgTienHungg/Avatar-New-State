#include "GameStateManager.h"
#include "../GameState/GSBase.h"

GameStateManager::GameStateManager()
{
	m_next_state = nullptr;
}

GameStateManager::~GameStateManager()
{
	for (auto it : m_list_state) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_list_state.clear();

	if (m_next_state != nullptr) {
		delete m_next_state;
	}
}

GSBase* GameStateManager::getCurrentState()
{
	if (m_list_state.empty()) {
		return nullptr;
	}
	return m_list_state.back();
}

GSBase* GameStateManager::getNextState()
{
	return m_next_state;
}

void GameStateManager::changeState(GameState state_type)
{
	GSBase* state = GSBase::createState(state_type);
	this->changeState(state);
}

void GameStateManager::changeState(GSBase* next_state)
{
	m_next_state = next_state;
}

void GameStateManager::pushState()
{
	m_list_state.push_back(m_next_state);
	getCurrentState()->initState();
	m_next_state = nullptr;
}

void GameStateManager::popState()
{
	if (!m_list_state.empty()) {
		m_list_state.pop_back();
	}
}

bool GameStateManager::needToChangeState()
{
	return m_next_state != nullptr;
}

bool GameStateManager::hasState()
{
	return m_list_state.size() > 0;
}