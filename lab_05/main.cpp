#include <iostream>
#include <limits>
#include <clocale>

namespace vf {
	// для пункта 1:
	float srednee(int n1, int n2) {
		std::cout << "Исп. функция среднего значения 2-х чисел." << std::endl;
		float sr;
		sr = (n1 + n2) / 2.f;
		return sr;
	}

	float srednee(int n1, int n2, int n3) {
		std::cout << "Исп. функция среднего значения 3-х чисел." << std::endl;
		float sr;
		sr = (n1 + n2 + n3) / 3.f;
		return sr;
	}
	// для пункта 2:
	void obr_2_5(int x) {
		int razInt;
		int razDouble;
		int razUnInt;
		int razLL;
		razInt = sizeof(int) * 8;
		razDouble = sizeof(double) * 8;
		razUnInt = sizeof(unsigned int) * 8;
		razLL = sizeof(long long) * 8;
		std::cout << "int занимает " << razInt << " бита, min = " << INT_MIN << ", max = " << INT_MAX << std::endl;
		std::cout << "double занимает " << razDouble << " бита, min = " << std::numeric_limits<double>::lowest() << ", max = " << DBL_MAX << std::endl;
		std::cout << "unsignet int занимает " << razUnInt << " бита, min = " << std::numeric_limits<unsigned int>::min() << ", max = " << std::numeric_limits<unsigned int>::max() << std::endl;
		std::cout << "long long занимает " << razLL << " бита, min = " << LLONG_MIN << ", max = " << LLONG_MAX << std::endl;
		if (x == 0) {
			std::cout << "Ошибка, число равно 0." << std::endl;
		}
		else {
			double obrat;
			unsigned int step2;
			long long step5;
			obrat = 1.f / x;
			step2 = x * x;
			step5 = pow(x, 5);
			std::cout << "Обратное = " << obrat << "; 2-я степень = " << step2 << "; 5-я степень = " << step5 << std::endl;
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	int punkt;
	std::cout << "Введите номер пункта, который будет выполняться (1 или 2):" << std::endl;
	std::cin >> punkt;

	if (punkt != 1 && punkt != 2) {
		std::cout << "Неправильный ввод пункта. Введите 1 или 2.";
		return 1;
	}

	if (punkt == 1) {
		std::cout << "Пункт 1" << std::endl;

		int a, b, c;
		std::cout << "Введите 3 целых чила (если число = 0, его нет): " << std::endl;
		std::cin >> a >> b >> c;

		int count = 0;
		if (a != 0) {
			++count;
		}
		if (b != 0) {
			++count;
		}
		if (c != 0) {
			++count;
		}

		float rez;
		if (count == 3) {
			rez = vf::srednee(a, b, c);
		}
		else if (count == 2) {
			if (a != 0 && b != 0) {
				rez = vf::srednee(a, b);
			}
			if (a != 0 && c != 0) {
				rez = vf::srednee(a, c);
			}
			if (b != 0 && c != 0) {
				rez = vf::srednee(b, c);
			}
		}
		else {
			std::cout << "Нужны 2 или 3 числа, которые не равны 0." << std::endl;
			return 1;
		}

		std::cout << rez << std::endl;
	}

	if (punkt == 2) {
		std::cout << "Пункт 2" << std::endl;

		int X;
		std::cout << "Введите целое число (не 0):" << std::endl;
		std::cin >> X;
		vf::obr_2_5(X);
	}

	return 0;
}