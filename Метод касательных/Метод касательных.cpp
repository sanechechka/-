#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

double f(double x)
{
    return x - 2 + sin(1 / x);
}

double f1(double x)
{
    return 1-((cos(1 / x)) / (pow(x, 2)));
}

double f2(double x)
{
    return -(sin(1 / x) - (2 * (cos(1 / x)) * x)) / (pow(x, 4));
}

int main()
{
    setlocale(LC_ALL, "Rus");

    double a, b, x0, x1, E=0.000001;

    cout << "Введите a и b, где [a;b] - интвервал, где находится корень: " << endl;
    cin >> a >> b;
    cout << endl;

    if ((f(a) * f2(a)) > 0)
    {
        x1 = b;

        x0 = a;

        cout << "Приближенное значение: " << x1 << endl;

        while ((abs(x1 - x0)) > E)
        {
            x1 = x0;
            x0 = x0 - (f(x0) / f1(x0));
            cout << "Новое приближенное значение: " << x0 << endl;
            cout << "delta x = " << abs(x1 - x0) << endl;
            cout << endl;
        }
        cout << "x = " << x0 << endl;
    }
    else
    {
        if ((f(b) * f2(b)) > 0)
        {
            x0 = b;

            x1 = a;

            cout << "Приближенное значение: " << x0 << endl;

            while ((abs(x1 - x0)) > E)
            {
                x0 = x1;
                x1 = x1 - (f(x1) / f1(x1));
                cout << "Новое приближенное значение: " << x1 << endl;
                cout << "delta x = " << abs(x1 - x0) << endl;
                cout << endl;
            }
            cout << "Решение: " << x1 << endl;
        }
        else
        {
            cout << "!" << endl;
        }
    }
    return 0;
}

