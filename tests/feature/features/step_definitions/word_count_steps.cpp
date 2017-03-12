#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include "word_counter.h"

#include <cstdint>
#include <queue>

namespace
{

using cucumber::ScenarioScope;

struct TextContext
{
    std::string text;
    uint64_t word_count;
};

GIVEN ("^the following text$")
{
    REGEX_PARAM(std::string, text);
    ScenarioScope<TextContext> context;
    context->text = text;
}

WHEN ("^the word (.+) are counted in the text$")
{
    REGEX_PARAM(std::string, word);
    ScenarioScope<TextContext> context;
    context->word_count = text_statistics::word_count(context->text, word);
}

THEN ("^the count should be (\\d+)$")
{
    REGEX_PARAM(uint64_t, result);
    ScenarioScope<TextContext> context;
    ASSERT_EQ(result, context->word_count);
}


} // namespace

