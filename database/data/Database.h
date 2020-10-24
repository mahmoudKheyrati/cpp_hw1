#pragma once

#include <vector>
#include "../../User.h"
#include "../../Profile.h"
#include <algorithm>
using namespace std;


class DataBase {
private:
    int userNextId = 1;
    int profileNextId = 1;
    vector<User> users = vector<User>();
    vector<Profile> profiles = vector<Profile>();
public:
    const vector<User> &getUsers() const;

    const vector<Profile> &getProfiles() const;

    Response addUser(User user);
    bool isUserExists(string username);
    User findUserByUserName(string username);
    User findUserByEmail(string email);

    Response addProfile(Profile profile);
    bool isProfileExists(string username);
    Profile findProfileByName(string name);
    Profile findProfileByUserName(string userName);
    Profile findProfileByPhoneNumber(string phoneNumber);

};