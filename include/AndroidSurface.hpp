#pragma once

#ifndef VK_USE_PLATFORM_ANDROID_KHR
#define VK_USE_PLATFORM_ANDROID_KHR

#include "UniqueObject.hpp"
#include <vulkan/vulkan.hpp>

namespace stellar {
	using UOAndroidSurface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::AndroidSurfaceCreateFlagsKHR>;
	class AndroidSurface : public UOAndroidSurface {
	public:
		class AndroidSurfaceBuilder : public Builder<AndroidSurfaceBuilder, AndroidSurface> {
		public:
			AndroidSurfaceBuilder( const ANativeWindow& aNativeWindow_ );

			AndroidSurface&& build() override;
		};

	protected:
		ANativeWindow& aNativeWindow;

	private:
		AndroidSurface( const ANativeWindow& aNativeWindow_ );
	};
}
#endif