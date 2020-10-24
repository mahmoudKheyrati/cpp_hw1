#pragma once

#include <string>

using namespace std;

class Exception {
public:
    explicit Exception(string message);

    string message;

};

class NotFoundException: Exception{
public:
    explicit NotFoundException(const string &message);
};