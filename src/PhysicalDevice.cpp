#include "PhysicalDevice.hpp"

namespace stellar {
	std::vector<vk::PhysicalDevice> PhysicalDevice::PhysicalDevices;

	std::vector<PhysicalDevice> PhysicalDevice::get_physical_devices( const Instance& instance_ ) {
		PhysicalDevices = instance_.get_unique_object()->enumeratePhysicalDevices();

		std::vector<stellar::PhysicalDevice> result;
		result.reserve( PhysicalDevices.size() );
		for( auto& p : PhysicalDevices ) {
			result.push_back( stellar::PhysicalDevice( p ) );
		}

		return result;
	}

	PhysicalDevice::PhysicalDevice( const vk::PhysicalDevice& physicalDevice_ ) : physicalDevice( physicalDevice_ ) {}

	const vk::PhysicalDevice& PhysicalDevice::get() const {
		return physicalDevice;
	}

	const vk::PhysicalDeviceFeatures2& PhysicalDevice::get_features() const {
		return features;
	}

	const vk::PhysicalDeviceProperties2& PhysicalDevice::get_properties() const {
		return properties;
	}

	const vk::PhysicalDeviceMemoryProperties2& PhysicalDevice::get_memory_properties() const {
		return memoryProperties;
	}

	const vk::QueueFamilyProperties2& PhysicalDevice::get_queue_family_properties( const uint32_t queueFamilyIndex_ ) const {
		return queueFamilyProperties[queueFamilyIndex_];
	}

	const int PhysicalDevice::get_memory_type_index( const vk::MemoryRequirements& requirements_, const vk::MemoryPropertyFlags& flags_ ) const {
		auto memProps = memoryProperties.memoryProperties;
		for( uint32_t i = 0; i < memProps.memoryTypeCount; ++i ) {
			if( (requirements_.memoryTypeBits & (1 << i)) &&
				((memProps.memoryTypes[i].propertyFlags & flags_) == flags_) ) {
				return i;
			}
		}

		return -1;
	}

	const std::vector<uint32_t> PhysicalDevice::get_queue_family_indices_of( const vk::QueueFlags& flags_ ) const {
		std::vector<uint32_t> ret;
		for( uint32_t i = 0; i < static_cast<uint32_t>(queueFamilyProperties.size()); i++ ) {
			auto queueFlags = queueFamilyProperties[i].queueFamilyProperties.queueFlags;
			if( queueFlags & flags_ ) {
				ret.push_back( i );
			}
		}

		return ret;
	}
}