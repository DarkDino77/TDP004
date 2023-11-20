#ifndef TIME_H
#define TIME_H

class Time
{
public:
    // Constructors
    Time();
    Time(int hh, int mm, int ss);

    // Addition operators
    Time operator+(int const value);
    Time& operator++();
    Time operator++(int);

    // Subtraction operators
    Time operator-(const int value);
    Time& operator--();
    Time operator--(int);

    // Comparison operators
    bool operator==(Time const &compare_to) const;
    bool operator!=(Time const &compare_to) const;
    bool operator>(Time const &compare_to) const;
    bool operator<(Time const &compare_to) const;
    bool operator>=(Time const &compare_to) const;
    bool operator<=(Time const &compare_to) const;

    // Print the time in a correct format
    std::string to_string(bool am_pm = false)const;

    // Set time
    void set_hour(int hh);
    void set_minute(int mm);
    void set_second(int ss);

private:
    int hour;
    int minute;
    int second;

    // Functions used to increment time with correct wrapping.
    void add_hour();
    void add_minute();
    void add_seconds(int value);
    void subtract_hour();
    void subtract_minute();
    void subtract_seconds(int value);

    // Takes in an int and returns the correctly formatted string i.e. '00'
    std::string time_formatter(int const time)const;

    // Calculates 
    int time_as_seconds() const;
};

std::istream& operator>>(std::istream& is, Time& time);
std::ostream& operator<<(std::ostream& os, Time& time);
Time operator+(int const value, Time const &time);

#endif