#include "User.h"
#include "database/DataBaseRepository.h"
#include "extentions/Extentions.h"
#include "exceptions/Exceptions.h"

#include <utility>

Response User::resetPassword(string currentPassword, string newPassword, string confirmPassword) {
    if (this->password == hash(std::move(currentPassword))) {
        setPassword(newPassword, confirmPassword);
    } else {
        return Error(400, "password is wrong!");
    }
}

Response User::setPassword(string newPassword, string confirmPassword) {
    if (newPassword == confirmPassword) {
        this->password = hash(newPassword);
        return Success(200, "password changed");
    }
    return Error(400, "confirmPassword is wrong");

}

User User::login(string username, string password) throw(Exception) {
    bool isUserExists = DataBaseRepository::getDataBase()->isUserExists(username);
    if (isUserExists) {
        auto user = DataBaseRepository::getDataBase()->findUserByUserName(username);
        if (user.password == hash(password)) {
            std::cout << "you are successfully login with username: " + username << std::endl;
            return user;
        } else {
            throw Exception("password is wrong!");
        }
    } else {
        throw Exception("username is wrong!");
    }
}

User User::signup(string username, string password, string confirmPassword, string email) throw(Exception) {
    bool isUserExists = DataBaseRepository::getDataBase()->isUserExists(username);

    if (isUserExists) throw Exception("username is already taken!");
    if (password != confirmPassword) throw Exception("confirmPassword doesn't match the password");


    Response response = DataBaseRepository::getDataBase()->addUser(User(0, username, password, email));
    if (instanceof<Success>(&response)){
        throw response.getMessage();
    }

    auto user = User::login(username, password);
    return user;
}

string User::hash(string value) {
    return to_string(std::hash<std::string>{}(value));
}

User::User(int id, string username, string password, string email) :
        id(id), username(std::move(username)),
        email(std::move(email)){
    setPassword(password,password);

}

const string &User::getUsername() const {
    return username;
}

User::User(string email) : email(std::move(email)) {

}

const string &User::getEmail() const {
    return email;
}

void User::setId(int id) {
    User::id = id;
}

