#include <graphics.h>
#include <stdio.h>
#include <math.h>

int WIDTH =640;
int HEIGHT =480;


typedef struct {
    float x, y, z;
} Point3D;


void project(Point3D p, int *x, int *y) {
    float scale = 200 / (200 + p.z); 
    *x = (int)(p.x * scale) + WIDTH / 2;
    *y = (int)(p.y * scale) + HEIGHT / 2;
}


void drawCube(Point3D cube[8]) {
    int x1, y1, x2, y2,i;


    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    for (i = 0; i < 12; i++) {
        project(cube[edges[i][0]], &x1, &y1);
        project(cube[edges[i][1]], &x2, &y2);
        line(x1, y1, x2, y2);
    }
}

void translate(Point3D *point, float tx, float ty, float tz) {
    point->x += tx;
    point->y += ty;
    point->z += tz;
}


void scale(Point3D *point, float sx, float sy, float sz) {
    point->x *= sx;
    point->y *= sy;
    point->z *= sz;
}
int i;
int gd = DETECT, gm;
float tx, ty, tz;
float sx, sy, sz;
 Point3D cube[8] = {
        { -1, -1, -1 }, { 1, -1, -1 }, { 1, 1, -1 }, { -1, 1, -1 },
        { -1, -1, 1 }, { 1, -1, 1 }, { 1, 1, 1 }, { -1, 1, 1 }
    };


 Point3D originalCube[8] = {
        { -1, -1, -1 }, { 1, -1, -1 }, { 1, 1, -1 }, { -1, 1, -1 },
        { -1, -1, 1 }, { 1, -1, 1 }, { 1, 1, 1 }, { -1, 1, 1 }
    };

int main() {
    
    initgraph(&gd, &gm, "");

   
    setcolor(WHITE);
    drawCube(cube);
    outtextxy(50, 20, "Original Cube");
    

    
    printf("Enter translation factors (tx, ty, tz): ");
    scanf("%f %f %f", &tx, &ty, &tz);

    for ( i = 0; i < 8; i++) {
        translate(&cube[i], tx, ty, tz);
    }

    setcolor(YELLOW);
    drawCube(cube);
    outtextxy(50, 350, "Translated Cube");


   


    
    printf("Enter scaling factors (sx, sy, sz): ");
    scanf("%f %f %f", &sx, &sy, &sz);


    for ( i = 0; i < 8; i++) {
        cube[i] = originalCube[i];  
        scale(&cube[i], sx, sy, sz);
    }


    setcolor(RED);
    drawCube(cube);
    outtextxy(50, 650, "Scaled Cube");

    getch();
    closegraph();
    return 0;
}
