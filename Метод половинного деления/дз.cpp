#include<iostream>
#include <cmath>
#include <clocale>

using namespace std;

double f(double x)
{
    return x - 2 + sin(1 / x);
}

int main() {
    setlocale(LC_ALL, "Rus");

    double a, b, E=0.000001,c;

    cout << "Введите a и b, где [a;b] - интвервал, где находится корень: " << endl;
    cin >> a >> b;

    if ((f(a)*f(b)) < 0)
    {
        while ((b - a) > E)
        {
            c = (a + b) / 2;
            if ((f(a) * f(c)) < 0)
            {
                b = c;
                cout << "Новое значение b: " << c << endl;
            }
            else
            {
                a = c;
                cout << "Новое значение а: " << c << endl;
            }
        }
        cout << "Решение: " << c << endl;
    }
    else
    {
        cout << "Применить этот способ не удалось." << endl;
    }
    return 0;
}