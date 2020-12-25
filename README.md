# SpaceEye Windows Node API

Native Windows API for [SpaceEye app](https://github.com/KYDronePilot/SpaceEye),
to set multi-monitor wallpaper images.

## Info

This package utilizes the
[`node-addon-api`](https://github.com/nodejs/node-addon-api) to interface NodeJS
directly with the win32
[IDesktopWallpaper](https://docs.microsoft.com/en-us/windows/win32/api/shobjidl_core/nn-shobjidl_core-idesktopwallpaper)
API in C++, to set the wallpaper on Windows computers. This package is designed
specifically for use with the [SpaceEye
app](https://github.com/KYDronePilot/SpaceEye).

## Related

- [SpaceEye](https://github.com/KYDronePilot/SpaceEye) - The main SpaceEye app
- [space-eye-icons](https://github.com/KYDronePilot/space-eye-icons) - Icons for
  SpaceEye app
- [SpaceEyeSatelliteConfig](https://github.com/KYDronePilot/SpaceEyeSatelliteConfig) -
  Config of available satellite views for SpaceEye app
- [space-eye-mac-node-api](https://github.com/KYDronePilot/space-eye-mac-node-api) -
  Native Mac API for SpaceEye app, to set multi-monitor wallpaper images
