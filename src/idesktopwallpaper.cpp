#include "idesktopwallpaper.h"

void IDesktopWallpaperAPI::SetupWallpaperPointer(IDesktopWallpaper** p_wallpaper, HRESULT* co_init, HRESULT* co_create) {
    *co_init = CoInitialize(NULL);
    if (SUCCEEDED(*co_init)) {
        *co_create = CoCreateInstance(__uuidof(DesktopWallpaper), NULL, CLSCTX_ALL, IID_PPV_ARGS(p_wallpaper));
    }
}

void IDesktopWallpaperAPI::TearDownWallpaperPointer(IDesktopWallpaper* p_wallpaper, HRESULT* co_create) {
    if (SUCCEEDED(*co_create)) {
        p_wallpaper->Release();
    }
    p_wallpaper = NULL;
    CoUninitialize();
}

Napi::Object IDesktopWallpaperAPI::GetMonitorDevicePathAt(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    UINT monitorIndex = info[0].As<Napi::Number>().Uint32Value();
    LPWSTR monitorPath = L"";

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->GetMonitorDevicePathAt(monitorIndex, &monitorPath);
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    std::wstring wstr(monitorPath);
    std::u16string u16str(wstr.begin(), wstr.end());

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), Napi::String::New(env, u16str));
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
}

Napi::Object IDesktopWallpaperAPI::GetMonitorDevicePathCount(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    UINT monitorCount = -1;

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->GetMonitorDevicePathCount(&monitorCount);
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), Napi::Number::New(env, monitorCount));
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
}

Napi::Object IDesktopWallpaperAPI::GetWallpaper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::u16string monitorID_u16 = info[0].As<Napi::String>().Utf16Value();
    std::wstring monitorID(monitorID_u16.begin(), monitorID_u16.end());
    LPWSTR wallpaper = L"";

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->GetWallpaper(monitorID.c_str(), &wallpaper);
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    std::wstring wstr(wallpaper);
    std::u16string u16str(wstr.begin(), wstr.end());

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), Napi::String::New(env, u16str));
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
}

Napi::Object IDesktopWallpaperAPI::SetWallpaper(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    std::u16string monitorID_u16 = info[0].As<Napi::String>().Utf16Value();
    std::wstring monitorID(monitorID_u16.begin(), monitorID_u16.end());
    std::u16string wallpaper_u16 = info[1].As<Napi::String>().Utf16Value();
    std::wstring wallpaper(wallpaper_u16.begin(), wallpaper_u16.end());

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->SetWallpaper(monitorID.c_str(), wallpaper.c_str());
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), NULL);
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
}

Napi::Object IDesktopWallpaperAPI::GetPosition(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    DESKTOP_WALLPAPER_POSITION position = DWPOS_CENTER;

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->GetPosition(&position);
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    std::string enumValue = "ERROR";
    if (SUCCEEDED(wall_res)) {
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
    }

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), Napi::String::New(env, enumValue));
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
}

Napi::Object IDesktopWallpaperAPI::SetPosition(const Napi::CallbackInfo& info) {
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

    HRESULT co_init = E_FAIL, co_create = E_FAIL, wall_res = E_FAIL;
    IDesktopWallpaper* p_wallpaper = nullptr;
    SetupWallpaperPointer(&p_wallpaper, &co_init, &co_create);
    if (SUCCEEDED(co_create)) {
        wall_res = p_wallpaper->SetPosition(position);
    }
    TearDownWallpaperPointer(p_wallpaper, &co_create);

    auto obj = Napi::Object::New(env);
    obj.Set(Napi::String::New(env, "output"), NULL);
    obj.Set(Napi::String::New(env, "wall_res"), Napi::Number::New(env, wall_res));
    obj.Set(Napi::String::New(env, "co_init"), Napi::Number::New(env, co_init));
    obj.Set(Napi::String::New(env, "co_create"), Napi::Number::New(env, co_create));
    return obj;
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
