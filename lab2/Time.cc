// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Time
{

public:
    //constructors
    Time()
        :hour{}, minute{}, second{}
        {}
    Time(int hh, int mm, int ss)
        :hour{hh}, minute{mm}, second{ss}
        {}
    // format string
    string time_formatter(const int time)
    {
        if (time < 10)
        {
            return "0" + to_string(time);
        }
        else
        {
            return to_string(time);
        }
    }
    string get_formated_time()
    {
        return "[" + time_formatter(hour) + ":"+ time_formatter(minute) + ":" + time_formatter(second) + "]";
    }
    //print time
    void print()
    {
        cout << get_formated_time() << endl;
    }
    // add time
    void add_hour()
    {
        hour++;
        if (hour > 23)
        {
            hour = 0;
        } 
    }
    void add_minute()
    {
        minute++;
        if (minute > 59)
        {
            minute = 0;
            add_hour();
        }
    }
    void add_seconds(int value)
    {
        while(value > 0)
        {
            second++;
            if (second > 59)
            {
                second = 0;
                add_minute();
            }
            value--;
        }
    }
    Time operator+(const int value)
    {
        Time new_time{*this};
        new_time.add_seconds(value);
        return new_time;
    }
private:
    int hour;
    int minute;
    int second;

};


