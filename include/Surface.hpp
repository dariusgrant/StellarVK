#pragma once

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <vulkan/vulkan_android.h>
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include <wayland-client.h>
#include <vulkan/vulkan_wayland.h>
#elif defined(VK_USE_PLATFORM_WIN32_KHR)
#include <Windows.h>
#include <vulkan/vulkan_win32.h>
#elif defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb.h>
#include <vulkan/vulkan_xcb.h>
#elif defined(VK_USE_PLATFORM_XLIB_KHR)
#include <X11/Xlib.h>
#include <vulkan/vulkan_xlib.h>
#elif defined(VK_USE_PLATFORM_DIRECTFB_EXT)
#include <directfb/directfb.h>
#include <vulkan/vulkan_directfb.h>
#elif defined(VK_USE_PLATFORM_IOS_MVK)
#include <vulkan/vulkan_ios.h>
#elif defined(VK_USE_PLATFORM_MACOS_MVK)
#include <vulkan/vulkan_macos.h>
#elif defined(VK_USE_PLATFORM_VI_NN)
#include <vulkan/vulkan_vi.h>
#elif defined(VK_USE_PLATFORM_FUCHSIA)
#include <zircon/types.h>
#include <vulkan/vulkan_fuchsia.h>
#elif defined(VK_USE_PLATFORM_METAL_EXT)
#include <vulkan/vulkan_metal.h>
#endif

#include "UniqueObject.hpp"
#include "WindowSystemType.hpp"

namespace stellar {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::AndroidSurfaceCreateFlagsKHR>;
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::WaylandSurfaceCreateFlagsKHR>;
#elif defined(VK_USE_PLATFORM_WIN32_KHR)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::Win32SurfaceCreateFlagsKHR>;
#elif defined(VK_USE_PLATFORM_XCB_KHR)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::XcbSurfaceCreateFlagsKHR>;
#elif defined(VK_USE_PLATFORM_XLIB_KHR)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::XlibSurfaceCreateFlagsKHR>;
#elif defined(VK_USE_PLATFORM_DIRECTFB_EXT)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::DirectFBSurfaceCreateFlagsEXT>;
#elif defined(VK_USE_PLATFORM_IOS_MVK)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::IOSSurfaceCreateFlagsMVK>;
#elif defined(VK_USE_PLATFORM_MACOS_MVK)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::MacOSSurfaceCreateFlagsMVK>;
#elif defined(VK_USE_PLATFORM_VI_NN)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::ViSurfaceCreateFlagsNN>;
#elif defined(VK_USE_PLATFORM_FUCHSIA)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::ImagePipeSurfaceCreateFlagsFUCHSIA>;
#elif defined(VK_USE_PLATFORM_METAL_EXT)
	using UOSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::VkMetalSurfaceCreateFlagsEXT>;
#endif
	template <typename Flags>
	using UOS = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, Flags>;

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
	class AndroidSurface : public UOS<vk::AndroidSurfaceCreateFlagsKHR> {
	public:
		class AndroidSurfaceBuilder : public Builder<AndroidSurfaceBuilder, AndroidSurface> {
		public:
			AndroidSurfaceBuilder( const ANativeWindow& window_ );

			template <typename Extension, typename... Extensions>
			AndroidSurfaceBuilder& add_next_extension( const Extension& first_, const Extensions&... rest_ ) {
				object->extensionMap.add( first_, rest_... );
				return *this;
			}

			AndroidSurface&& build() override {
				return std::move( *derivedUniqueObject );
			}
		};

	public:
		AndroidSurface() = default;

	private:
		const ANativeWindow& window;
	};
#endif
}