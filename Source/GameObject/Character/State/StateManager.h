#pragma once
#include "IState.h"
#include "IdleState.h"
#include "RunState.h"
#include "WeakAttackState.h"
#include "NormalAttackState.h"
#include "StrongAttackState.h"
#include "UltimateAttackState.h"
#include "DefendState.h"
#include "HurtState.h"
#include "DeathState.h"

enum class CharacterState
{
	// Đúng theo thứ tự đọc file data vào
	IDLE,
	RUN,
	ATK_WEAK,
	ATK_NORMAL,
	ATK_STRONG,
	ATK_ULTIMATE,
	DEFEND,
	HURT,
	DEATH,
};

class StateManager
{
private:
	Character* m_character;
	IState* m_current_state;

	IState* m_idle_state;
	IState* m_run_state;
	IState* m_weak_attack_state;
	IState* m_normal_attack_state;
	IState* m_strong_attack_state;
	IState* m_ultimate_attack_state;
	IState* m_defend_state;
	IState* m_hurt_state;
	IState* m_death_state;

	Vector2f m_scale;

public:
	StateManager(Character* character);
	~StateManager();

	void changeState(CharacterState type);
	IState* getCurrentState();
	Vector2f getScale();

	void initStateManager(Vector2f scale);
	void updateStateManager(float delta_time);
	void renderStateManager(RenderWindow* window);
};