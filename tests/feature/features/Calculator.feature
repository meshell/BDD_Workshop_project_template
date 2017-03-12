# language: en
Feature: Cucumber-cpp Example Exercise
  As a C++ developer with first time contact with Cucumber-cpp
  I want to implement all kind of cucumber steps
  In order to learn how to define cucumber steps in C++


  Scenario: Simple Steps
    Given the numbers 6 and 7
    When this numbers are multiplied
    Then the result should be 42


  Scenario Outline: Examples
    Given the numbers <number 1> and <number 2>
    When this numbers are added
    Then the result should be <result>

    Examples:
      | number 1 | number 2 | result |
      | 4        | 25       | 29     |
      | 109      | 11       | 120    |
      | 600      | 66       | 666    |
      | 0        | 0        | 0      |
      | -20      | 25       | 5      |
      | -100     | -25      | -125   |


  Scenario: Input Table
    Given the following numbers:
      | number |
      | 23     |
      | 45     |
      | 34     |
      | 100    |

    When each number is multiplied by 2
    Then the results should be the following:
      | result |
      | 46     |
      | 90     |
      | 68     |
      | 200    |

