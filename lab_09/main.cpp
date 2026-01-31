#include <iostream>
#include <clocale>
#include <string>

class Clock
{
private:
    int day_;
    int month_;
    int year_;
    int hours_;
    int minutes_;
    std::string day_of_week_;

protected:
    bool is_day(int day, int month) {
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

    bool is_month(int month) {
        if (month >= 1 && month <= 12) {
            return true;
        }
    }

    bool is_year(int year) {
        if (year >= 0) {
            return true;
        }
    }

    bool is_hours(int hours) {
        if (hours >= 0 && hours <= 23) {
            return true;
        }
    }

    bool is_minutes(int minutes) {
        if (minutes >= 0 && minutes <= 59) {
            return true;
        }
    }

    bool is_day_of_week(const std::string& day_of_week) {
        if (day_of_week == "Понедельник" || day_of_week == "Вторник" ||
            day_of_week == "Среда" || day_of_week == "Четверг" ||
            day_of_week == "Пятница" || day_of_week == "Суббота" ||
            day_of_week == "Воскресенье") {
            return true;
        }
    }

    void norm_time() {
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

    void norm_date() {
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

public:
    Clock() : day_(1), month_(1), year_(2000), hours_(0), minutes_(0), day_of_week_("Четверг") {
        std::cout << "Создан объект (конструктор по умолчанию)" << std::endl;
    }

    Clock(int day, int month, int year, int hours, int minutes, const std::string& day_of_week) {
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
            day_of_week_ = "Понедельник";
        }
        std::cout << "Создан объект (конструктор полного заполнения)" << std::endl;
    }

    Clock(const Clock& other) {
        day_ = other.day_;
        month_ = other.month_;
        year_ = other.year_;
        hours_ = other.hours_;
        minutes_ = other.minutes_;
        day_of_week_ = other.day_of_week_;
        std::cout << "Создан объект (конструктор копирования)" << std::endl;
    }

    ~Clock() {
        std::cout << "Вызван деструктор" << std::endl;
    }

    int get_day() const {
        return day_;
    }
    int get_month() const {
        return month_;
    }
    int get_year() const {
        return year_;
    }
    int get_hours() const {
        return hours_;
    }
    int get_minutes() const {
        return minutes_;
    }
    std::string get_day_of_week() const {
        return day_of_week_;
    }

    void set_day_of_week(const std::string& new_day_of_week) {
        if (is_day_of_week(new_day_of_week)) {
            day_of_week_ = new_day_of_week;
        }
        else {
            std::cout << "Ошибка: неправильный ввод" << std::endl;
        }
    }

    void Print() const {
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
    }

    void add_minutes(int x) {
        if (x < 0) {
            std::cout << "Ошибка: неправильный ввод" << std::endl;
            return;
        }
        minutes_ += x;
        norm_time();
        std::cout << "Добавлено " << x << " минут" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    Clock clock1;
    clock1.Print();

    std::cout << "\n";
    Clock clock2(31, 1, 2026, 17, 30, "Пятница");
    clock2.Print();

    std::cout << "\n";
    Clock clock3(clock2);
    clock3.Print();

    std::cout << "\n";
    clock1.set_day_of_week("Суббота");
    clock1.Print();

    std::cout << "\n";
    clock1.set_day_of_week("ААААААА");

    std::cout << "\n";
    Clock clock4(31, 12, 2023, 23, 30, "Воскресенье");
    clock4.Print();

    std::cout << "\n";
    clock4.add_minutes(30);
    clock4.Print();

    std::cout << "\n";
    clock4.add_minutes(60 * 24);
    clock4.Print();

    std::cout << "\n";
    clock4.add_minutes(60 * 24 * 10);
    clock4.Print();

    return 0;
}