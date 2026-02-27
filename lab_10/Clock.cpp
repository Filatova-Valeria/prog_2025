#include "Clock.hpp"
#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

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

Clock::Clock() : day_(1), month_(1), year_(2000), hours_(0), minutes_(0), tasks_() {
    std::cout << "Создан объект (конструктор по умолчанию)" << std::endl;
}

Clock::Clock(int day, int month, int year, int hours, int minutes, const std::vector<std::string>& tasks) {
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

    tasks_ = tasks;

    std::cout << "Создан объект (конструктор полного заполнения)" << std::endl;
}

Clock::Clock(const Clock& other) {
    day_ = other.day_;
    month_ = other.month_;
    year_ = other.year_;
    hours_ = other.hours_;
    minutes_ = other.minutes_;
    tasks_ = other.tasks_;
    std::cout << "Создан объект (конструктор копирования)" << std::endl;
}

Clock::~Clock() {
    tasks_.clear();
    std::cout << "Вызван деструктор" << std::endl;
}

Clock& Clock::operator=(const Clock& other) {
    if (this != &other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        minutes_ = other.minutes_;
        tasks_ = other.tasks_;
    }
    std::cout << "Оператор присваивания" << std::endl;
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
    }

    temp.day_ += 7;
    temp.hours_ += 1;
    temp.norm_date();
    temp.norm_time();

    std::vector<std::string> un_tasks;

    for (int i = 0; i < tasks_.size(); i++) {
        std::string cur = tasks_[i];
        bool found = false;
        for (int j = 0; j < un_tasks.size(); j++) {
            if (un_tasks[j] == cur) {
                found = true;
                break;
            }
        }
        if (!found) {
            un_tasks.push_back(cur);
        }
    }

    for (int i = 0; i < other.tasks_.size(); i++) {
        std::string now_task = other.tasks_[i];
        bool found = false;
        for (int j = 0; j < un_tasks.size(); j++) {
            if (un_tasks[j] == now_task) {
                found = true;
                break;
            }
        }
        if (!found) {
            un_tasks.push_back(now_task);
        }
    }
    temp.tasks_ = un_tasks;
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
    }
    temp.day_ += 3;
    temp.norm_date();

    srand(time(NULL));
    std::vector<std::string> new_tasks;

    if (!tasks_.empty()) {
        int count1 = rand() % tasks_.size() + 1;

        std::vector<std::string> temp1 = tasks_;

        for (int i = 0; i < count1; i++) {
            if (temp1.empty()) break;

            int random_index = rand() % temp1.size();
            std::string selected = temp1[random_index];
            temp1.erase(temp1.begin() + random_index);
            new_tasks.push_back(selected);
        }
    }

    if (!other.tasks_.empty()) {
        int count2 = rand() % other.tasks_.size() + 1;

        std::vector<std::string> temp2 = other.tasks_;

        for (int i = 0; i < count2; i++) {
            if (temp2.empty()) break;

            int random_index = rand() % temp2.size();
            std::string selected = temp2[random_index];
            temp2.erase(temp2.begin() + random_index);

            bool exist = false;

            for (int j = 0; j < new_tasks.size(); j++) {
                if (new_tasks[j] == selected) {
                    exist = true;
                    break;
                }
            }

            if (!exist) {
                new_tasks.push_back(selected);
            }
        }
    }

    temp.tasks_ = new_tasks;

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

std::vector<std::string> Clock::get_tasks() const {
    return tasks_;
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

    std::cout << "Дела: ";
    if (tasks_.empty()) {
        std::cout << "(нет)";
    }
    else {
        for (int i = 0; i < tasks_.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << tasks_[i];
        }
    }
    std::cout << std::endl;
}

void Clock::add_minutes(int x) {
    if (x < 0) {
        std::cout << "Ошибка: неправильный ввод" << std::endl;
        return;
    }
    minutes_ += x;
    norm_time();
    std::cout << "Добавлено " << x << " минут" << std::endl;
}