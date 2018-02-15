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

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  edges = new_matrix(4, 4);
  add_edge(edges,40,0,0,30,10,0);
  add_edge(edges,30,10,0,20,30,0);
  add_edge(edges,20,30,0,20,60,0);
  add_edge(edges,20,60,0,30,80,0);
  add_edge(edges,30,80,0,50,90,0);
  add_edge(edges,50,90,0,70,90,0);
  add_edge(edges,70,90,0,90,80,0);
  add_edge(edges,90,80,0,100,60,0);
  add_edge(edges,100,60,0,100,30,0);
  add_edge(edges,100,30,0,90,10,0);
  add_edge(edges,90,10,0,80,0,0);
  add_edge(edges,80,0,0,40,0,0);

  print_matrix(edges);
  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );
}
