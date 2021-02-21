#include "Win32Surface.hpp"

namespace stellar {
	Win32Surface::Win32SurfaceBuilder::Win32SurfaceBuilder( const Instance& instance_, const HWND& hwnd_ ) {
		derivedUniqueObject = std::unique_ptr<Win32Surface>( new Win32Surface( instance_, hwnd_ ) );
	}

	Win32Surface::Win32SurfaceBuilder& Win32Surface::Win32SurfaceBuilder::set_hinstance( const HINSTANCE& hInstance_ ) {
		derivedUniqueObject->hInstance = hInstance_;
		return *this;
	}

	Win32Surface&& Win32Surface::Win32SurfaceBuilder::build() {
		auto ci = init_create_info<vk::Win32SurfaceCreateInfoKHR>()
			.setHwnd( derivedUniqueObject->hWnd )
			.setHinstance( derivedUniqueObject->hInstance );

		derivedUniqueObject->uniqueObject = derivedUniqueObject->instance.get_unique_object()->createWin32SurfaceKHRUnique( ci );
		return std::move( *derivedUniqueObject );
	}

	const HWND& Win32Surface::get_hwnd() const {
		return hWnd != nullptr ? hWnd : nullptr;
	}

	const HINSTANCE& Win32Surface::get_hinstance() const {
		return hInstance != nullptr ? hInstance : nullptr;
	}

	Win32Surface::Win32Surface( const Instance& instance_, const HWND& hWnd_ ) :
		instance( instance_ ),
		hWnd( hWnd_ ),
		hInstance( nullptr ){}
}

