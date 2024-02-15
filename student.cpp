#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

Student :: Student() {
  id = 0;
}

Student:: Student(char* newname, char* newlast, float newgpa,int newid){
  id = newid;
  gpa = newgpa;
  name = newname;
  lastName = newlast;
}

int Student::getID(){
  return id;
}

char* Student:: getName(){
  return name;
}

char* Student:: getlastName(){
  return lastName;
}

float Student:: getGPA(){
  return gpa;
}
