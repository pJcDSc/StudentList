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
bool parse (char c[10], vector<Student>* v);
void add (vector<Student>* v);
void del (vector<Student>* v);
void quit ();
void printAll(vector<Student>* v);

int main() {
  cout << "Thank you for using StudentList.exe" << endl;
  cout << "Type 'h' for help" << endl;

  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  
  vector<Student> studentList;
  vector<Student>* studentPointer;

  bool running = true;
  while(running){
    char input[10] = "";
    cin.get(input, 10);
    cin.get();
    cin.clear();
    running = parse(input, studentPointer);
  }

  return 0;
}

bool parse(char c[10], vector<Student>* v){
  for(int i = 0; i < strlen(c); i++){
    c[i] = toupper(c[i]);
  }
  if (strcmp(c, "H") == 0){
    //cout << "HELP" << endl;
    printHelp();
  } else if(strcmp(c, "ADD") == 0){
    //cout << "ADD" << endl;
    add(v);
  } else if(strcmp(c, "PRINT") == 0){
    //cout << "PRINT" << endl;
    printAll(v);
  } else if(strcmp(c, "DELETE") == 0){
    //cout << "DELETE" << endl;
    del(v);
  } else if(strcmp(c, "QUIT") == 0) {
    //cout << "QUIT" << endl;
    quit();
    return false;
  } else {
    cout << "Command was: " << c << endl;
    //cout << "Sorry, please type in a valid command. Type 'h' for help." << endl;
  }
  return true;
}

void printHelp() {
  cout << "Help Manual:" << endl;
  cout << "Commands: " << endl;
  cout << "ADD: add a student to the student list" << endl;
  cout << "DELETE: delete a student from the student list" << endl;
  cout << "PRINT: print all students in student list" << endl;
  cout << "QUIT: exit the program" << endl;
}

void add(vector<Student>* v) {
  Student newStud;
  cout << "Please enter the student's first name" << endl;
  cin >> newStud.firstName;
  cout << "Please enter the student's last name" << endl;
  cin >> newStud.lastName;
  cout << "Please enter the student's ID" << endl;
  cin >> newStud.id;
  cout << "Please enter the student's GPA" << endl;
  cin >> newStud.gpa;
  (*v).push_back(newStud);
  //cin.clear();
  cin.get();
  cout << "Student " << newStud.firstName << " " << newStud.lastName << " has been added to the list." << endl;
}

void printAll(vector<Student>* v){
  vector<Student>::iterator it;
  
  for (it = (*v).begin(); it != (*v).end(); it++) {
    cout << (*it).firstName << " " << (*it).lastName << ": " << (*it).id << ", " << (*it).gpa << endl; 
  }
}

void quit() {
  cout << "Thank you for using StudentList! Have a great day!" << endl;
}

void del(vector<Student>* v) {
  char first[20];
  char last[20];
  cout << "Enter the student name (First and Last)" << endl;
  cin >> first >> last;
  cin.get();
  vector<Student>::iterator it;

  bool removed = false;
  for (it = (*v).begin(); it != (*v).end(); it++){
    if (strcmp((*it).firstName, first) == 0 && strcmp((*it).lastName, last) == 0) {
      (*v).erase(it);
      removed = true;
      cout << "Removed Student " << first << " " << last << " from list." << endl;
    }
  }
  if(!removed){
    cout << "Could not find any students with name " << first << " " << last << " in list." << endl;
  }
}
  
