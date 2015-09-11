cmake_minimum_required(VERSION 3.3)
project(01Converter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Find the QtWidgets library
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)

set(SOURCE_FILES main.cpp Model/Number.cpp Model/Number.h Presentation/MainWindow.cpp Presentation/MainWindow.h Presentation/Keyboards/Keyboard.cpp Presentation/Keyboards/Keyboard.h Presentation/Labels/Label.cpp Presentation/Labels/Label.h)
add_executable(01Converter ${SOURCE_FILES})

# Use the Widgets module from Qt 5.
target_link_libraries(01Converter Qt5::Core Qt5::Gui Qt5::Widgets)