#include <graphics.h>
#include <iostream>

using namespace std;

class bresen {
    float x, y, a, b, r, p, h, k, p1, p2;

public:
    void get();
    void cal();
};

void bresen::get() {
    cout << "ENTER CENTER OF ELLIPSE" << endl;
    cout << "ENTER (h, k): ";
    cin >> h >> k;
    cout << "ENTER LENGTH OF MAJOR AND MINOR AXIS" << endl;
    cin >> a >> b;
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
    y = b;
    // REGION 1
    p1 = (b * b) - (a * a * b) + (a * a) / 4;
    while (2 * b * b * x < 2 * a * a * y) {
        putpixel(x + h, y + k, RED);
        putpixel(-x + h, -y + k, RED);
        putpixel(x + h, -y + k, RED);
        putpixel(-x + h, y + k, RED);
        if (p1 < 0)
            p1 += (2 * b * b * (x + 1)) - (2 * a * a * (y - 1)) + b * b;
        else {
            p1 += (2 * b * b * (x + 1)) - (2 * a * a * (y - 1)) - b * b;
            y--;
        }
        x++;
    }
    // REGION 2
    p2 = (b * b) * (x + 0.5) + (a * a) * (y - 1) * (y - 1) - a * a * b * b;
    while (y >= 0) {
        if (p2 > 0)
            p2 = p2 - 2 * a * a * (y - 1) + a * a;
        else {
            p2 = p2 - 2 * a * a * (y - 1) + 2 * b * b * (x + 1) + a * a;
            x++;
        }
        y--;
        putpixel(x + h, y + k, RED);
        putpixel(-x + h, -y + k, RED);
        putpixel(x + h, -y + k, RED);
        putpixel(-x + h, y + k, RED);
    }

    getch();
}

int main() {
    bresen b;
    b.get();
    b.cal();
    closegraph();
    return 0;
}
