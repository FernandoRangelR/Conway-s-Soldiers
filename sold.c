#include "sold.h"

int main(int argc, char *argv[]){
  int row, column, solution_board;
  static Conways_soldiers conways_soldiers;

  (void)argc;
  sscanf(argv[1], "%d", &row);
  sscanf(argv[2], "%d", &column);

  if(row > HEIGHT || column > WIDTH || row < 0 || column < 0){
    printf("ERROR. Input location not valid.\n");
    return 0;
  }

  if(row >= (HEIGHT/2)){
    printf("ERROR. Input location already occupied by a tile.\n");
    return 0;
  }

  initialise_board(&conways_soldiers);
  game(&conways_soldiers, row, column);
  test_all(&conways_soldiers);
  solution_board = conways_soldiers.solution_board;
  if(solution_board == IMPOSSIBLE){
    printf("WARNING. Impossible to get tile to desired location.\n");
    return 0;
  }

  print_solution(&conways_soldiers, solution_board);
  while(solution_board != 0){
    solution_board = conways_soldiers.boards_array[solution_board].parent_board;
    print_solution(&conways_soldiers, solution_board);
  }

  return 0;
}

void initialise_board(Conways_soldiers *conways_soldiers){
  int row, column;

  /*Initialise upper half of the board*/
  for(row = 0; row < HEIGHT/2; row++){
    for(column = 0; column < WIDTH; column++){
      (*conways_soldiers).boards_array[0].board[row][column] = EMPTY;
    }
  }
  /*Initialise lower half of the board*/
  while(row < HEIGHT){
    for(column = 0; column < WIDTH; column++){
      (*conways_soldiers).boards_array[0].board[row][column] = TILE;
    }
    row++;
  }
}

int game(Conways_soldiers *conways_soldiers, int row, int column){
  int current_board = 0;
  int next_available_array_element = 1, x, y;

  for(current_board = 0; next_available_array_element < NUMBOARDS; current_board++){
    for(x = 0; x < HEIGHT; x++){
      for(y = 0; y < WIDTH; y++){
        next_available_array_element += rules_move_right(conways_soldiers, x, y, current_board, next_available_array_element);
        if(((*conways_soldiers).boards_array[next_available_array_element-1].board[row][column]) == TILE){
          (*conways_soldiers).solution_board = next_available_array_element-1;
          return 0;
        }
        next_available_array_element += rules_move_left(conways_soldiers, x, y, current_board, next_available_array_element);
        if(((*conways_soldiers).boards_array[next_available_array_element-1].board[row][column]) == TILE){
          (*conways_soldiers).solution_board = next_available_array_element-1;
          return 0;
        }
        next_available_array_element += rules_move_up(conways_soldiers, x, y, current_board, next_available_array_element);
        if(((*conways_soldiers).boards_array[next_available_array_element-1].board[row][column]) == TILE){
          (*conways_soldiers).solution_board = next_available_array_element-1;
          return 0;
        }
      }
    }
  }
  (*conways_soldiers).solution_board = IMPOSSIBLE;
  return 0;
}

int rules_move_right(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  int last_column = WIDTH - 1;
  if((*conways_soldiers).boards_array[current_board].board[x][y] == EMPTY){
    return 0;
  }
  if(y == last_column || y == last_column - 1){
    return 0;
  }
  if((*conways_soldiers).boards_array[current_board].board[x][y+1] == TILE){
    if((*conways_soldiers).boards_array[current_board].board[x][y+2] == EMPTY){
      move_right(conways_soldiers, x, y, current_board, next_available_array_element);
      return 1;
    }
  }
  return 0;
}

void move_right(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  (*conways_soldiers).boards_array[next_available_array_element] = (*conways_soldiers).boards_array[current_board];
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y+1] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y+2] = TILE;
  (*conways_soldiers).boards_array[next_available_array_element].parent_board = current_board;
}

int rules_move_left(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  int first_column = 0;

  if((*conways_soldiers).boards_array[current_board].board[x][y] == EMPTY){
    return 0;
  }
  if(y == first_column || y == first_column + 1){
    return 0;
  }
  if((*conways_soldiers).boards_array[current_board].board[x][y-1] == TILE){
    if((*conways_soldiers).boards_array[current_board].board[x][y-2] == EMPTY){
      move_left(conways_soldiers, x, y, current_board, next_available_array_element);
      return 1;
    }
  }
  return 0;
}

void move_left(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  (*conways_soldiers).boards_array[next_available_array_element] = (*conways_soldiers).boards_array[current_board];
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y-1] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y-2] = TILE;
  (*conways_soldiers).boards_array[next_available_array_element].parent_board = current_board;
}

int rules_move_up(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  int first_row = 0;

  if((*conways_soldiers).boards_array[current_board].board[x][y] == EMPTY){
    return 0;
  }
  if(x == first_row || x == first_row + 1){
    return 0;
  }
  if((*conways_soldiers).boards_array[current_board].board[x-1][y] == TILE){
    if((*conways_soldiers).boards_array[current_board].board[x-2][y] == EMPTY){
      move_up(conways_soldiers, x, y, current_board, next_available_array_element);
      return 1;
    }
  }
  return 0;
}

void move_up(Conways_soldiers *conways_soldiers, int x, int y, int current_board, int next_available_array_element){
  (*conways_soldiers).boards_array[next_available_array_element] = (*conways_soldiers).boards_array[current_board];
  (*conways_soldiers).boards_array[next_available_array_element].board[x][y] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x-1][y] = EMPTY;
  (*conways_soldiers).boards_array[next_available_array_element].board[x-2][y] = TILE;
  (*conways_soldiers).boards_array[next_available_array_element].parent_board = current_board;
}

void print_solution(Conways_soldiers *conways_soldiers, int board_number){
  int x, y;

  for(x = 0; x < HEIGHT; x++){
    for(y = 0; y < WIDTH; y++){
      printf("%c", (*conways_soldiers).boards_array[board_number].board[x][y]);
    }
    printf("\n");
  }
  printf("\n");

}
