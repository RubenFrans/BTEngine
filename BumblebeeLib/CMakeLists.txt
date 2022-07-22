# BumblebeeLib cmake file

project(BumblebeeLib) 

# configure project soures
add_library(BumblebeeLib
	InputManager.h
	InputManager2.cpp
	InputManager2.h
	InternalStructs.h
	Keyboard.cpp
	Keyboard.h
	Main.cpp
	Minigin.cpp
	Minigin.h
	AchievementSystem.cpp
	AchievementSystem.h
	Animation.cpp
	Animation.h
	AnimationComponent.cpp
	AnimationComponent.h
	AudioClip.cpp
	AudioClip.h
	AudioClipImpl.cpp
	AudioClipImpl.h
	AudioSystem.h
	AudioSystemLocator.cpp
	AudioSystemLocator.h
	BaseComponent.cpp
	BaseComponent.h
	BoxCollider.cpp
	BoxCollider.h
	CacheDataGenerator.cpp
	CacheDataGenerator.h
	CircleCollider.cpp
	CircleCollider.h
	CMakeLists.txt
	ColliderComponent.cpp
	ColliderComponent.h
	CollisionComponent.cpp
	CollisionComponent.h
	Command.cpp
	Command.h
	ContactListener.cpp
	ContactListener.h
	ControllerButtons.h
	DebugSettings.cpp
	DebugSettings.h
	Events.h
	Font.cpp
	Font.h
	FPSComponent.cpp
	FPSComponent.h
	GameObject.cpp
	GameObject.h
	imconfig.h
	ImgGuiRenderComponent.cpp
	ImgGuiRenderComponent.h
	imgui.cpp
	imgui.h
	imgui.ini
	imgui_demo.cpp
	imgui_draw.cpp
	imgui_impl_opengl2.cpp
	imgui_impl_opengl2.h
	imgui_impl_sdl.cpp
	imgui_impl_sdl.h
	imgui_internal.h
	imgui_plot.cpp
	imgui_plot.h
	imgui_tables.cpp
	imgui_widgets.cpp
	ImGuiPlotComponent.cpp
	ImGuiPlotComponent.h
	imstb_rectpack.h
	imstb_textedit.h
	imstb_truetype.h
	InputManager.cpp
	World.cpp
	World.h
	XboxController.cpp
	XboxController.h
	XboxControllerImpl.cpp
	XboxControllerImpl.h
	MiniginPCH.cpp
	MiniginPCH.h
	NullAudioSystem.cpp
	NullAudioSystem.h
	Observer.cpp
	Observer.h
	PhysicsManager.cpp
	PhysicsManager.h
	RenderComponent.cpp
	RenderComponent.h
	Renderer.cpp
	Renderer.h
	ResourceManager.cpp
	ResourceManager.h
	RGBColor.h
	RigidBodyComponent.cpp
	RigidBodyComponent.h
	Scene.cpp
	Scene.h
	SceneManager.cpp
	SceneManager.h
	SceneObject.h
	Singleton.h
	structs.h
	Subject.cpp
	Subject.h
	temp.cpp
	TextComponent.cpp
	TextComponent.h
	TextObject.cpp
	TextObject.h
	Texture2D.cpp
	Texture2D.h
	TimeManager.cpp
	TimeManager.h
	Transform.cpp
	Transform.h
	TransformComponent.cpp
	TransformComponent.h
	WindowsAudioSystem.cpp
	WindowsAudioSystem.h
	WindowsAudioSystemImpl.cpp
	WindowsAudioSystemImpl.h
)

message("BUILDING FOR ${CMAKE_BUILD_TYPE}")

# set language standard
set_property(TARGET BumblebeeLib PROPERTY CXX_STANDARD 17)

# glm
set(glmIncDir ${CMAKE_SOURCE_DIR}/3rdParty/glm)
add_library(glm INTERFACE)
target_include_directories(BumblebeeLib PUBLIC ${glmIncDir})

# SDL2 (SDL2, SDL2_image, SDL2_mixer, SDL2_ttf)
## Support x64 and x86 builds for SDL
message(STATUS "Choosing correct SDL Libraries")
if("${CMAKE_SIZEOF_VOID_P}" MATCHES 8)
	message(STATUS "\tChose x64 libs based on settings")
	set(SDL_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x64/SDL2.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x64/SDL2main.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/SDL2_image.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/SDL2_mixer.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x64/SDL2_ttf.lib;"
	)

	# install x64 dll's'
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x64/SDL2.dll" DESTINATION bin)
	#install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x64/SDL2main.dll" DESTINATION bin)

	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/SDL2_image.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/zlib1.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/libjpeg-9.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/libpng16-16.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/libtiff-5.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x64/libwebp-7.dll" DESTINATION bin)
	
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/SDL2_mixer.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libFLAC-8.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libmodplug-1.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libmpg123-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libogg-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libogg-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libopus-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libopusfile-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libvorbis-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x64/libvorbisfile-3.dll" DESTINATION bin)


	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x64/SDL2_ttf.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x64/libfreetype-6.dll" DESTINATION bin)

