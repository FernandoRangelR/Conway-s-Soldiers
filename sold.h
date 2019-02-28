#include <stdio.h>
#include <string.h>
#include <assert.h>

#define HEIGHT 8
#define WIDTH 7
#define NUMBOARDS 10000000
#define TILE 'x'
#define EMPTY '.'
#define IMPOSSIBLE -1

struct board{
  char board[HEIGHT][WIDTH];
  int parent_board;
};

typedef struct board Board;

struct conways_soldiers{
  Board boards_array[NUMBOARDS];
  int solution_board;
};

typedef struct conways_soldiers Conways_soldiers;

void initialise_board(Conways_soldiers *conways_soldiers);
int game(Conways_soldiers *conways_soldiers, int row, int column);
int rules_move_right(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
void move_right(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
int rules_move_left(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
void move_left(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
int rules_move_up(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
void move_up(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element);
void print_solution(Conways_soldiers *conways_soldiers, int board_number);

void test_all(Conways_soldiers *conways_soldiers);
