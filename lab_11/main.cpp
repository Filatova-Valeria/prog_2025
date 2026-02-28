#include "Clock.hpp"
#include "Workshop.hpp"
#include <iostream>
#include <clocale>
#include <string>


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "-----------------------------------------------" << std::endl;
    Battery battery1;
    Battery battery2(75, 100);
    Battery battery3(battery2);

    battery1.Print();
    battery2.Print();
    battery3.Print();
    std::cout << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    Clock clock1;
    Clock clock2(15, 3, 2024, 14, 30, "Пятница");
    clock2.Print();
    std::cout << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Добавляем 1 день (1440 минут) к часам:" << std::endl;
    clock2.add_minutes(1440);
    clock2.Print();
    std::cout << std::endl;

    std::cout << "Добавляем 3 дня (4320 минут) к часам:" << std::endl;
    clock2.add_minutes(4320);
    clock2.Print();
    std::cout << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    Workshop workshop1("ул. Ленина, д. 10");
    Workshop workshop2(workshop1);

    std::cout << "\nДобавляем часы в мастерскую:" << std::endl;
    workshop1.add_clock(clock1);
    workshop1.add_clock(clock2);

    Clock clock3(20, 12, 2023, 10, 45, "Среда");
    clock3.set_battery(50, 50);
    workshop1.add_clock(clock3);

    workshop1.Print();
    std::cout << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    Clock clock4(1, 1, 2024, 0, 0, "Понедельник");
    Clock clock5(5, 1, 2024, 12, 0, "Пятница");

    std::cout << "Clock4:" << std::endl;
    clock4.Print();
    std::cout << "Clock5:" << std::endl;
    clock5.Print();

    Clock clock6 = clock4 + clock5;
    std::cout << "\nclock4 + clock5:" << std::endl;
    clock6.Print();

    Clock clock7 = clock4 / clock5;
    std::cout << "\nclock4 / clock5:" << std::endl;
    clock7.Print();
    std::cout << std::endl;

    return 0;
}
