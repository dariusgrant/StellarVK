#include "stellar_vk.hpp"

int main() {
	stellar::Instance i1 = stellar::Instance::InstanceBuilder()
		.include_layers( { "VK_LAYER_LUNARG_api_dump", "VK_LAYER_KHRONOS_validation" } )
		.include_extensions( { VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_EXTENSION_NAME } )
		.set_api_version( 1, 2 )
		.build();
	return 0;
}