#include <iostream>
#include <vector>
#include "Rational.h"
using namespace std;

Rational operator-(Rational first, Rational second) {
    int new_a = first.a * second.b - first.b * second.a;
    int new_b = first.b * second.b;
    return Rational(new_a, new_b);
}

int main()
{
    int a, b, kolvo;
    setlocale(LC_ALL, "Russian");

    cout << "Введите кол-во дробей: ";
    cin >> kolvo;
    vector <Rational> arr(kolvo);

    for (int i = 0; i < kolvo; i++) {
        cout << "Введите числитель и знаменатель дроби номер " << i + 1 << " : ";
        cin >> a >> b;
        arr[i] = Rational(a, b);
    }

    cout << "Рациональные дроби: " << endl;
    for (int i = 0; i < kolvo; i++) {
        arr[i].show();
        cout << endl;
    }

    cout << "Сложение + первых двух элементов: ";
    (arr[0] + arr[1]).show();
    cout << endl;

    cout << "Вычитание - первых двух элементов: ";
    (arr[0] - arr[1]).show();
    cout << endl;

    cout << "Увеличение на единицу ++ числителя первого элементе: ";
    ++arr[0];
    arr[0].show();
    cout << endl;

    cout << "Сравнение == первых двух элементов: ";
    if (arr[0] == arr[1]) {
        cout << "Дроби равны" << endl;
    }
    else {
        cout << "Дроби не равны" << endl;
    }

    cout << "Сравнение > первых двух элементов: ";
    if (arr[0] > arr[1]) {
        cout << "Первая дробь больше второй" << endl;
    }
    else {
        cout << "Первая дробь меньше или равна второй" << endl;
    }

    cout << "Присваивание = элемента: ";
    arr[1] = arr[0];
    arr[1].show();
    cout << endl;

    return 0;
}