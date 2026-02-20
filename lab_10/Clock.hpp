#pragma once
#include <iostream>
#include <string>
#include <vector>

class Clock
{
private:
    int day_;
    int month_;
    int year_;
    int hours_;
    int minutes_;
    std::vector<std::string> tasks_;

protected:
    bool is_day(int day, int month);

    bool is_month(int month);

    bool is_year(int year);

    bool is_hours(int hours);

    bool is_minutes(int minutes);

    void norm_time();

    void norm_date();

public:
    Clock();

    Clock(int day, int month, int year, int hours, int minutes, const std::vector<std::string>& tasks);

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
    std::vector<std::string> get_tasks() const;

    void Print() const;

    void add_minutes(int x);
};