#include <napi.h>
#include <Windows.h>
#include "ShObjIdl.h"

namespace IDesktopWallpaperAPI {
    void SetupWallpaperPointer(IDesktopWallpaper** p_wallpaper, HRESULT* co_init, HRESULT* co_create);
    void TearDownWallpaperPointer(IDesktopWallpaper* p_wallpaper, HRESULT* co_create);
    Napi::Object GetMonitorDevicePathAt(const Napi::CallbackInfo& info);
    HRESULT _GetMonitorDevicePathCount(UINT *count);
    Napi::Number GetMonitorDevicePathCount(const Napi::CallbackInfo& info);
    HRESULT _GetWallpaper(LPCWSTR monitorID, LPWSTR  *wallpaper);
    Napi::String GetWallpaper(const Napi::CallbackInfo& info);
    HRESULT _SetWallpaper(LPCWSTR monitorID, LPCWSTR  wallpaper);
    void SetWallpaper(const Napi::CallbackInfo& info);
    HRESULT _GetPosition(DESKTOP_WALLPAPER_POSITION *position);
    Napi::String GetPosition(const Napi::CallbackInfo& info);
    HRESULT _SetPosition(DESKTOP_WALLPAPER_POSITION position);
    void SetPosition(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
