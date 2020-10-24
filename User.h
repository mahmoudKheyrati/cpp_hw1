#pragma once

#include <string>
#include "model/Response.h"
#include "exceptions/Exceptions.h"
#include <iostream>

using namespace std;

class User {
private:
    int id;
    string username;
    string password;
    string email;

public:
    User(int id, string username, string password, string email);

    User(string email);

    const string &getUsername() const;

    void setId(int id);

    const string &getEmail() const;

    Response resetPassword(string currentPassword, string newPassword, string confirmPassword);

    Response setPassword(string newPassword, string confirmPassword);

    static Response login(string username, string password) throw(Exception);

    static Response signup(string username, string password, string confirmPassword, string email) throw(Exception);

    static string hash(string value);
};