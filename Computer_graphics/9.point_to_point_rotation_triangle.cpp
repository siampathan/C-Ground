/*    
#include<stdio.h>  
    #include<graphics.h>  
    #include<math.h>  
    int main()  
    {  
        intgd=0,gm,x1,y1,x2,y2;  
        double s,c, angle;  
        initgraph(&gd, &gm, "C:\\TC\\BGI");  
        setcolor(RED);  
        printf("Enter coordinates of line: ");  
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
        cleardevice();  
        setbkcolor(WHITE);  
        line(x1,y1,x2,y2);  
        getch();  
        setbkcolor(BLACK);  
        printf("Enter rotation angle: ");  
        scanf("%lf", &angle);  
        setbkcolor(WHITE);  
        c = cos(angle *3.14/180);  
        s = sin(angle *3.14/180);  
        x1 = floor(x1 * c + y1 * s);  
        y1 = floor(-x1 * s + y1 * c);  
        x2 = floor(x2 * c + y2 * s);  
        y2 = floor(-x2 * s + y2 * c);  
        cleardevice();  
        line(x1, y1 ,x2, y2);  
        getch();  
        closegraph();  
    return 0;  
    }  */

//C++

#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int main() {
    int gd = 0, gm, x1, y1, x2, y2;
    double s, c, angle;
    
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
    setcolor(RED);
    cout << "Enter coordinates of line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    
    cleardevice();
    setbkcolor(WHITE);
    line(x1, y1, x2, y2);
    getch();
    
    setbkcolor(BLACK);
    cout << "Enter rotation angle: ";
    cin >> angle;
    setbkcolor(WHITE);
    
    c = cos(angle * M_PI / 180);
    s = sin(angle * M_PI / 180);
    
    int new_x1 = floor(x1 * c + y1 * s);
    int new_y1 = floor(-x1 * s + y1 * c);
    int new_x2 = floor(x2 * c + y2 * s);
    int new_y2 = floor(-x2 * s + y2 * c);
    
    cleardevice();
    line(new_x1, new_y1, new_x2, new_y2);
    getch();
    
    closegraph();
    return 0;
}
