*Algorithm competition practicing repo. Supports C++ & Python in VSCode. (`.vscode/` contains configuration of F9~F11 for VSCode similar to Dev-C++, and an extra `Ctrl+F10` to loop running.)*

## VSCode Configuration for Algorithm Competition (C++ any / Python 3)

Prerequisites:
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

Usage:
- To change the standard of C++, go to `.vscode/tasks.json` and modify `"args"` in the first task (i.e., the compile task).
- For Python, after inputting all the data needed, use `Ctrl+Z` to put an end to the input stream. (`Enter` is needed before and after the `Ctrl+Z`.)
