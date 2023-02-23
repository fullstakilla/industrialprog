#include <iostream>
#include <vector>
#include "Rational.h"
using namespace std;

int main()
{
    int a, b, kolvo;
    setlocale(LC_ALL, "Russian");

    cout << "Введите кол-во дробей: ";
    cin >> kolvo;
    vector <Rational> arr(kolvo);

    for (int i = 0; i < kolvo; i++) {
        cout << "Введите числитель и знаменатель дроби номер " << i+1 << " : ";
        cin >> a >> b;
        arr[i].set(a, b);
    }

    cout << "Рациональные дроби: " << endl;
    for (int i = 0; i < kolvo; i++) {
        arr[i].show();
        cout << endl;
    }

    return 0;
}
