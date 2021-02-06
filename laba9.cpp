#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

double fun(double x) 
{
    return log(x) - 5*cos(x);
}

double find(double A, double B, double eps) 
{
        double result = B, f0, f;

        do {
            f = fun(result);
            f0 = fun(A);

            result -= f / (f - f0) * (result - A);
        } while (fabs(f) > eps);

        return result;  
}

int main() 
{
    system("chcp 1251>nul");
    double a = 1, b = 8, x, eps = 0.0000000001, h = 0.1;
    int num = 0;
    cout << "a = "<<a<<"\n";
    cout << "b = " << b << "\n";
    cout << "eps = " << eps<<"\n";
    cout << "h = " << h << "\n\n";
    cout << "Функция: log(x) - 5*cos(x)" << "\n\n";
    cout << "Корни" << "\n";
    for (x = a; x <= b; x += h) 
    {
        if (fun(x) * fun(x + h) < 0) 
        {
            num++;
            double rez= find(x, x + h, eps);
            cout << num << "-й = " << rez << "\n";
            cout << "проверка = " << fun(rez) << "\n";
        }
    }
    cout << "\n\n\n";
    return 0;  
}





