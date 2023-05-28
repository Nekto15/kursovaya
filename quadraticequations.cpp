#include <iostream>
#include <locale>
#include <stdlib.h> // Для очистки экрана
#include <cmath> // Для операций с математическими функциями

using namespace std;

// Функции для решения квадратных уравнений

void method1(double a, double b, double c) {
	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		wcout << L"Нет реальных корней" << endl;
	}
	else if (discriminant == 0) {
		double x = -b / (2 * a);
		wcout << L"Один корень: " << x << endl;
	}
	else {
		double x1 = (-b + sqrt(discriminant)) / (2 * a);
		double x2 = (-b - sqrt(discriminant)) / (2 * a);
		wcout << L"Два корня: " << x1 << " и " << x2 << endl;
	}
}

void method2(double a, double b, double c) {
	double x1 = 0, x2 = 0;
	if (a == 0 && b == 0) {
		wcout << L"Корней нет" << endl;
		return;
	}
	else if (a == 0) {
		x1 = -c / b;
		wcout << L"Один корень: " << x1 << endl;
		return;
	}
	else if (b == 0) {
		if (-c / a < 0) {
			wcout << L"Нет реальных корней" << endl;
			return;
		}
		else {
			x1 = sqrt(-c / a);
			x2 = -sqrt(-c / a);
			wcout << L"Два корня: " << x1 << " и " << x2 << endl;
			return;
		}
	}
	else if (c == 0) {
		x1 = 0;
		x2 = -b / a;
		wcout << L"Два корня: " << x1 << " и " << x2 << endl;
		return;
	}
	else {
		double discriminant = b * b - 4 * a * c;
		if (discriminant < 0) {
			wcout << L"Нет реальных корней" << endl;
			return;
		}
		else if (discriminant == 0) {
			x1 = -b / (2 * a);
			wcout << L"Один корень: " << x1 << endl;
			return;
		}
		else {
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-b - sqrt(discriminant)) / (2 * a);
			wcout << L"Два корня: " << x1 << " и " << x2 << endl;
			return;
		}
	}
}

// Функция для вывода меню

void menu() {
	wcout << L"1. Типы квадратных уравнений" << endl;
	wcout << L"2. Методы решения квадратных уравнений" << endl;
	wcout << L"3. Сравнение методов решения квадратных уравнений" << endl;
	wcout << L"4. Решение квадратных уравнений" << endl;
	wcout << L"0. Выход из программы" << endl;
}

// Функция для возврата к меню

void backToMenu() {
	wcout << endl;
	system("pause"); // Ожидание нажатия любой клавиши
	system("cls"); // Очистка экрана
	menu(); // Вывод меню
}

int main() {
	setlocale(LC_ALL, "Russian");

	int choice;
	double a = 1, b = 1, c = 1;

	do {
		menu();
		wcout << L"Введите номер нужного действия: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			wcout << L"Типы квадратных уравнений:" << endl;
			wcout << L"1. Общий вид: ax^2 + bx + c = 0" << endl;
			wcout << L"2. Канонический вид: a(x - h)^2 + k = 0" << endl;
			wcout << L"3. Вершинно-осевая форма: a(x - x0)^2 + y0 = 0" << endl;
			backToMenu();
			break;
		}
		case 2: {
			wcout << L"Методы решения квадратных уравнений:" << endl;
			wcout << L"1. Формула дискриминанта" << endl;
			wcout << L"2. Метод деления коэффициентов" << endl;
			wcout << L"Описание методов:\n";
			wcout << L"Метод 1: d = b^2 - 4ac => x1, x2 = (-b +- sqrt(d)) / 2a\n";
			wcout << L"Метод 2: Ищем корни на основании следующих утверждений:\n";
			wcout << L"- Если a=0 и c=0, b - любое число, то корней нет.\n";
			wcout << L"- Если a=0 и b=0, c - любое число, то корней нет.\n";
			wcout << L"- Если a=0 и c<0, b - любое число, то корней нет.\n";
			wcout << L"- Если a=0 и c>0, b - любое число, то два корня: sqrt(-c/a) и -sqrt(-c/a).\n";
			wcout << L"- Если b=0 и c=0, a - любое число, то корни: 0 и -b/a.\n";
			wcout << L"- Если b=0 и a=0, c - любое число, то корней нет.\n";
			wcout << L"- Если c=0, то один из корней всегда равен 0.\n";
			wcout << L"- Если a, b и c != 0, то используем формулу дискриминанта (метод 1).\n";
			backToMenu();
			break;
		}
		case 3: {
			wcout << L"Сравнение методов решения квадратных уравнений:" << endl;
			wcout << L"Метод 1 вычисляет корни квадратного уравнения с помощью формулы дискриминанта.\n";
			wcout << L"Метод 2 изучает характеристики уравнения и на основании этого находит корни.\n";
			backToMenu();
			break;
		}
		case 4: {
			wcout << L"Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0)" << endl;
			wcout << L"a = ";
			cin >> a;
			wcout << L"b = ";
			cin >> b;
			wcout << L"c = ";
			cin >> c;
			wcout << L"Каким методом вы хотите решить квадратное уравнение?" << endl;
			wcout << L"1. Формула дискриминанта" << endl;
			wcout << L"2. Метод деления коэффициентов" << endl;
			int method;
			cin >> method;
			wcout << L"Решение квадратного уравнения: ";
			if (method == 1) {
				method1(a, b, c);
			}
			else if (method == 2) {
				method2(a, b, c);
			}
			backToMenu();
			break;
		}
		case 0: {
			wcout << L"Завершение работы программы." << endl;
			break;
		}
		default: {
			wcout << L"Ошибка! Введите номер действия из списка." << endl;
		}
		}

	} while (choice != 0);

	return 0;
}
