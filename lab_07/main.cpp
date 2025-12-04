#include <iostream>
#include <clocale>
#include <vector>
#include <array>
#include <ctime>

// функции для 1 пункта:

void show_arr(std::vector<int>& arr) {
    std::cout << "[";
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < (arr.size() - 1)) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}

void el_to_beg(std::vector<int>& arr) {
    int element;
    std::cout << "Введите элмент: " << std::endl;
    std::cin >> element;
    arr.insert(arr.begin(), element);
    std::cout << "Элемент добавлен." << std::endl;
}

void el_to_end(std::vector<int>& arr) {
    int element;
    std::cout << "Введите элмент: " << std::endl;
    std::cin >> element;
    arr.push_back(element);
    std::cout << "Элемент добавлен." << std::endl;
}

void clear_arr(std::vector<int>& arr) {
    arr.clear();
    std::cout << "Массив очищен." << std::endl;
}

void poisk_el(std::vector<int>& arr) {
    int element;
    std::cout << "Введите элемент" << std::endl;
    std::cin >> element;

    bool flag = false;
    std::cout << "Индексы: [";
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            if (flag) {
                std::cout << ", ";
            }
            std::cout << i;
            flag = true;
        }
    }
    std::cout << "]" << std::endl;
}

void variant(std::vector<int>& arr) {
    std::cout << "До:";
    show_arr(arr);

    std::vector<int> res;
    for (int i = (arr.size() - 1); i >= 0; --i) {
        if ((arr[i] % 7) != 0 || arr[i] == 777) {
            res.push_back(arr[i]);
        }
    }

    arr.resize(res.size());
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = res[i];
    }

    std::cout << "После:";
    show_arr(arr);
}

// функции для 2 пункта:

void show(std::array<int, 10>& arr) {
    const int size = arr.size();
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < (size - 1)) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;

}

void znach_arr(std::array<int, 10>& arr) {
    std::srand(std::time(nullptr));
    const int size = arr.size();

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 21 - 10;
    }
    show(arr);
}

void sort_po_znach(std::array<int, 10> arr) {
    std::cout << "\nПередача аргументов в функцию по значению: " << std::endl;
    const int size = arr.size();
    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::cout << "Сортировка по возрастанию: ";
    show(arr);
    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if (arr[i] < arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::cout << "Сортировка по убыванию: ";
    show(arr);
    std::cout << "(Создается полная копия всего массива,\nтратится дополнительная память на копию, все изменения происходят только в копии,\nоригинальный массив остается неизменным)" << std::endl;
}

void sort_po_ssylke(std::array<int, 10>& arr) {
    std::cout << "\nПередача аргументов в функцию по ссылке: " << std::endl;
    const int size = arr.size();
    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::cout << "Сортировка по возрастанию: ";
    show(arr);
    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if (arr[i] < arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    std::cout << "Сортировка по убыванию: ";
    show(arr);
    std::cout << "(Функция получает доступ к оригинальному массиву, нет дополнительных затрат на копирование,\nвсе изменения затрагивают оригинальный массив, доступ к элементам как обычно (arr[i]))" << std::endl;
}

void sort_po_ukaz(std::array<int, 10>* arr) {
    std::cout << "\nПередача аргументов в функцию по указателю: " << std::endl;
    const int size = (*arr).size();

    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if ((*arr)[i] > (*arr)[j]) {
                std::swap((*arr)[i], (*arr)[j]);
            }
        }
    }
    std::cout << "Сортировка по возрастанию: ";
    show(*arr);

    for (int i = 0; i < (size - 1); ++i) {
        for (int j = (i + 1); j < size; ++j) {
            if ((*arr)[i] < (*arr)[j]) {
                std::swap((*arr)[i], (*arr)[j]);
            }
        }
    }
    std::cout << "Сортировка по убыванию: ";
    show(*arr);
    std::cout << "(Функция получает адрес массива в памяти, нет дополнительных затрат на копирование,\nвсе изменения затрагивают оригинальный массив,\nдля доступа : (*arr)[i] При вызове : &arr (передаем адрес)" << std::endl;
}





int main() {

    setlocale(LC_ALL, "Russian");

    // 1 пункт

    std::cout << "Пункт 1" << std::endl;

    std::vector<int> vec = {1, 2, 3};

    int punkt;

    std::cout << "Меню:" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Просмотр массива" << std::endl;
    std::cout << "2. Добавить элемент в начало" << std::endl;
    std::cout << "3. Добавить элемент в конец" << std::endl;
    std::cout << "4. Очистка всего массива" << std::endl;
    std::cout << "5. Поиск элемента в массиве" << std::endl;
    std::cout << "6. Задание варианта" << std::endl;
    std::cout << "Выберите пункт: " << std::endl;

    do {
        std::cin >> punkt;

        switch (punkt) {
            case 0: {
                std::cout << "0. Выход" << std::endl;
                break;
            }
            case 1: {
                std::cout << "1. Просмотр массива: " << std::endl;
                show_arr(vec);
                break;
            }
            case 2: {
                std::cout << "2. Добавить элемент в начало: " << std::endl;
                el_to_beg(vec);
                break;
            }
            case 3: {
                std::cout << "3. Добавить элемент в конец: " << std::endl;
                el_to_end(vec);
                break;
            }
            case 4: {
                std::cout << "4. Очистка всего массива: " << std::endl;
                clear_arr(vec);
                break;
            }
            case 5: {
                std::cout << "5. Поиск элемента в массиве:" << std::endl;
                poisk_el(vec);
                break;
            }
            case 6: {
                std::cout << "6. Задание варианта: " << std::endl;
                variant(vec);
                break;
            }
            default: {
                std::cout << "Ошибка. Введите цифру от 0 до 6" << std::endl;
                break;
            }
        }
    } while (punkt != 0);

   // 2 пункт
    std::cout << "\nПункт 2" << std::endl;
    std::array<int, 10> arr;
    znach_arr(arr);
    sort_po_znach(arr);
    show(arr);
    sort_po_ssylke(arr);
    show(arr);
    sort_po_ukaz(&arr);
    show(arr);

    return 0;
}

/*
3 пункт
В пункте 1 нужно использовать std::vector, потому что:
Требуется изменение размера
Нужны операции добавления/удаления элементов
Размер массива неизвестен

В пункте 2 нет нужно использовать std::array, потому что:
Размер фиксирован (10 элементов)
Массив заполняется один раз и не меняет размер

Когда vector и array выполняют одинаковую роль:
Когда размер известен и не меняется
Когда нужен только доступ к элементам без изменения размера
*/
