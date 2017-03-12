#include "rpn_calculator.h"

#include <stdexcept>
#include <algorithm>

namespace
{

template<typename T, typename fncT>
T apply_and_push_front (const T & container, fncT fnc)
{
    if (container.size() < 2)
    {
        throw std::invalid_argument("Not enough inputs for operation");
    }
    T new_container{std::begin(container) + 2, std::end(container)};
    new_container.emplace_back(fnc(container.at(0), container.at(1)));
    std::rotate(new_container.rbegin(), new_container.rbegin() + 1, new_container.rend());
    return new_container;
}
}


namespace Calculator
{

RPNCalculator & RPNCalculator::number (int64_t n)
{
    numbers.push_back(n);
    return *this;
}

void RPNCalculator::clear ()
{
    numbers.clear();
}

int64_t RPNCalculator::multiply ()
{
    numbers = apply_and_push_front(numbers, [] (int64_t a, int64_t b) { return a * b; });
    return numbers.front();
}

int64_t RPNCalculator::add ()
{
    numbers = apply_and_push_front(numbers, [] (int64_t a, int64_t b) { return a + b; });
    return numbers.front();
}


} // namespace Calculator
