#include "User.h"
#include "database/DataBaseRepository.h"
#include "extentions/Extentions.h"
#include "exceptions/Exceptions.h"

#include <utility>

Response User::resetPassword(string currentPassword, string newPassword, string confirmPassword) {
    if (this->password == hash(std::move(currentPassword))) {
        setPassword(newPassword, currentPassword);
    } else {
        return Error(400, "password is wrong!");
    }
}

Response User::setPassword(string newPassword, string confirmPassword) {
    if (newPassword == confirmPassword) {
        this->password = newPassword;
        return Success(200, "password changed");
    }
    return Error(400, "confirmPassword is wrong");

}

Response User::login(string username, string password) throw(Exception) {
    bool isUserExists = DataBaseRepository::getDataBase()->isUserExists(username);
    if (isUserExists) {
        auto user = DataBaseRepository::getDataBase()->findUserByUserName(username);
        if (user.password == hash(password)) {
            std::cout << "you are successfully login with username: " + username << std::endl;
        } else {
            throw Exception("password is wrong!");
        }
    } else {
        throw Exception("username is wrong!");
    }
}

Response User::signup(string username, string password, string confirmPassword, string email) throw(Exception) {
    bool isUserExists = DataBaseRepository::getDataBase()->isUserExists(username);

    if (isUserExists) throw Exception("username is already taken!");
    if (password != confirmPassword) throw Exception("confirmPassword doesn't match the password");

    return DataBaseRepository::getDataBase()->addUser(User(0, username, password, email));

}

string User::hash(string value) {
    return to_string(std::hash<std::string>{}(value));
}

User::User(int id, string username, string password, string email) :
        id(id), username(std::move(username)),
        password(std::move(password)),
        email(std::move(email)) {

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

