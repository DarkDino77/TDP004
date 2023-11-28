#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <numeric>
#include "Text_Manip.h"

void print(std::vector<std::string> const& text)
{
    std::copy(text.begin(), text.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void frequency(std::vector<std::string> const& text, bool sort_by_key, bool key_align_right)
{
    std::set<std::string> unique_words{text.begin(),text.end()};
    std::vector<std::pair<std::string, int>> sorted_frequencies{unique_words.size()};
    
    std::transform(unique_words.begin(), unique_words.end(), sorted_frequencies.begin(), 
                   [&text](const std::string& word) -> std::pair<std::string, int> {
                       int c = int(std::count(text.begin(), text.end(), word));
                       return std::make_pair(word, c);
                   });

    std::sort(sorted_frequencies.begin(), sorted_frequencies.end(),
              [&sort_by_key](auto const& a, auto const& b) {
                if(sort_by_key)
                {
                    return a.first < b.first;
                }
                else
                {
                    return a.second > b.second;
                }
              });

    auto it_longest_word = std::max_element(text.begin(), text.end(), 
                               [](auto const& a, auto const& b) {
                                   return a.size() < b.size();
                               });

    size_t longest_word{(std::string(*it_longest_word).size())};

    transform(sorted_frequencies.begin(), sorted_frequencies.end(), std::ostream_iterator<std::string>{std::cout, "\n"},
    [key_align_right, longest_word] (auto const& pair) -> std::string {
        std::ostringstream oss{};
        oss << std::setw(longest_word);
        if(key_align_right)
                      {
                          oss << std::right ;
                      }
                      else
                      {
                          oss <<  std::left ;
                      }
        oss << pair.first << " " << pair.second;
        return oss.str();
    });
    std::cout << std::endl;
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

        if(std::count(text.begin(), text.end(), old_word) == 0)
        {
            std::cerr << "\x1B[91mError: '" << old_word << "' was not found in the text.\x1B[0m" << std::endl;
        }
        else
        {
            std::replace(text.begin(), text.end(), old_word, new_word);
        }
    }
    else
    {
        std::cerr << "\x1B[91mError: '" << word_to_substitute << "' is not a valid parameter for '--substitute'. The format should be '--substitute=old_word+new_word'.\x1B[0m" << std::endl;
    }
}
