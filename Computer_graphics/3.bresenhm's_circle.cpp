#include <graphics.h>
#include <iostream>

using namespace std;

class bresen {
    float x, y, a, b, r, p;

public:
    void get();
    void cal();
};

void bresen::get() {
    cout << "ENTER CENTER AND RADIUS" << endl;
    cout << "ENTER (a, b): ";
    cin >> a >> b;
    cout << "ENTER r: ";
    cin >> r;
}

void bresen::cal() {
    int gdriver = DETECT, gmode, errorcode;
    int midx, midy, i;
    initgraph(&gdriver, &gmode, "");

    errorcode = graphresult();
    if (errorcode != grOK) {
        cout << "Graphics error: " << grapherrormsg(errorcode) << endl;
        cout << "Press any key to halt:";
        getch();
        exit(1);
    }

    x = 0;
    y = r;
    putpixel(a, b + r, RED);
    putpixel(a, b - r, RED);
    putpixel(a - r, b, RED);
    putpixel(a + r, b, RED);
    p = 5 / 4 - r;

    while (x <= y) {
        if (p < 0)
            p += (4 * x) + 6;
        else {
            p += (2 * (x - y)) + 5;
            y--;
        }
        x++;
        putpixel(a + x, b + y, RED);
        putpixel(a - x, b + y, RED);
        putpixel(a + x, b - y, RED);
        putpixel(a - x, b - y, RED);
        putpixel(a + y, b + x, RED);
        putpixel(a - y, b + x, RED);
        putpixel(a + y, b - x, RED);
        putpixel(a - y, b - x, RED);
    }
}

int main() {
    bresen b;
    b.get();
    b.cal();
    getch();
    closegraph();
    return 0;
}
