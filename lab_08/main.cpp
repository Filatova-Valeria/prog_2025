#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <iomanip>

struct energy_drink {
    std::string name;      // название напитка
    std::string flavor;    // вкус
    double rating;          // оценка от 0.0 до 5.0
    energy_drink* similar;   // указатель на похожий напиток (название)
    double price;          // цена
};



energy_drink* create_new_drink(std::string name, std::string flavor, double rating, double price) {
    energy_drink* new_drink = new energy_drink;
    new_drink->name = name;
    new_drink->flavor = flavor;
    new_drink->rating = rating;
    new_drink->price = price;
    new_drink->similar = nullptr;
    return new_drink;
}

void view_drink(energy_drink* drink) {
    std::cout << "Информация о напитке:" << std::endl;
    std::cout << "Название: " << drink->name << std::endl;
    std::cout << "Вкус: " << drink->flavor << std::endl;
    std::cout << "Оценка: " << std::fixed << std::setprecision(1) << drink->rating << "/5.0" << std::endl;
    std::cout << "Цена: " << drink->price << " руб." << std::endl;
    if (drink->similar != nullptr) {
        std::cout << "Похожий напиток: " << drink->similar->name << std::endl;
    }
    else {
        std::cout << "Похожий напиток: нет" << std::endl;
    }
}

void view_catalog(std::vector<energy_drink*>& catalog) {
    std::cout << "Каталог энергетических напитков:" << std::endl;
    for (int i = 0; i < catalog.size(); i++) {
        std::cout << "\n[" << i + 1 << "] " << catalog[i]->name << std::endl;
        std::cout << "   Вкус: " << catalog[i]->flavor << std::endl;
        std::cout << "   Оценка: " << std::fixed << std::setprecision(1) << catalog[i]->rating << "/5.0" << std::endl;
        std::cout << "   Цена: " << catalog[i]->price << " руб." << std::endl;
        if (catalog[i]->similar != nullptr) {
            std::cout << "   Похожий на: " << catalog[i]->similar->name << std::endl;
        }
    }
    std::cout << "\nВсего напитков: " << catalog.size() << std::endl;
}

void sort_by_price(std::vector<energy_drink*>& catalog) {
    int n = catalog.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (catalog[j]->price > catalog[j + 1]->price) {
                energy_drink* temp = catalog[j];
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
    std::cout << "Каталог отсортирован по возрастанию цены." << std::endl;
}

void show_unique_flavors(std::vector<energy_drink*>& catalog) {
    bool found_unique = false;

    for (int i = 0; i < catalog.size(); i++) {
        if (catalog[i]->similar == nullptr) {
            std::cout << "• " << catalog[i]->name << " (" << catalog[i]->flavor << ")" << std::endl;
            found_unique = true;
        }
    }

    if (!found_unique) {
        std::cout << "Напитков с уникальными вкусами нет" << std::endl;
    }
}

void show_by_flavors(std::vector<energy_drink*>& catalog) {
    int total_drinks = catalog.size();

    // Проходим по всем напиткам
    for (int i = 0; i < total_drinks; i++) {
        // Проверяем, был ли уже выведен этот вкус
        bool found_earlier = false;
        for (int check = 0; check < i; check++) {
            if (catalog[check]->flavor == catalog[i]->flavor) {
                found_earlier = true;
                break;
            }
        }

        // Если этот вкус встречается впервые
        if (!found_earlier) {
            std::string flavor_to_print = catalog[i]->flavor;

            std::cout << "\nВкус: " << flavor_to_print << std::endl;
            std::cout << "Напитки:" << std::endl;

            int item_number = 1;

            // Ищем все напитки с таким вкусом
            for (int j = 0; j < total_drinks; j++) {
                if (catalog[j]->flavor == flavor_to_print) {
                    std::cout << "  " << item_number << ". " << catalog[j]->name;

                    // Обрабатываем переходы к похожим напиткам
                    energy_drink* similar = catalog[j]->similar;
                    if (similar != nullptr) {
                        std::cout << " похож на " << similar->name;
                    }
                    std::cout << std::endl;
                    item_number++;
                }
            }
        }
    }
}

void add_new_drink(std::vector<energy_drink*>& catalog) {
    std::string name, flavor;
    double rating, price;

    std::cout << "Введите название напитка: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите вкус напитка: ";
    std::getline(std::cin, flavor);

    std::cout << "Введите оценку (0.0-5.0): ";
    std::cin >> rating;

    std::cout << "Введите цену (руб.): ";
    std::cin >> price;

    energy_drink* new_drink = create_new_drink(name, flavor, rating, price);

    // указать похожий напиток
    if (!catalog.empty()) {
        std::cout << "\nХотите указать похожий напиток? (1 - да, 0 - нет): ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Доступные напитки:" << std::endl;
            for (int i = 0; i < catalog.size(); i++) {
                std::cout << i + 1 << ". " << catalog[i]->name << std::endl;
            }

            std::cout << "Выберите номер похожего напитка (0 - не указывать): ";
            int similar_index;
            std::cin >> similar_index;

            if (similar_index > 0 && similar_index <= catalog.size()) {
                new_drink->similar = catalog[similar_index - 1];
            }
        }
    }

    catalog.push_back(new_drink);
    std::cout << "Напиток добавлен в каталог!" << std::endl;
}

