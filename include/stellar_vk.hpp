#pragma once
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.hpp>
#include <fstream>
#include <map>
#include <any>
#include <optional>
#include <typeindex>

namespace stellar {
	namespace utility {
		constexpr uint32_t get_format_channel_count( vk::Format format ) {
			switch( format ) {
				case vk::Format::eUndefined:
					return 0;
				case vk::Format::eR4G4UnormPack8:
					return 2;
				case vk::Format::eR4G4B4A4UnormPack16:
					return 4;
				case vk::Format::eB4G4R4A4UnormPack16:
					return 4;
				case vk::Format::eR5G6B5UnormPack16:
					return 3;
				case vk::Format::eB5G6R5UnormPack16:
					return 3;
				case vk::Format::eR5G5B5A1UnormPack16:
					return 4;
				case vk::Format::eB5G5R5A1UnormPack16:
					return 4;
				case vk::Format::eA1R5G5B5UnormPack16:
					return 4;
				case vk::Format::eR8Unorm:
					return 1;
				case vk::Format::eR8Snorm:
					return 1;
				case vk::Format::eR8Uscaled:
					return 1;
				case vk::Format::eR8Sscaled:
					return 1;
				case vk::Format::eR8Uint:
					return 1;
				case vk::Format::eR8Sint:
					return 1;
				case vk::Format::eR8Srgb:
					return 1;
				case vk::Format::eR8G8Unorm:
					return 2;
				case vk::Format::eR8G8Snorm:
					return 2;
				case vk::Format::eR8G8Uscaled:
					return 2;
				case vk::Format::eR8G8Sscaled:
					return 2;
				case vk::Format::eR8G8Uint:
					return 2;
				case vk::Format::eR8G8Sint:
					return 2;
				case vk::Format::eR8G8Srgb:
					return 2;
				case vk::Format::eR8G8B8Unorm:
					return 3;
				case vk::Format::eR8G8B8Snorm:
					return 3;
				case vk::Format::eR8G8B8Uscaled:
					return 3;
				case vk::Format::eR8G8B8Sscaled:
					return 3;
				case vk::Format::eR8G8B8Uint:
					return 3;
				case vk::Format::eR8G8B8Sint:
					return 3;
				case vk::Format::eR8G8B8Srgb:
					return 3;
				case vk::Format::eB8G8R8Unorm:
					return 3;
				case vk::Format::eB8G8R8Snorm:
					return 3;
				case vk::Format::eB8G8R8Uscaled:
					return 3;
				case vk::Format::eB8G8R8Sscaled:
					return 3;
				case vk::Format::eB8G8R8Uint:
					return 3;
				case vk::Format::eB8G8R8Sint:
					return 3;
				case vk::Format::eB8G8R8Srgb:
					return 3;
				case vk::Format::eR8G8B8A8Unorm:
					return 4;
				case vk::Format::eR8G8B8A8Snorm:
					return 4;
				case vk::Format::eR8G8B8A8Uscaled:
					return 4;
				case vk::Format::eR8G8B8A8Sscaled:
					return 4;
				case vk::Format::eR8G8B8A8Uint:
					return 4;
				case vk::Format::eR8G8B8A8Sint:
					return 4;
				case vk::Format::eR8G8B8A8Srgb:
					return 4;
				case vk::Format::eB8G8R8A8Unorm:
					return 4;
				case vk::Format::eB8G8R8A8Snorm:
					return 4;
				case vk::Format::eB8G8R8A8Uscaled:
					return 4;
				case vk::Format::eB8G8R8A8Sscaled:
					return 4;
				case vk::Format::eB8G8R8A8Uint:
					return 4;
				case vk::Format::eB8G8R8A8Sint:
					return 4;
				case vk::Format::eB8G8R8A8Srgb:
					return 4;
				case vk::Format::eA8B8G8R8UnormPack32:
					return 4;
				case vk::Format::eA8B8G8R8SnormPack32:
					return 4;
				case vk::Format::eA8B8G8R8UscaledPack32:
					return 4;
				case vk::Format::eA8B8G8R8SscaledPack32:
					return 4;
				case vk::Format::eA8B8G8R8UintPack32:
					return 4;
				case vk::Format::eA8B8G8R8SintPack32:
					return 4;
				case vk::Format::eA8B8G8R8SrgbPack32:
					return 4;
				case vk::Format::eA2R10G10B10UnormPack32:
					return 4;
				case vk::Format::eA2R10G10B10SnormPack32:
					return 4;
				case vk::Format::eA2R10G10B10UscaledPack32:
					return 4;
				case vk::Format::eA2R10G10B10SscaledPack32:
					return 4;
				case vk::Format::eA2R10G10B10UintPack32:
					return 4;
				case vk::Format::eA2R10G10B10SintPack32:
					return 4;
				case vk::Format::eA2B10G10R10UnormPack32:
					return 4;
				case vk::Format::eA2B10G10R10SnormPack32:
					return 4;
				case vk::Format::eA2B10G10R10UscaledPack32:
					return 4;
				case vk::Format::eA2B10G10R10SscaledPack32:
					return 4;
				case vk::Format::eA2B10G10R10UintPack32:
					return 4;
				case vk::Format::eA2B10G10R10SintPack32:
					return 4;
				case vk::Format::eR16Unorm:
					return 1;
				case vk::Format::eR16Snorm:
					return 1;
				case vk::Format::eR16Uscaled:
					return 1;
				case vk::Format::eR16Sscaled:
					return 1;
				case vk::Format::eR16Uint:
					return 1;
				case vk::Format::eR16Sint:
					return 1;
				case vk::Format::eR16Sfloat:
					return 1;
				case vk::Format::eR16G16Unorm:
					return 2;
				case vk::Format::eR16G16Snorm:
					return 2;
				case vk::Format::eR16G16Uscaled:
					return 2;
				case vk::Format::eR16G16Sscaled:
					return 2;
				case vk::Format::eR16G16Uint:
					return 2;
				case vk::Format::eR16G16Sint:
					return 2;
				case vk::Format::eR16G16Sfloat:
					return 2;
				case vk::Format::eR16G16B16Unorm:
					return 3;
				case vk::Format::eR16G16B16Snorm:
					return 3;
				case vk::Format::eR16G16B16Uscaled:
					return 3;
				case vk::Format::eR16G16B16Sscaled:
					return 3;
				case vk::Format::eR16G16B16Uint:
					return 3;
				case vk::Format::eR16G16B16Sint:
					return 3;
				case vk::Format::eR16G16B16Sfloat:
					return 3;
				case vk::Format::eR16G16B16A16Unorm:
					return 4;
				case vk::Format::eR16G16B16A16Snorm:
					return 4;
				case vk::Format::eR16G16B16A16Uscaled:
					return 4;
				case vk::Format::eR16G16B16A16Sscaled:
					return 4;
				case vk::Format::eR16G16B16A16Uint:
					return 4;
				case vk::Format::eR16G16B16A16Sint:
					return 4;
				case vk::Format::eR16G16B16A16Sfloat:
					return 4;
				case vk::Format::eR32Uint:
					return 1;
				case vk::Format::eR32Sint:
					return 1;
				case vk::Format::eR32Sfloat:
					return 1;
				case vk::Format::eR32G32Uint:
					return 2;
				case vk::Format::eR32G32Sint:
					return 2;
				case vk::Format::eR32G32Sfloat:
					return 2;
				case vk::Format::eR32G32B32Uint:
					return 3;
				case vk::Format::eR32G32B32Sint:
					return 3;
				case vk::Format::eR32G32B32Sfloat:
					return 3;
				case vk::Format::eR32G32B32A32Uint:
					return 4;
				case vk::Format::eR32G32B32A32Sint:
					return 4;
				case vk::Format::eR32G32B32A32Sfloat:
					return 4;
				case vk::Format::eR64Uint:
					return 1;
				case vk::Format::eR64Sint:
					return 1;
				case vk::Format::eR64Sfloat:
					return 1;
				case vk::Format::eR64G64Uint:
					return 2;
				case vk::Format::eR64G64Sint:
					return 2;
				case vk::Format::eR64G64Sfloat:
					return 2;
				case vk::Format::eR64G64B64Uint:
					return 3;
				case vk::Format::eR64G64B64Sint:
					return 3;
				case vk::Format::eR64G64B64Sfloat:
					return 3;
				case vk::Format::eR64G64B64A64Uint:
					return 4;
				case vk::Format::eR64G64B64A64Sint:
					return 4;
				case vk::Format::eR64G64B64A64Sfloat:
					return 4;
				case vk::Format::eB10G11R11UfloatPack32:
					return 3;
				case vk::Format::eE5B9G9R9UfloatPack32:
					return 3;
				case vk::Format::eD16Unorm:
					return 1;
				case vk::Format::eX8D24UnormPack32:
					return 2;
				case vk::Format::eD32Sfloat:
					return 1;
				case vk::Format::eS8Uint:
					return 1;
				case vk::Format::eD16UnormS8Uint:
					return 2;
				case vk::Format::eD24UnormS8Uint:
					return 2;
				case vk::Format::eD32SfloatS8Uint:
					return 2;
				case vk::Format::eBc1RgbUnormBlock:
					return 3;
				case vk::Format::eBc1RgbSrgbBlock:
					return 3;
				case vk::Format::eBc1RgbaUnormBlock:
					return 4;
				case vk::Format::eBc1RgbaSrgbBlock:
					return 4;
				case vk::Format::eBc2UnormBlock:
					return 4;
				case vk::Format::eBc2SrgbBlock:
					return 4;
				case vk::Format::eBc3UnormBlock:
					return 4;
				case vk::Format::eBc3SrgbBlock:
					return 4;
				case vk::Format::eBc4UnormBlock:
					return 1;
				case vk::Format::eBc4SnormBlock:
					return 1;
				case vk::Format::eBc5UnormBlock:
					return 2;
				case vk::Format::eBc5SnormBlock:
					return 2;
				case vk::Format::eBc6HUfloatBlock:
					return 3;
				case vk::Format::eBc6HSfloatBlock:
					return 3;
				case vk::Format::eBc7UnormBlock:
					return 4;
				case vk::Format::eBc7SrgbBlock:
					return 4;
				case vk::Format::eEtc2R8G8B8UnormBlock:
					return 3;
				case vk::Format::eEtc2R8G8B8SrgbBlock:
					return 3;
				case vk::Format::eEtc2R8G8B8A1UnormBlock:
					return 4;
				case vk::Format::eEtc2R8G8B8A1SrgbBlock:
					return 4;
				case vk::Format::eEtc2R8G8B8A8UnormBlock:
					return 4;
				case vk::Format::eEtc2R8G8B8A8SrgbBlock:
					return 4;
				case vk::Format::eEacR11UnormBlock:
					return 1;
				case vk::Format::eEacR11SnormBlock:
					return 1;
				case vk::Format::eEacR11G11UnormBlock:
					return 2;
				case vk::Format::eEacR11G11SnormBlock:
					return 2;
				case vk::Format::eAstc4x4UnormBlock:
					return 4;
				case vk::Format::eAstc4x4SrgbBlock:
					return 4;
				case vk::Format::eAstc4x4SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc5x4UnormBlock:
					return 4;
				case vk::Format::eAstc5x4SrgbBlock:
					return 4;
				case vk::Format::eAstc5x4SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc5x5UnormBlock:
					return 4;
				case vk::Format::eAstc5x5SrgbBlock:
					return 4;
				case vk::Format::eAstc5x5SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc6x5UnormBlock:
					return 4;
				case vk::Format::eAstc6x5SrgbBlock:
					return 4;
				case vk::Format::eAstc6x5SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc6x6UnormBlock:
					return 4;
				case vk::Format::eAstc6x6SrgbBlock:
					return 4;
				case vk::Format::eAstc6x6SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc8x5UnormBlock:
					return 4;
				case vk::Format::eAstc8x5SrgbBlock:
					return 4;
				case vk::Format::eAstc8x5SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc8x6UnormBlock:
					return 4;
				case vk::Format::eAstc8x6SrgbBlock:
					return 4;
				case vk::Format::eAstc8x6SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc8x8UnormBlock:
					return 4;
				case vk::Format::eAstc8x8SrgbBlock:
					return 4;
				case vk::Format::eAstc8x8SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc10x5UnormBlock:
					return 4;
				case vk::Format::eAstc10x5SrgbBlock:
					return 4;
				case vk::Format::eAstc10x5SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc10x6UnormBlock:
					return 4;
				case vk::Format::eAstc10x6SrgbBlock:
					return 4;
				case vk::Format::eAstc10x6SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc10x8UnormBlock:
					return 4;
				case vk::Format::eAstc10x8SrgbBlock:
					return 4;
				case vk::Format::eAstc10x8SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc10x10UnormBlock:
					return 4;
				case vk::Format::eAstc10x10SrgbBlock:
					return 4;
				case vk::Format::eAstc10x10SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc12x10UnormBlock:
					return 4;
				case vk::Format::eAstc12x10SrgbBlock:
					return 4;
				case vk::Format::eAstc12x10SfloatBlockEXT:
					return 4;
				case vk::Format::eAstc12x12UnormBlock:
					return 4;
				case vk::Format::eAstc12x12SrgbBlock:
					return 4;
				case vk::Format::eAstc12x12SfloatBlockEXT:
					return 4;
				case vk::Format::eG8B8G8R8422Unorm:
					return 4;
				case vk::Format::eB8G8R8G8422Unorm:
					return 4;
				case vk::Format::eG8B8R83Plane420Unorm:
					return 3;
				case vk::Format::eG8B8R82Plane420Unorm:
					return 3;
				case vk::Format::eG8B8R83Plane422Unorm:
					return 3;
				case vk::Format::eG8B8R82Plane422Unorm:
					return 3;
				case vk::Format::eG8B8R83Plane444Unorm:
					return 3;
				case vk::Format::eR10X6UnormPack16:
					return 1;
				case vk::Format::eR10X6G10X6Unorm2Pack16:
					return 2;
				case vk::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16:
					return 4;
				case vk::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16:
					return 4;
				case vk::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16:
					return 4;
				case vk::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16:
					return 3;
				case vk::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16:
					return 3;
				case vk::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16:
					return 3;
				case vk::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16:
					return 3;
				case vk::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16:
					return 3;
				case vk::Format::eR12X4UnormPack16:
					return 1;
				case vk::Format::eR12X4G12X4Unorm2Pack16:
					return 2;
				case vk::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16:
					return 4;
				case vk::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16:
					return 4;
				case vk::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16:
					return 4;
				case vk::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16:
					return 3;
				case vk::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16:
					return 3;
				case vk::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16:
					return 3;
				case vk::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16:
					return 3;
				case vk::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16:
					return 3;
				case vk::Format::eG16B16G16R16422Unorm:
					return 4;
				case vk::Format::eB16G16R16G16422Unorm:
					return 4;
				case vk::Format::eG16B16R163Plane420Unorm:
					return 3;
				case vk::Format::eG16B16R162Plane420Unorm:
					return 3;
				case vk::Format::eG16B16R163Plane422Unorm:
					return 3;
				case vk::Format::eG16B16R162Plane422Unorm:
					return 3;
				case vk::Format::eG16B16R163Plane444Unorm:
					return 3;
				case vk::Format::ePvrtc12BppUnormBlockIMG:
					return 4;
				case vk::Format::ePvrtc14BppUnormBlockIMG:
					return 4;
				case vk::Format::ePvrtc22BppUnormBlockIMG:
					return 4;
				case vk::Format::ePvrtc24BppUnormBlockIMG:
					return 4;
				case vk::Format::ePvrtc12BppSrgbBlockIMG:
					return 4;
				case vk::Format::ePvrtc14BppSrgbBlockIMG:
					return 4;
				case vk::Format::ePvrtc22BppSrgbBlockIMG:
					return 4;
				case vk::Format::ePvrtc24BppSrgbBlockIMG:
					return 4;
				default:
					return 0;
			}
		}
	}