else()
	message(STATUS "\tChose x86 libs based on settings")
	set(SDL_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x86/SDL2.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x86/SDL2main.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/SDL2_image.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/SDL2_mixer.lib;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x86/SDL2_ttf.lib;"
	)

	# install x86 dll's'
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x86/SDL2.dll" DESTINATION bin)
	#install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2/lib/x86/SDL2main.dll" DESTINATION bin)
	
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/SDL2_image.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/zlib1.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/libjpeg-9.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/libpng16-16.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/libtiff-5.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/lib/x86/libwebp-7.dll" DESTINATION bin)

	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/SDL2_mixer.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libFLAC-8.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libmodplug-1.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libmpg123-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libogg-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libogg-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libopus-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libopusfile-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libvorbis-0.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/lib/x86/libvorbisfile-3.dll" DESTINATION bin)


	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x86/SDL2_ttf.dll" DESTINATION bin)
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/lib/x86/libfreetype-6.dll" DESTINATION bin)

endif()

set(SDL2_INCLUDE_DIRS
"${CMAKE_SOURCE_DIR}/3rdParty/SDL2/include;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_image/include;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_mixer/include;${CMAKE_SOURCE_DIR}/3rdParty/SDL2_ttf/include")
target_include_directories(BumblebeeLib PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(BumblebeeLib PUBLIC ${SDL_LIBRARIES})

# Box2D

# Support x64 and x86 builds for Box2D
message(STATUS "Choosing correct BOX2D Libraries")
if("${CMAKE_SIZEOF_VOID_P}" MATCHES 8)
	# Support debug and release build of Box2D in x64
	message(STATUS "\tChose x64 libs based on settings")
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		message(STATUS "\tChose debug libs based on settings")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x64/Debug/box2d.lib")
	else()
		message(STATUS "\tChose release libs based on settings")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x64/Release/box2d.lib")
	endif()
else()
	# Support debug and release build of Box2D in x86
		message(STATUS "\tChose x86 libs based on settings")
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		message(STATUS "\tChose debug libs based on settings")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x86/Debug/box2d.lib")
	else()
		message(STATUS "\tChose release libs based on settings")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x86/Release/box2d.lib")
	endif()
endif()

set(BOX2D_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/include")

target_include_directories(BumblebeeLib PUBLIC ${BOX2D_INCLUDE_DIRS})
target_link_libraries(BumblebeeLib PUBLIC ${BOX2D_LIBRARIES})



# IMGUI

# SteamWorks
if("${CMAKE_SIZEOF_VOID_P}" MATCHES 8)
	set(STEAMWORKS_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/steamworks/redistributable_bin/steam_api64.lib"
	)

	# install Steamworks dll
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/steamworks/redistributable_bin/steam_api64.dll" DESTINATION bin)

else()
	set(STEAMWORKS_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/steamworks/redistributable_bin/steam_api.lib"
	)

	# install Steamworks dll
	install(FILES "${CMAKE_SOURCE_DIR}/3rdParty/steamworks/redistributable_bin/steam_api.dll" DESTINATION bin)

endif()

set(STEAMWORKS_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/3rdParty/steamworks/include")

target_include_directories(BumblebeeLib PUBLIC ${STEAMWORKS_INCLUDE_DIRS})
target_link_libraries(BumblebeeLib PUBLIC ${STEAMWORKS_LIBRARIES})


# VLD (Visual Leak Detector)
if("${CMAKE_SIZEOF_VOID_P}" MATCHES 8)
	set(VLD_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/vld/lib/x64/vld.lib"
	)
else()
	set(VLD_LIBRARIES 
	"${CMAKE_SOURCE_DIR}/3rdParty/vld/lib/x86/vld.lib"
	)
endif()

set(VLD_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/3rdParty/vld/include")

target_include_directories(BumblebeeLib PUBLIC ${VLD_INCLUDE_DIRS})
target_link_libraries(BumblebeeLib PUBLIC ${VLD_LIBRARIES})

# OPENGL
find_package(OpenGL)
target_include_directories(BumblebeeLib PUBLIC ${OPENGL_INCLUDE_DIRECTORY})
target_link_libraries( BumblebeeLib PUBLIC OpenGL::GL)

set(BumblebeeLibIncDir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
