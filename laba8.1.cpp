#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
#define graphic(x) (cos(x))

int main(void)
{
    double x;
    HDC hDC = GetDC(GetConsoleWindow());
    HPEN Pen = CreatePen(0, 2, RGB(193, 0, 32));
    SelectObject(hDC, Pen);
    MoveToEx(hDC, 150, 20, 0);
    LineTo(hDC, 150, 280);
    MoveToEx(hDC, 10, 150, 0);
    LineTo(hDC, 290, 150);
    for (x = -12.0; x <= 12.0; x += 0.01)
    {
        MoveToEx(hDC, 10 * x + 150, -10 * graphic(x) + 150, 0);
        LineTo(hDC, 10 * x + 150, -10 * graphic(x) + 150);
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return 0;
}