	class ExtensionMap {
	private:
		std::map<std::size_t, std::any> map;
		void* pStart = nullptr;
		void** pEnd = nullptr;

	public:
		template <class T>
		ExtensionMap& add( T t_ ) {
			auto typeIndex = std::type_index( typeid(T) );
			auto hash = typeIndex.hash_code();
			map[hash] = t_;
			T& obj = std::any_cast<T&>(map[hash]);

			if( pStart == nullptr ) {
				pStart = &obj;
				pEnd = const_cast<void**>(&obj.pNext);
			}
			else {
				*pEnd = &obj;
				pEnd = const_cast<void**>(&obj.pNext);
			}

			return *this;
		}

		template <class T>
		const std::optional<T> get() const {
			auto typeIndex = std::type_index( typeid(T) );
			const auto& res = map.find( typeIndex.hash_code() );
			return std::optional<T>( res != map.end() ? std::any_cast<T>(res->second) : std::optional<T>() );
		}

		void* get_chain() const;


	private:
		template <class T>
		std::map<std::size_t, std::any>::iterator find() {
			return map.find( typeid(T).hash_code() );
		}
	};

	template<class UObject, class VkObject, typename Flags>
	class UniqueObject {
	public:
		template <class T>
		class Builder {
		public:
			std::unique_ptr<T> object;

