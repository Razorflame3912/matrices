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
  struct matrix *edges, *m1, *m2, *m3;

  c.red = MAX_COLOR;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  m1 = new_matrix(4,4);
  ident(m1);
  printf("\n\nPRINTING IDENTITY MATRIX M1:\n\n");
  print_matrix(m1);

  m2 = new_matrix(4,4);
  add_edge(m2,0,0,0,0,1,0);
  add_edge(m2,4,3,0,5,2,0);
  add_edge(m2,2,7,0,3,9,0);
  printf("\n\nPRINTING EDGE MATRIX M2:\n\n");
  print_matrix(m2);
  




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

  add_edge(edges,30,60,0,40,80,0);
  add_edge(edges,40,80,0,50,60,0);
  add_edge(edges,50,60,0,30,60,0);

  add_edge(edges,70,60,0,80,80,0);
  add_edge(edges,80,80,0,90,60,0);
  add_edge(edges,90,60,0,70,60,0);

  add_edge(edges,50,50,0,70,50,0);
  add_edge(edges,70,50,0,60,30,0);
  add_edge(edges,60,30,0,50,50,0);

  add_edge(edges,40,10,0,80,10,0);

  add_edge(edges,30,20,0,40,10,0);
  add_edge(edges,40,10,0,50,20,0);
  add_edge(edges,50,20,0,60,10,0);
  add_edge(edges,60,10,0,70,20,0);
  add_edge(edges,70,20,0,80,10,0);
  add_edge(edges,80,10,0,90,20,0);

  add_edge(edges,50,90,0,40,110,0);
  add_edge(edges,40,110,0,60,120,0);
  add_edge(edges,60,120,0,70,90,0);



  //print_matrix(edges);
  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );
  free_matrix( m1 );
  free_matrix( m2 );
}
