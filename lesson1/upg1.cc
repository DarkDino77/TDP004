#include <string>

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