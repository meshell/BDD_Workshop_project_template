#include <gmock/gmock.h>
#include "rpn_calculator.h"

#include <exception>

namespace {

using Calculator::RPNCalculator;
using namespace ::testing;

TEST(A_Calculator, should_return_the_correct_result_when_two_numbers_are_multiplied)
{
    EXPECT_THAT(RPNCalculator{}.number(2).number(5).multiply(), Eq(10));
    ASSERT_THAT(RPNCalculator{}.number(3).number(6).multiply(), Eq(18));
}

TEST(A_Calculator, should_return_the_correct_result_when_two_numbers_are_added)
{
    EXPECT_THAT(RPNCalculator{}.number(2).number(5).add(), Eq(7));
    ASSERT_THAT(RPNCalculator{}.number(3).number(6).add(), Eq(9));
}

TEST(A_Calculator, should_throw_an_exception_when_not_enough_numbers_as_input)
{
    EXPECT_THROW(RPNCalculator{}.multiply(), std::invalid_argument);
    EXPECT_THROW(RPNCalculator{}.number(1).multiply(), std::invalid_argument);
    EXPECT_THROW(RPNCalculator{}.add(), std::invalid_argument);
    EXPECT_THROW(RPNCalculator{}.number(1).add(), std::invalid_argument);
}

TEST(A_Calculator, should_use_the_previous_result_as_first_number)
{
    auto testee = RPNCalculator{};
    EXPECT_THAT(testee.number(2).number(5).multiply(), Eq(10)); // 2 * 5
    EXPECT_THAT(testee.number(3).multiply(), Eq(30)); // 10 * 3
    EXPECT_THAT(testee.number(3).add(), Eq(33)); //30 + 3
    EXPECT_THAT(testee.number(10).add(), Eq(43)); //33 + 10
}

TEST(A_Calculator, should_allow_to_input_multiple_numbers_and_multiply_them_in_sequence)
{
    auto testee = RPNCalculator{};
    EXPECT_THAT(testee.number(2).number(5).number(3).multiply(), Eq(10)); // 2 * 5
    EXPECT_THAT(testee.multiply(), Eq(30)); // 10 * 3
}

TEST(A_Calculator, should_allow_to_input_multiple_numbers_and_operate_on_them_in_sequence)
{
    auto testee = RPNCalculator{};
    EXPECT_THAT(testee.number(2).number(5).number(3).multiply(), Eq(10)); // 2 * 5
    EXPECT_THAT(testee.add(), Eq(13)); // 10 + 3
}

TEST(A_Calculator, should_start_new_when_cleared)
{
    auto testee = RPNCalculator{};
    EXPECT_THAT(testee.number(2).number(5).multiply(), Eq(10));
    testee.clear();
    ASSERT_THAT(testee.number(4).number(8).multiply(), Eq(32));
}

} //namespace
