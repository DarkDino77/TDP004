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
    std::string time_formatter(const int time) const;
    std::string to_string() const;

    // add time
    void add_hour();
    void add_minute();
    void add_seconds(int value);
    Time operator+(const int value);
    Time& operator++();
    Time operator++(int);

     // subtract time
    void subtract_hour();
    void subtract_minute();
    void subtract_seconds(int value);
    Time operator-(const int value);
    Time& operator--();
    Time operator--(int);

    //comparison operators
    int calc_time() const;
    bool operator==(Time compare) const;
    bool operator!=(Time compare) const;
    bool operator>(Time compare) const;
    bool operator<(Time compare) const;
    bool operator<=(Time compare) const;
    bool operator>=(Time compare) const;
    
    // Streaming

    friend std::istream& operator>>(std::istream &is, Time &time);

private:
    int hour;
    int minute;
    int second;
};
// Streaming
std::ostream& operator<<(std::ostream &os, Time &item);


#endif