		public:
			virtual Builder& add_flags( const Flags& flags_ ) = 0;
			virtual T&& build() = 0;
		};

	protected:
		UObject object;
		Flags flags;
		ExtensionMap extensionMap;

	public:
		constexpr UObject& get_unique_object() const {
			return object;
		}

		constexpr VkObject& get_object() const {
			return object.get();
		}

		void destroy() {
			object.reset();
		}
	};

	using UOInstance = UniqueObject<vk::UniqueInstance, vk::Instance, vk::InstanceCreateFlags>;
	class Instance : public UOInstance {
	public:
		class InstanceBuilder : public Builder<Instance> {
		public:
			InstanceBuilder();

			template <typename E>
			InstanceBuilder& add_next_extension( const E& extension_ ) {
				object->extensionMap.add( extension_ );
			}

			InstanceBuilder& set_application_name( const std::string& applicationName_ );

			InstanceBuilder& set_application_version( const uint32_t& major_, const uint32_t& minor_, const uint32_t& patch_ );

			InstanceBuilder& set_engine_name( const std::string& engineName_ );

			InstanceBuilder& set_engine_version( const uint32_t& major_, const uint32_t& minor_, const uint32_t& patch_ );

			InstanceBuilder& set_api_version( const uint32_t& major_, const uint32_t minor_ );

