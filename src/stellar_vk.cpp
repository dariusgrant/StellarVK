#include "stellar_vk.hpp"

namespace stellar {
	// Extension Map Definitions
	void* ExtensionMap::get_chain() const {
		return pStart;
	}

	// Instance Definitions
	const uint32_t Instance::Version = vk::enumerateInstanceVersion();
	const std::vector<vk::LayerProperties> Instance::AvailableLayers = vk::enumerateInstanceLayerProperties();
	const std::vector<vk::ExtensionProperties> Instance::AvailableExtensions = vk::enumerateInstanceExtensionProperties();

	Instance::InstanceBuilder::InstanceBuilder() {
		object = std::unique_ptr<Instance>( new Instance() );
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::add_flags( const vk::InstanceCreateFlags& flags_ ) {
		object->flags |= flags_;
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_application_name( const std::string& applicationName_ ) {
		object->applicationName = applicationName_;
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_application_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ ) {
		object->applicationVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_engine_name( const std::string& engineName_ ) {
		object->engineName = engineName_;
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_engine_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ ) {
		object->engineVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_api_version( const uint32_t major_, const uint32_t minor_ ) {
		auto Version = VK_MAKE_VERSION( major_, minor_, 0 );
		if( Version <= VK_API_VERSION_1_0 && Version != 0 ) {
			throw vk::LogicError( "The API Version must be greater than or equal to VK_API_VERSION_1_0." );
		}
		else {
			object->apiVersion = Version;
		}
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_layer( const std::string& layerName_ ) {
		auto haveLayer = std::any_of( AvailableLayers.begin(),
									  AvailableLayers.end(),
									  [layerName_]( vk::LayerProperties l ) { return layerName_ == l.layerName; } );
		if( !haveLayer ) {
			throw vk::LayerNotPresentError( "The instance layer '" + layerName_ + "' is not an available layer." );
		}

		object->enabledLayerNames.push_back( layerName_ );
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_layers( const vk::ArrayProxy<const std::string> layerNames_ ) {
		for( const auto& n : layerNames_ ) {
			include_layer( n );
		}
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_all_available_layers() {
		for( const auto& l : AvailableLayers ) {
			object->enabledLayerNames.push_back( l.layerName );
		}
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_extension( const std::string& extensionName_ ) {
		auto haveExtension = std::any_of( AvailableExtensions.begin(),
										  AvailableExtensions.end(),
										  [extensionName_]( vk::ExtensionProperties e ) { return extensionName_ == e.extensionName; } );
		if( !haveExtension ) {
			throw vk::ExtensionNotPresentError( "The instance extension '" + extensionName_ + "' is not an available extension." );
		}

		object->enabledExtensionNames.push_back( extensionName_ );
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_extensions( const vk::ArrayProxy<const std::string> extensionNames_ ) {
		for( const auto& n : extensionNames_ ) {
			include_extension( n );
		}
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::include_all_available_extensions() {
		for( const auto& e : AvailableExtensions ) {
			object->enabledExtensionNames.push_back( e.extensionName );
		}
		return *this;
	}

	Instance&& Instance::InstanceBuilder::build() {
		std::vector<const char*> layerNames, extensionNames;
		for( const auto& n : object->enabledLayerNames ) {
			layerNames.push_back( n.data() );
		}

		for( const auto& n : object->enabledExtensionNames ) {
			extensionNames.push_back( n.data() );
		}

		vk::ApplicationInfo appInfo;
		appInfo.setPApplicationName( object->applicationName.data() );
		appInfo.setApplicationVersion( object->applicationVersion );
		appInfo.setPEngineName( object->engineName.data() );
		appInfo.setEngineVersion( object->engineVersion );
		appInfo.setApiVersion( object->apiVersion );

		vk::InstanceCreateInfo ci;
		ci.setPNext( object->extensionMap.get_chain() );
		ci.setFlags( object->flags );
		ci.setPApplicationInfo( &appInfo );
		ci.setEnabledLayerCount( layerNames.size() );
		ci.setPEnabledLayerNames( layerNames );
		ci.setEnabledExtensionCount( extensionNames.size() );
		ci.setPEnabledExtensionNames( extensionNames );
		object->object = vk::createInstanceUnique( ci );

		return std::move( *object );
	}

	const bool Instance::layer_exists( const std::string& layerName_ ) const {
		return std::any_of( AvailableLayers.begin(), AvailableLayers.end(), [&]( vk::LayerProperties p ) { return layerName_ == p.layerName; } );
	}

	const std::string& Instance::get_application_name() const {
		return applicationName;
	}

	const uint32_t& Instance::get_application_version() const {
		return applicationVersion;
	}

	const std::string& Instance::get_engine_name() const {
		return engineName;
	}

	const uint32_t& Instance::get_engine_version() const {
		return engineVersion;
	}

	const uint32_t& Instance::get_api_version() const {
		return apiVersion;
	}

	const std::vector<std::string>& Instance::get_enabled_layer_names() const {
		return enabledLayerNames;
	}

	const std::vector<std::string>& Instance::get_enabled_extension_names() const {
		return enabledExtensionNames;
	}

	const bool Instance::extension_exists( const std::string& extensionName_ ) const {
		return std::any_of( AvailableExtensions.begin(), AvailableExtensions.end(), [&]( vk::ExtensionProperties p ) { return extensionName_ == p.extensionName; } );
	}

	// PhysicalDevice Definitions
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