#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
private:
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	float S;
	float P;
public:
	Figure(float ax1, float ax2, float ax3, float ax4, float ay1, float ay2, float ay3, float ay4) {
		x1 = ax1; x2 = ax2; x3 = ax3; x4 = ax4; y1 = ay1; y2 = ay2; y3 = ay3; y4 = ay4;
		S = 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) + (x4 - x1) * (y2 - y1) + (x2 - x1) * (y4 - y1) - (x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1));
		P = (hypot(x1 - x2, y1 - y2) + hypot(x2 - x3, y2 - y3) + hypot(x3 - x4, y3 - y4) + hypot(x4 - x1, y4 - y1));
	}
	void show() {
		cout << "Периметр четырёхугольника = " << P << endl;
		cout << "Площадь четырёхугольника = " << S << endl;
	}
	bool is_prug() {
		return (hypot(x1 - x2, y1 - y2) == hypot(x3 - x4, y3 - y4)) && (hypot(x1 - x2, y1 - y2) == hypot(x4 - x1, y4 - y1)) && (hypot(x1 - x3, y1 - y3) == hypot(x4 - x2, y4 - y2));
	}
	bool is_square() {
		return is_prug() && (hypot(x1 - x2, y1 - y2) == hypot(x2 - x3, y2 - y3));
	}
	bool is_romb() {
		return  (hypot(x1 - x2, y1 - y2) == hypot(x3 - x4, y3 - y4)) && (hypot(x2 - x3, y2 - y3) == hypot(x4 - x1, y4 - y1));
	}
	bool is_in_circle() {
		return (hypot(x1 - x2, y1 - y2) + hypot(x3 - x4, y3 - y4)) == (hypot(x1 - x2, y1 - y2) + hypot(x4 - x1, y4 - y1));
	}
	bool is_out_circle() {
		float cos1 = ((x2 - x1) * (x2 - x3) + (y2 - y1) * (y2 - y3)) / (hypot(x2 - x1, y2 - y1) * hypot(x3 - x2, y3 - y2));
		float cos2 = ((x4 - x1) * (x4 - x3) + (y4 - y1) * (y4 - y3)) / (hypot(x4 - x1, y4 - y1) * hypot(x4 - x3, y4 - y3));
		if ((acos(cos1) + acos(cos1)) - 3.14159 < 0.001)
		{
			return true;
		}
		return false;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	vector<Figure> mas;
	float x1, x2, x3, x4, y1, y2, y3, y4;
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите координаты x1,x2,x3,x4,y1,y2,y3,y4 для четырёхугольника №" << i + 1 << endl;
		cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
		mas.push_back(Figure(x1, x2, x3, x4, y1, y2, y3, y4));
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Параметры четырёхугольника №" << i + 1 << " : "; mas[i].show();
		cout << "Является ли прямоугольником четырёхугольник №" << i + 1 << " : " << mas[i].is_prug() << endl;
		cout << "Является ли квадратом четырёхугольник №" << i + 1 << " : " << mas[i].is_square() << endl;
		cout << "Является ли ромбом четырёхугольник № " << i + 1 << " : " << mas[i].is_romb() << endl;
		cout << "Можно ли вписать в окружность четырёхугольник №" << i + 1 << " : " << mas[i].is_in_circle() << endl;
		cout << "Может ли быть вписана окружность в четырёхугольник №" << i + 1 << " : " << mas[i].is_out_circle() << endl << endl;
	}
}