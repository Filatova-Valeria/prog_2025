#pragma once
#include <iostream>
#include <string>

struct Battery;

class Clock
{
private:
    int day_;
    int month_;
    int year_;
    int hours_;
    int minutes_;
    std::string day_of_week_;
    Battery* battery_;

protected:
    bool is_day(int day, int month);

    bool is_month(int month);

    bool is_year(int year);

    bool is_hours(int hours);

    bool is_minutes(int minutes);

    bool is_day_of_week(const std::string& day_of_week);

    void norm_time();

    void norm_date();

public:
    Clock();

    Clock(int day, int month, int year, int hours, int minutes, const std::string& day_of_week);

    Clock(const Clock& other);

    ~Clock();

    Clock& operator=(const Clock& other);

    Clock operator+(const Clock& other);

    Clock operator/(const Clock& other);

    int get_day() const;
    int get_month() const;
    int get_year() const;
    int get_hours() const;
    int get_minutes() const;
    std::string get_day_of_week() const;
    Battery get_battery() const;

    void set_day(const int new_day);
    void set_month(const int new_month);
    void set_year(const int new_year);
    void set_hours(const int new_hours);
    void set_minutes(const int new_minutes);
    void set_day_of_week(const std::string& new_day_of_week);
    void set_battery(const Battery& new_battery);
    void set_battery(int now_charge, int max_charge);

    void Print() const;

    void add_minutes(int x);
};
