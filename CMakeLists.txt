# CMakeList.txt : CMake project for StellarVk, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("StellarVk")
set(CMAKE_CXX_STANDARD 17)
# Add source to this project's executable.
find_package(Vulkan 1.2 REQUIRED)
if (Vulkan_FOUND)
	include_directories(${Vulkan_INCLUDE_DIR})
	link_libraries(${Vulkan_LIBRARIES})
endif (Vulkan_FOUND)

include_directories("include")
add_library (StellarVk "src/stellar_vk.cpp" "include/stellar_vk.hpp")
add_executable(StellarVkExe "examples/test.cpp")
target_link_libraries(StellarVkExe StellarVk)

# TODO: Add tests and install targets if needed.
