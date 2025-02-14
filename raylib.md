---
title: Pong Game Documentation
description: Documentation for a simple Pong game implemented in C using the Raylib library.
---

# Pong Game Documentation

## Overview

This documentation provides an overview of a simple Pong game implemented in C using the Raylib library. The game features two paddles controlled by the player and the computer, a ball that bounces off the paddles and walls, and a scoring system.

## Game Structure

### Player Attributes

The `PlayerAttr` struct represents the attributes of a player, including their name and score.

```c
typedef struct PlayerAttr {
  char name[11];
  int score;
} Player;
```

### Paddle Attributes

The `PaddleAttr` struct represents the attributes of a paddle, including its position, width, and height.

```c
typedef struct PaddleAttr {
  int posx;
  int posy;
  int paddlewidth;
  int paddleheight;
} Paddle;
```

### Circle Attributes

The `CircleAttr` struct represents the attributes of the ball, including its center position, radius, and velocity.

```c
typedef struct CircleAttr {
  int center_x;
  int center_y;
  int radius;
  int velocity_y;
  int velocity_x;
} Circle;
```

## Function Prototypes

### right_paddleAI

Moves the right paddle based on the ball's position and collision status.

```c
void right_paddleAI(Paddle *paddle_right, Paddle paddle_left, Circle game_ball, bool collision, int width);
```

### DrawGameScene

Draws the game scene, including the paddles, ball, and scores.

```c
void DrawGameScene(Paddle left, Paddle right, Circle ball, int height, int width, char *player_score, char *computer_score);
```

### check_for_collision

Checks for collision between the ball and the paddles.

```c
bool check_for_collision(Paddle left, Paddle *right, Circle game_ball);
```

### displayWinner

Displays the winner of the game.

```c
void displayWinner(Player player1, Player computer);
```

## Main Logic

The main function initializes the game window, sets up the game objects, and runs the game loop.

```c
int main(void) {
  // Initialize game objects and variables
  // Run game loop
  // Display winner
  // Close window
}
```

## Game Loop

The game loop handles input, updates the game state, checks for collisions, and draws the game scene.

```c
while (!WindowShouldClose()) {
  // Handle input
  // Update game state
  // Check for collisions
  // Draw game scene
}
```

## Collision Detection

The `check_for_collision` function checks for collision between the ball and the paddles using the Raylib library's collision detection functions.

```c
bool check_for_collision(Paddle paddle_left, Paddle *paddle_right, Circle game_ball) {
  // Check for collision with left paddle
  // Check for collision with right paddle
  // Return collision status
}
```

## AI for Right Paddle

The `right_paddleAI` function moves the right paddle based on the ball's position and collision status.

```c
void right_paddleAI(Paddle *paddle_right, Paddle paddle_left, Circle game_ball, bool collision, int width) {
  // Move right paddle based on ball position and collision status
}
```

## Display Winner

The `displayWinner` function displays the winner of the game based on the scores of the player and the computer.

```c
void displayWinner(Player player1, Player computer) {
  // Display winner based on scores
}
```

## Conclusion

This documentation provides an overview of the Pong game implemented in C using the Raylib library. The game features two paddles controlled by the player and the computer, a ball that bounces off the paddles and walls, and a scoring system. The game loop handles input, updates the game state, checks for collisions, and draws the game scene. The `check_for_collision` function checks for collision between the ball and the paddles, and the `right_paddleAI` function moves the right paddle based on the ball's position and collision status. The `displayWinner` function displays the winner of the game based on the scores of the player and the computer.