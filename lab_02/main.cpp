#include <iostream>
#include <clocale>
#include <bitset>

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "����� 1" << std::endl;
    short A;
    int i;
    int i_bit; // i-�� ��� ����� A
    short A_new; // �������� ����� A
    int num_1;
    int num_2;
    int num_1_abs;
    int num_2_abs;

    std::cout << "������ ����� A:" << std::endl;
    std::cin >> A;
    std::cout << "������ ����� ���� (i):" << std::endl;
    std::cin >> i;

    if (i < 0 || i > 7) {
        std::cout << "������������ ���� i: ������� �� 1 �� 7" << std::endl;
        return 1;
    }

    std::bitset<8> A_2(A);
    std::cout << A << " = " << A_2 << " (� �������� �������)" << std::endl;

    i_bit = (A >> i) & 1;
    std::cout << i << " = " << i_bit << " (i-�� ��� ����� A)" << std::endl;

    if (i_bit != 0) {
        A_new = A ^ (1 << i);
        std::bitset<8> A_new_2(A_new);
        std::cout << "�������� ����� A: " << A_new << " = " << A_new_2 << std::endl;
    }
    else {
        std::cout << "������ ��� ����� �����:" << std::endl;
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
        else { // ������ �����, ������� ����� ����� ����� �����
            std::cout << num_1 << num_1 << std::endl;
        }
    }



    std::cout << "����� 2" << std::endl;
    int N;
    int M;
    int bochonok;
    std::cout << "������ ������ ����� �������:" << std::endl;
    std::cin >> N;
    std::cout << "������ ������ ����� �������:" << std::endl;
    std::cin >> M;
    bochonok = N * 10 + M;
    switch(bochonok) {
        case 11: std::cout << "���������� �������"; break;
        case 22: std::cout << "����-������"; break;
        case 33: std::cout << "��������"; break;
        case 44: std::cout << "���������"; break;
        case 55: std::cout << "��������"; break;
        case 66: std::cout << "�������"; break;
        case 77: std::cout << "��������"; break;
        case 88: std::cout << "�������"; break;
        default: std::cout << "����� �� �����"; break;
    }

    return 0;
}