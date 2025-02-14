
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// check o your function prototypes and function declarations esp parameters.
// try adding a velocity atttribute --> for the difficulty level.
// movement of left paddle should be relative to the y position f the ball.
// reeview logic logic to prevent ball from sticking to edges.
// right paddle moves if ball in the right region only.
// set game difficulty and refine the game AI..
// announce winner at the end of the game.

typedef struct PlayerAttr {
  char name[11];
  int score;
} Player;

typedef struct PaddleAttr {
  int posx;
  int posy;
  int paddlewidth;
  int paddleheight;
} Paddle;

typedef struct CircleAttr {
  int center_x;
  int center_y;
  int radius;
  int velocity_y;
  int velocity_x;
} Circle;

// function prototypes
void right_paddleAI(Paddle *paddle_right, Paddle paddle_left, Circle game_ball,
                    bool collision, int width);
void DrawGameScene(Paddle left, Paddle right, Circle ball, int height,
                   int width, char *player_score, char *computer_score);
int move_right_paddle(Paddle right, int height, int width, Circle game_ball);
bool check_for_collision(Paddle left, Paddle *right, Circle game_ball);
void setGameAttributes(void);
void displayWinner(Player player1, Player computer);

// main logic
int main(void) {
  //int pos_y = 0;
  //int pos_x;
  char name[11];
  char player1_score[20];
  char computer_score[20];

  Player computer = {.name = "computer", .score = 00};
  Player player1;

  printf("Enter name to use in the game : ");
  fgets(name, 10, stdin);
  strcpy(player1.name, name);

  player1.score = 00;

  InitWindow(1000, 600, "Pong game");
  SetTargetFPS(60);

  int width = GetScreenWidth();
  int height = GetScreenHeight();
  bool collision;

  Paddle paddle_left = {.posx = 10,
                        .posy = ((height / 2) - 60),
                        .paddlewidth = 20,
                        .paddleheight = 120};
  Paddle paddle_right = {.posx = (width - 30),
                         .posy = ((height / 2) - 60),
                         .paddlewidth = 20,
                         .paddleheight = 120};
  Circle game_ball = {.center_x = (width / 2),
                      .center_y = (height / 2),
                      .radius = 10,
                      .velocity_y = 3,
                      .velocity_x = 3};

  // game loop.
  while (!WindowShouldClose()) {

    ClearBackground(BLACK);

    if ((IsKeyDown(KEY_UP) && paddle_left.posy > 0) || (paddle_left.posy >= (height - 60))) {
      paddle_left.posy -= 5;

    } else if (IsKeyDown(KEY_DOWN) && paddle_left.posy < (height - 80)) {
      paddle_left.posy += 5;
    }

    game_ball.center_x += game_ball.velocity_x;
    game_ball.center_y += game_ball.velocity_y;

    collision = check_for_collision(paddle_left, &paddle_right, game_ball);

    if (game_ball.center_x >= (width - game_ball.radius)) {
      game_ball.center_x = width - game_ball.radius;
      game_ball.velocity_x *= -1;
      player1.score++;

    } else if (game_ball.center_x <= 0) {
      game_ball.velocity_x *= -1;
      computer.score++;

    } else if (game_ball.center_y <= 0) {
      game_ball.velocity_y *= -1;

    } else if (game_ball.center_y >= (height - game_ball.radius)) {
      game_ball.center_y = height - game_ball.radius;
      game_ball.velocity_y *= -1;

    } else if (collision) {
      game_ball.velocity_x *= -1;

    } else if ((game_ball.center_x == 0 && collision) ||
               (game_ball.center_x >= (width - game_ball.radius) &&
                collision)) {
      game_ball.center_x = width / 2;
      game_ball.center_y = height / 2;
    }

    right_paddleAI(&paddle_right, paddle_left, game_ball, collision, width);

    sprintf(player1_score, "%s : %d", player1.name, player1.score);
    sprintf(computer_score, "%s : %d", computer.name, computer.score);

    DrawGameScene(paddle_left, paddle_right, game_ball, height, width,
                  player1_score, computer_score);
  }

  displayWinner(player1, computer);

  CloseWindow();

  return 0;
}

void DrawGameScene(Paddle paddle_left, Paddle paddle_right, Circle game_ball,
                   int height, int width, char *player_score,
                   char *computer_score) {

  BeginDrawing();
  DrawRectangle(paddle_left.posx, paddle_left.posy, paddle_left.paddlewidth,
                paddle_left.paddleheight, BEIGE);

  DrawLine((width / 2), 0, (width / 2), height, YELLOW);

  DrawRectangle(paddle_right.posx, paddle_right.posy, paddle_right.paddlewidth,
                paddle_right.paddleheight, LIGHTGRAY);

  DrawCircle(game_ball.center_x, game_ball.center_y, game_ball.radius,
             RAYWHITE);
  DrawText(player_score, 40, 10, 20, BEIGE);
  DrawText(computer_score, (width - 200), 10, 20, WHITE);
  EndDrawing();
}

bool check_for_collision(Paddle paddle_left, Paddle *paddle_right,
                         Circle game_ball) {
  Vector2 circle_center = {game_ball.center_x, game_ball.center_y};
  Rectangle left_paddle = {paddle_left.posx, paddle_left.posy,
                           paddle_left.paddlewidth, paddle_left.paddleheight};
  Rectangle right_paddle = {paddle_right->posx, paddle_right->posy,
                            paddle_right->paddlewidth,
                            paddle_right->paddleheight};

  if (CheckCollisionCircleRec(circle_center, game_ball.radius, left_paddle)) {
    return true;
  } else if (CheckCollisionCircleRec(circle_center, game_ball.radius,
                                     right_paddle)) {
    return true;
  } else {
    return false;
  }
}

void right_paddleAI(Paddle *paddle_right, Paddle paddle_left, Circle game_ball,
                    bool collision, int width) {
  if (game_ball.center_x >= (0.75 * width) &&
      paddle_right->posy < game_ball.center_y) {
    paddle_right->posy += 5;
  } else if (game_ball.center_x >= (0.75 * width) &&
             paddle_right->posy == game_ball.center_y) {
    paddle_right->posy = game_ball.center_y;
  } else if (game_ball.center_x >= (0.75 * width) &&
             paddle_right->posy > game_ball.center_y) {
    paddle_right->posy -= 5;
  } else if (check_for_collision(paddle_left, paddle_right, game_ball)) {
    paddle_right->posy = paddle_right->posy;
  }
}

void displayWinner(Player player1, Player computer) {

  while (1) {
    ClearBackground(BLACK);
    BeginDrawing();

    DrawText(">><< Press <Esc> to quit >><<", 200, 100, 40, MAGENTA);

    if (player1.score > computer.score) {
      DrawText("YOU WON!!", 400, 300, 40, BLUE);
    } else if (player1.score < computer.score) {
      DrawText("YOU LOST!!", 400, 300, 40, RED);
    } else if (player1.score == computer.score) {
      DrawText("ITS A TIE!!", 400, 300, 40, BEIGE);
    }
    EndDrawing();
    if (IsKeyPressed(KEY_ESCAPE))
      break;
  }
}
