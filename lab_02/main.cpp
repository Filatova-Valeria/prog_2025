#include <iostream>
#include <clocale>
#include <bitset>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Пункт 1" << std::endl;
    short A;
    int i;
    int i_bit; // i-ый бит числа A
    short A_new; // итоговое число A
    int num_1;
    int num_2;
    int num_1_abs;
    int num_2_abs;

    std::cout << "Ввести число A:" << std::endl;
    std::cin >> A;
    std::cout << "Ввести номер бита (i):" << std::endl;
    std::cin >> i;

    if (i < 0 || i > 7) {
        std::cout << "Неправильный ввод i: введите от 1 до 7" << std::endl;
        return 1;
    }

    std::bitset<8> A_2(A);
    std::cout << A << " = " << A_2 << " (в двоичной системе)" << std::endl;

    i_bit = (A >> i) & 1;
    std::cout << i << " = " << i_bit << " (i-ый бит числа A)" << std::endl;

    if (i_bit != 0) {
        A_new = A ^ (1 << i);
        std::bitset<8> A_new_2(A_new);
        std::cout << "Итоговое число A: " << A_new << " = " << A_new_2 << std::endl;
    }
    else {
        std::cout << "Ввести два целых числа:" << std::endl;
        std::cin >> num_1 >> num_2;
        if (num_1 < 0) {
            num_1_abs = num_1 * (-1);
        }
        else {
            num_1_abs = num_1;
        }
        if (num_2 < 0) {
            num_2_abs = num_2 * (-1);
        }
        else {
            num_2_abs = num_2;
        }
        if (num_1_abs > num_2_abs) {
            std::cout << num_1 << num_1 << std::endl;
        }
        else if (num_2_abs > num_1_abs) {
            std::cout << num_2 << num_2 << std::endl;
        }
        else { // модули равны, поэтому можем взять любое число
            std::cout << num_1 << num_1 << std::endl;
        }
    }



    std::cout << "Пункт 2" << std::endl;
    int N;
    int M;
    int bochonok;
    std::cout << "Ввести первую цифру бочонка:" << std::endl;
    std::cin >> N;
    std::cout << "Ввести вторую цифру бочонка:" << std::endl;
    std::cin >> M;
    bochonok = N * 10 + M;
    switch(bochonok) {
        case 11: std::cout << "Барабанные палочки"; break;
        case 22: std::cout << "Гуси-лебеди"; break;
        case 33: std::cout << "Богатыри"; break;
        case 44: std::cout << "Стульчики"; break;
        case 55: std::cout << "Перчатки"; break;
        case 66: std::cout << "Валенки"; break;
        case 77: std::cout << "Топорики"; break;
        case 88: std::cout << "Матрёшки"; break;
        default: std::cout << "Номер не дубль"; break;
    }

    return 0;
}