#pragma once

#ifdef STELLAR_USE_PLATFORM_WIN32_KHR
#include "Win32Surface.hpp"
#endif

#ifdef STELLAR_USE_PLATFORM_ANDROID_KHR
#include "AndroidSurface.hpp"
#endif

#include "Instance.hpp"
#include "PhysicalDevice.hpp"


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

}