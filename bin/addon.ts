import * as fs from 'fs';
import * as path from 'path';

['idesktopwallpaper'].forEach((name: string) => {
  const src: string = path.join(__dirname, `../build/Release/${name}.node`);
  const dest: string = path.join(__dirname, `../src/addons/${name}.node`);

  fs.copyFileSync(src, dest);
});
