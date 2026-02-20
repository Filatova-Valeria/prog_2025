#include "Clock.hpp"
#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<std::string> tasks1 = { "a", "b", "v" };
    std::vector<std::string> tasks2 = { "b", "p", "r" };

    Clock clock1(27, 12, 2005, 12, 0, tasks1);
    Clock clock2(5, 6, 2003, 10, 0, tasks2);

    std::cout << "[27.12.2005,12:00,(a,b,v)] + [05.06.2003,10:00,(b,p,r)] = " << std::endl;
    Clock res_plus = clock1 + clock2;
    res_plus.Print();

    std::cout << "[27.12.2005,12:00,(a,b,v)] / [05.06.2003,10:00,(b,p,r)] = " << std::endl;
    Clock res_div = clock1 / clock2;
    res_div.Print();

    Clock clock3(clock1);
    clock3.Print();

    Clock clock4;
    clock4 = clock2;
    clock4.Print();

    return 0;
}