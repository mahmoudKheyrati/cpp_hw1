#pragma once

#include <string>
#include <vector>
#include "User.h"

using namespace std;

enum Gender{
    Male, Female
};

class Profile {
private:
    int id;
    string name;
    string bio;
    vector<User> followings = vector<User>();
    vector<User> followers = vector<User>();
    bool isPrivate;
    User user;
    string phoneNumber;
    Gender gender;
public:
    Profile(int id, string name, User user, string  bio, vector<User> followings,
            vector<User> followers, bool isPrivate, string  phoneNumber, Gender gender);

    const string &getName() const;

    const string &getBio() const;

    void setId(int id);

    const vector<User> &getFollowings() const;

    const vector<User> &getFollowers() const;

    bool isPrivate1() const;

    const User &getUser() const;

    const string &getPhoneNumber() const;

    Gender getGender() const;

    bool getPrivate() const;

    void setPrivate(bool isPrivate);

    void addFollower(User user);

    void addFollowing(User user);

};
