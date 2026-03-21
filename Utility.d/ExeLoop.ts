import { spawn } from 'child_process';
import * as path from 'path';

const fileNoExtension = (process.argv[2] as string).toLowerCase(), fileExtname = (process.argv[3] as string).toLowerCase();

function oneTime(command: string, parameters: string[]): Promise<Number> {
	return new Promise((resolve, reject) => {
		const child = spawn(command, parameters, {
			stdio: 'inherit',	// 继承父进程的 stdio
			shell: false,		// 不通过 shell，直接启动 exe
		});
		child.on('exit', (code: Number) => {
			if (code !== 0) {
				console.warn(`Exited with ${code}`);
				reject(code);
			}
			resolve(code);
		});
	});
}

const times = process.argv[4] ? Number(process.argv[4]) : Infinity;
async function runLoop(fileNoExtension: string, fileExtname: string): Promise<void> {
	switch (fileExtname) {
		case ".cpp": {
			const fullFilePath = path.resolve(fileNoExtension+".exe");
			console.log(`Running C++ ...`);
			let i = 0;
			for (; i < times; i++) {
				console.log(`\n---- Round ${i} ----`);
				try {
					await oneTime(fullFilePath, []);
				} catch (err) {
					console.error(`${fullFilePath} exited with error: \n`, err);
					break;
				}
			}
			console.log(`\nFinished ${i} rounds.`);
		} break;
		case ".py": {
			const fullFilePath = path.resolve(fileNoExtension+fileExtname);
			console.log(`Running Python ...`);
			let i = 0;
			for(; i < times; i++){
				console.log(`\n---- Round ${i} ----`);
				try {
					await oneTime("python3", [fullFilePath]);
				} catch (err) {
					console.error(`${fullFilePath} exited with error: \n`, err);
					break;
				}
			}
			console.log(`\nFinished ${i} rounds.`);
		} break;
		default: {
			console.log(`Programming language (${fileExtname}) not supported. Exiting...`);
		}
	}
}
runLoop(fileNoExtension, fileExtname);