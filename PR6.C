#include <stdio.h>
#include <graphics.h>
int i;
void drawPolygon(int vertices[], int num_points) {
    for (i = 0; i<num_points - 1;i++){
        line(vertices[2 * i], vertices[2 * i + 1], vertices[2 * (i + 1)], vertices[2 * (i + 1) + 1]);
    }
    
    line(vertices[0], vertices[1], vertices[2 * (num_points - 1)], vertices[2 * (num_points - 1) + 1]);
}


void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y); 
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);     
        delay(5);                       

        
        boundaryFill(x + 1, y, fill_color, boundary_color); 
        boundaryFill(x - 1, y, fill_color, boundary_color); 
        boundaryFill(x, y + 1, fill_color, boundary_color); 
        boundaryFill(x, y - 1, fill_color, boundary_color); 
    }
}
int gd = DETECT, gm;
int vertices[] = {200, 200, 300, 150, 400, 200, 350, 300, 250, 300};  
int num_points = 5; 


int main() {
    
    initgraph(&gd, &gm, "");
    
    setcolor(WHITE);
    drawPolygon(vertices, num_points);

   
    boundaryFill(300, 200, RED, WHITE);  
    getch();
    closegraph();
    return 0;
}
