#include <napi.h>
#include "./idesktopwallpaper.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    return IDesktopWallpaperAPI::Init(env, exports);
}

NODE_API_MODULE(win32addon, InitAll)
