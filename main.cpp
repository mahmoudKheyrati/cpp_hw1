#include <iostream>
#include "model/Response.h"
#include "extentions/Extentions.h"
#include "User.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Response *response = new Success(1, "message");

    bool isSuccess = dynamic_cast<Response *>(response);
    std::cout << isSuccess << std::endl;

    if (instanceof<Success>(response)) {
        std::cout << "haha response is instance of Success" << std::endl;
    }

    return 0;
}
