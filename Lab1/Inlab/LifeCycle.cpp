//Name: Ashley Nguyen - apn2my
//InLab01 - LifeCycle.cpp
//1.26.16

#include <iostream>
#include <string>
#include "LifeCycle.h"

using namespace std;

//---------------------------------------------------- static variables
int MyObject::numObjs = 0;  // static member for all objects in class
static MyObject staticObj("I'm static, outside of main");

// ------------------------------------------------  default constructor
MyObject::MyObject(const char *n) : name(n) {
    id = ++numObjs;
    cout << "MyObject Default constructor: " << *this << endl;
}

// ---------------------------------------------------  copy constructor
MyObject::MyObject(const MyObject& rhs) : name(rhs.name) {
    id = ++numObjs;
    cout << "MyObject Copy constructor:    " << *this << endl;
}

// --------------------------------------------------------  destructor
MyObject::~MyObject() {
    cout << "MyObject Destructor:          " << *this << endl;
}

// ----------------------------------------------------------  print out
ostream& operator<<(ostream& output, const MyObject& obj) {
    // output in format:  ("object name",id)
    return output << "(\"" << obj.name << "\"," << obj.id << ")";
}
