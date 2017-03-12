#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include "rpn_calculator.h"

#include <cstdint>
#include <queue>

namespace
{

using cucumber::ScenarioScope;

struct CalculatorContext
{
    Calculator::RPNCalculator calculator;
    int64_t result;
};

struct CalculatorContext2
{
    Calculator::RPNCalculator calculator;
    std::vector<int64_t> numbers;
    std::vector<int64_t> results;
};

GIVEN ("^the numbers (-?\\d+) and (-?\\d+)$")
{
    REGEX_PARAM(int64_t, first_number);
    REGEX_PARAM(int64_t, second_number);
    ScenarioScope<CalculatorContext> context;

    context->calculator
        .number(first_number)
        .number(second_number);
}

GIVEN ("^the following numbers:$")
{
    ScenarioScope<CalculatorContext2> context{};
    TABLE_PARAM(number_params);
    const auto & number_table = number_params.hashes();
    for (const auto & table_row : number_table)
    {
        context->numbers.push_back(std::stoi(table_row.at("number")));
    }
}


WHEN ("^this numbers are multiplied$")
{
    ScenarioScope<CalculatorContext> context;
    context->result = context->calculator.multiply();
}

WHEN ("^this numbers are added$")
{
    ScenarioScope<CalculatorContext> context;
    context->result = context->calculator.add();
}

WHEN ("^each number is multiplied by (-?\\d+)$")
{
    REGEX_PARAM(int64_t, multiplier);
    ScenarioScope<CalculatorContext2> context{};
    for (const auto & number : context->numbers)
    {
        context->results.push_back(number * multiplier);
    }
}

THEN ("^the result should be (-?\\d+)$")
{
    REGEX_PARAM(int64_t, result);
    ScenarioScope<CalculatorContext> context;
    ASSERT_EQ(result, context->result);
}

THEN ("^the results should be the following:$")
{
    ScenarioScope<CalculatorContext2> context{};
    TABLE_PARAM(number_params);
    const auto & number_table = number_params.hashes();
    std::queue<int64_t> expected_results;
    for (const auto & table_row : number_table)
    {
        expected_results.push(std::stoi(table_row.at("result")));
    }
    for (const auto & result: context->results)
    {
        EXPECT_EQ(expected_results.front(), result);
        expected_results.pop();
    }
}


}//namespace
