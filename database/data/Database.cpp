#include "Database.h"
#include "../../exceptions/Exceptions.h"

Response DataBase::addUser(User user) {
    // validations
    bool isFind = find_if(users.begin(), users.end(), [&](const User& currentUser) {
        return currentUser.getUsername() == user.getUsername() || currentUser.getEmail() == user.getUsername();
    }) != users.end();
    if (isFind) {
        return Error(400, "the userName or Email is already taken! choose another username or Email");
    }
    user.setId(userNextId++);
    users.push_back(user);
    return Success(200, "user added to database");

}

bool DataBase::isUserExists(string username) {
    auto discovered = find_if(users.begin(), users.end(), [&](User currentUser) {
        return currentUser.getUsername() == username;
    });
    bool isFind = discovered!=users.end();
    return isFind;
}
User DataBase::findUserByUserName(string username) {
    auto discovered = find_if(users.begin(), users.end(), [&](User currentUser) {
        return currentUser.getUsername() == username;
    });
    bool isFind = discovered!=users.end();
    if (isFind) {
        return discovered[0];
    }
    throw NotFoundException("user with name [ "+username+" ] was not found.");
}

User DataBase::findUserByEmail(string email) {
    auto discovered = find_if(users.begin(), users.end(), [&](User currentUser) {
        return currentUser.getEmail() == email;
    });
    bool isFind = discovered!=users.end();
    if (isFind) {
        return discovered[0];
    }
    throw NotFoundException("user with email [ "+email+" ] was not found.");

}

Response DataBase::addProfile(Profile profile) {
    bool isFind = find_if(profiles.begin(), profiles.end(), [&](Profile currentProfile) {
        return currentProfile.getUser().getUsername() == profile.getUser().getUsername() || currentProfile.getUser().getEmail() == profile.getUser().getEmail();
    }) != profiles.end();
    if (isFind) {
        return Error(400, "you can't add profile because the userName or email is already taken");
    }
    profile.setId(profileNextId++);
    profiles.push_back(profile);
    return Success(200, "profiles added to database");
}
bool DataBase::isProfileExists(string username) {
    auto discovered = find_if(profiles.begin(), profiles.end(), [&](Profile currentProfile) {
        return currentProfile.getUser().getUsername() == username;
    });
    bool isFind = discovered!=profiles.end();
    return isFind;
}


Profile DataBase::findProfileByName(string name) {
    auto discovered = find_if(profiles.begin(), profiles.end(), [&](Profile currentProfile) {
        return currentProfile.getName() == name;
    });
    bool isFind = discovered!=profiles.end();
    if (isFind) {
        return discovered[0];
    }
    throw NotFoundException("profile with name [ "+name+" ] was not found.");

}

Profile DataBase::findProfileByUserName(string userName) {
    auto discovered = find_if(profiles.begin(), profiles.end(), [&](Profile currentProfile) {
        return currentProfile.getUser().getUsername() == userName;
    });
    bool isFind = discovered!=profiles.end();
    if (isFind) {
        return discovered[0];
    }
    throw NotFoundException("profile with userName [ "+userName+" ] was not found.");

}

Profile DataBase::findProfileByPhoneNumber(string phoneNumber) {
    auto discovered = find_if(profiles.begin(), profiles.end(), [&](Profile currentProfile) {
        return currentProfile.getPhoneNumber() == phoneNumber;
    });
    bool isFind = discovered!=profiles.end();
    if (isFind) {
        return discovered[0];
    }
    throw NotFoundException("profile with phoneNumber [ "+phoneNumber+" ] was not found.");

}

const vector<User> &DataBase::getUsers() const {
    return users;
}

const vector<Profile> &DataBase::getProfiles() const {
    return profiles;
}




