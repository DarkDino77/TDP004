// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include <iostream>
#include <string>
#include <iomanip>

#include "Time.h"

//-----------------------Public---------------------------
// Constructors
Time::Time()
:hour{}, minute{}, second{}
{}

Time::Time(int hh, int mm, int ss)
:hour{}, minute{}, second{}
{
    set_hour(hh);
    set_minute(mm);
    set_second(ss);
}

// Format string
std::string Time::to_string(bool am_pm) const
{
    if (am_pm)
    {
        if (hour > 11)
        {
        return Time::time_formatter(hour - 12) + ":" 
               + Time::time_formatter(minute) + ":" 
               + Time::time_formatter(second) + " pm";
        }

        return Time::time_formatter(hour) + ":" 
               + Time::time_formatter(minute) + ":" 
               + Time::time_formatter(second) + " am";
    }

    return Time::time_formatter(hour) + ":" 
           + Time::time_formatter(minute) + ":" 
           + Time::time_formatter(second);
}

// Addtion operators
Time Time::operator+(int const value)
{
    Time new_time{*this};
    if (value < 0)
    {
        new_time.Time::subtract_seconds(-value);
        return new_time;    
    }

    new_time.Time::add_seconds(value);
    return new_time;
}

Time& Time::operator++()
{
    Time::add_seconds(1);
    return *this;
}

Time Time::operator++(int)
{
    Time new_time{*this};
    operator++();
    return new_time;
}

// Subtraction operators
Time Time::operator-(int const value)
{
    Time new_time{*this};
    if (value < 0)
    {
        new_time.Time::add_seconds(-value);
        return new_time;    
    }

    new_time.Time::subtract_seconds(value);
    return new_time;
}

Time& Time::operator--()
{
    Time::subtract_seconds(1);
    return *this;
}

Time Time::operator--(int)
{
    Time new_time{*this};
    operator--();
    return new_time;
}

// Comparison operators
bool Time::operator==(Time const &compare) const
{
    if (Time::time_as_seconds() == compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator!=(Time const &compare) const
{
    if (Time::time_as_seconds() != compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator>(Time const &compare) const
{
    if (Time::time_as_seconds() > compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator<(Time const &compare) const
{
    if (Time::time_as_seconds() < compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator<=(Time const &compare) const
{
    if (Time::time_as_seconds() <= compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

bool Time::operator>=(Time const &compare) const
{
    if (Time::time_as_seconds() >= compare.Time::time_as_seconds())
    {
        return true;
    }

    return false;
}

// Set a specific time
void Time::set_hour(int hh)
{
    if (hh > 23 || hh < 0)
    {
        throw ("Fel timmar måste vara mellan 0 till 23");
    }

    hour = hh;
}

void Time::set_minute(int mm)
{
    if (mm > 59 || mm < 0)
    {
        throw ("Fel minuter måste vara mellan 0 till 59");
    } 

    minute = mm;
}

void Time::set_second(int ss)
{
    if (ss > 59 || ss < 0)
    {
        throw ("Fel sekunder måste vara mellan 0 till 59");
    }

    second = ss;
}

//------------------PRIVATE--------------------------
// Format string
std::string Time::time_formatter(int const time) const
{
    if (time < 10)
    {
        return "0" + std::to_string(time);
    }
    else
    {
        return std::to_string(time);
    }
}

// Add time
void Time::add_hour() 
{
    hour++;
    if (hour > 23)
    {
        hour = 0;
    } 
}

void Time::add_minute() 
{
    minute++;
    if (minute > 59)
    {
        minute = 0;
        Time::add_hour();
    }
}

void Time::add_seconds(int value) 
{
    while(value > 0)
    {
        second++;
        if (second > 59)
        {
            second = 0;
            Time::add_minute();
        }

        value--;
    }
}

// Subtract time
void Time::subtract_hour()
{
    hour--;
    if (hour < 0)
    {
        hour = 23;
    } 
}

void Time::subtract_minute()
{
    minute--;
    if (minute < 0)
    {
        minute = 59;
        Time::subtract_hour();
    }
}

void Time::subtract_seconds(int value)
{
    while(value > 0)
    {
        second--;
        if (second < 0)
        {
            second = 59;
            Time::subtract_minute();
        }

        value--;
    }
}

// Comparison operators calculates the time in second for easy comparison
int Time::time_as_seconds() const
{
    return hour*60*60 + minute*60 + second;
}

//------------outside class--------------------
// Stream operator 
// Streaming out
std::ostream& operator<<(std::ostream &os, Time &item)
{
    os << item.to_string();
    return os;
}

// Streaming in    
std::istream& operator>>(std::istream &is, Time &time)
{
    std::string temp_hour{};
    std::getline(is, temp_hour, ':');
    std::string temp_min{};
    std::getline(is, temp_min, ':');
    std::string temp_sec{};
    is >> temp_sec;

    int hour_i{stoi(temp_hour)};
    int min_i{stoi(temp_min)};
    int sec_i{stoi(temp_sec)};

    // Checks if input is in the valid intervale.
    // If so it adds a fail flag to istream.
    if (hour_i > 23 || hour_i < 0)
    {
        is.setstate(std::ios_base::failbit);
    }

    if (min_i > 59 || min_i < 0)
    {
        is.setstate(std::ios_base::failbit);
        
    }

    if (sec_i > 59 || sec_i < 0)
    {
        is.setstate(std::ios_base::failbit);
    }

    // If istream has a fail flag throw an exception 
    if (is.fail())
    {
        throw std::istream::failure("FEL: Felaktig inmatning\nFÖRKLARING: Formatet måste vara 'HH:MM:SS' där HH är 0-23, MM är 0-59 och SS är 0-59");
    }
    
    time.Time::set_hour(stoi(temp_hour));
    time.Time::set_minute(stoi(temp_min));
    time.Time::set_second(stoi(temp_sec));

    return is;
}

// Addtion operator
Time operator+(int const value, Time const &time)
{
    Time new_time{time};
    return new_time + value;    
}