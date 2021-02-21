#pragma once

#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR

#include "UniqueObject.hpp"
#include "Instance.hpp"

namespace stellar {
	using UOWin32Surface = UniqueObject<vk::UniqueSurfaceKHR, vk::SurfaceKHR, vk::Win32SurfaceCreateFlagsKHR>;
	class Win32Surface : public UOWin32Surface {
	public:
		class Win32SurfaceBuilder : public Builder<Win32SurfaceBuilder, Win32Surface> {
		public:
			Win32SurfaceBuilder( const Instance& instance_, const HWND& hWnd_ );

			Win32SurfaceBuilder& set_hinstance( const HINSTANCE& hInstance_ );

			Win32Surface&& build() override;
		};

	protected:
		const Instance& instance;
		HWND hWnd;
		HINSTANCE hInstance;

	public:
		const HWND& get_hwnd() const;

		const HINSTANCE& get_hinstance() const;

	private:
		Win32Surface( const Instance& instance_, const HWND& hWnd_ );
	};
}

#endif