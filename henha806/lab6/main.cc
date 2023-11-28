#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Text_Manip.h"

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        std::cerr << "\x1B[91mError: Inavlid amount of arguments. Atleast two arguments are expected, the second one being the filename of the file to read.\x1B[0m" << std::endl;
        return 1;
    }

    if(argc == 2 && (std::string(argv[1]) == "--h" || std::string(argv[1]) == "--help"))
    {
        std::cout << "Usage: ./a.out [file_name] [arguments]\n"
                  << "Arguments:\n"
                  << " --print                  prints the content of the file.\n"
                  << " --frequency              prints a frequency-table of all words in the text, sorted by frequency in ascending order.\n"
                  << " --table                  prints a frequency-table of all words in the text, sorted by word in alphabetical order.\n"
                  << " --substitute=<old>+<new> substitutes the given <old> word to the given <new> word(excluding '<' and '>') in the text.\n"
                  << " --remove=<word>          removes the given <word>(excluding the '<' and '>') from the text.\n"
                  << std::endl;
        return 0;
    }

    std::string filename{argv[1]};
    std::ifstream file_stream{filename, file_stream.in};

    if(!file_stream.is_open())
    {
        std::cerr << "\x1B[91mError: Could not open file with name '" << filename << "'.\x1B[0m" << std::endl;
        return 1;
    }

    // Store arguments
    std::vector<std::string> arguments{};

    std::transform(argv + 2, argv + argc, 
                    std::back_inserter(arguments),
                    [](char const* arg)
                    {
                        return std::string(arg);
                    });

    // Store text
    std::vector<std::string> text{
        std::istream_iterator<std::string>{file_stream},
        std::istream_iterator<std::string>{}
    };

    // Split the arguments at '='
    std::vector<std::pair<std::string, std::string> > split_arguments{};

    std::transform(arguments.begin(), arguments.end(),
                   std::back_inserter(split_arguments),
                   [&split_arguments](std::string const& argument)
                   {
                      std::pair<std::string, std::string> arg_pair{};
                      
                      auto it{std::find(argument.begin(), argument.end(), '=')};
                      if (it != argument.end())
                      {
                          arg_pair.first = {argument.begin(), it};
                          arg_pair.second = {it+1, argument.end()};
                      }
                      else
                      {
                          arg_pair.first = {argument.begin(), it};
                          arg_pair.second = "";
                      }
                      return arg_pair;
                   }
                  );

    std::for_each(split_arguments.begin(), split_arguments.end(),
                  [&text](auto const& argument)
                  {   
                      if(argument.first == "--print")
                      {
                          print(text);
                      }
                      else if(argument.first == "--frequency")
                      {
                          frequency(text, false, true);
                      }
                      else if(argument.first == "--table")
                      {
                          frequency(text, true, false);
                      }
                      else if(argument.first == "--substitute")
                      {
                          substitute(text, argument.second);
                      }
                      else if(argument.first == "--remove")
                      {
                          remove(text, argument.second);
                      }
                      else
                      {
                          std::cerr << "\x1B[91mError: '" << argument.first << "' is not a valid argument.\x1B[0m" << std::endl;
                      }
                  });

    return 0;
}