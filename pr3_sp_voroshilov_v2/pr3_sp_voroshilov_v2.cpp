// pr3_sp_voroshilov_v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Circle {
	float radius;

	float Area() {
		return radius * radius * 3.14;
	}
};

struct Rectangle {
	float firstLen;
	float secondLen;

	float Area() {
		return firstLen * secondLen;
	}
};

struct Triangle {
	float firstLen;
	float secondLen;
	float thirdLen;

	float Area() {
		float p = (firstLen + secondLen + thirdLen) / 2;

		return sqrt(p * (p - firstLen) * (p - secondLen) * (p - thirdLen));
	}
};

union TypeOfFigures {
	Circle circle;
	Rectangle rectangle;
	Triangle triangle;
};

struct Figures {
	char color[255];
	float area;
	char nameOfType[10];

	TypeOfFigures type;
};

int main()
{
	Figures figures[4];


	figures[0].type.circle.radius = 5;
	strcpy_s(figures[0].nameOfType, "circle");
	strcpy_s(figures[0].color, "red");
	figures[0].area = figures[0].type.circle.Area(); //78.5

	std::cout << figures[0].nameOfType << " " << figures[0].area << " " << figures[0].color << std::endl;

	figures[1].type.rectangle.firstLen = 15;
	figures[1].type.rectangle.secondLen = 10;
	strcpy_s(figures[1].nameOfType, "rectangle");
	strcpy_s(figures[1].color, "blue");
	figures[1].area = figures[1].type.rectangle.Area(); //150
	
	std::cout << figures[1].nameOfType << " " << figures[1].area << " " << figures[1].color << std::endl;

	figures[2].type.circle.radius = 3;
	strcpy_s(figures[2].nameOfType, "circle");
	strcpy_s(figures[2].color, "magenta");
	figures[2].area = figures[2].type.circle.Area(); //28.26

	std::cout << figures[2].nameOfType << " " << figures[2].area << " " << figures[2].color << std::endl;

	figures[3].type.triangle.firstLen = 6;
	figures[3].type.triangle.secondLen = 10;
	figures[3].type.triangle.thirdLen = 9;
	strcpy_s(figures[3].nameOfType, "triangle");
	strcpy_s(figures[3].color, "yellow");
	figures[3].area = figures[3].type.triangle.Area(); //26.6634

	std::cout << figures[3].nameOfType << " " << figures[3].area << " " << figures[3].color << std::endl << std::endl;



	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (figures[i].area > figures[j].area) {
				Figures temp = figures[j];
				figures[j] = figures[i];
				figures[i] = temp;
			}
		}
		std::cout << figures[i].nameOfType << " " << figures[i].area << " " << figures[i].color << std::endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
