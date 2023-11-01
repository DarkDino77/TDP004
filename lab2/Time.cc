// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include <iostream>
#include <string>
#include <iomanip>

#include "Time.h"



    Time::Time()
        :hour{}, minute{}, second{}
        {}
    Time::Time(int hh, int mm, int ss)
        :hour{hh}, minute{mm}, second{ss}
        {
            if (hh > 23 || hh < 0)
            {
                throw ("Fel timmar måste vara mellan 0 till 23");
            }
            if (mm > 59 || mm < 0)
            {
                throw ("Fel minuter måste vara mellan 0 till 59");
            }
            if (ss > 59 || ss < 0)
            {
                throw ("Fel sekunder måste vara mellan 0 till 59");
            }

        }

    // format string
    

    std::string Time::to_string(bool am_pm) const
    {
        if (am_pm)
        {
            if (hour > 11)
            {
            return Time::time_formatter(hour - 12) + ":"+ Time::time_formatter(minute) + ":" + Time::time_formatter(second) + "am";
            }

            return Time::time_formatter(hour) + ":"+ Time::time_formatter(minute) + ":" + Time::time_formatter(second) + "pm";
        }

        return Time::time_formatter(hour) + ":"+ Time::time_formatter(minute) + ":" + Time::time_formatter(second);
    }



    // add time

    Time Time::operator+(const int value)
    {
        Time new_time{*this};
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

    // subtract time
    Time Time::operator-(const int value)
    {
        Time new_time{*this};
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

    //comparison operators


    bool Time::operator==(Time compare) const
    {
        if (Time::calc_time() == compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    bool Time::operator!=(Time compare) const
    {
        if (Time::calc_time() != compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    bool Time::operator>(Time compare) const
    {
        if (Time::calc_time() > compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    bool Time::operator<(Time compare) const
    {
        if (Time::calc_time() < compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    bool Time::operator<=(Time compare) const
    {
        if (Time::calc_time() <= compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    bool Time::operator>=(Time compare) const
    {
        if (Time::calc_time() >= compare.Time::calc_time())
        {
            return true;
        }
        return false;
    }
    
    // Stream operator 
    std::ostream& operator<<(std::ostream &os, Time &item)
    {
        os << item.to_string();
        return os;
    }
        
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
        
        if (hour_i > 23 || hour_i < 0)
        {
            throw std::istream::failure("Fel timmar måste vara mellan 0 till 23");
        }
        if (min_i > 59 || min_i < 0)
        {
            throw std::istream::failure("Fel minuter måste vara mellan 0 till 59");
        }
        if (sec_i > 59 || sec_i < 0)
        {
            throw std::istream::failure("Fel sekunder måste vara mellan 0 till 59");
        }
        

        time.hour = hour_i;
        time.minute = min_i;
        time.second = sec_i;
        return is;
    }

    //------------------PRIVATE--------------------------

    //format string
    std::string Time::time_formatter(const int time) const
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
    // add time
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
    // subtract time
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
    // comparison operators calculates the time in second for easy comparison
    int Time::calc_time() const
    {
        return hour*60*60 + minute*60 + second;
    }