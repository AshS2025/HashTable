#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void addStudent(Node*, Node** &hash, int, Node*, int);
void rehash(Node** &hash, int &);
void print(Node** &hash, int);
void deleteStudent(Node** &hash, int, int);

int main() {
  //all the nodes in the original array are head nodes

  
  int size = 100;
  Node** hash = new Node*[size];

  for (int i = 0; i < size; i++){
    hash[i] = NULL;
  }

  bool playing = true;

  while (playing == true){
    cout << "type in a command" << endl;
    char command[7];
    cin >> command;

    if (strcmp (command, "QUIT") == 0){
      playing = false;
    }

    if (strcmp (command, "DELETE") == 0) {
      int findid;
      cout << "enter the id of the student you'd like to delete" << endl;
      cin >> findid;
      deleteStudent(hash, size, findid);
    }

    if (strcmp (command, "ADD") == 0){
      //create the student
      char* name = new char[20];
      char* lastName = new char[20];
      float gpa;
      int id;
      
    cout << "ok we gonna create the student first" << endl;
    cout << "enter first name" << endl;
    cin >> name;
    cin.ignore(80, '\n');
    cout << "enter last name" << endl;
    cin >> lastName;
    cout << "enter gpa" << endl;
    cin >> gpa;
    cout << "enter id" << endl;
    cin >> id;
    Student* stu = new Student(name, lastName, gpa, id);

    Node* newNode = new Node(stu);
    int modulus = (stu->id) % size;
    Node* current = hash[modulus];
    addStudent(newNode, hash, modulus, current, size);

    }

    if (strcmp (command, "PRINT") == 0){
      print(hash, size);
    }
  }

    


    
  
  
}

void addStudent(Node* newNode, Node** &hash, int modulus, Node* current, int size) {
  /*
    create the studnet outisde of the function
    modulus id and size
    hashtable[modulus] = NULL then fill in the spot
    collisions check:L =/= null, keep going
    int that tracks position in while loop
    if position = 3 then rehash
    addstudent returns a boolean that determines whether or not to rehash
   */

    int position = 0;
    //Node* current = hash[modulus];

    if (current == NULL){
      cout << modulus << endl;
      cout << "normal hash" << endl;
      hash[modulus] = newNode;
      cout << (hash[modulus])->getStudent()->getID() << endl;
    }
    


    else {
	while (current->getNext() != NULL){
	  current = current->getNext();
	  position = position + 1;
	}
	if(position <= 1){
	  current->setNext(newNode);
	}
	if (position >=2){
	  current->setNext(newNode);
	  cout << "rehash necessary" << endl;
	  rehash(hash, size);
	}
	  //addStudent(newNode, hash, modulus, current, size);
	}
    /*if ((current->getNext() == NULL) && (position <= 1)){
	  //the greater than less than two things are super funky idt i did it right 
	  cout << "hashing!" << endl;
	  (hash[modulus])->setNext(newNode);
	}
	if ((current->getNext() == NULL) && (position >= 2)){
	  cout << "rehash necessary" << endl;
	  rehash(hash, size);
	}
    */

}

void rehash(Node** &hash, int &size) {

  size = size * 2;

  Node** newHash = new Node*[size];


  for (int i = 0; i < size; i++) {

    newHash[i] = nullptr;

  }


  for (int i = 0; i < size / 2; i++) {

    Node* current = hash[i];


    while (current != nullptr) {

      Node* next = current->getNext();

      int newModulo = current->getStudent()->getID() % size;


      current->setNext(newHash[newModulo]);

      newHash[newModulo] = current;


      current = next;

    }

  }


  for (int i = 0; i < size / 2; i++) {

    Node* current = hash[i];

    while (current != nullptr) {

      Node* next = current->getNext();

      delete current;

      current = next;

    }

  }


  delete[] hash;


  // Update the hash pointer to point to the new hash table

  hash = newHash;

}

/*void rehash(Node** &hash, int &size){
  
    for loop through the original hash table and find all the non null things and rehash them
    also remember to check for linked nodes
    and make sure that there aren't any weird pointer things like set things back to null
   

  cout << "inside function" << endl;
  size = size * 2;
  cout << size << endl;
  Node** newHash = new Node*[size];

   for (int i = 0; i < size; i++){
     newHash[i] = NULL;
  }

  cout << "did we get here" << endl;
  
  for (int i = 0; i < size; i++){
    
    if (hash[i] != NULL){
      Node* c = hash[i];
      hash[i] = c->getNext();
      c->setNext(NULL);
      while (c != NULL){
	int newid = c->getStudent()->getID();
	int modulo = newid % size;
	if (newHash[modulo] == NULL){
	  newHash[modulo] = c;
	}
	else { //if that spot in the new hash table has already been taken up
	  Node* temp = newHash[modulo];
	  while (temp->getNext() != NULL){
	    temp = temp->getNext();
	  }
	  if (temp->getNext() == NULL){
	    temp->setNext(c);
	  }
	 }

	c = c->getNext();
	
	}
       
      }
    }
  cout << "getting here" << endl;

  delete hash;
  hash = newHash;
  print(hash, size);
  cout << "after print" << endl;
  }*/

void print(Node** &hash, int size){
  /*
    for loop through the thing
    should be similar to print function in previous student list
    only issue is checking for linked list in each slot
    is there an order i have to print in?

    for i
    if (hash[i] != NULL){
    Node* c = hash[i];
    while (c != NULL){
    cout << c's id
    c = c.getNext()
    }
    }
    
  */

  for (int i = 0; i < size; i++){
    if (hash[i] != NULL){
      Node* c = hash[i];
      while (c != NULL){
	cout << c->getStudent()->getID() << ", ";
	c = c->getNext();
      }
    }
    // cout << " " << endl;
  }
}

void deleteStudent (Node** &hash, int size, int findId){

  
  for (int i = 0; i < size; i++){
    if (hash[i] != NULL){
      Node* c = hash[i];
      Node* p = hash[i];
      while (c != NULL){
	//check if the id of that student is equal to the findid
	if ((c->getStudent()->getID()) == findId){
	  cout << "is this the first name of the student you would like to delete: " << c->getStudent()->getName() << " ?" << endl;
	  cout << "type 'y' or 'n'" << endl;
	  char a;
	  cin >> a;
	  if (a == 'y'){
	    //if head
	    if (c == hash[i]){
	      cout << "first case" << endl;
	      Node* temp = c;
	      hash[i] = c->getNext();
	      delete temp;
	      return;
	    }
	    else if (c->getNext() == NULL){
	      //if p != c
	      cout << "last case" << endl;
	      p->setNext(NULL);
	      delete c;
	      return;
	    }

	    else {
	      cout << "middle case" << endl;
	      p->setNext(c->getNext());
	      delete c;
	      return;
	    }
	  }
	  else {
	    p = c;
	    c = c->getNext();
	   }
	    //if last
	    //else middle
	    
	    //does deleting a node delete associated pointers?
	}
       else {
	 cout << "getting to the else statement" << endl;
	     p = c;
	     c = c->getNext();
	     
	   }

	}

      }
    
	 }
	  
	    
	}
	
      
    
  
  