			InstanceBuilder& include_layer( const std::string& layerName_ );

			InstanceBuilder& include_layers( const vk::ArrayProxy<const std::string> layerNames_ );

			InstanceBuilder& include_all_available_layers();

			InstanceBuilder& include_extension( const std::string& extensionName_ );

			InstanceBuilder& include_extensions( const vk::ArrayProxy<const std::string> extensionNames_ );

			InstanceBuilder& include_all_available_extensions();

			InstanceBuilder& add_flags( const vk::InstanceCreateFlags& flags_ ) override;

			Instance&& build() override;
		};

	public:
		static const uint32_t version;
		static const std::vector<vk::LayerProperties> availableLayers;
		static const std::vector<vk::ExtensionProperties> availableExtensions;

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

	//class PhysicalDevice {
	//public:
	//	vk::PhysicalDevice physicalDevice;
	//	vk::PhysicalDeviceFeatures2 features;
	//	vk::PhysicalDeviceProperties2 properties;
	//	vk::PhysicalDeviceMemoryProperties2 memoryProperties;
	//	std::vector<vk::QueueFamilyProperties2> queueFamilyProperties;
	//	ExtensionMap featureExtensions;
	//	ExtensionMap propertyExtensions;
	//	ExtensionMap memoryPropertyExtensions;


	//public:
	//	static std::vector<stellar::PhysicalDevice> get_physical_devices( stellar::Instance& instance_ ) {
	//		auto physicalDevices = instance_.get().enumeratePhysicalDevices();

	//		std::vector<stellar::PhysicalDevice> result;
	//		for( auto& p : physicalDevices ) {
	//			auto features = p.getFeatures2();
	//			auto properties = p.getProperties2();
	//			auto memoryProperties = p.getMemoryProperties();
	//			auto queueFamilyProperties = p.getQueueFamilyProperties2();
	//			result.push_back( stellar::PhysicalDevice( p, features, properties, memoryProperties, queueFamilyProperties ) );
	//		}

	//		return result;
	//	}

	//	const vk::PhysicalDevice& get() const {
	//		return physicalDevice;
	//	}


	//	const int get_memory_type_index( vk::MemoryRequirements requirements_, vk::MemoryPropertyFlags flags_ ) const {
	//		auto memProps = memoryProperties.memoryProperties;
	//		for( uint32_t i = 0; i < memProps.memoryTypeCount; ++i ) {
	//			if( (requirements_.memoryTypeBits & (1 << i)) &&
	//				((memProps.memoryTypes[i].propertyFlags & flags_) == flags_) ) {
	//				return i;
	//			}
	//		}

	//		return -1;
	//	}

	//	const std::vector<uint32_t> get_queue_family_indices_of( vk::QueueFlags flags ) const {
	//		std::vector<uint32_t> ret;
	//		for( uint32_t i = 0; i < static_cast<uint32_t>(queueFamilyProperties.size()); i++ ) {
	//			auto queueFlags = queueFamilyProperties[i].queueFamilyProperties.queueFlags;
	//			if( queueFlags & flags ) {
	//				ret.push_back( i );
	//			}
	//		}

	//		return ret;
	//	}

	//	template <class T>
	//	PhysicalDevice& add_feature_extension( T t_ ) {
	//		featureExtensions.add( t_ );
	//		return *this;
	//	}

	//	template <class T>
	//	PhysicalDevice& add_property_extension( T t_ ) {
	//		propertyExtensions.add( t_ );
	//	}



	//private:
	//	PhysicalDevice( vk::PhysicalDevice physicalDevice_,
	//					vk::PhysicalDeviceFeatures2 features_,
	//					vk::PhysicalDeviceProperties2 properties_,
	//					vk::PhysicalDeviceMemoryProperties2 memoryProperties_,
	//					std::vector<vk::QueueFamilyProperties2> queueFamilyProperties_ )
	//		: physicalDevice( physicalDevice_ )
	//		, features( features_ )
	//		, properties( properties_ )
	//		, memoryProperties( memoryProperties_ )
	//		, queueFamilyProperties( queueFamilyProperties_ ) {}
	//};

	//using UODevice = UniqueObject<vk::UniqueDevice, vk::Device, vk::DeviceCreateFlags>;
	//class Device : UODevice {
	//public:
	//	stellar::PhysicalDevice& physicalDevice;
	//	std::vector<std::string> enabledExtensionNames;
	//	std::map<uint32_t, std::tuple<uint32_t, vk::DeviceQueueCreateFlags>> queueInclusions;
	//	std::map<uint32_t, vk::ArrayProxy<const float>> queuePriorities;

	//	const std::vector<vk::ExtensionProperties> availableExtensions;

	//public:
	//	Device( stellar::PhysicalDevice& physicalDevice )
	//		: physicalDevice( physicalDevice )
	//		, availableExtensions( physicalDevice.get().enumerateDeviceExtensionProperties() ) {}

	//	Device& include_extension( std::string extensionName_ ) {
	//		auto haveExtension = std::any_of( availableExtensions.begin(),
	//										  availableExtensions.end(),
	//										  [extensionName_]( vk::ExtensionProperties e ) { return extensionName_ == e.extensionName; } );
	//		if( !haveExtension ) {
	//			throw vk::ExtensionNotPresentError( "The device extension '" + extensionName_ + "' is not an available extension." );
	//		}

	//		enabledExtensionNames.push_back( extensionName_ );
	//		return *this;
	//	}

	//	Device& include_extensions( vk::ArrayProxy<const std::string> names ) {
	//		for( const auto& n : names ) {
	//			include_extension( n );
	//		}
	//		return *this;
	//	}

	//	Device& include_all_available_extensions() {
	//		for( const auto& e : availableExtensions ) {
	//			enabledExtensionNames.push_back( e.extensionName );
	//		}
	//		return *this;
	//	}

