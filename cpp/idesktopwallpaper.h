#include <napi.h>
#include <Windows.h>
#include "ShObjIdl.h"

namespace IDesktopWallpaperAPI {
    void SetupWallpaperPointer(IDesktopWallpaper** p_wallpaper, HRESULT* co_init, HRESULT* co_create);
    void TearDownWallpaperPointer(IDesktopWallpaper* p_wallpaper, HRESULT* co_create);
    Napi::Object GetMonitorDevicePathAt(const Napi::CallbackInfo& info);
    Napi::Object GetMonitorDevicePathCount(const Napi::CallbackInfo& info);
    Napi::Object GetWallpaper(const Napi::CallbackInfo& info);
    Napi::Object SetWallpaper(const Napi::CallbackInfo& info);
    Napi::Object GetPosition(const Napi::CallbackInfo& info);
    Napi::Object SetPosition(const Napi::CallbackInfo& info);

    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
