#include <iostream>
#include <clocale>
#include <iomanip>

namespace vf {
    //
    void print_matrix(int** matrix, int str, int stlb) {
        for (int i = 0; i < str; ++i) {
            for (int j = 0; j < stlb; ++j) {
                std::cout << std::setw(5) << matrix[i][j] << " ";
            }
            std::cout << " " << std::endl;
        }
    }

    //

    int* nol(int** matrix, int str, int stlb, int& count_nol) {
        int* nol_stlb = (int*)calloc(stlb, sizeof(int)); // столбцы с нулями
        count_nol = 0;

        for (int j = 0; j < stlb; j++) {
            bool flag_nol = false;
            for (int i = 0; i < str; i++) {
                if (matrix[i][j] == 0) {
                    flag_nol = true;
                    break;
                }
            }
            if (flag_nol) {
                nol_stlb[count_nol] = j;
                count_nol++;
            }
        }

        if (count_nol > 0) {
            nol_stlb = (int*)realloc(nol_stlb, count_nol * sizeof(int));
        }
        else {
            free(nol_stlb);
            nol_stlb = nullptr; //нулевой указатель
        }
        return nol_stlb;
    }

}



int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Пункт 1" << std::endl;

    // ввод чисел

    int A;
    int B;
    int C;
    int D;

    do {
        std::cout << "Ввести число A - сколько строк нужно добавить снизу: ";
        std::cin >> A;
        if (A < 0) {
            std::cout << "Ошибка ( A - отрицательное ). Введите корректное число: \n";
        }
    } while (A < 0);

    do {
        std::cout << "Ввести число B - сколько столбцов нужно добавить справа: ";
        std::cin >> B;
        if (B < 0) {
            std::cout << "Ошибка ( B - отрицательное ). Введите корректное число: \n";
        }
    } while (B < 0);

    std::cout << "Ввести целое число C - коэф. для заполнения: " << std::endl;
    std::cin >> C;
    std::cout << "Ввести целое число D - коэф. для заполнения: " << std::endl;
    std::cin >> D;

    // создание начальной матрицы 2x2 

    int nach_str = 2;
    int nach_stlb = 2;

    int** matrix = (int**)malloc(nach_str * sizeof(int*));

    for (int i = 0; i < nach_str; ++i) {
        matrix[i] = (int*)malloc(nach_stlb * sizeof(int));
    }

    matrix[0][0] = A;
    matrix[1][0] = C;
    matrix[0][1] = B;
    matrix[1][1] = D;

    std::cout << "Матрица 2x2: " << std::endl;
    vf::print_matrix(matrix, nach_str, nach_stlb);

    // преобразование матрицы

    int str = nach_str + A;
    int stlb = nach_stlb + B;

    matrix = (int**)realloc(matrix, str * sizeof(int*));

    for (int i = 0; i < str; ++i) {
        if (i < nach_str) {
            matrix[i] = (int*)realloc(matrix[i], stlb * sizeof(int));
        }
        else {
            matrix[i] = (int*)malloc(stlb * sizeof(int));
        }
    }

    for (int i = 0; i < str; ++i) {
        for (int j = 0; j < stlb; ++j) {
            if (i < 2 && j < 2) {
                // оставляем исходные значения A, B, C, D без изменений
                // matrix[i][j] уже содержит правильные значения
            }
            else {
                matrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }

    // вывести матрицу
    std::cout << "Новая матрица " << str << "x" << stlb << " :" << std::endl;
    vf::print_matrix(matrix, str, stlb);

    // Ищем нулевые столбцы

    int count_nol = 0;
    int* nol_stlb = vf::nol(matrix, str, stlb, count_nol);


    if (count_nol > 0) {
        std::cout << "Столбцы, содержащие нули: ";
        for (int i = 0; i < count_nol; i++) {
            std::cout << nol_stlb[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Нулевых элементов нет" << std::endl;
    }

    // Удаление столбцов 

    if (count_nol > 0) {
        int new_stlb = stlb; // новое количество столбцов после удаления

        for (int j = stlb - 1; j >= 0; j--) {
            int should_del = j;
            bool del = false;

            for (int q = 0; q < count_nol; q++)
            {
                if (should_del == nol_stlb[q])
                    del = true;
            }

            if (del == true) {
                new_stlb--;
                for (int k = j + 1; k < stlb; k++)
                {
                    for (int t = 0; t < str; t++)
                    {
                        matrix[t][k - 1] = matrix[t][k];
                    }
                }

            }

        }

        for (int i = 0; i < str; i++) {

            matrix[i] = (int*)realloc(matrix[i], new_stlb * sizeof(int));
        }

        stlb = new_stlb;

    }

    std::cout << "Матрица после удаления столбцов: " << std::endl;
    vf::print_matrix(matrix, str, stlb);



    //

    for (int i = 0; i < str; i++)
        free(matrix[i]);
    free(matrix);
    if (nol_stlb != nullptr) {
        free(nol_stlb);
    }




    // Пункт 2

    std::cout << "Пункт 2" << std::endl;

    double a, b;
    std::cout << "Ввести a: " << std::endl;
    std::cin >> a;
    std::cout << "Ввести b: " << std::endl;
    std::cin >> b;

    double* pa = new double(a);
    double* pb = new double(b);

    *pa = *pa * 3;

    double temp = *pa;
    *pa = *pb;
    *pb = temp;

    std::cout << "Итог:" << std::endl;
    std::cout << "a = " << *pa << ", b = " << *pb << std::endl;

    delete pa;
    delete pb;

    return 0;
}