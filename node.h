#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"

using namespace std;

class Node {
 public:
  // Constructor (and its corresponding student)
  Node(Student* newStudent);
  // Destructor
  ~Node();
  // Get the next node in the list
  Node* getNext();
  // Get the student that corresponds with the node
  Student* getStudent();
  // Set the next node in the list
  void setNext(Node* n);

  //void setPrevious(Node* p);
  //void getPrevious();

 private:
  // Variables
  Node* next;
  Student* stu;
  //Node* previous;
};
#endif
