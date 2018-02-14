#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  if(m->lastcol == m->cols){
    grow_matrix(m, lastcol * 2);
  }
  
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
}





void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

 int xnow,ynow,d,a,b;

  if(x0 > x1){
    int tmp = x1;
    x1 = x0;
    x0 = tmp;
    tmp = y1;
    y1 = y0;
    y0 = tmp;
  }
  
  a = y1 - y0;
  b = x0 - x1;
  d = (2*a) + b;
  xnow = x0;
  ynow = y0;
  //printf("%d ",d);

  if(y1 - y0 >= 0 && abs(a) <= abs(b)){
    //printf("octet 1 code \n");
     while(xnow <= x1){
      plot(s,c,xnow,ynow);
      if(d > 0){
	ynow++;
	d += (2*b);
      }
      xnow++;
      d += (2*a);
      
      //printf("%d ", xnow);
     }
  }

  else if(y1 - y0 >= 0 && abs(b) <= abs(a)){
    //printf("octet 2 code \n");
    while(ynow <= y1){
      plot(s,c,xnow,ynow);
      if(d < 0){
	xnow++;
	d += (2*a);
      }
      ynow++;
      d += (2*b);
      
      //printf("%d ", ynow);
    }
  }

  else if(y1 - y0 <= 0 && abs(b) <= abs(a)){
    //printf("octet 7 code \n");
    while(ynow >= y1){
      plot(s,c,xnow,ynow);
      if(d < 0){
	xnow++;
	d -= (2*a);
      }
      ynow--;
      d += (2*b);
      
      //printf("%d ", ynow);
    }
  }

  else{
    //printf("octet 8 code \n");
    while(xnow <= x1){
      plot(s,c,xnow,ynow);
      if(d > 0){
	ynow--;
	d += (2*b);
      }
      xnow++;
      d -= (2*a);
      
      //printf("%d ", xnow);
     }
  }
} //end draw_line
