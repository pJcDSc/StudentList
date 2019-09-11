#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[25];
  int id;
  float gpa;
};

void printHelp();
void parse (char c[10]);
void add (vector<Student> v);
void del (vector<Student> v);
void quit ();
void printAll(vector<Student> v);

int main() {
  cout << "Thank you for using student list" << endl;
  cout << "Type 'h' for help" << endl;

  vector<Student> studentList;
  
  //Program will exit in quit function
  while(true){
    char input[10];
    for(int i = 0; i < 10; i++){
      input[i] = ' ';
    }
    cin.get(input, 10);
    cin.get();
    parse(input);
  }

  return 0;
}

void parse(char c[10]){
  if (strcmp(c, "H") == 0 || strcmp(c, "h") == 0){
    //cout << "HELP" << endl;
    printHelp();
  } else if(strcmp(c, "ADD") == 0){
    //cout << "ADD" << endl;
    add();
  } else if(strcmp(c, "PRINT") == 0){
    cout << "PRINT" << endl;
  } else if(strcmp(c, "DELETE") == 0){
    cout << "DELETE" << endl;
  } else if(strcmp(c, "QUIT") == 0) {
    cout << "QUIT" << endl;
  } else {
    cout << "Sorry, please type in a valid command. Type 'h' for help." << endl;
  }
}

void printHelp() {
  cout << "Help Manual:" << endl;
  cout << "Commands: " << endl;
  cout << "ADD: add a student to the student list" << endl;
  cout << "DELETE: delete a student from the student list" << endl;
  cout << "PRINT: print all students in student list" << endl;
  cout << "QUIT: exit the program" << endl;
}

void add(vector<Student> v) {
  Student newStud;
  cout << "Please enter the student's first name" << endl;
  cin >> newStud.firstName;
  cout << "Please enter the student's last name" << endl;
  cin >> newStud.lastName;
  cout << "Please enter the student's ID" << endl;
  cin >> newStud.id;
  cout << "Please enter the student's GPA" << endl;
  cin >> newStud.gpa;
  v.push_back(newStud);
  cout << "Student " << newStud.firstName << " " << newStud.lastName << " has been added to the list." << endl;
}

void printAll(vector<Student> v){
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *i.firstName << " " << *i.lastName << ": " << *i.id << ", " << *i.gpa << endl; 
  }
}
