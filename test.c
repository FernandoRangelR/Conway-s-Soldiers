#include "sold.h"

void test_all(Conways_soldiers *conways_soldiers){
  int upper_half = HEIGHT/2, first_column = 0, last_column = WIDTH, first_row = 0, last_row = HEIGHT, initial_board = 0;

  assert(rules_move_right(conways_soldiers, upper_half, first_column, initial_board, 1) == 0);
  assert(rules_move_left(conways_soldiers, upper_half, first_column, initial_board, 1) == 0);
  assert(rules_move_up(conways_soldiers, upper_half, first_column, initial_board, 1) == 0);

  assert(rules_move_right(conways_soldiers, first_row, last_column, initial_board, 1) == 0);
  assert(rules_move_left(conways_soldiers, first_row, first_column, initial_board, 1) == 0);
  assert(rules_move_up(conways_soldiers, first_row, first_row, initial_board, 1) == 0);

  assert(rules_move_right(conways_soldiers, last_row, first_column, initial_board, 1) == 0);
  assert(rules_move_left(conways_soldiers, last_row, first_column, initial_board, 1) == 0);
  assert(rules_move_up(conways_soldiers, last_row, first_column, initial_board, 1) == 0);
  assert(rules_move_up(conways_soldiers, upper_half + 1, first_column, initial_board, 1) == 1);
  assert(rules_move_up(conways_soldiers, upper_half, first_column, initial_board + 1, 1) == 0);
  assert(rules_move_up(conways_soldiers, upper_half, first_column, WIDTH, 1) == 0);

}