	//	Device& include_queues( uint32_t familyIndex_, uint32_t count_, vk::DeviceQueueCreateFlags flags_ = {} ) {
	//		queueInclusions[familyIndex_] = std::tuple<uint32_t, vk::DeviceQueueCreateFlags>( count_, flags_ );
	//		return *this;
	//	}

	//	Device& include_queue_priority( uint32_t familyIndex_, vk::ArrayProxy<const float> priorities_ ) {
	//		queuePriorities[familyIndex_] = priorities_;
	//		return *this;
	//	}

	//	Device& add_flags( vk::DeviceCreateFlags flags_ ) override {
	//		flags |= flags_;
	//		return *this;
	//	}

	//	Device& set_next( void* next_ ) {
	//		return *this;
	//	}


	//	Device& init() override {
	//		std::vector<vk::DeviceQueueCreateInfo> queuesCI;
	//		for( const auto& q : queueInclusions ) {
	//			vk::DeviceQueueCreateInfo qci;
	//			qci.setFlags( std::get<vk::DeviceQueueCreateFlags>( q.second ) )
	//				.setQueueFamilyIndex( q.first )
	//				.setQueueCount( std::get<uint32_t>( q.second ) )
	//				.setPQueuePriorities( queuePriorities[q.first].data() );

	//			queuesCI.push_back( qci );
	//		}

	//		std::vector<const char*> extensionNames;
	//		for( const auto& n : enabledExtensionNames ) {
	//			extensionNames.push_back( n.data() );
	//		}

	//		//physicalDevice.features12.setPNext( next );
	//		vk::DeviceCreateInfo ci;
	//		ci.setPNext( &physicalDevice.features )
	//			.setFlags( flags )
	//			.setQueueCreateInfoCount( queuesCI.size() )
	//			.setQueueCreateInfos( queuesCI )
	//			.setEnabledExtensionCount( enabledExtensionNames.size() )
	//			.setPEnabledExtensionNames( extensionNames );

	//		object = physicalDevice.get().createDeviceUnique( ci );

	//		return *this;
	//	}
	//};

	//struct surface {
	//	vk::UniqueSurfaceKHR _surface;
	//	vk::Bool32 _supported;
	//	vk::SurfaceCapabilitiesKHR _capabilities;
	//	std::vector<vk::SurfaceFormatKHR> _formats;
	//	std::vector<vk::PresentModeKHR> _presentModes;

	//	surface( stellar::Instance& instance,
	//			 stellar::PhysicalDevice& physicalDevice,
	//			 stellar::Device& Device,
	//			 HWND hWnd,
	//			 HINSTANCE hInstance = nullptr ) {
	//		vk::Win32SurfaceCreateInfoKHR ci = vk::Win32SurfaceCreateInfoKHR( {}, hInstance, hWnd );
	//		_surface = instance.get().createWin32SurfaceKHRUnique( ci );

	//		auto& phyDev = physicalDevice.physicalDevice;
	//		_supported = phyDev.getSurfaceSupportKHR( Device._generalQueueIndex, _surface.get() );
	//		_capabilities = phyDev.getSurfaceCapabilitiesKHR( _surface.get() );
	//		_formats = phyDev.getSurfaceFormatsKHR( _surface.get() );
	//		_presentModes = phyDev.getSurfacePresentModesKHR( _surface.get() );
	//	}
	//};

	//struct command_buffers {
	//	vk::UniqueCommandPool _generalCommandPool;
	//	vk::UniqueCommandPool _computeCommandPool;
	//	vk::UniqueCommandPool _transferCommandPool;
	//	std::vector<vk::UniqueCommandBuffer> _primaryGeneralCommandBuffers;
	//	std::vector<vk::UniqueCommandBuffer> _primaryComputeCommandBuffers;
	//	std::vector<vk::UniqueCommandBuffer> _primaryTransferCommandBuffers;
	//	std::vector<vk::UniqueCommandBuffer> _secondaryGeneralCommandBuffers;
	//	std::vector<vk::UniqueCommandBuffer> _secondaryComputeCommandBuffers;
	//	std::vector<vk::UniqueCommandBuffer> _secondaryTransferCommandBuffers;

	//	command_buffers( stellar::Device& Device,
	//					 uint32_t primaryGeneralCount = 1,
	//					 uint32_t primaryComputeCount = 1,
	//					 uint32_t primaryTransferCount = 1,
	//					 uint32_t secondaryGeneralCount = 1,
	//					 uint32_t secondaryComputeCount = 1,
	//					 uint32_t secondaryTransferCount = 1 ) {
	//		vk::CommandPoolCreateInfo poolCI;
	//		poolCI.setFlags( vk::CommandPoolCreateFlagBits::eResetCommandBuffer );
	//		poolCI.setQueueFamilyIndex( Device._generalQueueIndex );

	//		_generalCommandPool = Device._device->createCommandPoolUnique( poolCI );

	//		poolCI.setQueueFamilyIndex( Device._computeQueueIndex );

	//		_computeCommandPool = Device._device->createCommandPoolUnique( poolCI );

	//		poolCI.setQueueFamilyIndex( Device._transferQueueIndex );

	//		_transferCommandPool = Device._device->createCommandPoolUnique( poolCI );

	//		std::vector<vk::UniqueCommandBuffer> primaryGenerals, primaryComputes, primaryTransfers;
	//		std::vector<vk::UniqueCommandBuffer> secondaryGenerals, secondaryComputes, secondaryTransfers;

	//		auto primaryAI = vk::CommandBufferAllocateInfo( _generalCommandPool.get(), vk::CommandBufferLevel::ePrimary, primaryGeneralCount );
	//		_primaryGeneralCommandBuffers = Device._device->allocateCommandBuffersUnique( primaryAI );

	//		primaryAI.setCommandPool( _computeCommandPool.get() );
	//		primaryAI.setCommandBufferCount( primaryComputeCount );
	//		_primaryComputeCommandBuffers = Device._device->allocateCommandBuffersUnique( primaryAI );

