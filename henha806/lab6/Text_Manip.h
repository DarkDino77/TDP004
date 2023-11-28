#ifndef TEXT_MANIP_H
#define TEXT_MANIP_H

#include <vector>
#include <string>

void print(std::vector<std::string> const& text);
void frequency(std::vector<std::string> const& text, bool sort_by_key = false, bool key_align_right = true);
void remove(std::vector<std::string> & text, std::string const& word_to_remove);
void substitute(std::vector<std::string> & text, std::string const& word_to_substitute);


#endif