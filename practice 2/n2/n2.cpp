#include <iostream>
#include <cmath>
using namespace std;

class Circle{
	private:
		float radius, x_center, y_center;
	public:
		Circle() {
		};
		void set_circle(float r, float x, float y) {
			radius = r;
			x_center = x;
			y_center = y;
		};
		float square() {
			return  3.14159 * radius * radius;
		};
		bool triangle_around(float a, float b, float c) {
			float p_triangle = (a + b + c) / 2;
			float square_trinagle = sqrt(p_triangle * (p_triangle - a) * (p_triangle - b) * (p_triangle - c));
			return radius == a * b * c / 4 / square_trinagle;
		};
		bool triangle_in(float a, float b, float c) {
			float p_triangle = (a + b + c) / 2;
			float square_trinagle = sqrt(p_triangle * (p_triangle - a) * (p_triangle - b) * (p_triangle - c));
			return radius == 2 * square_trinagle / (a + b + c);
		};
		bool check_circle(float r, float x_cntr, float y_cntr) {
			double len_between_centers = sqrt(pow((x_center - x_cntr), 2) + pow((y_center - y_cntr), 2));
			return len_between_centers <= (r + radius);
		};

};

int main() {
	setlocale(LC_ALL, "Russian");

	Circle mas[3];
	float r, x, y;
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите радиус, x и y центра для окружности № " << i + 1 << " через пробел: " << endl;
		cin >> r >> x >> y;
		mas[i].set_circle(r, x, y);
	}
	float a, b, c;
	for (int i = 0; i < 3; i++)
	{
		cout << "Площадь окружности № " << i + 1 << ": " << mas[i].square() << endl;
		cout << "Введите a, b и c для треугольника который нужно проверить на возможность быть описанным окуржностью № " << i + 1 << " через пробел: " << endl;
		cin >> a >> b >> c;
		cout << mas[i].triangle_in(a, b, c) << endl;
		cout << "Введите a, b и c для треугольника в который нужно вписать окружность № " << i + 1 << " через пробел: " << endl;
		cin >> a >> b >> c;
		cout << mas[i].triangle_around(a, b, c) << endl;
		cout << "Введите радиус и координаты центра для окружности, которую нужно проверить на условие касания" << endl;
		cin >> a >> b >> c;
		cout << mas[i].check_circle(a, b, c) << endl << endl;
	}
	return 0;
}