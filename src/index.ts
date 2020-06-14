// const testAddon = require('../addons');

// import * as win32addon from '../addons/idesktopwallpaper';

import {IDesktopWallpaper} from '../addons';

console.log(IDesktopWallpaper.GetMonitorDevicePathCount().output);

// console.log(testAddon.GetMonitorDevicePathCount());
// console.log(testAddon.GetMonitorDevicePathAt(0));
// const monID = testAddon.GetMonitorDevicePathAt(0).output;
// console.log(testAddon.GetWallpaper(monID));

// testAddon.SetWallpaper(monID, "C:\\Users\\Michael Galliers\\Desktop\\wallpaper.jpg");
// console.log(testAddon.GetPosition());

// testAddon.SetPosition("DWPOS_FIT");

function GetMonitorDevicePathCount(): number {
    
}

export * from '../addons';