	//		primaryAI.setCommandPool( _transferCommandPool.get() );
	//		primaryAI.setCommandBufferCount( primaryTransferCount );
	//		_primaryTransferCommandBuffers = Device._device->allocateCommandBuffersUnique( primaryAI );

	//		auto secondaryAI = vk::CommandBufferAllocateInfo( _generalCommandPool.get(), vk::CommandBufferLevel::eSecondary, secondaryGeneralCount );
	//		_secondaryGeneralCommandBuffers = Device._device->allocateCommandBuffersUnique( secondaryAI );

	//		secondaryAI.setCommandPool( _computeCommandPool.get() );
	//		secondaryAI.setCommandBufferCount( primaryComputeCount );
	//		_secondaryComputeCommandBuffers = Device._device->allocateCommandBuffersUnique( secondaryAI );

	//		secondaryAI.setCommandPool( _transferCommandPool.get() );
	//		secondaryAI.setCommandBufferCount( primaryTransferCount );
	//		_secondaryTransferCommandBuffers = Device._device->allocateCommandBuffersUnique( secondaryAI );
	//	}
	//};

	//struct image {
	//	vk::UniqueImage _image;
	//	vk::MemoryRequirements _memoryRequirements;
	//	uint32_t _width;
	//	uint32_t _height;
	//	vk::Format _format;
	//	vk::ImageUsageFlags _usage;
	//	vk::DeviceSize _size;
	//	vk::UniqueSampler _sampler;
	//	vk::ImageLayout _layout;

	//	image( stellar::Device& Device,
	//		   uint32_t width,
	//		   uint32_t height,
	//		   vk::Format format,
	//		   vk::ImageUsageFlags usage )
	//		: _width( width )
	//		, _height( height )
	//		, _format( format )
	//		, _usage( usage )
	//		, _size( static_cast<vk::DeviceSize>(width)* height* stellar::utility::get_format_channel_count( format ) )
	//		, _layout( vk::ImageLayout::eUndefined ) {
	//		vk::ImageCreateInfo imageCI = vk::ImageCreateInfo(
	//			vk::ImageCreateFlags(),
	//			vk::ImageType::e2D,
	//			_format,
	//			vk::Extent3D( _width, _height, 1 ),
	//			1,
	//			1,
	//			vk::SampleCountFlagBits::e1,
	//			vk::ImageTiling::eOptimal,
	//			_usage,
	//			vk::SharingMode::eExclusive,
	//			0,
	//			nullptr,
	//			_layout
	//		);

	//		auto& dev = Device._device;
	//		_image = dev->createImageUnique( imageCI );
	//		_memoryRequirements = dev->getImageMemoryRequirements( _image.get() );

	//		auto samplerCI = vk::SamplerCreateInfo(
	//			vk::SamplerCreateFlags(),
	//			vk::Filter::eLinear,
	//			vk::Filter::eLinear,
	//			vk::SamplerMipmapMode::eLinear,
	//			vk::SamplerAddressMode::eRepeat,
	//			vk::SamplerAddressMode::eRepeat,
	//			vk::SamplerAddressMode::eRepeat,
	//			0.0f,
	//			false,
	//			0.0f,
	//			false,
	//			vk::CompareOp::eNever,
	//			0.0f,
	//			0.0f,
	//			vk::BorderColor::eIntOpaqueBlack,
	//			false
	//		);

	//		_sampler = dev->createSamplerUnique( samplerCI );
	//	}

	//	image( stellar::Device& Device,
	//		   vk::Image& image,
	//		   uint32_t width,
	//		   uint32_t height,
	//		   vk::Format format,
	//		   vk::ImageUsageFlags usage )
	//		: _image( vk::UniqueImage( image ) )
	//		, _memoryRequirements( Device._device->getImageMemoryRequirements( _image.get() ) )
	//		, _width( width )
	//		, _height( height )
	//		, _format( format )
	//		, _usage( usage )
	//		, _size( static_cast<vk::DeviceSize>(width)* height* stellar::utility::get_format_channel_count( format ) )
	//		, _layout( vk::ImageLayout::eUndefined ) {
	//		auto samplerCI = vk::SamplerCreateInfo(
	//			vk::SamplerCreateFlags(),
	//			vk::Filter::eLinear,
	//			vk::Filter::eLinear,
	//			vk::SamplerMipmapMode::eLinear,
	//			vk::SamplerAddressMode::eRepeat,
	//			vk::SamplerAddressMode::eRepeat,
	//			vk::SamplerAddressMode::eRepeat,
	//			0.0f,
	//			false,
	//			0.0f,
	//			false,
	//			vk::CompareOp::eNever,
	//			0.0f,
	//			0.0f,
	//			vk::BorderColor::eIntOpaqueBlack,
	//			false
	//		);

	//		_sampler = Device._device->createSamplerUnique( samplerCI );

	//	}
	//};

	//struct image_view {
	//	vk::UniqueImageView _imageView;
	//	const stellar::image& _imageReference;
	//	vk::ImageAspectFlags _aspect;

	//	image_view( stellar::Device& Device,
	//				stellar::image& image,
	//				vk::ImageAspectFlags aspect )
	//		: _aspect( aspect )
	//		, _imageReference( image ) {
	//		auto ci = vk::ImageViewCreateInfo(
	//			vk::ImageViewCreateFlags(),
	//			image._image.get(),
	//			vk::ImageViewType::e2D,
	//			image._format,
	//			vk::ComponentMapping(),
	//			vk::ImageSubresourceRange( _aspect, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS )
	//		);

	//		_imageView = Device._device->createImageViewUnique( ci );
	//	}
	//};


	//struct buffer {
	//	vk::UniqueBuffer _buffer;
	//	vk::MemoryRequirements _memoryRequirements;
	//	vk::DeviceSize _size;
	//	vk::BufferUsageFlags _usage;

	//	buffer( stellar::Device& Device,
	//			stellar::PhysicalDevice& physicalDevice,
	//			vk::DeviceSize size,
	//			vk::BufferUsageFlags usage )
	//		: _size( size )
	//		, _usage( usage ) {
	//		auto ci = vk::BufferCreateInfo(
	//			vk::BufferCreateFlags(),
	//			_size,
	//			_usage,
	//			vk::SharingMode::eExclusive,
	//			0,
	//			nullptr
	//		);

