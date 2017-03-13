# language: en
Feature: Cucumber-cpp Text Input Example Exercise
  As a C++ developer with first time contact with Cucumber-cpp
  I want to implement cucumber steps with Text input
  In order to learn how to define cucumber steps in C++

@proposal
Scenario: String Input
  Given the following text
    """
    Then the Queen left off, quite out of breath, and said to Alice, 
    'Have you seen the Mock Turtle yet?'
    'No,' said Alice. 'I don't even know what a Mock Turtle is.'
    'It's the thing Mock Turtle Soup is made from,' said the Queen.
    'I never saw one, or heard of one,' said Alice.
    'Come on, then,' said the Queen, 'and he shall tell you his history,' 
    """
  When the word mock are counted in the text
  Then the count should be 3
  
  
