# BumblebeeLib cmake file

project(BumblebeeLib) 

# configure project soures
add_library(BumblebeeLib
	Main.cpp
	Minigin.cpp
	Minigin.h
	MiniginPCH.cpp
	MiniginPCH.h
	AudioSystem/AudioClip.cpp
	AudioSystem/AudioClip.h
	AudioSystem/AudioClipImpl.cpp
	AudioSystem/AudioClipImpl.h
	AudioSystem/AudioSystem.h
	AudioSystem/NullAudioSystem/NullAudioSystem.cpp
	AudioSystem/NullAudioSystem/NullAudioSystem.h
	AudioSystem/WindowsAudioSystem/WindowsAudioSystem.cpp
	AudioSystem/WindowsAudioSystem/WindowsAudioSystem.h
	AudioSystem/WindowsAudioSystem/WindowsAudioSystemImpl.cpp
	AudioSystem/WindowsAudioSystem/WindowsAudioSystemImpl.h
	Components/AchievementComponent/AchievementSystem.cpp
	Components/AchievementComponent/AchievementSystem.h
	Components/AnimationComponent/Animation/Animation.cpp
	Components/AnimationComponent/Animation/Animation.h
	Components/AnimationComponent/AnimationComponent.cpp
	Components/AnimationComponent/AnimationComponent.h
	Components/ColliderComponent/ColliderComponent.cpp
	Components/ColliderComponent/ColliderComponent.h
	Components/ColliderComponent/BoxCollider/BoxCollider.cpp
	Components/ColliderComponent/BoxCollider/BoxCollider.h
	Components/ColliderComponent/CircleCollider/CircleCollider.cpp
	Components/ColliderComponent/CircleCollider/CircleCollider.h
	Components/CollisionComponent/CollisionComponent.cpp
	Components/CollisionComponent/CollisionComponent.h
	Components/FPSComponent/FPSComponent.cpp
	Components/FPSComponent/FPSComponent.h
	Components/ImguiRenderComponent/ImgGuiRenderComponent.cpp
	Components/ImguiRenderComponent/ImgGuiRenderComponent.h
	Components/ImguiRenderComponent/ImguiPlotComponent/ImGuiPlotComponent.cpp
	Components/ImguiRenderComponent/ImguiPlotComponent/ImGuiPlotComponent.h
	Components/RenderComponent/RenderComponent.cpp
	Components/RenderComponent/RenderComponent.h
	Components/RigidBodyComponent/RigidBodyComponent.cpp
	Components/RigidBodyComponent/RigidBodyComponent.h
	Components/TextComponent/Font.cpp
	Components/TextComponent/Font.h
	Components/TextComponent/RGBColor.h
	Components/TextComponent/TextComponent.cpp
	Components/TextComponent/TextComponent.h
	Components/TransformComponent/Transform.cpp
	Components/TransformComponent/Transform.h
	Components/TransformComponent/TransformComponent.cpp
	Components/TransformComponent/TransformComponent.h
	Components/BaseComponent.cpp
	Components/BaseComponent.h
	Debug/DebugSettings.cpp
	Debug/DebugSettings.h
	Deprecated/CacheDataGenerator.cpp
	Deprecated/CacheDataGenerator.h
	Deprecated/InputManager.h
	Deprecated/InputManager.cpp
	Deprecated/TextObject.cpp
	Deprecated/TextObject.h
	GameObject/GameObject.cpp
	GameObject/GameObject.h
	Imgui/imconfig.h
	Imgui/imgui.cpp
	Imgui/imgui.h
	Imgui/imgui.ini
	Imgui/imgui_demo.cpp
	Imgui/imgui_draw.cpp
	Imgui/imgui_impl_opengl2.cpp
	Imgui/imgui_impl_opengl2.h
	Imgui/imgui_impl_sdl.cpp
	Imgui/imgui_impl_sdl.h
	Imgui/imgui_internal.h
	Imgui/imgui_plot.cpp
	Imgui/imgui_plot.h
	Imgui/imgui_tables.cpp
	Imgui/imgui_widgets.cpp
	Imgui/imstb_rectpack.h
	Imgui/imstb_textedit.h
	Imgui/imstb_truetype.h
	Input/Commands/Command.cpp
	Input/Commands/Command.h
	Input/Controllers/XboxController.cpp
	Input/Controllers/XboxController.h
	Input/Controllers/XboxControllerImpl.cpp
	Input/Controllers/XboxControllerImpl.h
	Input/Controllers/ControllerButtons.h
	Input/InputManager2.cpp
	Input/InputManager2.h
	Input/Keyboards/Keyboard.cpp
	Input/Keyboards/Keyboard.h
	Observer/Events.h
	Observer/Observer.cpp
	Observer/Observer.h
	Observer/Subject.cpp
	Observer/Subject.h
	Physics/ContactListener/ContactListener.cpp
	Physics/ContactListener/ContactListener.h
	Physics/World/World.cpp
	Physics/World/World.h
	Physics/PhysicsManager.cpp
	Physics/PhysicsManager.h
	Rendering/Renderer.cpp
	Rendering/Renderer.h
	Rendering/Texture2D.cpp
	Rendering/Texture2D.h
	ResourceManager/ResourceManager.cpp
	ResourceManager/ResourceManager.h
	Scene/Scene.cpp
	Scene/Scene.h
	Scene/SceneManager.cpp
	Scene/SceneManager.h
	Scene/SceneObject.h
	Services/AudioService/AudioSystemLocator.cpp
	Services/AudioService/AudioSystemLocator.h
	Structs/InternalStructs.h
	Structs/structs.h
	Time/TimeManager.cpp
	Time/TimeManager.h
	Singleton.h
	temp.cpp
	#CMakeLists.txt
)

target_precompile_headers(BumblebeeLib PRIVATE MiniginPCH.cpp)
target_include_directories(BumblebeeLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}	)

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
	message(STATUS "\tChose x64 libs based on Build target")
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
	message(STATUS "\tChose x86 libs based on Build target")
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
	message(STATUS "\tChose x64 libs based on Build target")
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		message(STATUS "\tChose debug libs based on Build target")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x64/Debug/box2d.lib")
	else()
		message(STATUS "\tChose release libs based on Build target")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x64/Release/box2d.lib")
	endif()
else()
	# Support debug and release build of Box2D in x86
		message(STATUS "\tChose x86 libs based on Build target")
	if(CMAKE_BUILD_TYPE MATCHES Debug)
		message(STATUS "\tChose debug libs based on Build target")
		set(BOX2D_LIBRARIES "${CMAKE_SOURCE_DIR}/3rdParty/Box2D/x86/Debug/box2d.lib")
	else()
		message(STATUS "\tChose release libs based on Build target")
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