std::vector<energy_drink*> make_catalog() {
    std::vector<energy_drink*> catalog;

    // Создаем 6 напитков
    energy_drink* drink1 = create_new_drink("Red Bull", "Классический", 4.2, 120.0);
    energy_drink* drink2 = create_new_drink("Burn", "Яблоко", 3.8, 90.0);
    energy_drink* drink3 = create_new_drink("Adrenaline Rush", "Цитрус", 4.0, 110.0);
    energy_drink* drink4 = create_new_drink("Monster Energy", "Тропик", 4.5, 150.0);
    energy_drink* drink5 = create_new_drink("Flash", "Кола", 3.5, 70.0);
    energy_drink* drink6 = create_new_drink("Gorilla Energy", "Лесные ягоды", 4.1, 130.0);

    // Настраиваем похожие напитки
    drink1->similar = drink3;  // Red Bull похож на Adrenaline Rush
    drink2->similar = drink5;  // Burn похож на Flash
    drink3->similar = drink1;  // Adrenaline Rush похож на Red Bull
    drink4->similar = nullptr; // Monster Energy уникальный
    drink5->similar = drink2;  // Flash похож на Burn
    drink6->similar = drink4;  // Gorilla Energy похож на Monster Energy

    catalog.push_back(drink1);
    catalog.push_back(drink2);
    catalog.push_back(drink3);
    catalog.push_back(drink4);
    catalog.push_back(drink5);
    catalog.push_back(drink6);

    return catalog;
}

void clear_memory(std::vector<energy_drink*>& catalog) {
    for (int i = 0; i < catalog.size(); i++) {
        delete catalog[i];
        catalog[i] = nullptr;  // дополнительная безопасность
    }
    catalog.clear();
}


int main() {

    setlocale(LC_ALL, "Russian");

    std::vector<energy_drink*> catalog = make_catalog();
    int punkt;

    std::cout << "Меню:" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "1. Просмотр каталога" << std::endl;
    std::cout << "2. Просмотр конкретного напитка" << std::endl;
    std::cout << "3. Добавить новый напиток" << std::endl;
    std::cout << "4. Сортировка каталога по стоимости" << std::endl;
    std::cout << "5. Вывод напитков с уникальными вкусами" << std::endl;
    std::cout << "6. Показать напитки по вкусам" << std::endl;

    do {
        std::cin >> punkt;

        switch (punkt) {
            case 0: {
                std::cout << "0. Выход" << std::endl;
                break;
            }
            case 1: {
                std::cout << "1. Просмотр каталога:" << std::endl;
                view_catalog(catalog);
                break;
            }
            case 2: {
                std::cout << "2. Просмотр конкретного напитка:" << std::endl;
                if (!catalog.empty()) {
                    int drink_num;
                    std::cout << "Введите номер напитка (1-" << catalog.size() << "): ";
                    std::cin >> drink_num;
                    if (drink_num >= 1 && drink_num <= catalog.size()) {
                        view_drink(catalog[drink_num - 1]);
                    }
                    else {
                        std::cout << "Неверный номер напитка." << std::endl;
                    }
                }
                else {
                    std::cout << "Каталог пустой." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "3. Добавить новый напиток: " << std::endl;
                add_new_drink(catalog);
                break;
            }
            case 4: {
                std::cout << "4. Сортировка каталога по стоимости: " << std::endl;
                if (!catalog.empty()) {
                    sort_by_price(catalog);
                }
                else {
                    std::cout << "Каталог пустой." << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "5. Вывод напитков с уникальными вкусами: " << std::endl;
                if (!catalog.empty()) {
                    show_unique_flavors(catalog);
                }
                else {
                    std::cout << "Каталог пустой." << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "6. Показать напитки по вкусам:" << std::endl;
                if (!catalog.empty()) {
                    show_by_flavors(catalog);
                }
                else {
                    std::cout << "Каталог пустой" << std::endl;
                }
                break;
            }
            default: {
                std::cout << "Ошибка. Введите цифру от 0 до 6" << std::endl;
            }
        }
    } while (punkt != 0);
    
    clear_memory(catalog);
    return 0;
}