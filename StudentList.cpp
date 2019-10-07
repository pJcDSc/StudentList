/*
 * Author: Peter Jin
 * Date: 9/17/19
 * Program that holds a list of students
 * each student has a id, gpa, and full name
 * functions:
 * Print, Delete, Add, Quit, H
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//A student struct which contains a firstname, lastname, id, and gpa
struct Student {
  char firstName[20];
  char lastName[25];
  int id;
  float gpa;
};

//declare functions
void printHelp();
bool parse (char c[10], vector<Student*>* v);
void add (vector<Student*>* v);
void del (vector<Student*>* v);
void quit ();
void printAll(vector<Student*>* v);

int main() {
  cout << "Thank you for using StudentList.exe" << endl;
  cout << "Type 'h' for help" << endl;

  //configure cout to print floats to 2 decimal places
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  //create the list pointers
  vector<Student*> studentList;
  vector<Student*>* studentPointer = &studentList;

  //while running, keep running until parse returns false (quit is called)
  bool running = true;
  while(running){
    //Get input (command shouldn't be more than 10 chars
    char input[10] = "";
    cin.get(input, 10);
    cin.get();
    cin.clear();
    running = parse(input, studentPointer);
  }

  return 0;
}

//Parse function which decides which functions to call and passes necessary arguments
bool parse(char c[10], vector<Student*>* v){
  for(int i = 0; i < strlen(c); i++){
    c[i] = toupper(c[i]);
  }

  //Print help if H 
  if (strcmp(c, "H") == 0){
    //cout << "HELP" << endl;
    printHelp();
  }
  //Add student with add
  else if(strcmp(c, "ADD") == 0){
    //cout << "ADD" << endl;
    add(v);
  }
  //Print all students with print
  else if(strcmp(c, "PRINT") == 0){
    //cout << "PRINT" << endl;
    printAll(v);
  }
  //Delete a student with delete
  else if(strcmp(c, "DELETE") == 0){
    //cout << "DELETE" << endl;
    del(v);
  }
  //Quit program with quit
  else if(strcmp(c, "QUIT") == 0) {
    //cout << "QUIT" << endl;
    quit();
    return false;
  } else {
    cout << "Command was: " << c << endl;
    //cout << "Sorry, please type in a valid command. Type 'h' for help." << endl;
  }
  return true;
}

//Prints the help manual which consists of all the commands
void printHelp() {
  cout << "Help Manual:" << endl;
  cout << "Commands: " << endl;
  cout << "ADD: add a student to the student list" << endl;
  cout << "DELETE: delete a student from the student list" << endl;
  cout << "PRINT: print all students in student list" << endl;
  cout << "QUIT: exit the program" << endl;
}

//Prompts user for inputs and adds to studentlist
void add(vector<Student*>* v) {
  Student *newStud = new Student();

  //Prompt user for first, last, id, and gpa
  cout << "Please enter the student's first name" << endl;
  cin >> (*newStud).firstName;
  cout << "Please enter the student's last name" << endl;
  cin >> (*newStud).lastName;
  cout << "Please enter the student's ID" << endl;
  cin >> (*newStud).id;
  cout << "Please enter the student's GPA" << endl;
  cin >> (*newStud).gpa;
  
  //Add student to list
  (*v).push_back(newStud);

  //Clear newline from input
  cin.get();

  //Tell user they added a student to the list
  cout << "Student " << (*newStud).firstName << " " << (*newStud).lastName << " has been added to the list." << endl;
}

//Prints students in list
void printAll(vector<Student*>* v){
  bool printed = false;

  //iterator for vector
  vector<Student*>::iterator it;

  //iterate through vector
  for (it = (*v).begin(); it != (*v).end(); ++it) {
    printed = true;

    //Print the student with formatting
    cout << (**it).firstName << " " << (**it).lastName << ": " << (**it).id << ", " << (**it).gpa << endl; 
  }

  //If no students were printed say so
  if(!printed) cout << "There are no students in the list." << endl;
}

//Prints exit message (add other exit functions here)
void quit() {
  cout << "Thank you for using StudentList! Have a great day!" << endl;
}

//Deletes given student
void del(vector<Student*>* v) {
  int id;

  //Prompt user for first and last name
  cout << "Enter the student ID" << endl;
  cin >> id;
  cin.get();
  vector<Student*>::iterator it;
  bool removed = false;
  char first[20];
  char last[20];
  
  //iterate through vector
  for (it = (*v).begin(); it != (*v).end(); it++){
    if ((**it).id == id) {
      strcpy(first, (**it).firstName);
      strcpy(last, (**it).lastName);
      //Delete data of pointer
      delete (*it);
      //Remove student from list
      (*v).erase(it);
      removed = true;
      cout << "Removed Student " << first << " " << last << "." << endl;
      break;
    }
  }
  
  //If no students were removed say so
  if(!removed){
    cout << "Could not find any students with name " << first << " " << last << " in list." << endl;
  }
}

