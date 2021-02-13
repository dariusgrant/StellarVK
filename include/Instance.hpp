#pragma once
#include "UniqueObject.hpp"

namespace stellar {
	using UOInstance = UniqueObject<vk::UniqueInstance, vk::Instance, vk::InstanceCreateFlags>;
	class Instance : public UOInstance {
	public:
		class InstanceBuilder : public Builder<InstanceBuilder, Instance> {
		public:
			InstanceBuilder();

			InstanceBuilder& set_application_name( const std::string& applicationName_ );

			InstanceBuilder& set_application_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ );

			InstanceBuilder& set_engine_name( const std::string& engineName_ );

			InstanceBuilder& set_engine_version( const uint32_t major_, const uint32_t minor_, const uint32_t patch_ );

			InstanceBuilder& set_api_version( const uint32_t major_, const uint32_t minor_ );

			InstanceBuilder& include_layer( const std::string& layerName_ );

			InstanceBuilder& include_layers( const vk::ArrayProxy<const std::string> layerNames_ );

			InstanceBuilder& include_all_available_layers();

			InstanceBuilder& include_extension( const std::string& extensionName_ );

			InstanceBuilder& include_extensions( const vk::ArrayProxy<const std::string> extensionNames_ );

			InstanceBuilder& include_all_available_extensions();

			Instance&& build() override;
		};

	public:
		static const uint32_t Version;
		static const std::vector<vk::LayerProperties> AvailableLayers;
		static const std::vector<vk::ExtensionProperties> AvailableExtensions;

	private:
		std::string applicationName;
		uint32_t applicationVersion;
		std::string engineName;
		uint32_t engineVersion;
		uint32_t apiVersion;
		std::vector<std::string> enabledLayerNames;
		std::vector<std::string> enabledExtensionNames;

	public:
		const std::string& get_application_name() const;

		const uint32_t& get_application_version() const;

		const std::string& get_engine_name() const;

		const uint32_t& get_engine_version() const;

		const uint32_t& get_api_version() const;

		const std::vector<std::string>& get_enabled_layer_names() const;

		const std::vector<std::string>& get_enabled_extension_names() const;

		const bool layer_exists( const std::string& layerName_ ) const;

		const bool extension_exists( const std::string& extensionName_ ) const;

	private:
		Instance() = default;
	};
}