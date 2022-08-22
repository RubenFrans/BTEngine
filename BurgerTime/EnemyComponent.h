#pragma once
#include "Components/BaseComponent.h"
#include "Observer/Subject.h"

class EnemyComponent :
    public BaseComponent, public Subject
{
public:
	EnemyComponent(BTEngine::GameObject* pOwner);
	virtual ~EnemyComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	void Die();

private:

};

