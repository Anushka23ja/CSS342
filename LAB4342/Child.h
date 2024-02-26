#ifndef CHILD_H
#define CHILD_H

#include <string>
#include <iostream>

using namespace std;

class Child {
private:
    //CREATING PRIVATE VARIABLES 
    int age;
    string first;
    string last;

public:

    //DEFAULT + DIFFERENT CONSTRUCTORS 
    Child();
    Child(string lastname);
    Child(string firstname, string lastname);
    Child(string firstname, string lastname, int age);
    ~Child();

    //SETTERS
    void setage(int age);
    void setfirstname(const string firstname);
    void setlastname(const string lastname);
    void setfullname(const string firstname, const string lastname);

    //GETTERS
    int getage() const;
    string getfirstname() const;
    string getlastname() const;

    //OPERATORS
    bool operator>(const Child& other) const;
    bool operator<(const Child& other) const;
    void operator=(const Child& other);
    bool operator!=(const Child& other) const;
    bool operator==(const Child& other) const;

    //FRIEND FUNCTION
    friend ostream& operator<<(ostream& os, const Child& child);
};

#endif
