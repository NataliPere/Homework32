#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> 

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
//������ 1
template <typename T>
void memory(T*& ptr, int num1, int num2) {
	ptr = new T[num1];
	for (int i = 0; i < num1; i++) {
		ptr[i] = new int[num2];
	}
};
//������ 2
 std::string char_func(std::string& str, char ch1, char ch2) {
	std::string result;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch1)
			str[i] = ch2;
		result = str;
	}
	return result;
}

//������ 3
struct route {
	int route_number;
	std::string type_of_transport;
	std::string begin_route;
	std::string end_route;

} a, b, c;

struct fare {
	int cost;
	int value;
} a1, b1, c1;

void show_route(route& P) {

	std::cout << "�� ������� ����� ��������: " << P.route_number << "\n��� ����������: " << P.type_of_transport << "\n������ ��������: " << P.begin_route << "\n����� ��������: " << P.end_route << "\n";
}

struct choice_route {
	int number = 0;
	std::string options = " ";
};

void fare(route& P, fare& P1) {

	std::cout << "��������� �������: " << P1.cost << "\n";
	std::cout << "���������� ������� � ����������: " << P1.value << "\n";
	std::cout << "����� ��������� �������: " << P1.cost * P1.value << "\n";
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//������ 1
	std::cout << "������� ���������� ��������� ���������� �������.\n";
	std::cout << "���������� �����: ";
	std::cin >> n;
	std::cout << "���������� ��������: ";
	std::cin >> m;
	int** pArr = nullptr;
	memory(pArr, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			pArr[i][j] = rand() % 20;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << pArr[i][j] << "\t";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < n; i++)
		delete[] pArr[i];
		std::cout << "\n\n";
	
	//������ 2.
	std::string str = "Find symbol in the string!\n";
	char n1, m1;
	std::cout << "������: " << str;
	std::cout << "������� 1-� ������: ";
	std::cin >> n1;
	int i = 0;
	if (str[i] != n1) {
		std::cout << "�� ����� �� ������������ � ������ �����! ������� ��������: ";
		std::cin >> n1;
	}
	std::cout << "������� 2-� ������: ";
	std::cin >> m1;
	std::cout << "�������� ������: ";
	std::cout << char_func(str, n1, m1);
	std::cout << "\n\n";


	//������ 3.
	a.route_number = 30;
	a.type_of_transport = "bus";
	a.begin_route = "Shevchenko";
	a.end_route = "Mashinostroiteley";

	b.route_number = 32;
	b.type_of_transport = "tram";
	b.begin_route = "Korolenko";
	b.end_route = "Geologicheskaya";

	c.route_number = 35;
	c.type_of_transport = "trolleybus";
	c.begin_route = "Tehnicheskaya";
	c.end_route = "Pobedy";

	a1.cost = 25;
	a1.value = 15;

	b1.cost = 28;
	b1.value = 21;

	c1.cost = 32;
	c1.value = 11;

	int num;
	std::cout << "������ 3: " << "\n";
	std::cout << "������� ����� �� 1 �� 3: " << "\n";
	std::cin >> num;
	if (num > 3) {
		std::cout << "�� ����� ������������ �����. ������� �������� �� 1 �� 3: ";
		std::cin >> num;
	}
	switch (num) {
	case 1: show_route(a); fare(a, a1); break;
	case 2: show_route(b); fare(b, b1); break;
	case 3: show_route(c); fare(c, c1); break;
	
	default: break;
	}
	std::cout << "\n";

	return 0;
}