import { spawn } from 'child_process';
import * as path from 'path';

const exePath = process.argv[2];
if (!exePath) {
	console.error('No executable provided');
	process.exit(1);
}
const absolutePath = path.resolve(exePath);
const times = process.argv[3] ? Number(process.argv[3]) : 10;

async function runLoop() {
	for (let i = 0; i < times; i++) {
		console.log(`\n---- Round ${i} ----`);
		try {
			await new Promise((resolve, reject) => {
				const child = spawn(absolutePath, [], { // args=[]
					stdio: 'inherit',	// 继承父进程的 stdio
					shell: false,		// 不通过 shell，直接启动 exe
				});
				child.on('exit', (code) => {
					if (code !== 0) {
						console.warn(`Exited with ${code}`);
						reject(null);
					}
					resolve(null);
				});
			});
		} catch (err) {
			console.error(`The .exe exited with error: `, err);
			break;
		}
	}
	console.log(`\nFinished ${times} rounds.`);
}

runLoop();