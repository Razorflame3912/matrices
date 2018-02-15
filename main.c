#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  struct matrix *edges;

  edges = new_matrix(40, 4);
  //ident(edges);
  add_edge(edges,0,10,0,30,40,0);
  add_edge(edges,30,40,0,20,50,0);
  add_edge(edges,20,50,0,0,10,0);
  print_matrix(edges);
  //draw_lines(edges, s, c);
  //display(s);
  free_matrix( edges );
}
