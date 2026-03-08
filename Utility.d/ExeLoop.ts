import { spawn } from 'child_process';
import * as path from 'path';

const exePath = process.argv[2];
if (!exePath) {
	console.error('请提供可执行文件路径');
	process.exit(1);
}
const absolutePath = path.resolve(exePath);
const times = 10;

async function runLoop() {
	for (let i = 0; i < times; i++) {
		console.log(`\n--- 第 ${i + 1} 次执行 ---`);
		try {
			await new Promise((resolve, reject) => {
				// 使用 spawn 并设置 stdio: 'inherit'
				const child = spawn(absolutePath, [], {
					stdio: 'inherit',   // 关键：直接继承父进程的 stdio
					shell: false,        // 不通过 shell，直接启动 exe
				});

				child.on('error', (err) => {
					console.error('启动进程失败:', err);
					reject(err);
				});

				child.on('exit', (code) => {
					if (code !== 0) {
						console.warn(`进程退出，退出码: ${code}`);
					}
					resolve(null);
				});
			});
		} catch (err) {
			console.error('执行过程中发生错误:', err);
			// 可选择是否中断循环
			// break;
		}
	}
	console.log('\n所有执行完成');
}

runLoop();