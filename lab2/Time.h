// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
class Time
{
public:
    //constructor
    Time();
    Time(int hh, int mm, int ss);

    //print return a formated string
    std::string to_string(bool am_pm=false) const;

    // add time
    Time operator+(const int value);
    Time& operator++();
    Time operator++(int);

    // subtract time
    Time operator-(const int value);
    Time& operator--();
    Time operator--(int);

    //comparison operators
    bool operator==(Time compare) const;
    bool operator!=(Time compare) const;
    bool operator>(Time compare) const;
    bool operator<(Time compare) const;
    bool operator<=(Time compare) const;
    bool operator>=(Time compare) const;
    
    void set_hour(int hh);
    void set_minute(int mm);
    void set_second(int ss);
    void add_seconds(int value);

private:

    int hour;
    int minute;
    int second;
    //format string
    std::string time_formatter(const int time) const;
    // add time
    void add_hour();
    void add_minute();
    
     // subtract time
    void subtract_hour();
    void subtract_minute();
    void subtract_seconds(int value);
    // comparison operators calculates the time in second for easy comparison
    int calc_time() const;

};
// Streaming
std::ostream& operator<<(std::ostream &os, Time &item);
// Streaming
std::istream& operator>>(std::istream &is, Time &time);
// Additon 
Time operator+(const int value, const Time& time);
#endif