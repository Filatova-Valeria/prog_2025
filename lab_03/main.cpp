#include <iostream>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "����� 1"<< std::endl;

	int N;
	std::cout << "������ ����� N (���-�� ����� � ������-���):" << std::endl;
	std::cin >> N;
	if (N <= 0) {
		std::cout << "������ ������������������." << std::endl;
		return 1;
	}

	int first_num;
	int now_num;
	int flag = 0;
    int summa = 0;
	int min_num = INT_MAX;
	int num_num = -1;

	std::cout << "������ 1-�� ����� ������������������:" << std::endl;
	std::cin >> first_num;

	for (int i = 2; i <= N; ++i) {
		std::cout << "������ " << i << "-�� ����� ������������������:" << std::endl;
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
		std::cout << "� ������������������ ��� �����, ������� ������ �������." << std::endl;
	}
	else {
		std::cout << "����� �����, ������� ������ �������: " << summa << std::endl;
		std::cout << "���������� �� ���� �����: " << min_num << std::endl;
		std::cout << "����� ����� ����� � ������������������: " << num_num << std::endl;
	}



	std::cout << "����� 2" << std::endl;

	int x;
	std::cout << "������ ����� ����� X:" << std::endl;
	std::cin >> x;

	if (x <= -1000 || x >= 1000) {
		std::cout << "������ ����������� �������: |X| < 1000" << std::endl;
		return 1;
	}

	int num = abs(x);
	if (num == 0) {
		std::cout << "����� ���������� � ���������� ���� = 0" << std::endl;
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
	std::cout << "����� ���������� � ���������� ���� = " << min_tsifra + max_tsifra << std::endl;

	return 0;
}