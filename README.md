# Bumblebee
Bumblebee is a 2D game engine powered by C++, Box2D, SDL and IMGui and aims to provide a simple interface to create 2D games for the Windows platform.

## Engine Architecture
### GameObject Class
The gameobject should be used to construct all visible gameobjects in the scene. Gameobject is final because unique game objects should be constructed
by adding different components to the game object that provide logic and functionality to set game object.
For objects that don't require rendering or a transform, you can use a SceneObject instead of GameObject.

```cpp
class BaseComponent;

namespace BTEngine
{
	class Texture2D;

	class GameObject final : public SceneObject
	{
	public:
		GameObject();
		~GameObject(); // no virtual because class is final
		GameObject(const GameObject & other) = delete;
		GameObject(GameObject && other) = delete;
		GameObject& operator=(const GameObject & other) = delete;
		GameObject& operator=(GameObject && other) = delete;

		void Update() override;
		void FixedUpdate() override;
		void Render() const override;
		void Initialize() override;
		void OnAttached();
		void OnDetached();
		void SetTag(const std::string& tag);
		const std::string& GetTag() const;

		template <typename T> T* AddComponent();
		template <typename T> T* GetComponent() const;
		template <typename T> void RemoveComponent();

		GameObject* GetParent() const;

		size_t GetAmountOfChildren() const;
		GameObject* GetChildAt(int index);
		void RemoveChild(int index);
		void AddChild(GameObject* gameObject);
		bool HasBeenInitialized() const;

	private:
		std::string m_Tag;
		void SetParent(GameObject* parent);
		GameObject* m_pParent;
		std::vector<BaseComponent*> m_Components;
		std::vector<GameObject*> m_Children;
		bool m_HasBeenInitialized;
	};

// ...
```
### Component System
The engine supports a component system where components inherit from the BaseComponent class.
These components are added to a gameobject to provide logic for rendering, player input or adding animation etc..

### Examples
##### Creating a scene with physics enabled
```cpp
auto& scene = SceneManager::GetInstance().CreateScene("Demo");
auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
AudioSystemLocator::GetAudio().LoadAudioClip(0, "Navi - Hey.mp3", true);

auto physics = std::make_shared<PhysicsManager>();
scene.Add(physics);
```
##### Creating a player game object
```cpp
auto mrPepper = std::make_shared<GameObject>();
mrPepper->SetTag("Peter");
```
###### Adding components
```cpp
auto pepperComp = mrPepper->AddComponent<MrPepperComponent>();
	
auto pepperTransform = mrPepper->AddComponent<TransformComponent>();
pepperTransform->SetSize(50.0f, 50.0f);
pepperTransform->Translate(150.0f, 100.0f);
	
mrPepper->AddComponent<RenderComponent>()->SetTexture("spritesheet.png");
mrPepper->AddComponent<AnimationComponent>();
mrPepper->AddComponent<RigidBodyComponent>();
auto collider = mrPepper->AddComponent<CircleCollider>();
collider->SetRadius(25.0f);
```
###### Mapping Controller Buttons
```cpp
InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Right, std::make_shared<MoveRightCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Left, std::make_shared<MoveLeftCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Up, std::make_shared<MoveUpCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
InputManager::GetInstance().AddButtonMapping(ControllerButton::DPad_Down, std::make_shared<MoveDownCommand>(pepperComp), ButtonBehaviour::Pressed, 0);
InputManager::GetInstance().AddButtonMapping(ControllerButton::ButtonA, std::make_shared<PlaySoundCommand>(), ButtonBehaviour::DownThisFrame);
```
###### Mapping Keyboard Buttons
```cpp
InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::RightArrow, std::make_shared<MoveRightCommand>(pepperComp), ButtonBehaviour::Pressed);
InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::LeftArrow, std::make_shared<MoveLeftCommand>(pepperComp), ButtonBehaviour::Pressed);
InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::UpArrow, std::make_shared<MoveUpCommand>(pepperComp), ButtonBehaviour::Pressed);
InputManager::GetInstance().AddKeyboardMapping(KeyboardButton::DownArrow, std::make_shared<MoveDownCommand>(pepperComp), ButtonBehaviour::Pressed);
```
##### Adding the created object to the scene
```cpp
scene.Add(mrPepper);
```

## Building using CMAKE

Bumblebee supports CMAKE builds for both x86 and x64.

## WIP Features
- Scripting via LUA
- Visual Game Editor
- Unit Tests
