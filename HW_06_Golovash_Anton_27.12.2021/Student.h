#pragma once
#include<iostream>
#include <sstream>

using namespace std;

class Student
{
public:
	Student();
	Student(int ID, string Name, string Phone);
	~Student();
	string operator<<(Student& students);
private:
	int _ID;
	string _Name;
	string _Phone;
};
