//
// Created by lolip on 10/24/2020.
//

#include "Response.h"

#include <utility>

Response::Response(int responseCode, string message) : responseCode(responseCode), message(std::move(message)) {

}

int Response::getResponseCode() const {
    return responseCode;
}

void Response::setResponseCode(int responseCode) {
    Response::responseCode = responseCode;
}

const string &Response::getMessage() const {
    return message;
}

void Response::setMessage(const string &message) {
    Response::message = message;
}

Response::Response() {

}

Success::Success(int responseCode, const string &message) : Response(responseCode, message) {}

void Success::setResponseCode(int responseCode) {
    this->responseCode = responseCode;
}

void Success::setMessage(const string &message) {
    this->message = "[SUCCESS] " + message;
}

Error::Error(int responseCode, const string &message) : Response(responseCode, message) {}

void Error::setResponseCode(int responseCode) {
    this->responseCode = responseCode;
}

void Error::setMessage(const string &message) {
    this->message = "[ERROR] " + message;

}


