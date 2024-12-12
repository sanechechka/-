#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double f(double x)
{
    return 2 - sin(1 / x);
}

double f1(double x)
{
    return ((cos(1 / x)) / (pow(x, 2)));
}

int main()
{
    setlocale(LC_ALL, "Rus");

    double a, b, x1, x0, E = 0.000001;

    cout << "Введите a и b, где [a;b] - интвервал, где находится корень: " << endl;
    cin >> a >> b;

    x0 = b;

    x1 = f(x0);

    int k = 1; //счетчик итераций

    cout << "Начальное значение: " << x0 << endl;// вывод каждого приближения
    cout << "Приближенное значение x: " << x1 << endl; // вывод каждого приближения

    if ((abs(f1(x0))) < 1)//условие сходимости
    {
        while ((abs(x1 - x0)) >= E) // цикл, проверяющий точность вычислений
        {
            k += 1; // работа со счетчиком
            x0 = x1; 
            x1 = f(x1); // вычисление приближения
            cout << "Приближенное значение x: " << x1 << endl; // вывод каждого приближения
        }
        cout << "Корень: " << x1 << endl;
        cout << "Количество итераций: " << k << endl;
    }
    else
    {
        cout << "Применить этот способ не удалось." << endl;
    }
    return 0;
}
