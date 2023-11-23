#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>

void print(std::vector<std::string> const& text)
{
    std::for_each(text.begin(), text.end(), 
                  [](std::string const& word)
                  {
                      std::cout << word << " ";
                  });

    std::cout << std::endl;
}

void frequency(std::vector<std::string> const& text, bool sort_by_key = false, bool key_align_right = true)
{
    std::map<std::string, int> frequency_table{};
    std::for_each(text.begin(), text.end(), 
                  [&frequency_table](std::string const& word)
                  {
                      if(frequency_table.count(word) == 0)
                      {
                          frequency_table[word] = 1;
                      }
                      else
                      {
                          frequency_table[word] = frequency_table[word]+1;
                      }
                  });

    std::vector<std::pair<std::string, int>> sorted_frequencies{};    
    std::transform(frequency_table.begin(), frequency_table.end(),
                  std::back_inserter(sorted_frequencies),
                  [&sorted_frequencies](auto const& pair)
                  {
                      return pair;
                  });

    auto map_compare = [&sort_by_key](std::pair<std::string, int>& a, std::pair<std::string, int>& b) 
    {
        if(sort_by_key)
        {
            return a.first < b.first;
        }
        else
        {
            return a.second > b.second;
        }
    };

    std::sort(sorted_frequencies.begin(), sorted_frequencies.end(), map_compare);
    std::for_each(sorted_frequencies.begin(), sorted_frequencies.end(),
                  [key_align_right](auto const& pair)
                  {
                      if(key_align_right)
                      {
                          std::cout << std::setw(11) << std::right << pair.first << " " << pair.second << std::endl;
                      }
                      else
                      {
                          std::cout << std::setw(11) << std::left << pair.first << " " << pair.second << std::endl;
                      }
                      
                  });
}

void remove(std::vector<std::string> & text, std::string const& word_to_remove)
{
    auto it {std::remove(text.begin(), text.end(), word_to_remove)};
    text.erase(it, text.end());
}

void substitute(std::vector<std::string> & text, std::string const& word_to_substitute)
{
    auto it{std::find(word_to_substitute.begin(), word_to_substitute.end(), '+')};
    if(it != word_to_substitute.end())
    {
        std::string old_word{word_to_substitute.begin(), it};
        std::string new_word{it+1, word_to_substitute.end()};

        std::replace(text.begin(), text.end(), old_word, new_word);
    }
    else
    {
        std::cerr << "\x1B[91mError: '" << word_to_substitute << "' is not a valid parameter for '--substitute'. The format should be '--substitute=old_word+new_word'.\x1B[0m" << std::endl;
    }
}

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
        return 1;
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