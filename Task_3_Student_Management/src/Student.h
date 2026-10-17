#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student{
	private:
    	int id;
    	std::string name;
    	int age;
    	std::string department;
    	double gpa;
	
	public:
    	Student();
    	Student(int id, std::string name, int age, std::string department, double gpa);

    	int getId() const;
    	std::string getName() const;
    	int getAge() const;
    	std::string getDepartment() const;
    	double getGpa() const;

    	void setName(std::string name);
    	void setAge(int age);
    	void setDepartment(std::string department);
    	void setGpa(double gpa);

    	void display() const;

    	std::string toFileFormat() const;
    	static Student fromFileFormat(const std::string& line);
};

#endif
