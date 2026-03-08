*Algorithm competition practicing repo. Using C++ 17. (`.vscode/` contains configuration of F9~F11 for VSCode similar to Dev-C++, and an extra `Ctrl+F10` to loop running.)*

## VSCode Configuration for C++ Algorithm Competition

Prerequisites:
- Bun ([bun.sh](bun.sh)) in your computer, for looping running a compiled .exe file. (Or anything you like. :\) If you do not need this feature, you can skip this.)
- gcc/g++ in your computer and added to the path in environment variables.
- ~~Have VSCode (or other similar pow4 text editor) installed,~~ and copy the contents of `.vscode/keybindings.not-here.json` to your favorite `keybindings.json`:

	If you are not using "Profiles" feature in VSCode, then the target keybindings.json is in:
	- `%APPDATA%\Code\User` (Windows),
	- `~/.config/Code/User` (Linux),
	- `~/Library/Application Support/Code/User` (MacOS, not sure because I does not have one :\( ). 
	
	If you are using a VSCode Profile, then paste it to the keybindings in `(your path above)/profiles/(a string of number representing your target profile)`.