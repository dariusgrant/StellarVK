#include "stellar_vk.hpp"
#include <iostream>

int main() {
	stellar::Instance i1 = stellar::Instance::InstanceBuilder()
		.add_flags( vk::InstanceCreateFlagBits() )
		.include_layers( { "VK_LAYER_LUNARG_api_dump", "VK_LAYER_KHRONOS_validation" } )
		.include_extensions( { VK_EXT_DEBUG_UTILS_EXTENSION_NAME } )
		.set_api_version( 1, 2 )
		.build();

	auto physicalDevices = stellar::PhysicalDevice::get_physical_devices( i1 );
	auto p1 = physicalDevices.front()
		.query_features<vk::PhysicalDeviceVulkan11Features, vk::PhysicalDeviceVulkan12Features>()
		.query_properties<vk::PhysicalDeviceVulkan11Properties, vk::PhysicalDeviceVulkan12Properties>();

	return 0;
}
