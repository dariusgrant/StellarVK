#include "../include/stellar_vk.hpp"

namespace stellar {
	void* ExtensionMap::get_chain() const {
		return pStart;
	}

	const uint32_t Instance::version = vk::enumerateInstanceVersion();
	const std::vector<vk::LayerProperties> Instance::availableLayers = vk::enumerateInstanceLayerProperties();
	const std::vector<vk::ExtensionProperties> Instance::availableExtensions = vk::enumerateInstanceExtensionProperties();

	Instance::InstanceCreator::InstanceCreator() {
		object = std::make_unique<Instance>();
	}

	Instance::InstanceCreator& Instance::InstanceCreator::add_flags( const vk::InstanceCreateFlags& flags_ ) {
		object->flags |= flags_;
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::set_application_name( const std::string& applicationName_ ) {
		object->applicationName = applicationName_;
		return *this;

	}

	Instance::InstanceCreator& Instance::InstanceCreator::set_application_version( const uint32_t& major_, const uint32_t& minor_, const uint32_t& patch_ ) {
		object->applicationVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::set_engine_name( const std::string& engineName_ ) {
		object->engineName = engineName_;
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::set_engine_version( const uint32_t& major_, const uint32_t& minor_, const uint32_t& patch_ ) {
		object->engineVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;

	}

	Instance::InstanceCreator& Instance::InstanceCreator::set_api_version( const uint32_t& major_, const uint32_t minor_ ) {
		auto version = VK_MAKE_VERSION( major_, minor_, 0 );
		if( version <= VK_API_VERSION_1_0 && version != 0 ) {
			throw vk::LogicError( "The API version must be greater than or equal to VK_API_VERSION_1_0." );
		}
		else {
			object->apiVersion = version;
		}
		return *this;

	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_layer( const std::string& layerName_ ) {
		auto haveLayer = std::any_of( availableLayers.begin(),
									  availableLayers.end(),
									  [layerName_]( vk::LayerProperties l ) { return layerName_ == l.layerName; } );
		if( !haveLayer ) {
			throw vk::LayerNotPresentError( "The instance layer '" + layerName_ + "' is not an available layer." );
		}

		object->enabledLayerNames.push_back( layerName_ );
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_layers( const vk::ArrayProxy<const std::string> layerNames_ ) {
		for( const auto& n : layerNames_ ) {
			include_layer( n );
		}
		return *this;

	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_all_available_layers() {
		for( const auto& l : availableLayers ) {
			object->enabledLayerNames.push_back( l.layerName );
		}
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_extension( const std::string& extensionName_ ) {
		auto haveExtension = std::any_of( availableExtensions.begin(),
										  availableExtensions.end(),
										  [extensionName_]( vk::ExtensionProperties e ) { return extensionName_ == e.extensionName; } );
		if( !haveExtension ) {
			throw vk::ExtensionNotPresentError( "The instance extension '" + extensionName_ + "' is not an available extension." );
		}

		object->enabledExtensionNames.push_back( extensionName_ );
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_extensions( const vk::ArrayProxy<const std::string> extensionNames_ ) {
		for( const auto& n : extensionNames_ ) {
			include_extension( n );
		}
		return *this;
	}

	Instance::InstanceCreator& Instance::InstanceCreator::include_all_available_extensions() {
		for( const auto& e : availableExtensions ) {
			object->enabledExtensionNames.push_back( e.extensionName );
		}
		return *this;
	}

	Instance&& Instance::InstanceCreator::create() {
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
		return std::any_of( availableLayers.begin(), availableLayers.end(), [&]( vk::LayerProperties p ) { return layerName_ == p.layerName; } );
	}

	const bool Instance::extension_exists( const std::string& extensionName_ ) const  {
		return std::any_of( availableExtensions.begin(), availableExtensions.end(), [&]( vk::ExtensionProperties p ) { return extensionName_ == p.extensionName; } );
	}
}