#include "Student.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

const string DATA_FILE = "../data/students.txt";

// Function declarations
void displayMenu();
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);

void saveStudents(const vector<Student>& students);
void loadStudents(vector<Student>& students);

int getValidInteger(const string& prompt);
double getValidGPA(const string& prompt);
string getNonEmptyString(const string& prompt);

// Display main menu
void displayMenu(){
    cout << "\n ========================================\n";
    cout << "        STUDENT MANAGEMENT SYSTEM\n";
    cout << " ========================================\n";
    cout << "  1. Add Student\n";
    cout << "  2. Display All Students\n";
    cout << "  3. Search Student\n";
    cout << "  4. Update Student\n";
    cout << "  5. Delete Student\n";
    cout << "  6. Exit\n";
    cout << " ========================================\n";
}

// Add a new student
void addStudent(vector<Student>& students){
    cout << "\n --- Add Student ---\n";

    int id = getValidInteger(" Enter student ID: ");

    // Check for duplicate ID
    for (const Student& student : students) {
        if (student.getId() == id) {
            cout << " Error: A student with this ID already exists!\n";
            return;
        }
    }

    string name = getNonEmptyString(" Enter student name: ");
    int age = getValidInteger(" Enter student age: ");
    string department = getNonEmptyString(" Enter department: ");
    double gpa = getValidGPA(" Enter GPA (0.0 - 4.0): ");

    students.emplace_back(id, name, age, department, gpa);

    saveStudents(students);

    cout << "\n Student added successfully!\n";
}


// Display all students
void displayStudents(const vector<Student>& students){
    cout << "\n --- Student Records ---\n";

    if (students.empty()) {
        cout << " No student records found!\n";
        return;
    }

    for (const Student& student : students) {
        cout << "\n ----------------------------------------------\n";
        student.display();
    }

    cout << " ----------------------------------------------\n";
}

// Search for a student by ID
void searchStudent(const vector<Student>& students){
    cout << "\n --- Search Student ---\n";

    int id = getValidInteger(" Enter student ID to search: ");

    for (const Student& student : students) {
        if (student.getId() == id) {
            cout << "\n Student found:\n";
            cout << " ----------------------------------------------\n";
            student.display();
            cout << " ----------------------------------------------\n";
            return;
        }
    }

    cout << " Student with ID " << id << " was not found!\n";
}


// Update an existing student
void updateStudent(vector<Student>& students){
    cout << "\n --- Update Student ---\n";

    int id = getValidInteger(" Enter student ID to update: ");

    for (Student& student : students) {
        if (student.getId() == id) {
            cout << "\n Current student information:\n";
            cout << " ----------------------------------------------\n";
            student.display();
            cout << " ----------------------------------------------\n";

            string name = getNonEmptyString(" Enter new name: ");
            int age = getValidInteger(" Enter new age: ");
            string department = getNonEmptyString(" Enter new department: ");
            double gpa = getValidGPA(" Enter new GPA (0.0 - 4.0): ");

            student.setName(name);
            student.setAge(age);
            student.setDepartment(department);
            student.setGpa(gpa);

            saveStudents(students);

            cout << "\n Student updated successfully!\n";
            return;
        }
    }

    cout << " Student with ID " << id << " was not found!\n";
}

// Delete a student
void deleteStudent(vector<Student>& students){
    cout << "\n --- Delete Student ---\n";

    int id = getValidInteger(" Enter student ID to delete: ");

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {

            cout << "\n Student found:\n";
            cout << " ----------------------------------------------\n";
            it->display();
            cout << " ----------------------------------------------\n";

            char confirmation;
            cout << " Are you sure you want to delete this student? (y/n): ";
            cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                students.erase(it);
                saveStudents(students);

                cout << " Student deleted successfully!\n";
            } else {
                cout << " Delete operation cancelled!\n";
            }

            return;
        }
    }

    cout << " Student with ID " << id << " was not found!\n";
}

// Save all students to file
void saveStudents(const vector<Student>& students){
    ofstream file(DATA_FILE);

    if (!file) {
        cout << " Error: Unable to open data file for writing!\n";
        return;
    }

    for (const Student& student : students) {
        file << student.toFileFormat() << '\n';
    }

    file.close();
}

// Load students from file
void loadStudents(vector<Student>& students){
    ifstream file(DATA_FILE);

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            try {
                students.push_back(Student::fromFileFormat(line));
            }
            catch (...) {
                cout << " Warning: Skipping invalid student record!\n";
            }
        }
    }

    file.close();
}

// Get a valid integer from the user
int getValidInteger(const string& prompt){
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << " Invalid input. Please enter a valid number!\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get a valid GPA
double getValidGPA(const string& prompt){
    double gpa;

    while (true) {
        cout << prompt;

        if (cin >> gpa && gpa >= 0.0 && gpa <= 4.0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return gpa;
        }

        cout << " Invalid GPA. Please enter a value between 0.0 and 4.0!\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get a non-empty string
string getNonEmptyString(const string& prompt){
    string value;

    while (true) {
        cout << prompt;
        getline(cin, value);

        if (!value.empty()) {
            return value;
        }

        cout << " Input cannot be empty. Please try again!\n";
    }
}

// Main function
int main(){
    vector<Student> students;

    // Load previously saved records
    loadStudents(students);

    int choice;

    do {
        displayMenu();
        choice = getValidInteger(" Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                updateStudent(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 6:
                cout << "\n Thank you for using Student Management System!\n";
                break;

            default:
                cout << " Invalid choice! Please select 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}