	//		auto dev = Device._device.get();
	//		_buffer = Device._device->createBufferUnique( ci );
	//		_memoryRequirements = Device._device->getBufferMemoryRequirements( _buffer.get() );
	//	}
	//};

	//struct device_memory {
	//	vk::UniqueDeviceMemory _deviceMemory;
	//	vk::DeviceSize _allocationSize;
	//	int _memoryTypeIndex;

	//	device_memory( stellar::Device& Device,
	//				   stellar::PhysicalDevice& physicalDevice,
	//				   stellar::image& image,
	//				   vk::MemoryPropertyFlags memoryProperties )
	//		: _allocationSize( image._memoryRequirements.size )
	//		, _memoryTypeIndex( physicalDevice.get_memory_type_index( image._memoryRequirements, memoryProperties ) ) {
	//		vk::MemoryAllocateInfo ai = vk::MemoryAllocateInfo( _allocationSize, _memoryTypeIndex );
	//		_deviceMemory = Device._device->allocateMemoryUnique( ai );
	//	}

	//	device_memory( stellar::Device& Device,
	//				   stellar::PhysicalDevice& physicalDevice,
	//				   stellar::buffer& buffer,
	//				   vk::MemoryPropertyFlags memoryProperties )
	//		: _allocationSize( buffer._memoryRequirements.size )
	//		, _memoryTypeIndex( physicalDevice.get_memory_type_index( buffer._memoryRequirements, memoryProperties ) ) {
	//		vk::MemoryAllocateInfo ai = vk::MemoryAllocateInfo( _allocationSize, _memoryTypeIndex );
	//		_deviceMemory = Device._device->allocateMemoryUnique( ai );
	//	}

	//	void bind_image( stellar::image& image,
	//					 vk::DeviceSize memoryOffset = 0 ) {
	//		auto dev = _deviceMemory.getOwner();
	//		dev.bindImageMemory( image._image.get(), _deviceMemory.get(), memoryOffset );
	//	}

	//	void bind_buffer( stellar::buffer& buffer,
	//					  vk::DeviceSize memoryOffset = 0 ) {
	//		auto dev = _deviceMemory.getOwner();
	//		dev.bindBufferMemory( buffer._buffer.get(), _deviceMemory.get(), memoryOffset );
	//	}

	//	void map_data( void* data,
	//				   vk::DeviceSize dataSize,
	//				   vk::DeviceSize memoryOffset = 0 ) {
	//		auto dev = _deviceMemory.getOwner();
	//		auto mem = _deviceMemory.get();
	//		void* p = nullptr;
	//		dev.mapMemory( mem, memoryOffset, dataSize, vk::MemoryMapFlags(), &p );
	//		memcpy( p, data, dataSize );
	//		dev.unmapMemory( mem );
	//	}
	//};

	//struct swapchain {
	//	vk::UniqueSwapchainKHR _swapchain;
	//	std::vector<stellar::image> _images;
	//	std::vector<stellar::image_view> _imageViews;

	//	swapchain( stellar::Device& Device,
	//			   stellar::surface& surface ) {
	//		auto& capabilities = surface._capabilities;
	//		auto& format = surface._formats.front();

	//		vk::SwapchainCreateInfoKHR swapchainCI = vk::SwapchainCreateInfoKHR(
	//			vk::SwapchainCreateFlagsKHR(),
	//			surface._surface.get(),
	//			capabilities.minImageCount,
	//			format.format,
	//			format.colorSpace,
	//			capabilities.currentExtent,
	//			1,
	//			vk::ImageUsageFlagBits::eColorAttachment,
	//			vk::SharingMode::eExclusive,
	//			0,
	//			nullptr,
	//			capabilities.currentTransform,
	//			vk::CompositeAlphaFlagBitsKHR::eOpaque,
	//			vk::PresentModeKHR::eFifo,
	//			VK_TRUE,
	//			nullptr
	//		);

	//		auto& dev = Device._device;
	//		_swapchain = dev->createSwapchainKHRUnique( swapchainCI );
	//		auto swapchainImages = dev->getSwapchainImagesKHR( _swapchain.get() );
	//		for( auto& i : swapchainImages ) {
	//			_images.push_back( stellar::image( Device,
	//											   i,
	//											   capabilities.currentExtent.width,
	//											   capabilities.currentExtent.height,
	//											   format.format,
	//											   vk::ImageUsageFlagBits::eColorAttachment )
	//			);
	//		}

	//		_imageViews.reserve( _images.size() );
	//		for( auto& i : swapchainImages ) {
	//			_imageViews.push_back( stellar::image_view( Device, _images.back(), vk::ImageAspectFlagBits::eColor ) );
	//		}
	//	}
	//};

	//struct render_pass_attachments {
	//	std::vector<vk::AttachmentDescription> _attachments;

	//	render_pass_attachments() = default;
	//	render_pass_attachments( std::vector<vk::AttachmentDescription> attachments )
	//		: _attachments( attachments ) {}

	//	void add_attachment( vk::Format format,
	//						 vk::ImageLayout initialLayout,
	//						 vk::ImageLayout finalLayout ) {
	//		vk::AttachmentDescription a = vk::AttachmentDescription(
	//			vk::AttachmentDescriptionFlags(),
	//			format,
	//			vk::SampleCountFlagBits::e1,
	//			vk::AttachmentLoadOp::eClear,
	//			vk::AttachmentStoreOp::eStore,
	//			vk::AttachmentLoadOp::eDontCare,
	//			vk::AttachmentStoreOp::eDontCare,
	//			initialLayout,
	//			finalLayout
	//		);

	//		_attachments.push_back( a );
	//	}

	//	void add_attachment( const stellar::image& image,
	//						 vk::ImageLayout finalLayout ) {
	//		add_attachment( image._format, image._layout, finalLayout );
	//	}

	//	void add_attachment( stellar::image_view& view,
	//						 vk::ImageLayout finalLayout ) {
	//		add_attachment( view._imageReference, finalLayout );
	//	}
	//};

