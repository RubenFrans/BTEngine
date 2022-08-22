
#include "Components\ColliderComponent\CircleCollider\CircleCollider.h"
#include "Rendering/Renderer.h"
#include "b2_fixture.h"
#include "Debug/DebugSettings.h"

CircleCollider::CircleCollider(BTEngine::GameObject* pOwner)
	: ColliderComponent(pOwner), m_Radius{ 1.0f }
{

}

void CircleCollider::Initialize()
{
	ColliderComponent::Initialize();
	// RigidBody initialized by base class
	m_pFixture = m_pRigidBodyComponent->AddFixtureToBody(m_Radius, this);
}

void CircleCollider::Update()
{

}

void CircleCollider::FixedUpdate()
{
}

void CircleCollider::Render() const
{
	if(DebugSettings::DebugDrawingEnabled())
		BTEngine::Renderer::GetInstance().RenderCircle(m_pRigidBodyComponent->GetPosition(), m_Radius);
}

void CircleCollider::SetRadius(float radius)
{
	m_Radius = radius;
}
