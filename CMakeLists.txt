# Root directory of the BTEngine project
cmake_minimum_required(VERSION 3.20)
project(BumblebeeEngine)

# subproject Game Engine library
add_subdirectory(BumblebeeLib)

# subproject Game Engine visual Editor
add_subdirectory(BumblebeeEditor)

# subproject unit tests
add_subdirectory(BumblebeeUnitTests)

# subproject burgertime
add_subdirectory(BurgerTime)

# Dependencies
add_dependencies(BumblebeeEditor BumblebeeLib)
add_dependencies(BurgerTime BumblebeeLib)

# includes
include(InstallRequiredSystemLibraries)
include(CPack)