#pragma once
#include "Components/BaseComponent.h"
#include "Observer/Subject.h" 

class BurgerComponent :
    public BaseComponent, public Subject
{
public:
	BurgerComponent(BTEngine::GameObject* pOwner);
	virtual ~BurgerComponent() = default;
	virtual void Update() override;
	virtual void FixedUpdate() override;
	virtual void Initialize() override;
	void DropBurger();
private:

};

