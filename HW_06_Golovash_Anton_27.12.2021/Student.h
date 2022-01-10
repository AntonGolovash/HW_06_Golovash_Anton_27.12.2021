#pragma once
#include<iostream>
#include <string>
#include <ostream>

using namespace std;

class Student
{
public:
	Student();
	Student(int ID, string Name, string Phone);
	~Student();
	int getID();
	string getName();
	string getPhone();
	void print();
	friend ostream& operator<<(ostream& out, Student& students);
private:
	int _ID;
	string _Name;
	string _Phone;
};
