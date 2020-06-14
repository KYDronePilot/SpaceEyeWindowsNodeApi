import {IDesktopWallpaper} from '../addons';
import {IDesktopReturnObject} from '../addons/idesktopwallpaper';

// enum HResult {
//     S_OK,            // Operation successful
//     S_FALSE,         // Succeeded, with a caveat
//     E_NOTIMPL,       // Not implemented
//     E_NOINTERFACE,   // No such interface supported
//     E_POINTER,       // Pointer that is not valid
//     E_ABORT,         // Operation aborted
//     E_FAIL,          // Unspecified failure
//     E_UNEXPECTED,    // Unexpected failure
//     E_ACCESSDENIED,  // General access denied error
//     E_HANDLE,        // Handle that is not valid
//     E_OUTOFMEMORY,   // Failed to allocate necessary memory
//     E_INVALIDARG,    // One or more arguments are not valid
// }
//
// const HResultToEnum = {
//     0x00000000: HResult.S_OK,
//     0x00000001: HResult.S_FALSE,
//     0x80004001: HResult.E_NOTIMPL,
//     0x80004002: HResult.E_NOINTERFACE,
//     0x80004003: HResult.E_POINTER,
//     0x80004004: HResult.E_ABORT,
//     0x80004005: HResult.E_FAIL,
//     0x8000FFFF: HResult.E_UNEXPECTED,
//     0x80070005: HResult.E_ACCESSDENIED,
//     0x80070006: HResult.E_HANDLE,
//     0x8007000E: HResult.E_OUTOFMEMORY,
//     0x80070057: HResult.E_INVALIDARG,
// }
//
// const EnumToHResult = {
//     [HResult.S_OK]: 0x00000000,
//     [HResult.S_FALSE]: 0x00000001,
//     [HResult.E_NOTIMPL]: 0x80004001,
//     [HResult.E_NOINTERFACE]: 0x80004002,
//     [HResult.E_POINTER]: 0x80004003,
//     [HResult.E_ABORT]: 0x80004004,
//     [HResult.E_FAIL]: 0x80004005,
//     [HResult.E_UNEXPECTED]: 0x8000FFFF,
//     [HResult.E_ACCESSDENIED]: 0x80070005,
//     [HResult.E_HANDLE]: 0x80070006,
//     [HResult.E_OUTOFMEMORY]: 0x8007000E,
//     [HResult.E_INVALIDARG]: 0x80070057,
// }

class HResultError extends Error {
    constructor(error: number) {
        super(error.toString());
        Object.setPrototypeOf(this, new.target.prototype);
    }
}

enum WallpaperPosition {
    center = 'DWPOS_CENTER',
    tile = 'DWPOS_TILE',
    stretch = 'DWPOS_STRETCH',
    fit = 'DWPOS_FIT',
    fill = 'DWPOS_FILL',
    span = 'DWPOS_SPAN',
    error = 'ERROR',
}

function checkResultAndThrowError(result: number) {
    if (result < 0)
        throw new HResultError(result);
}

/**
 * Check if there was an error when calling the native function, throwing if so.
 * @param result - The native result to check
 */
function checkResultsAndThrowError<RT>(result: IDesktopReturnObject<RT>) {
    checkResultAndThrowError(result.co_init);
    checkResultAndThrowError(result.co_create);
    checkResultAndThrowError(result.wall_res);
}

function GetMonitorDevicePathCount(): number {
    const res = IDesktopWallpaper.GetMonitorDevicePathCount();
    checkResultsAndThrowError(res);
    return res.output;
}

function GetMonitorDevicePathAt(monitorIndex: number): string {
    const res = IDesktopWallpaper.GetMonitorDevicePathAt(monitorIndex);
    checkResultsAndThrowError(res);
    return res.output;
}

function GetWallpaper(monitorId: string): string {
    const res = IDesktopWallpaper.GetWallpaper(monitorId);
    checkResultsAndThrowError(res);
    return res.output;
}

function SetWallpaper(monitorId: string, wallpaperPath: string) {
    const res = IDesktopWallpaper.SetWallpaper(monitorId, wallpaperPath);
    checkResultsAndThrowError(res);
}

function GetPosition(): WallpaperPosition {
    const res = IDesktopWallpaper.GetPosition();
    checkResultsAndThrowError(res);
    return res.output as WallpaperPosition;
}
function SetPosition(position: WallpaperPosition) {
    const res = IDesktopWallpaper.SetPosition(position);
    checkResultsAndThrowError(res);
}

module.exports = {
    IDesktopWallpaper: {
        GetMonitorDevicePathCount,
        GetMonitorDevicePathAt,
        GetWallpaper,
        SetWallpaper,
        GetPosition,
        SetPosition,
        WallpaperPosition,
    }
}
