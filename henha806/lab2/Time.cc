#include <iostream>
#include <string>

#include "Time.h"

// Constructors
Time::Time()
    : Time(0, 0, 0)
    {}

Time::Time(int hh, int mm, int ss)
    : hour{}, minute{}, second{}
    {
        set_hour(hh);
        set_minute(mm);
        set_second(ss);
    }

// ------------------- Operators ------------------------
Time Time::operator+(const int value)
{
    Time new_time{*this};
    if(value < 0)
    {
        new_time.subtract_seconds(-value);
        return new_time;
    }

    new_time.add_seconds(value);
    return new_time;
}

Time& Time::operator++()
{
    add_seconds(1);
    return *this;
}

Time Time::operator++(int)
{
    Time new_time{*this};
    operator++();
    return new_time;
}

Time Time::operator-(const int value)
{
    Time new_time{*this};
    if(value < 0)
    {
        new_time.add_seconds(-value);
        return new_time;
    }

    new_time.subtract_seconds(value);
    return new_time;
}

Time& Time::operator--()
{
    subtract_seconds(1);
    return *this;
}

Time Time::operator--(int)
{
    Time new_time{*this};
    operator--();
    return new_time;
}

// ------------------- Comparison Operators ------------------------

bool Time::operator==(Time const &compare_to) const
{
    if (time_as_seconds() == compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator!=(Time const &compare_to) const
{
    if (time_as_seconds() != compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator>(Time const &compare_to) const
{
    if (time_as_seconds() > compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator<(Time const &compare_to) const
{
    if (time_as_seconds() < compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator>=(Time const &compare_to) const
{
    if (time_as_seconds() >= compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator<=(Time const &compare_to) const
{
    if (time_as_seconds() <= compare_to.time_as_seconds())
    {
        return true;
    }

    return false;
}

// Return correctly formatted time
std::string Time::to_string(bool am_pm) const
{
    if (am_pm)
    {
        if (hour > 11)
        {
            return time_formatter(hour-12) + ":" 
                   + time_formatter(minute) + ":"
                   + time_formatter(second) + " pm";
        }

        return time_formatter(hour) + ":" 
               + time_formatter(minute) + ":" 
               + time_formatter(second) + " am"; 
    }

    return time_formatter(hour) + ":" 
           + time_formatter(minute) + ":" 
           + time_formatter(second);
}

void Time::set_hour(int hh)
{
    if (hh > 23 || hh < 0)
    {
        throw("FEL: Timmar måste vara minst 0 (noll) och som mest 23");
    }

    hour = hh;
}

void Time::set_minute(int mm)
{
    if (mm > 59 || mm < 0)
    {
        throw("FEL: Minuter måste vara minst 0 (noll) och som mest 59");
    }

    minute = mm;
}

void Time::set_second(int ss)
{
    if (ss > 59 || ss < 0)
    {
        throw("FEL: Sekunder måste vara minst 0 (noll) och som mest 59");
    }

    second = ss;
}

// Private functions
void Time::add_hour()
{
    hour++;
    if (hour > 23)
    {
        hour = 0;
    }
}

// Add minute to time
void Time::add_minute()
{
    minute++;
    if (minute > 59)
    {
        minute = 0;
        add_hour();
    }
}

// Add seconds to time
void Time::add_seconds(int value)
{
    while(value > 0)
    {
        second++;
        if(second > 59)
        {
            second = 0;
            add_minute();
        }

        value--;
    }
}

// Subtract hour from time
void Time::subtract_hour()
{
    hour--;
    if (hour < 0)
    {
        hour = 23;
    }
}

// Subtract minute from time
void Time::subtract_minute()
{
    minute--;
    if (minute < 0)
    {
        minute = 59;
        subtract_hour();
    }
}

// Subtract seconds from time
void Time::subtract_seconds(int value)
{
    while(value > 0)
    {
        second--;
        if(second < 0)
        {
            second = 59;
            subtract_minute();
        }

        value--;
    }
}

// Convert time to 00 format
std::string Time::time_formatter(int const time) const
{
    if (time < 10)
    {
        return "0" + std::to_string(time);
    }

    return std::to_string(time);
}

int Time::time_as_seconds() const
{
    return (hour*3600 + minute*60 + second);
}

std::istream& operator>>(std::istream &is, Time& time)
{
    std::string temp_hour{};
    std::getline(is, temp_hour, ':');
    std::string temp_minute{};
    std::getline(is, temp_minute, ':');
    std::string temp_second{};
    is >> temp_second;

    int hour_i{stoi(temp_hour)};
    int minute_i{stoi(temp_minute)};
    int second_i{stoi(temp_second)};

    // Checks if the input is in the corresponding interval - else trigger the istreams fail()-flag.
    if (hour_i > 23 || hour_i < 0)
    {
        is.setstate(std::ios_base::failbit);
    }

    if (minute_i > 59 || minute_i < 0)
    {
        is.setstate(std::ios_base::failbit);
    }

    if (second_i > 59 || second_i < 0)
    {
        is.setstate(std::ios_base::failbit);
    }

    // If istream has the fail()-flag set, throw an exception with a message
    if (is.fail())
    {
        throw std::istream::failure(
            "FEL: Felaktig inmatning\nFÖRKLARING: Formatet måste vara 'HH:MM:SS' där HH är 0-23, MM är 0-59 och SS är 0-59"
            );
    }

    time.set_hour(stoi(temp_hour));
    time.set_minute(stoi(temp_minute));
    time.set_second(stoi(temp_second));
    
    return is;
}

std::ostream& operator<<(std::ostream &os, Time &time)
{
    os << time.to_string();
    return  os;
}

Time operator+(int const value, Time const &time)
{
    Time new_time{time};
    return new_time + value;
}

