#include "Clock.hpp"
#include "Workshop.hpp"
#include <iostream>
#include <clocale>
#include <string>

bool Clock::is_day(int day, int month) {
    if (day < 1 || day > 31) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2 && day > 28) {
        return false;
    }
    return true;
}

bool Clock::is_month(int month) {
    if (month >= 1 && month <= 12) {
        return true;
    }
}

bool Clock::is_year(int year) {
    if (year >= 0) {
        return true;
    }
}

bool Clock::is_hours(int hours) {
    if (hours >= 0 && hours <= 23) {
        return true;
    }
}

bool Clock::is_minutes(int minutes) {
    if (minutes >= 0 && minutes <= 59) {
        return true;
    }
}

bool Clock::is_day_of_week(const std::string& day_of_week) {
    if (day_of_week == "Понедельник" || day_of_week == "Вторник" ||
        day_of_week == "Среда" || day_of_week == "Четверг" ||
        day_of_week == "Пятница" || day_of_week == "Суббота" ||
        day_of_week == "Воскресенье") {
        return true;
    }
}

void Clock::norm_time() {
    if (minutes_ >= 60) {
        hours_ += minutes_ / 60;
        minutes_ %= 60;
    }
    if (hours_ >= 24) {
        day_ += hours_ / 24;
        hours_ %= 24;
        norm_date();
    }
}

void Clock::norm_date() {
    while (true) {
        int days_in_month;
        if (month_ == 2) {
            days_in_month = 28;
        }
        else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
            days_in_month = 30;
        }
        else {
            days_in_month = 31;
        }

        if (day_ > days_in_month) {
            day_ -= days_in_month;
            month_++;
            if (month_ > 12) {
                month_ = 1;
                year_++;
            }
        }
        else {
            break;
        }
    }
}

Clock::Clock() : day_(1), month_(1), year_(2000), hours_(0), minutes_(0), day_of_week_("Четверг"), battery_(new Battery()) {
    std::cout << "Создан объект Clock (конструктор по умолчанию)" << std::endl;
}

Clock::Clock(int day, int month, int year, int hours, int minutes, const std::string& day_of_week) {
    if (is_month(month)) {
        month_ = month;
    }
    else {
        month_ = 1;
    }

    if (is_day(day, month_)) {
        day_ = day;
    }
    else {
        day_ = 1;
    }

    if (is_year(year)) {
        year_ = year;
    }
    else {
        year_ = 2000;
    }

    if (is_hours(hours)) {
        hours_ = hours;
    }
    else {
        hours_ = 0;
    }

    if (is_minutes(minutes)) {
        minutes_ = minutes;
    }
    else {
        minutes_ = 0;
    }

    if (is_day_of_week(day_of_week)) {
        day_of_week_ = day_of_week;
    }
    else {
        day_of_week_ = "Четверг";
    }

    battery_ = new Battery();

    std::cout << "Создан объект Clock (конструктор полного заполнения)" << std::endl;
}

Clock::Clock(const Clock& other) {
    day_ = other.day_;
    month_ = other.month_;
    year_ = other.year_;
    hours_ = other.hours_;
    minutes_ = other.minutes_;
    day_of_week_ = other.day_of_week_;

    if (other.battery_) {
        battery_ = new Battery(*other.battery_);
    }
    else {
        battery_ = new Battery();
    }
    std::cout << "Создан объект Clock (конструктор копирования)" << std::endl;
}

Clock::~Clock() {
    delete battery_;
    std::cout << "Вызван деструктор Clock" << std::endl;
}

Clock& Clock::operator=(const Clock& other) {
    if (this != &other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        minutes_ = other.minutes_;
        day_of_week_ = other.day_of_week_;

        delete battery_;
        if (other.battery_) {
            battery_ = new Battery(*other.battery_);
        }
        else {
            battery_ = new Battery();
        }
    }
    std::cout << "Оператор присваивания Clock" << std::endl;
    return *this;
}

Clock Clock::operator+(const Clock& other) {
    Clock temp = *this;

    bool this_later = false;
    bool other_later = false;


    if (year_ > other.year_) {
        this_later = true;
    }
    else if (year_ < other.year_) {
        other_later = true;
    }
    else if (month_ > other.month_) {
        this_later = true;
    }
    else if (month_ < other.month_) {
        other_later = true;
    }
    else if (day_ > other.day_) {
        this_later = true;
    }
    else if (day_ < other.day_) {
        other_later = true;
    }
    else if (hours_ > other.hours_) {
        this_later = true;
    }
    else if (hours_ < other.hours_) {
        other_later = true;
    }
    else if (minutes_ > other.minutes_) {
        this_later = true;
    }
    else if (minutes_ < other.minutes_) {
        other_later = true;
    }

    if (other_later) {
        temp.day_ = other.day_;
        temp.month_ = other.month_;
        temp.year_ = other.year_;
        temp.hours_ = other.hours_;
        temp.minutes_ = other.minutes_;
        temp.day_of_week_ = other.day_of_week_;
        temp.set_battery(other.get_battery());
    }

    temp.day_ += 7;
    temp.hours_ += 1;
    temp.norm_date();
    temp.norm_time();

    return temp;
}

