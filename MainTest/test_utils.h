//
// Created by Taras Martynyuk on 4/2/2018.
//
#ifndef ARRAY_TEST_UTILS_H
#define ARRAY_TEST_UTILS_H
#include <string>

template <typename TException>
bool expressionThrows( void (*const expression)())
{
    try
    {
        expression();
        return false;
    }
    catch(TException& e)
    {
        return true;
    }
}

void logPassed(std::string testName);
void logAllPassed();

#endif //ARRAY_TEST_UTILS_H
