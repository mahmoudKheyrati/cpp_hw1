#include "Profile.h"

#include <utility>

bool Profile::getPrivate() const {
    return isPrivate;
}

void Profile::setPrivate(bool isPrivate) {
    Profile::isPrivate = isPrivate;
}

Profile::Profile(int id, string name, User user, string bio = "", vector<User> followings = vector<User>(),
                 vector<User> followers = vector<User>(),
                 bool isPrivate = false, string phoneNumber = "", Gender gender = Male) :
        id(id),
        name(std::move(name)), bio(std::move(bio)),
        followings(std::move(followings)),
        followers(std::move(followers)),
        isPrivate(isPrivate),
        user(std::move(user)),
        phoneNumber(std::move(phoneNumber)),
        gender(gender) {

}

const string &Profile::getName() const {
    return name;
}

const string &Profile::getBio() const {
    return bio;
}

const vector<User> &Profile::getFollowings() const {
    return followings;
}

const vector<User> &Profile::getFollowers() const {
    return followers;
}

bool Profile::isPrivate1() const {
    return isPrivate;
}

const User &Profile::getUser() const {
    return user;
}

const string &Profile::getPhoneNumber() const {
    return phoneNumber;
}

Gender Profile::getGender() const {
    return gender;
}

void Profile::setId(int id) {
    Profile::id = id;
}

void Profile::addFollowing(User user) {
    followings.push_back(user);
}

void Profile::addFollower(User user) {
    followers.push_back(user);
}
