#include "IngredientPartComponent.h"
#include "MrPepperComponent.h"
#include <string>
#include "Components/TransformComponent/TransformComponent.h"
#include "Components/ColliderComponent/BoxCollider/BoxCollider.h"
#include "GameObject/GameObject.h"

IngredientPartComponent::IngredientPartComponent(BTEngine::GameObject* pOwner)
	: BaseComponent(pOwner)
	, m_SteppedOver{ false }
	, m_SteppedOnPosOffset{ 0.0f, 10.0f }
	, m_TriggerCallback{}
	, m_pTransformComponent{ nullptr }
{

}

void IngredientPartComponent::Initialize()
{
	m_pTransformComponent = GetGameObject()->GetComponent<TransformComponent>();
	InitializeCollisions();
}

void IngredientPartComponent::InitializeCollisions() {

	BoxCollider* colliderComponent = GetGameObject()->GetComponent<BoxCollider>();

	assert(colliderComponent != nullptr);

	colliderComponent->SetCollisionCallback([&](BTEngine::GameObject* pOtherObject, TriggerAction action) {
		
			OnTriggerCallback(pOtherObject, action);

		});
	
}

void IngredientPartComponent::OnTriggerCallback(BTEngine::GameObject* pOtherObject, TriggerAction action) {

	// Only execute when not yet stepped over
	if (m_SteppedOver)
		return;

	if (pOtherObject && pOtherObject->GetTag().compare("Peter") == 0) {

		if (action == TriggerAction::Enter) {
			
			m_pTransformComponent->Translate(m_SteppedOnPosOffset.x, m_SteppedOnPosOffset.y);

			m_SteppedOver = true;
			
		}
	}
}

void IngredientPartComponent::Update()
{

}

void IngredientPartComponent::FixedUpdate()
{

}

bool IngredientPartComponent::IsSteppedOn() {

	return m_SteppedOver;
}
