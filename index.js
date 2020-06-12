const testAddon = require('./build/Debug/win32addon.node');

console.log(testAddon.GetMonitorDevicePathCount());
console.log(testAddon.GetMonitorDevicePathAt(0));
const monID = testAddon.GetMonitorDevicePathAt(0);
console.log(testAddon.GetWallpaper(monID));

testAddon.SetWallpaper(monID, "C:\\Users\\Michael Galliers\\Desktop\\wallpaper.jpg");
console.log(testAddon.GetPosition());

testAddon.SetPosition("DWPOS_FIT");

module.exports = testAddon;
