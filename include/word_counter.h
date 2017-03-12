#ifndef CPP_USERGROUP_BDD_EXERCISE_WORD_COUNTER_H
#define CPP_USERGROUP_BDD_EXERCISE_WORD_COUNTER_H

#include <cstdint>
#include <string>
#include <boost/algorithm/string.hpp>

namespace text_statistics
{

inline uint64_t word_count (const std::string & text, const std::string & word)
{
    std::vector<std::string> strings;

    std::string lower_case_word;
    std::transform(word.cbegin(),
                   word.cend(),
                   std::back_inserter(lower_case_word),
                   [] (const char & c) { return std::tolower(c); });

    std::string lower_case_phrase;
    std::transform(text.cbegin(),
                   text.cend(),
                   std::back_inserter(lower_case_phrase),
                   [] (const char & c) { return std::tolower(c); });


    boost::split(strings, lower_case_phrase, boost::is_space());

    unsigned word_count{};
    for (auto & str : strings)
    {
        if (str.compare(lower_case_word) == 0)
        {
            word_count++;
        }
    }
    return word_count;
}

}
#endif //CPP_USERGROUP_BDD_EXERCISE_WORD_COUNTER_H
