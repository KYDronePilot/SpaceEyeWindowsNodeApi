#include <napi.h>
#include <Windows.h>
#include "ShObjIdl.h"

namespace IDesktopWallpaperAPI {
    HRESULT _GetMonitorDevicePathAt(UINT monitorIndex, LPWSTR *monitorPath);
    Napi::String GetMonitorDevicePathAt(const Napi::CallbackInfo& info);
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
