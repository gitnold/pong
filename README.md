# Intro
Welcome to my own implementation of the legacy arcade game Pong.
Pong is a two-dimensional game built to simulate table tennis. It first debuted in 1972
and was created by Allan Alcorn and published by [Atari](https://en.wikipedia.org/wiki/Atari,_Inc) for arcades.
Written in C using [Raylib](https://www.raylib.com/ "Raylib Official Website") as library for the rendering and low level graphics tasks for the terminal.
## Features
Score tracking capabilities
Single player
Basic collision detection
Simple game AI that works(*most of the time!*).
## Installation
### Manual Installation.
1. The [raylib library](https://github.com/raysan5/raylib?tab=readme-ov-file) and a C compiler of your choice need to be installed .
**Linux or WSL environments**.
1. Clone the repository.
```
$ git clone https://github.com/gitnold/pong.git
$ cd pong
```
2. Make `./install.sh` executable by running the following command.
```
$ chmod +x install.sh
```
3.Run the `install.sh` script.
```
$ ./install.sh
```
Anytime you want to run pong just run `$ ./pong` in your terminal where your executable is located.
**Windows.**
1.Compile the executable using a compiler of your choice.Below is an example using [gcc](https://gcc.gnu.org/install/download.html "Gcc installation page")
```
$ gcc -o pong.exe pong.c -lraylib -lgdi32 -lwinmm
```
2.Run the executable.
```
$ ./pong.exe
```
### Binary Releases.
**Windows**.
Navigate to the [releases](https://github.com/gitnold/pong/releases "Releases page") page and download the precompiled binaries. All binaries are statically linked and require no external dependencies.
## How it works.
The arrow keys are used to control the game paddle and the 'Escape' exits the game.
Failure to return the ball to your opponent results in your opponent gaining a point.
Whoever has the highest score when the game ends wins.
![image](https://github.com/user-attachments/assets/a1e6d349-c5ad-4fd9-9b45-e71a918a1a14)

## License.
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
This project uses the Raylib library, which is licensed under the zlib/libpng license. See the [LICENSE_raylib.txt](https://github.com/raysan5/raylib/blob/master/LICENSE "Raylib License") file for details.
## Roadmap(*future features*).
More refined game AI.
Score tracking capabilities.
More refined  graphics and user experience.
Sound effects.
Cross platform builds.
*more to be added later*
