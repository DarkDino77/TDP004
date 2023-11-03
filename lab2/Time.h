// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs
#ifndef TIME_H
#define TIME_H
class Time
{
public:

    // Constructor
    Time();
    Time(int hh, int mm, int ss);

    // Return a formated string
    std::string to_string(bool am_pm = false) const;

    // Addtion operators
    Time operator+(int const value);
    Time& operator++();
    Time operator++(int);

    // Subtraction operators
    Time operator-(int const value);
    Time& operator--();
    Time operator--(int);

    // Comparison operators
    bool operator==(Time const &compare) const;
    bool operator!=(Time const &compare) const;
    bool operator>(Time const &compare) const;
    bool operator<(Time const &compare) const;
    bool operator<=(Time const &compare) const;
    bool operator>=(Time const &compare) const;

    // Set a specific time
    void set_hour(int hh);
    void set_minute(int mm);
    void set_second(int ss);
    
private:

    // Variable defenition
    int hour;
    int minute;
    int second;

    // Format string
    std::string time_formatter(int const time) const;

    // Add time
    void add_hour();
    void add_minute();
    void add_seconds(int value);

    // Subtract time
    void subtract_hour();
    void subtract_minute();
    void subtract_seconds(int value);

    // Comparison operators calculates the time in seconds for easy comparison
    int time_as_seconds() const;

};

// Streaming out
std::ostream& operator<<(std::ostream &os, Time &item);

// Streaming in 
std::istream& operator>>(std::istream &is, Time &time);

// Addtion operator
Time operator+(int const value, Time const &time);

#endif