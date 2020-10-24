#include "Exceptions.h"

#include <utility>

Exception::Exception(string message) : message(std::move(message)) {

}

NotFoundException::NotFoundException(const string &message) : Exception(message) {

}
