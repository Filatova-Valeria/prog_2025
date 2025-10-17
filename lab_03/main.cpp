#include <iostream>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "Пункт 1"<< std::endl;

	int N;
	std::cout << "Ввести число N (кол-во чисел в послед-сти):" << std::endl;
	std::cin >> N;
	if (N <= 0) {
		std::cout << "Пустая последовательность." << std::endl;
		return 1;
	}

	int first_num;
	int now_num;
	int flag = 0;
    int summa = 0;
	int min_num = INT_MAX;
	int num_num = -1;

	std::cout << "Ввести 1-ое число последовательности:" << std::endl;
	std::cin >> first_num;

	for (int i = 2; i <= N; ++i) {
		std::cout << "Ввести " << i << "-ое число последовательности:" << std::endl;
		std::cin >> now_num;
		if (now_num <= first_num) {
			continue;
		}
		flag = 1;
		summa += now_num;
		if (now_num < min_num) {
			min_num = now_num;
			num_num = i;
		}
	}
	if (flag == 0) {
		std::cout << "В последовательности нет чисел, которые больше первого." << std::endl;
	}
	else {
		std::cout << "Сумма чисел, которые больше первого: " << summa << std::endl;
		std::cout << "Наименьшее из этих чисел: " << min_num << std::endl;
		std::cout << "Номер этого числа в последовательности: " << num_num << std::endl;
	}



	std::cout << "Пункт 2" << std::endl;

	int x;
	std::cout << "Ввести целое число X:" << std::endl;
	std::cin >> x;

	if (x <= -1000 || x >= 1000) {
		std::cout << "Должно выполняться условие: |X| < 1000" << std::endl;
		return 1;
	}

	int num = abs(x);
	if (num == 0) {
		std::cout << "Сумма наименьшей и наибольшей цифр = 0" << std::endl;
		return 0;
	}

	int min_tsifra = 9;
	int max_tsifra = 0;
	int now_tsifra;

	while (num > 0) {
		now_tsifra = num % 10;
		if (now_tsifra < min_tsifra) {
			min_tsifra = now_tsifra;
		}
		if (now_tsifra > max_tsifra) {
			max_tsifra = now_tsifra;
		}
		num /= 10;
	}
	std::cout << "Сумма наименьшей и наибольшей цифр = " << min_tsifra + max_tsifra << std::endl;

	return 0;
}