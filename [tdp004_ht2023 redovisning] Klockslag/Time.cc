#include <iomanip>

#include "Time.h"

//-----------------------Public---------------------------
// Constructors
Time::Time()
:hour{}, minute{}, second{}
{}

Time::Time(int hh, int mm, int ss)
:hour{hh}, minute{mm}, second{ss}
{}

// Convert a Time object to a formatted string- hh:mm:ss
std::string Time::to_string(bool am_pm) const
{
    std::string ss{Time::time_formatter(second)};
    std::string mm{Time::time_formatter(minute)};
    std::string hh{};
    std::string am_pm_string{"am"};

    if (am_pm && hour > 12)
    {
        hh = Time::time_formatter(hour - 12);
        am_pm_string = "pm";
    }
    else
    {
        hh = Time::time_formatter(hour);
    }
    
    return hh + ":" + mm + ":" + ss + ((am_pm) ? " " + am_pm_string : "");
}

// Addtion operators
Time Time::operator+(int const value) const
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
    ++*this;
    return new_time;operator++();
}

// Subtraction operators
Time Time::operator-(int const value) const
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
    --*this;
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
    if (*this == compare)
    {
        return false;
    }

    return true;
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
    if (*this > compare or *this == compare)
    {
        return false;
    }

    return true;
}

bool Time::operator<=(Time const &compare) const
{
    if (*this < compare or *this == compare)
    {
        return true;
    }

    return false;
}

bool Time::operator>=(Time const &compare) const
{
    if (*this > compare or *this == compare)
    {
        return true;
    }

    return false;
}

//------------------PRIVATE--------------------------
// Format time section to a string with two numbers.
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

bool Time::is_valid() const
{
    if (hour > 23 || hour < 0)
    {
        return false;
    }

    if (minute > 59 || minute < 0)
    {
        return false;

    }

    if (second > 59 || second < 0)
    {
        return false;
    }
    return true;
}

//------------outside class--------------------

// Stream operator out
std::ostream& operator<<(std::ostream &os, Time &item)
{
    os << item.to_string();
    return os;
}

// Stream operator in
// Expects the input in the format "hh:mm:ss" where each is an integer.
// Reads the input *until the specified hour, minute, and second are obtained*.
std::istream& operator>>(std::istream &is, Time &time)
{
    int hour_i{}, min_i{}, sec_i{};
    char garbage{};
    
    is >> hour_i >> garbage >> min_i >> garbage >> sec_i;

    // Store the input in a temporary Time object and check if it is invalid.
    Time temp_time{hour_i, min_i, sec_i};

    // If invalid, it adds a fail flag to istream.
    if (temp_time.is_valid() == false)
    {
        is.setstate(std::ios_base::failbit);
    }

    // Performs conversion and adds the calculated time to the Time object.
    time = time + (hour_i*3600 + min_i*60 + sec_i);

    if(is.fail())
    {
        std::cerr << "Invalid input, '" << hour_i << ":" 
                  << min_i << ":" << sec_i 
                  << "' automatically converted to '" 
                  << time << "'" << std::endl;
    }

    return is;
}

// Addtion operator
Time operator+(int const value, Time const &time)
{
    Time new_time{time};
    return new_time + value;    
}