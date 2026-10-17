#include "Student.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// Default constructor
Student :: Student()
	: id(0), name(""), age(0), department(""), gpa(0.0) {}

// Parameterized constructor
Student::Student(int id, string name, int age, string department, double gpa)
    : id(id), name(name), age(age), department(department), gpa(gpa) {}

// Getter functions
int Student :: getId() const{
    return id;
}

string Student :: getName() const{
    return name;
}

int Student :: getAge() const{
    return age;
}

string Student :: getDepartment() const{
    return department;
}

double Student :: getGpa() const{
    return gpa;
}

// Setter functions
void Student :: setName(string name){
    this->name = name;
}

void Student :: setAge(int age){
    this->age = age;
}

void Student :: setDepartment(string department){
    this->department = department;
}

void Student :: setGpa(double gpa){
    this->gpa = gpa;
}

// Display student information
void Student :: display() const{
    cout << " ID: " << id;
    cout << " | Name: " << name;
    cout << " | Age: " << age << endl;
    cout << " Department: " << department;
    cout << " | GPA: " << fixed << setprecision(2) << gpa << endl;
}

// Convert student data into file format
string Student :: toFileFormat() const{
    ostringstream output;

    output << id << "|" << name << "|" << age << "|" << department << "|" << fixed << setprecision(2) << gpa;

    return output.str();
}

// Create a Student object from a saved file line
Student Student :: fromFileFormat(const string& line){
    stringstream input(line);

    string idString;
    string name;
    string ageString;
    string department;
    string gpaString;

    getline(input, idString, '|');
    getline(input, name, '|');
    getline(input, ageString, '|');
    getline(input, department, '|');
    getline(input, gpaString, '|');

    int id = stoi(idString);
    int age = stoi(ageString);
    double gpa = stod(gpaString);

    return Student(id, name, age, department, gpa);
}