	//struct attachment_references {
	//	std::vector<vk::AttachmentReference> _inputAttachmentReferences;
	//	std::vector<vk::AttachmentReference> _colorAttachmentReferences;
	//	std::vector<vk::AttachmentReference> _resolveAttachmentReferences;
	//	vk::AttachmentReference _depthStencilAttachmentReference;
	//	std::vector<uint32_t> _preserveAttachments;

	//	attachment_references() = default;
	//	attachment_references( std::vector<vk::AttachmentReference> inputs,
	//						   std::vector<vk::AttachmentReference> colors,
	//						   std::vector<vk::AttachmentReference> resolves,
	//						   vk::AttachmentReference depthStencil,
	//						   std::vector<uint32_t> preserves )
	//		: _inputAttachmentReferences( inputs )
	//		, _colorAttachmentReferences( colors )
	//		, _resolveAttachmentReferences( resolves )
	//		, _depthStencilAttachmentReference( depthStencil )
	//		, _preserveAttachments( preserves ) {}

	//	void add_input_reference( uint32_t index, vk::ImageLayout layout ) {
	//		_inputAttachmentReferences.push_back( vk::AttachmentReference( index, layout ) );
	//	}

	//	void add_color_reference( uint32_t index, vk::ImageLayout layout = vk::ImageLayout::eColorAttachmentOptimal ) {
	//		_colorAttachmentReferences.push_back( vk::AttachmentReference( index, layout ) );
	//	}

	//	void add_resolve_reference( uint32_t index, vk::ImageLayout layout ) {
	//		_resolveAttachmentReferences.push_back( vk::AttachmentReference( index, layout ) );
	//	}

	//	void set_depth_stencil_reference( uint32_t index, vk::ImageLayout layout = vk::ImageLayout::eDepthStencilAttachmentOptimal ) {
	//		_depthStencilAttachmentReference = vk::AttachmentReference( index, layout );
	//	}

	//	void add_preserve_index( uint32_t index ) {
	//		_preserveAttachments.push_back( index );
	//	}

	//};

	//struct render_pass_subpasses {
	//	std::vector<vk::SubpassDescription> _subpasses;

	//	render_pass_subpasses() = default;
	//	render_pass_subpasses( std::vector<vk::SubpassDescription> subpasses )
	//		: _subpasses( subpasses ) {}

	//	void add_subpass( vk::PipelineBindPoint bindPoint, stellar::attachment_references& references ) {
	//		vk::SubpassDescription s = vk::SubpassDescription(
	//			vk::SubpassDescriptionFlags(),
	//			bindPoint,
	//			references._inputAttachmentReferences.size(),
	//			references._inputAttachmentReferences.data(),
	//			references._colorAttachmentReferences.size(),
	//			references._colorAttachmentReferences.data(),
	//			references._resolveAttachmentReferences.data(),
	//			&references._depthStencilAttachmentReference,
	//			references._preserveAttachments.size(),
	//			references._preserveAttachments.data()
	//		);

	//		_subpasses.push_back( s );
	//	}
	//};

	//struct render_pass {
	//	vk::UniqueRenderPass _renderPass;

	//	render_pass( stellar::Device& Device,
	//				 stellar::render_pass_attachments& attachments,
	//				 stellar::render_pass_subpasses& subpasses ) {
	//		vk::RenderPassCreateInfo ci = vk::RenderPassCreateInfo(
	//			vk::RenderPassCreateFlags(),
	//			attachments._attachments.size(),
	//			attachments._attachments.data(),
	//			subpasses._subpasses.size(),
	//			subpasses._subpasses.data(),
	//			0,
	//			nullptr
	//		);

	//		_renderPass = Device._device->createRenderPassUnique( ci );
	//	}
	//};

	//struct framebuffer {
	//	vk::UniqueFramebuffer _framebuffer;

	//	framebuffer( stellar::Device& Device,
	//				 stellar::render_pass& renderPass,
	//				 std::vector<std::reference_wrapper<stellar::image_view>> attachments ) {
	//		auto views = std::vector<vk::ImageView>();
	//		for( auto& a : attachments ) {
	//			views.push_back( a.get()._imageView.get() );
	//		}

	//		auto& image = attachments.front().get()._imageReference;
	//		vk::FramebufferCreateInfo ci = vk::FramebufferCreateInfo(
	//			vk::FramebufferCreateFlags(),
	//			renderPass._renderPass.get(),
	//			views.size(),
	//			views.data(),
	//			image._width,
	//			image._height,
	//			1
	//		);

	//		Device._device->createFramebufferUnique( ci );
	//	}
	//};

	//struct descriptor_pool {
	//	vk::UniqueDescriptorPool _descriptorPool;

	//	descriptor_pool( stellar::Device& Device,
	//					 std::vector<vk::DescriptorPoolSize> poolSizes,
	//					 uint32_t poolSets ) {
	//		vk::DescriptorPoolCreateInfo ci = vk::DescriptorPoolCreateInfo(
	//			vk::DescriptorPoolCreateFlags(),
	//			poolSets,
	//			poolSizes.size(),
	//			poolSizes.data()
	//		);
	//		_descriptorPool = Device._device->createDescriptorPoolUnique( ci );;
	//	}
	//};

	//struct descriptor_set_layout {
	//	vk::UniqueDescriptorSetLayout _descriptorSetLayout;

	//	descriptor_set_layout( stellar::Device& Device,
	//						   std::vector<vk::DescriptorSetLayoutBinding> bindings ) {
	//		vk::DescriptorSetLayoutCreateInfo ci = vk::DescriptorSetLayoutCreateInfo(
	//			vk::DescriptorSetLayoutCreateFlags(),
	//			bindings.size(),
	//			bindings.data()
	//		);

	//		_descriptorSetLayout = Device._device->createDescriptorSetLayoutUnique( ci );
	//	}
	//};

	//struct descriptor_set {
	//	vk::UniqueDescriptorSet _descriptorSet;

	//	descriptor_set( stellar::Device& Device,
	//					stellar::descriptor_pool& pool,
	//					stellar::descriptor_set_layout& layout ) {
	//		vk::DescriptorSetAllocateInfo ai = vk::DescriptorSetAllocateInfo(

	//		);
	//	}
	//};
}