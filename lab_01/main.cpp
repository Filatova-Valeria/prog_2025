#include <iostream>
#include <limits>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");

	int x; // int, т.к. x должно быть целое число
	double obrat; // double, т.к. обратное значение будет дробным и для большей точности
	unsigned int step2; // unsigned int, т.к. вторя степень всегда будет больше 0
	long long step5; // long long, т.к. пятая степень может быть отрицательной и чтобы избежать переполнение

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

	std::cin >> x;
	obrat = 1.f / x;
	std::cout << "обратное значение: " << obrat << " (double)" << std::endl;
	step2 = x * x;
	std::cout << "вторая степень: " << step2 << " (unsigned int)" << std::endl;
	step5 = pow(x, 5);
	std::cout << "пятая степень: " << step5 << " (long long)" << std::endl;

	return 0;
}