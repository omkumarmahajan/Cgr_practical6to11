#include <graphics.h>
#include <stdio.h>
#include <math.h>

 int WIDTH= 640;
 int HEIGHT= 480;
 float PI =3.14159265;


typedef struct {
    float x, y, z;
} Point3D;


void project(Point3D p, int *x, int *y) {
    float scale = 200 / (200 + p.z); 
    *x = (int)(p.x * scale) + WIDTH / 2;
    *y = (int)(p.y * scale) + HEIGHT / 2;
}


void drawRectangle(Point3D rect[4]) {
    int x1, y1, x2, y2,i;

   
    int edges[4][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}
    };

    for (i = 0; i < 4; i++) {
        project(rect[edges[i][0]], &x1, &y1);
        project(rect[edges[i][1]], &x2, &y2);
        line(x1, y1, x2, y2);
    }
}


void rotateX(Point3D *p, float angle) {
    float rad = angle * PI / 180;
    float y = p->y;
    float z = p->z;
    p->y = y * cos(rad) - z * sin(rad);
    p->z = y * sin(rad) + z * cos(rad);
}


void rotateY(Point3D *p, float angle) {
    float rad = angle * PI / 180;
    float x = p->x;
    float z = p->z;
    p->x = x * cos(rad) + z * sin(rad);
    p->z = -x * sin(rad) + z * cos(rad);
}

void rotateZ(Point3D *p, float angle) {
    float rad = angle * PI / 180;
    float x = p->x;
    float y = p->y;
    p->x = x * cos(rad) - y * sin(rad);
    p->y = x * sin(rad) + y * cos(rad);
}
  int gd = DETECT, gm;
    Point3D rect[4] = {
        { -6, -3, 0 }, { 6, -3, 0 }, { 6, 3, 0 }, { -6, 3, 0 }
    };
     float angleX, angleY, angleZ;
     int i;
int main() {
    
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    drawRectangle(rect);
    outtextxy(50, 20, "Original Rectangle");

   
    printf("Enter rotation angles (X Y Z): ");
    scanf("%f %f %f", &angleX, &angleY, &angleZ);

    
    for (i = 0; i < 4; i++) {
        rotateX(&rect[i], angleX);
        rotateY(&rect[i], angleY);
        rotateZ(&rect[i], angleZ);
    }

   
    setcolor(YELLOW);
    drawRectangle(rect);
    outtextxy(50, 350, "Rotated Rectangle");

    getch();
    closegraph();
    return 0;
}
