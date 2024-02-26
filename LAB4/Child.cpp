#include "Child.h"
#include <iostream>

using namespace std;

Child::Child() {
    first = " ";
    last = " ";
    age = 0;
}

Child::Child(string lastname) {
    first = "";
    last = lastname;
    age = 0;
}

Child::Child(string firstname, string lastname) {
    first = firstname;
    last = lastname;
    age = 0;
}

Child::Child(string firstname, string lastname, int age) {
    first = firstname;
    last = lastname;
    this->age = age;
}

Child::~Child() {}

void Child::setage(int age) {
    this->age = age;
}

void Child::setfirstname(const string firstname) {
    first = firstname;
}

void Child::setlastname(const string lastname) {
    last = lastname;
}

void Child::setfullname(const string firstname, const string lastname) {
    first = firstname;
    last = lastname;
}

int Child::getage() const {
    return age;
}

string Child::getfirstname() const {
    return first;
}

string Child::getlastname() const {
    return last;
}

bool Child::operator>(const Child& other) const {
    if (last > other.last)
        return true;
    else if (last == other.last) {
        if (first > other.first)
            return true;
        else if (first == other.first) {
            if (age > other.age)
                return true;
        }
    }
    return false;
}

bool Child::operator<(const Child& other) const {
    return !(*this > other || *this == other);
}

void Child::operator=(const Child& other) {
    first = other.first;
    last = other.last;
    age = other.age;
}

bool Child::operator!=(const Child& other) const {
    return !(*this == other);
}

bool Child::operator==(const Child& other) const {
    return (first == other.first && last == other.last && age == other.age);
}

ostream& operator<<(ostream& os, const Child& child) {
    if (child.getfirstname() != "") {
        os << child.getfirstname() << " ";
    }
    if (child.getlastname() != "") {
        os << child.getlastname() << " ";
    }
    if (child.getage() != 0) {
        os << child.getage();
    }
    return os;
}