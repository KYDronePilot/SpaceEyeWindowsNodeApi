#include "idesktopwallpaper.h"

HRESULT IDesktopWallpaperAPI::_GetMonitorDevicePathAt(UINT monitorIndex, LPWSTR *monitorPath) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->GetMonitorDevicePathAt(monitorIndex, monitorPath);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

Napi::String IDesktopWallpaperAPI::GetMonitorDevicePathAt(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    UINT monitorIndex = info[0].As<Napi::Number>().Uint32Value();
    LPWSTR monitorPath;
    _GetMonitorDevicePathAt(monitorIndex, &monitorPath);

    std::wstring wstr(monitorPath);
    std::u16string u16str(wstr.begin(), wstr.end());

    auto returnValue = Napi::String::New(env, u16str);
    return returnValue;
}

HRESULT IDesktopWallpaperAPI::_GetMonitorDevicePathCount(UINT *count) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->GetMonitorDevicePathCount(count);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

Napi::Number IDesktopWallpaperAPI::GetMonitorDevicePathCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    UINT monitorCount;
    _GetMonitorDevicePathCount(&monitorCount);

    auto returnValue = Napi::Number::New(env, monitorCount);

    return returnValue;
}

HRESULT IDesktopWallpaperAPI::_GetWallpaper(LPCWSTR monitorID, LPWSTR  *wallpaper) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->GetWallpaper(monitorID, wallpaper);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

Napi::String IDesktopWallpaperAPI::GetWallpaper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::u16string monitorID_u16 = info[0].As<Napi::String>().Utf16Value();
    std::wstring monitorID(monitorID_u16.begin(), monitorID_u16.end());
    LPWSTR wallpaper;
    _GetWallpaper(monitorID.c_str(), &wallpaper);

    std::wstring wstr(wallpaper);
    std::u16string u16str(wstr.begin(), wstr.end());

    auto returnValue = Napi::String::New(env, u16str);

    return returnValue;
}

HRESULT IDesktopWallpaperAPI::_SetWallpaper(LPCWSTR monitorID, LPCWSTR  wallpaper) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->SetWallpaper(monitorID, wallpaper);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

void IDesktopWallpaperAPI::SetWallpaper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::u16string monitorID_u16 = info[0].As<Napi::String>().Utf16Value();
    std::wstring monitorID(monitorID_u16.begin(), monitorID_u16.end());
    std::u16string wallpaper_u16 = info[1].As<Napi::String>().Utf16Value();
    std::wstring wallpaper(wallpaper_u16.begin(), wallpaper_u16.end());
    _SetWallpaper(monitorID.c_str(), wallpaper.c_str());
}

HRESULT IDesktopWallpaperAPI::_GetPosition(DESKTOP_WALLPAPER_POSITION *position) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->GetPosition(position);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

Napi::String IDesktopWallpaperAPI::GetPosition(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    DESKTOP_WALLPAPER_POSITION position;
    _GetPosition(&position);
    std::string enumValue;
    switch (position) {
    case DWPOS_CENTER:
        enumValue = "DWPOS_CENTER";
        break;
    case DWPOS_TILE:
        enumValue = "DWPOS_TILE";
        break;
    case DWPOS_STRETCH:
        enumValue = "DWPOS_STRETCH";
        break;
    case DWPOS_FIT:
        enumValue = "DWPOS_FIT";
        break;
    case DWPOS_FILL:
        enumValue = "DWPOS_FILL";
        break;
    case DWPOS_SPAN:
        enumValue = "DWPOS_SPAN";
        break;
    default:
        enumValue = "ERROR";
        break;
    }

    return Napi::String::New(env, enumValue);
}

HRESULT IDesktopWallpaperAPI::_SetPosition(DESKTOP_WALLPAPER_POSITION position) {
    HRESULT hr = CoInitialize(nullptr);
    IDesktopWallpaper* p_wallpaper = nullptr;
    hr = CoCreateInstance(__uuidof(DesktopWallpaper), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&p_wallpaper));
    p_wallpaper->SetPosition(position);
    p_wallpaper->Release();
    p_wallpaper = NULL;
    return hr;
}

void IDesktopWallpaperAPI::SetPosition(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::u16string position_str_u16 = info[0].As<Napi::String>().Utf16Value();
    std::wstring position_str(position_str_u16.begin(), position_str_u16.end());
    DESKTOP_WALLPAPER_POSITION position;
    if (position_str == L"DWPOS_CENTER") {
        position = DWPOS_CENTER;
    } else if (position_str == L"DWPOS_TILE") {
        position = DWPOS_TILE;
    } else if (position_str == L"DWPOS_STRETCH") {
        position = DWPOS_STRETCH;
    } else if (position_str == L"DWPOS_FIT") {
        position = DWPOS_FIT;
    } else if (position_str == L"DWPOS_FILL") {
        position = DWPOS_FILL;
    } else {
        position = DWPOS_SPAN;
    }
    _SetPosition(position);
}

Napi::Object IDesktopWallpaperAPI::Init(Napi::Env env, Napi::Object exports) {
    exports.Set(
        "GetMonitorDevicePathAt", Napi::Function::New(env, IDesktopWallpaperAPI::GetMonitorDevicePathAt)
    );
    exports.Set(
        "GetMonitorDevicePathCount", Napi::Function::New(env, IDesktopWallpaperAPI::GetMonitorDevicePathCount)
    );
    exports.Set(
        "GetWallpaper", Napi::Function::New(env, IDesktopWallpaperAPI::GetWallpaper)
    );
    exports.Set(
        "SetWallpaper", Napi::Function::New(env, IDesktopWallpaperAPI::SetWallpaper)
    );
    exports.Set(
        "GetPosition", Napi::Function::New(env, IDesktopWallpaperAPI::GetPosition)
    );
    exports.Set(
        "SetPosition", Napi::Function::New(env, IDesktopWallpaperAPI::SetPosition)
    );

    return exports;
}
