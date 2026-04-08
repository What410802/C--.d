*Algorithm competition practicing repo. Supports C++ & Python in VSCode. (`.vscode/` contains configuration of F9~F11 for VSCode similar to Dev-C++, and an extra `Ctrl+F10` to loop running.)*

## VSCode Configuration for Algorithm Competition (C++ any / Python 3)

### Features

+ Using this configuration set, you can use VSCode to write, compile and run C++/Python codes easily! (`F9`: Compile. `F10`: Run. `F11`: Compile & Run.)
+ You can customize compiling options for different OJ: modifying `Utility.d/compile_opts.toml` is enough. (The corresponding `.exe` compiled by Rust will do the rest of the work.)

### Prerequisites
- Bun installed on your computer, for looping running. (Or anything you like. :\) If you do not need this feature, you can skip this.)
	- Install Bun ([<img src="README_assets/bun.svg" style="height: 1em; vertical-align: text-bottom;"><img src="README_assets/bun_text.png" style="height: 1em; vertical-align: text-bottom;"> bun.sh](https://bun.sh));
	- `cd Utility.d` and `bun install`.
- gcc/g++ in your computer and added to the path in environment variables, if you use C++.
- ~~Having VSCode installed.~~ Copy the contents of `.vscode/keybindings.not-here.json` to your favorite `keybindings.json`:

	If you are not using "Profiles" feature in VSCode, then the target keybindings.json is in:
	- `%APPDATA%\Code\User` (Windows),
	- `~/.config/Code/User` (Linux),
	- `~/Library/Application Support/Code/User` (MacOS, not sure because I does not have one :\( ). 
	
	If you are using a VSCode Profile, then paste it to the keybindings in `(your path above)/profiles/(a string of number representing your target profile)`.
- Enable `config`'s `BiS.Dev-C++-hotkeys.enabled`: Open `settings.json` in the same directory with `keybindings.json`. Add one line in the outmost `{}`:
```json
    "BiS.Dev-C++-hotkeys.enabled": true,
```
- If you are using Linux, don't forget to re-compile (`cargo b -r`) the `Utility.d/Rusts.d/compile_selector` project to `Utility.d/compile_selector.exe`. (If you are unfamiliar with that, go to `rustup.rs` and get your hands on Rust! :\) ) Then move the compiled `Utility.d/Rusts.d/compile_selector/target/release/compile_selector` to `Utility.d/compile_selector.exe`. (You can also run `git update-index --skip-worktree Utility.d/compile_selector.exe` to skip tracking this file.)
<!-- add execution permission to `Utility.d/compile_selector.exe`, like `chmod +x {path to the .exe}`. -->

### Usage
- To start with, copy the things inside `.vscode/keybindings.not-here.json` as <a href="#prerequisites">Prerequisites</a> describes.
- For Python input, after inputting all the data needed, use `Ctrl+Z` to put an end to the input stream. (`Enter` is needed before and after the `Ctrl+Z`.)
- To add more OJs and their C++ standard, just append them to `Utility.d/compile_opts.toml`.