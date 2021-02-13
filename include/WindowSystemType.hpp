#pragma once

namespace stellar {
	enum class WindowSystemType {
		Android,
		Wayland,
		Windows,
		XCB,
		XLib,
		DirectFB,
		GoogleGames,
		iOS,
		macOS,
		VI,
		Fuchsia,
		Metal
	};
}