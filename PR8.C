#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to perform 2D Rotation
void rotate(int x, int y, float angle, int *new_x, int *new_y) {
    // Convert angle to radians
    float rad = angle * (M_PI / 180.0);

    // Apply rotation formulas
    *new_x = x * cos(rad) - y * sin(rad);
    *new_y = x * sin(rad) + y * cos(rad);
}
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
     int new_x1, new_y1, new_x2, new_y2;
    float angle;
int main() {

    initgraph(&gd, &gm, "");

    // Original line coordinates (a simple shape: line from (100, 100) to (200, 100))


    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    outtextxy(50, 20, "Original Line");

    // Rotation angle
    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);

    // Variables to store new rotated coordinates
   

    // Perform rotation on both points of the line
    rotate(x1, y1, angle, &new_x1, &new_y1);
    rotate(x2, y2, angle, &new_x2, &new_y2);

    // Draw rotated line
    setcolor(YELLOW);
    line(new_x1, new_y1, new_x2, new_y2);
    outtextxy(50, 350, "Rotated Line");

    getch();
    closegraph();
    return 0;
}
