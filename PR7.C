#include <stdio.h>
#include <graphics.h>

// Function for 2D Translation
void translate(int x, int y, int tx, int ty, int *new_x, int *new_y) {
    *new_x = x + tx;
    *new_y = y + ty;
}

// Function for 2D Scaling
void scale(int x, int y, float sx, float sy, int *new_x, int *new_y) {
    *new_x = x * sx;
    *new_y = y * sy;
}
     int gd = DETECT, gm;
     int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 50;
    int x3 = 150, y3 = 150;
     int tx = 50, ty = 50;
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    float sx = 1.5, sy = 1.5;


int main() {
   
    initgraph(&gd, &gm, "");

    // Original triangle vertices
    
    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(50, 20, "Original Triangle");

    // Translation factors
   
    // Perform translation
    translate(x1, y1, tx, ty, &new_x1, &new_y1);
    translate(x2, y2, tx, ty, &new_x2, &new_y2);
    translate(x3, y3, tx, ty, &new_x3, &new_y3);

    // Draw translated triangle
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(50, 350, "Translated Triangle");

    // Scaling factors
    

    // Perform scaling (on translated triangle)
    scale(new_x1, new_y1, sx, sy, &new_x1, &new_y1);
    scale(new_x2, new_y2, sx, sy, &new_x2, &new_y2);
    scale(new_x3, new_y3, sx, sy, &new_x3, &new_y3);

    // Draw scaled triangle
    setcolor(RED);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(250, 350, "Scaled Triangle");

    getch();
    closegraph();
    return 0;
}
