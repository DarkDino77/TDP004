#include <string>
//Bra exemple
class Paper
{
    public:
        Paper();
        Paper(int width, int row_count);

        int get_width();
        int get_height();

        std::string read_row(int row);
        void write_row(int row, std::string text);

    private:
        int width;
        int height;

};

//dåligt exemple
class Car {
public:
    double speed;

    Car() : speed(0.0) {}
};

//Enkaptulation handlar om sammsätta liknade funktioner till en enhete.
//För att presentera så lite som möjligt 
//Detta är för att skydda data från direkt manipulation.