Clock Clock::operator/(const Clock& other) {
    Clock temp = *this;

    bool this_earlier = false;
    bool other_earlier = false;

    if (year_ < other.year_) {
        this_earlier = true;
    }
    else if (year_ > other.year_) {
        other_earlier = true;
    }
    else if (month_ < other.month_) {
        this_earlier = true;
    }
    else if (month_ > other.month_) {
        other_earlier = true;
    }
    else if (day_ < other.day_) {
        this_earlier = true;
    }
    else if (day_ > other.day_) {
        other_earlier = true;
    }
    else if (hours_ < other.hours_) {
        this_earlier = true;
    }
    else if (hours_ > other.hours_) {
        other_earlier = true;
    }
    else if (minutes_ < other.minutes_) {
        this_earlier = true;
    }
    else if (minutes_ > other.minutes_) {
        other_earlier = true;
    }

    if (other_earlier) {
        temp.day_ = other.day_;
        temp.month_ = other.month_;
        temp.year_ = other.year_;
        temp.hours_ = other.hours_;
        temp.minutes_ = other.minutes_;
        temp.day_of_week_ = other.day_of_week_;
        temp.set_battery(other.get_battery());
    }
    temp.day_ += 3;
    temp.norm_date();

    return temp;
}

int Clock::get_day() const {
    return day_;
}

int Clock::get_month() const {
    return month_;
}

int Clock::get_year() const {
    return year_;
}

int Clock::get_hours() const {
    return hours_;
}

int Clock::get_minutes() const {
    return minutes_;
}

std::string Clock::get_day_of_week() const {
    return day_of_week_;
}

Battery Clock::get_battery() const {
    if (battery_) {
        return *battery_;
    }
    return Battery();
}

void Clock::set_day(const int new_day) {
    if (is_day(new_day, month_)) {
        day_ = new_day;
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_month(const int new_month) {
    if (is_month(new_month)) {
        if (is_day(day_, new_month)) {
            month_ = new_month;
        }
        else {
            std::cout << "Ошибка: текущий день (" << day_ << ") некорректен для месяца " << new_month << std::endl;
        }
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_year(const int new_year) {
    if (is_year(new_year)) {
        year_ = new_year;
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_hours(const int new_hours) {
    if (is_hours(new_hours)) {
        hours_ = new_hours;
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_minutes(const int new_minutes) {
    if (is_minutes(new_minutes)) {
        minutes_ = new_minutes;
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_day_of_week(const std::string& new_day_of_week) {
    if (is_day_of_week(new_day_of_week)) {
        day_of_week_ = new_day_of_week;
    }
    else {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
    }
}

void Clock::set_battery(const Battery& new_battery) {
    delete battery_;
    battery_ = new Battery(new_battery);
}

void Clock::set_battery(int now_charge, int max_charge) {
    delete battery_;
    battery_ = new Battery(now_charge, max_charge);
}

void Clock::Print() const {
    std::cout << "Дата: ";
    if (day_ < 10) {
        std::cout << "0";
    }
    std::cout << day_ << ".";

    if (month_ < 10) {
        std::cout << "0";
    }
    std::cout << month_ << ".";
    std::cout << year_ << std::endl;

    std::cout << "Время: ";
    if (hours_ < 10) {
        std::cout << "0";
    }
    std::cout << hours_ << ":";

    if (minutes_ < 10) {
        std::cout << "0";
    }
    std::cout << minutes_ << std::endl;

    std::cout << "День недели: " << day_of_week_ << std::endl;

    if (battery_) {
        battery_->Print();
    }
}

void Clock::add_minutes(int x) {
    if (x < 0) {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
        return;
    }

    if (battery_) {
        if (!battery_->is_charge()) {
            std::cout << "Батарейка разряжена. Добавить время нельзя." << std::endl;
            return;
        }

        int days_to_add = x / 1440;
        int ost_minutes = x % 1440;

        if (days_to_add > 0) {
            if (battery_->now_charge_ >= days_to_add) {
                battery_->use_charge(days_to_add);
                minutes_ += x;
            }
            else {
                int d_days = battery_->now_charge_;
                std::cout << "Недостаточно заряда батарейки! Добавляем только "
                    << d_days * 1440 << " минут" << std::endl;
                minutes_ += d_days * 1440;
                battery_->use_charge(d_days);
            }
        }
        else {
            minutes_ += x;
        }
    }
    else {
        minutes_ += x;
    }

    norm_time();
    std::cout << "Добавлено " << x << " минут" << std::endl;
}
