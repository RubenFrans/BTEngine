# Build file of the burgertime game project

project(BurgerTime)

add_executable(BurgerTime
	LivesComponent.h
	MrPepperComponent.cpp
	MrPepperComponent.h
	PlatformComponent.cpp
	PlatformComponent.h
	PointsComponent.cpp
	PointsComponent.h
	Sounds.h
	BurgerComponent.cpp
	BurgerComponent.h
	BurgerEngine.cpp
	BurgerEngine.h
	BurgerTime.cpp
	Commands.cpp
	Commands.h
	EnemyComponent.cpp
	EnemyComponent.h
	GameObjectTags.h
	imgui.ini
	IngredientPartComponent.cpp
	IngredientPartComponent.h
	IngridientComponent.cpp
	IngridientComponent.h
	LevelComponent.cpp
	LevelComponent.h
	LivesComponent.cpp
)

target_include_directories(BurgerTime PUBLIC ${BumblebeeLibIncDir})
target_link_libraries(BurgerTime BumblebeeLib)

# install executable
install(TARGETS BurgerTime DESTINATION bin)

# install assets
install(DIRECTORY "${CMAKE_SOURCE_DIR}/Data" DESTINATION bin)