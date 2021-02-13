#include "Instance.hpp"

namespace stellar {
	const uint32_t Instance::Version = vk::enumerateInstanceVersion();
	const std::vector<vk::LayerProperties> Instance::AvailableLayers = vk::enumerateInstanceLayerProperties();
	const std::vector<vk::ExtensionProperties> Instance::AvailableExtensions = vk::enumerateInstanceExtensionProperties();

	Instance::InstanceBuilder::InstanceBuilder() {
		derivedUniqueObject = std::unique_ptr<Instance>( new Instance() );
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_application_name( const std::string& applicationName_ ) {
		derivedUniqueObject->applicationName = applicationName_;
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_application_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ ) {
		derivedUniqueObject->applicationVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_engine_name( const std::string& engineName_ ) {
		derivedUniqueObject->engineName = engineName_;
		return *this;
	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_engine_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ ) {
		derivedUniqueObject->engineVersion = VK_MAKE_VERSION( major_, minor_, patch_ );
		return *this;

	}

	Instance::InstanceBuilder& Instance::InstanceBuilder::set_api_version( const uint32_t major_, const uint32_t minor_ ) {
		auto Version = VK_MAKE_VERSION( major_, minor_, 0 );
		if( Version <= VK_API_VERSION_1_0 && Version != 0 ) {
			throw vk::LogicError( "The API Version must be greater than or equal to VK_API_VERSION_1_0." );
		}
		else {
			derivedUniqueObject->apiVersion = Version;
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

		derivedUniqueObject->enabledLayerNames.push_back( layerName_ );
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
			derivedUniqueObject->enabledLayerNames.push_back( l.layerName );
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

		derivedUniqueObject->enabledExtensionNames.push_back( extensionName_ );
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
			derivedUniqueObject->enabledExtensionNames.push_back( e.extensionName );
		}
		return *this;
	}

	Instance&& Instance::InstanceBuilder::build() {
		std::vector<const char*> layerNames, extensionNames;
		for( const auto& n : derivedUniqueObject->enabledLayerNames ) {
			layerNames.push_back( n.data() );
		}

		for( const auto& n : derivedUniqueObject->enabledExtensionNames ) {
			extensionNames.push_back( n.data() );
		}

		vk::ApplicationInfo appInfo;
		appInfo.setPApplicationName( derivedUniqueObject->applicationName.data() );
		appInfo.setApplicationVersion( derivedUniqueObject->applicationVersion );
		appInfo.setPEngineName( derivedUniqueObject->engineName.data() );
		appInfo.setEngineVersion( derivedUniqueObject->engineVersion );
		appInfo.setApiVersion( derivedUniqueObject->apiVersion );

		vk::InstanceCreateInfo ci;
		ci.setPNext( derivedUniqueObject->extensionMap.get_chain() );
		ci.setFlags( derivedUniqueObject->flags );
		ci.setPApplicationInfo( &appInfo );
		ci.setEnabledLayerCount( layerNames.size() );
		ci.setPEnabledLayerNames( layerNames );
		ci.setEnabledExtensionCount( extensionNames.size() );
		ci.setPEnabledExtensionNames( extensionNames );
		derivedUniqueObject->uniqueObject = vk::createInstanceUnique( ci );

		return std::move( *derivedUniqueObject );
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

}