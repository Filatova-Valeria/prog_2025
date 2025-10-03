#include <iostream>
#include <limits>

int main() {
	setlocale(LC_ALL, "Russian");

	int x; // int, �.�. x ������ ���� ����� �����
	double obrat; // double, �.�. �������� �������� ����� ������� � ��� ������� ��������
	unsigned int step2; // unsigned int, �.�. ����� ������� ������ ����� ������ 0
	long long step5; // long long, �.�. ����� ������� ����� ���� ������������� � ����� �������� ������������

	int razInt;
	int razDouble;
	int razUnInt;
	int razLL;
	razInt = sizeof(int) * 8;
	razDouble = sizeof(double) * 8;
	razUnInt = sizeof(unsigned int) * 8;
	razLL = sizeof(long long) * 8;

	std::cout << "int �������� " << razInt << " ����, min = " << INT_MIN << ", max = " << INT_MAX << std::endl;
	std::cout << "double �������� " << razDouble << " ����, min = " << DBL_MIN << ", max = " << DBL_MAX << std::endl;
	std::cout << "unsignet int �������� " << razUnInt << " ����, min = " << std::numeric_limits<unsigned int>::min() << ", max = " << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "long long �������� " << razLL << " ����, min = " << LLONG_MIN << ", max = " << LLONG_MAX << std::endl;

	std::cin >> x;
	obrat = 1.f / x;
	std::cout << "�������� ��������: " << obrat << " (double)" << std::endl;
	step2 = x * x;
	std::cout << "������ �������: " << step2 << " (unsigned int)" << std::endl;
	step5 = pow(x, 5);
	std::cout << "����� �������: " << step5 << " (long long)" << std::endl;

	return 0;
}