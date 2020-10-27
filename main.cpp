#include <iostream>
#include "model/Response.h"
#include "extentions/Extentions.h"
#include "User.h"

int main() {
    try {
        User::signup("mahmoud", "pass", "pass", "mahl@mail.com");
        auto user = User::login("mahmoud", "pass");
        auto user2 = User::login("mahmoud", "wer");

    } catch (Exception e) {
        std::cout<<e.message<<std::endl;

    }


    return 0;
}
