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
**Linux or WSL environments**.
1. The [raylib library](https://github.com/raysan5/raylib?tab=readme-ov-file) and a C compiler of your choice need to be installed .
2. Clone the repository.
```
$ git clone https://github.com/gitnold/pong
$ cd pong
```
3. Make `./install.sh` executable by running the following command.
```
$ chmod +x install.sh
```
4.Run the `install.sh` script.
```
$ ./install.sh
```
Anytime you want to run pong just run `$ ./pong` in your terminal.
## How it works.
The arrow keys are used to control the game paddle and the 'Escape' exits the game.
Failure to return the ball to your opponent results in your opponent gaining a point.
Whoever has the highest score when the game ends wins.
## License.
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
This project uses the Raylib library, which is licensed under the zlib/libpng license. See the [LICENSE_raylib.txt](https://github.com/raysan5/raylib/blob/master/LICENSE "Raylib License") file for details.
## Roadmap(*future features*).
More refined game AI.
Score tracking capabilities.
More refined  graphics and user experience.
Sound effects.
*more to be added later*
