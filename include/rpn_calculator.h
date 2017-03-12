#ifndef CPP_USERGROUP_BDD_EXERCISE_RPN_CALCULATOR_H_
#define CPP_USERGROUP_BDD_EXERCISE_RPN_CALCULATOR_H_

#include <cstdint>
#include <vector>

namespace Calculator
{

/**
 * @brief The Dummy class used as walking Skeleton class for the unit, spec and feature tests of the template
 */
class RPNCalculator
{
public:
    /**
     * @brief
    */
    RPNCalculator () = default;

    RPNCalculator & number (int64_t n);

    int64_t multiply ();

    int64_t add ();

    void clear ();

private:
    std::vector<int64_t> numbers;
};


} // namespace CppTemplate

#endif //CPP_USERGROUP_BDD_EXERCISE_RPN_CALCULATOR_H_
