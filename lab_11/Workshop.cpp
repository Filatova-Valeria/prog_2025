#include "Workshop.hpp"
#include <iostream>
#include <stdexcept>

Battery::Battery() : now_charge_(100), max_charge_(100) {
    std::cout << "Создана батарейка (конструктор по умолчанию)" << std::endl;
}

Battery::Battery(int now_charge, int max_charge) {
    if (max_charge <= 0) {
        max_charge_ = 100;
    }
    else {
        max_charge_ = max_charge;
    }

    if (now_charge < 0 || now_charge > max_charge_) {
        now_charge_ = max_charge_;
    }
    else {
        now_charge_ = now_charge;
    }
    std::cout << "Создана батарейка (конструктор с параметрами)" << std::endl;
}

Battery::Battery(const Battery& other) {
    max_charge_ = other.max_charge_;
    now_charge_ = other.now_charge_;
    std::cout << "Создана батарейка (конструктор копирования)" << std::endl;
}

void Battery::Print() const {
    std::cout << "Батарейка: " << now_charge_ << "/" << max_charge_ << std::endl;
}

bool Battery::is_charge() const {
    return now_charge_ > 0;
}

void Battery::use_charge(int k) {
    if (k < 0) return;
    if (now_charge_ >= k) {
        now_charge_ -= k;
    }
    else {
        now_charge_ = 0;
    }
}


Workshop::Workshop() : address_("Неизвестный адрес") {
    std::cout << "Создана мастерская (конструктор по умолчанию)" << std::endl;
}

Workshop::Workshop(const std::string& address) {
    address_ = address;
    std::cout << "Создана мастерская (конструктор с параметрами)" << std::endl;
}

Workshop::Workshop(const Workshop& other) {
    address_ = other.address_;
    clocks_ = other.clocks_;
    std::cout << "Создана мастерская (конструктор копирования)" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Вызван деструктор мастерская" << std::endl;
}

void Workshop::replace_battery(int clock_index, int new_max_charge) {
    if (clock_index >= 0 && clock_index < static_cast<int>(clocks_.size())) {
        clocks_[clock_index].set_battery(new_max_charge, new_max_charge);
        std::cout << "Батарейка заменена в часах #" << clock_index + 1 << std::endl;
    }
    else {
        std::cout << "Ошибка: неверный индекс часов" << std::endl;
    }
}

void Workshop::Print() const {
    std::cout << "Мастерская:" << std::endl;
    std::cout << "Адрес: " << address_ << std::endl;
    std::cout << "Часов в работе: " << clocks_.size() << std::endl;
    if (clocks_.empty()) {
        std::cout << "Нет часов в работе" << std::endl;
    }
    else {
        for (size_t i = 0; i < clocks_.size(); ++i) {
            std::cout << "\n Часы #" << i + 1 << ":" << std::endl;
            clocks_[i].Print();
        }
    }
}

void Workshop::add_clock(const Clock& clock) {
    clocks_.push_back(clock);
    std::cout << "Часы добавлены в мастерскую" << std::endl;
}
