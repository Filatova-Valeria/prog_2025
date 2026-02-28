#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Clock.hpp"

struct Battery {
    int now_charge_;
    int max_charge_;

    Battery();

    Battery(int now_charge, int max_charge);

    Battery(const Battery& other);

    void Print() const;

    bool is_charge() const;

    void use_charge(int k);
};

class Workshop {
private:
    std::string address_;
    std::vector<Clock> clocks_;

public:
    Workshop();

    Workshop(const std::string& address);

    Workshop(const Workshop& other);

    ~Workshop();

    void replace_battery(int clock_index, int new_max_charge);

    void Print() const;

    void add_clock(const Clock& clock);
};