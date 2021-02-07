#include "stellar_vk.hpp"

int main() {
	vk::ValidationCheckEXT v = vk::ValidationCheckEXT::eAll;
	stellar::Instance i1 = stellar::Instance::InstanceBuilder()
		.include_layers( { "VK_LAYER_LUNARG_api_dump", "VK_LAYER_KHRONOS_validation" } )
		.include_extensions( { VK_KHR_SURFACE_EXTENSION_NAME, VK_KHR_WIN32_SURFACE_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_EXTENSION_NAME } )
		.set_api_version( 1, 2 )
		.add_next_extension( vk::ValidationFeaturesEXT(),
							 vk::ValidationFlagsEXT()
							 .setDisabledValidationCheckCount( 1 )
							 .setPDisabledValidationChecks( &v ) )
		.build();

	auto physicalDevices = stellar::PhysicalDevice::get_physical_devices( i1 );
	auto p1 = physicalDevices.front()
		.query_features<vk::PhysicalDeviceVulkan11Features, vk::PhysicalDeviceVulkan12Features>()
		.query_properties<vk::PhysicalDeviceVulkan11Properties, vk::PhysicalDeviceVulkan12Properties>();

	return 0;
}