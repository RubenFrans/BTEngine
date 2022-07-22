# Root directory of the BTEngine project
cmake_minimum_required(VERSION 3.20)
project(BTEngine)

# subproject Game Engine library
add_subdirectory(BTEngineLib)

# subproject Game Engine visual Editor
add_subdirectory(BTEngineVisualEditor)

# subproject unit tests
add_subdirectory(BTEngineUnitTests)

# subproject burgertime
add_subdirectory(BurgerTime)

# Dependencies
add_dependencies(BTEngineVisualEditor BTEngineLib)
add_dependencies(BurgerTime BTEngineLib)

# includes
include(InstallRequiredSystemLibraries)
include(CPack)