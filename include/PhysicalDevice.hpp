#pragma once
#include <vulkan/vulkan.hpp>
#include "Instance.hpp"

namespace stellar {
	class PhysicalDevice {
	private:
		static std::vector<vk::PhysicalDevice> PhysicalDevices;

		const vk::PhysicalDevice& physicalDevice;
		vk::PhysicalDeviceFeatures2 features;
		vk::PhysicalDeviceProperties2 properties;
		vk::PhysicalDeviceMemoryProperties2 memoryProperties;
		std::vector<vk::QueueFamilyProperties2> queueFamilyProperties;

		ExtensionMap featureExtensions;
		ExtensionMap propertyExtensions;
		ExtensionMap memoryPropertyExtensions;
		std::vector<ExtensionMap> queueFamilyPropertyExtensions;


	public:
		static std::vector<stellar::PhysicalDevice> get_physical_devices( const stellar::Instance& instance_ );

		const vk::PhysicalDevice& get() const;

		const vk::PhysicalDeviceFeatures2& get_features() const;

		const vk::PhysicalDeviceProperties2& get_properties() const;

		const vk::PhysicalDeviceMemoryProperties2& get_memory_properties() const;

		const vk::QueueFamilyProperties2& get_queue_family_properties( const uint32_t queueFamilyIndex_ ) const;

		const int get_memory_type_index( const vk::MemoryRequirements& requirements_, const vk::MemoryPropertyFlags& flags_ ) const;

		const std::vector<uint32_t> get_queue_family_indices_of( const vk::QueueFlags& flags_ ) const;

		template <typename... Extensions>
		PhysicalDevice& query_features() {
			featureExtensions.add( Extensions()... );
			features.pNext = featureExtensions.get_chain();
			physicalDevice.getFeatures2( &features );
			return *this;
		}

		template <typename... Extensions>
		PhysicalDevice& query_properties() {
			propertyExtensions.add( Extensions()... );
			properties.pNext = propertyExtensions.get_chain();
			physicalDevice.getProperties2( &properties );
			return *this;
		}

		template <typename... Extensions>
		PhysicalDevice& query_memory_properties() {
			memoryPropertyExtensions.add( Extensions()... );
			memoryProperties.pNext = memoryPropertyExtensions.get_chain();
			physicalDevice.getMemoryProperties2( &memoryProperties );
			return *this;
		}

		template <typename... Extensions>
		PhysicalDevice& query_queue_family_properties( const uint32_t queueFamilyIndex_ ) {
			queueFamilyPropertyExtensions[queueFamilyIndex_].add( Extensions()... );
			queueFamilyProperties[queueFamilyIndex_].pNext = queueFamilyPropertyExtensions[queueFamilyIndex_].get_chain();
			physicalDevice.getQueueFamilyProperties2( &queueFamilyProperties );
			return *this;
		}

		template <typename... Extensions>
		PhysicalDevice& query_queue_family_properties( const vk::ArrayProxy<uint32_t>& queueFamilyIndices_ ) {
			for( auto& i : queueFamilyIndices_ ) {
				query_queue_family_properties<Extensions...>( i );
			}
			return *this;
		}

		template <typename Extension>
		const Extension* get_feature_extension() const {
			return featureExtensions.get<Extension>();
		}

		template <typename Extension>
		const Extension* get_property_extension() const {
			return propertyExtensions.get<Extension>();
		}

		template <typename Extension>
		const Extension* get_memory_property_extension() const {
			return memoryPropertyExtensions.get<Extension>();
		}

		template <typename Extension>
		const Extension* get_queue_family_property_extension( const uint32_t queueFamilyIndex_ ) const {
			return queueFamilyPropertyExtensions[queueFamilyIndex_].get<Extension>();
		}

	private:
		PhysicalDevice( const vk::PhysicalDevice& physicalDevice_ );
	};
}
