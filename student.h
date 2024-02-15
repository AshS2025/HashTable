#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
//#include "node.h" //might have to take out idk

using namespace std;

class Student {
 public:
  Student(); //default constructor
  Student(char*, char*, float, int); //modified constructor
  int id;
  char* name;
  char* lastName;
  float gpa;
  int getID();
  char* getName();
  char* getlastName();
  float getGPA();
};

#endif

