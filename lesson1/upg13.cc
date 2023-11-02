#include "upg1.cc"

int main()
{
    std::string input = "This input came from the player";

    Paper paper{30,40};
    int counter{0};
    std::string row_content{paper.read_row(counter)};

    while ( row_content != "" && counter <= paper.get_height())
    {
        row_content = paper.read_row(counter);
        counter++;
    }

    if ( counter <= paper.get_height())
    {
        paper.write_row(counter, input);
    }

    return 0;
}