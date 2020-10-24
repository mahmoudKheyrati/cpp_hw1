#pragma once

#include <string>

using namespace std;


class Response {

protected:

    Response(int responseCode, string message);

    Response();

    int responseCode{};
    string message;

public:

    int getResponseCode() const;

    virtual void setResponseCode(int responseCode);

    const string &getMessage() const;

    virtual void setMessage(const string &message);

public:

};

class Success : public Response {
public:
    Success(int responseCode, const string &message);

    void setResponseCode(int responseCode) override;

    void setMessage(const string &message) override;

};

class Error : public Response {
public:
    Error(int responseCode, const string &message);

    void setResponseCode(int responseCode) override;

    void setMessage(const string &message) override;
};