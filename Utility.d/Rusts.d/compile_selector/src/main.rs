use serde::Deserialize;
use std::collections::HashMap;
use std::env;
use std::fs;
use std::process::{Command, exit};

#[derive(Debug, Deserialize)]
struct Config {
	opts: HashMap<String, String>,
}

fn main() {
	let args: Vec<String> = env::args().collect();
	if args.len() != 4 {
		eprintln!("Usage: {} <workspace> <source_file> <output_exe>", args[0]);
		exit(1);
	}

	let workspace = &args[1];
	let source = &args[2];
	let output = &args[3];

	// 读配置文件，需要与可执行文件同目录
	let config_path = env::current_exe()
		.expect("failed to get exe path")
		.parent()
		.expect("exe has no parent")
		.join("compile_opts.toml");

	let config_content = fs::read_to_string(&config_path)
		.expect("failed to read compile_opts.toml");

	let config: Config = toml::from_str(&config_content)
		.expect("failed to parse compile_opts.toml");

	// By default -std=c++17
	let opts = config.opts
		.get(workspace.as_str())
		.map(|s| s.as_str())
		.unwrap_or("-std=c++17");
	
	let status = Command::new("g++")
		.arg("-lm")
		.arg("-Wpedantic")
		.arg("-Wall")
		.arg("-Wextra")
		.args(opts.split_whitespace())
		.arg("-o")
		.arg(output)
		.arg(source)
		.status()
		.expect("failed to execute g++");

	exit(status.code().unwrap_or(1));
}