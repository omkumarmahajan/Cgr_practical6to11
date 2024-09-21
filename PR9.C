#include <stdio.h>
#include <graphics.h>

// Function for Reflection across X-axis
void reflectX(int x, int y, int *new_x, int *new_y) {
    *new_x = x;
    *new_y = -y;
}

// Function for Reflection across Y-axis
void reflectY(int x, int y, int *new_x, int *new_y) {
    *new_x = -x;
    *new_y = y;
}

// Function for Shearing along X-axis
void shearX(int x, int y, float shx, int *new_x, int *new_y) {
    *new_x = x + (shx * y);
    *new_y = y;
}

// Function for Shearing along Y-axis
void shearY(int x, int y, float shy, int *new_x, int *new_y) {
    *new_x = x;
    *new_y = y + (shy * x);
}
  int gd = DETECT, gm;
   int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 50;
    int new_x1, new_y1, new_x2, new_y2, new_x3, new_y3;
    float shx = 0.5, shy = 0.5;


int main() {
    
    initgraph(&gd, &gm, "");

    // Original triangle vertices
   

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(50, 20, "Original Triangle");

    // Variables for reflection
   

    // Reflection across X-axis
    reflectX(x1, y1, &new_x1, &new_y1);
    reflectX(x2, y2, &new_x2, &new_y2);
    reflectX(x3, y3, &new_x3, &new_y3);

    // Draw reflected triangle across X-axis
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(50, 350, "Reflected Triangle (X-axis)");

    // Reset original coordinates
    new_x1 = x1; new_y1 = y1;
    new_x2 = x2; new_y2 = y2;
    new_x3 = x3; new_y3 = y3;

    // Reflection across Y-axis
    reflectY(x1, y1, &new_x1, &new_y1);
    reflectY(x2, y2, &new_x2, &new_y2);
    reflectY(x3, y3, &new_x3, &new_y3);

    // Draw reflected triangle across Y-axis
    setcolor(RED);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(250, 350, "Reflected Triangle (Y-axis)");

    // Shearing factors
   
    // Variables for shearing
    shearX(x1, y1, shx, &new_x1, &new_y1);
    shearX(x2, y2, shx, &new_x2, &new_y2);
    shearX(x3, y3, shx, &new_x3, &new_y3);

    // Draw sheared triangle along X-axis
    setcolor(GREEN);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(50, 600, "Sheared Triangle (X-axis)");

    // Reset original coordinates for Y-axis shearing
    new_x1 = x1; new_y1 = y1;
    new_x2 = x2; new_y2 = y2;
    new_x3 = x3; new_y3 = y3;

    // Shearing along Y-axis
    shearY(x1, y1, shy, &new_x1, &new_y1);
    shearY(x2, y2, shy, &new_x2, &new_y2);
    shearY(x3, y3, shy, &new_x3, &new_y3);

    // Draw sheared triangle along Y-axis
    setcolor(CYAN);
    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x2, new_y2, new_x3, new_y3);
    line(new_x3, new_y3, new_x1, new_y1);
    outtextxy(250, 600, "Sheared Triangle (Y-axis)");

    getch();
    closegraph();
    return 0;
}
