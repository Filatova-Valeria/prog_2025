#include <iostream>
#include <clocale>

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "ѕункт 1" << std::endl;

	const int raz = 7 + 3;
	int x[raz];

	std::cout << "¬ведите " << raz << " чисел массива:" << std::endl;
	for (int i = 0; i < raz; ++i) {
		std::cin >> x[i];
	}

	if (x[0] > x[raz - 1]) {
		for (int p = 0; p < (raz - 1); ++p) {
			for (int v = p + 1; v < raz; ++v) {
				if (x[p] > x[v]) {
					int tmp = x[p];
					x[p] = x[v];
					x[v] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < raz; ++i) {
		std::cout << x[i] << " ";
	}



	std::cout << std::endl << "ѕункт 2" << std::endl;

	const int str = 3;
	const int stlb = 4;
	int matrix[str][stlb];

	std::cout << "¬ведите числа дл€ матрицы формата " << str << " x " << stlb << " :" << std::endl;
	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < stlb; ++j) {
			std::cin >> matrix[i][j];
		}
	}
	
	long long summa[stlb];
	for (int i = 0; i < stlb; ++i) {
		summa[i] = 0;
	}

	for (int i = 0; i < stlb; ++i) {
		for (int j = 0; j < str; ++j) {
			summa[i] += matrix[j][i];
		}
	}

	int max_summa = LLONG_MIN;
	int nom_stlb = -1;

	for (int i = 0; i < stlb; ++i) {
		if (summa[i] > max_summa) {
			max_summa = summa[i];
			nom_stlb = i;
		}
	}

	if (nom_stlb == -1) {
		nom_stlb = 0;
	}

	for (int i = 0; i < str; ++i) {
		matrix[i][nom_stlb] = 0;
	}

	for (int i = 0; i < str; ++i) {
		for (int j = 0; j < stlb; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << " " << std::endl;
	}

	return 0;
}