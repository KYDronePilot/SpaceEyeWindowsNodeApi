export interface IDesktopReturnObject<OT> {
    output: OT
    wall_res: number
    co_init: number
    co_create: number
}

export function GetMonitorDevicePathCount(): IDesktopReturnObject<number>;
export function GetMonitorDevicePathAt(monitorIndex: number): IDesktopReturnObject<string>;
export function GetWallpaper(monitorId: string): IDesktopReturnObject<string>;
export function SetWallpaper(monitorId: string, wallpaperPath: string): IDesktopReturnObject<number>;
export function GetPosition(): IDesktopReturnObject<string>;
export function SetPosition(position: string): IDesktopReturnObject<number>;
