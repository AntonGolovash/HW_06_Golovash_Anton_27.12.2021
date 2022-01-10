#include "Student.h"

Student::Student()
{
	_ID = 0;
	_Name = "Name";
	_Phone = "Phone";
}

Student::Student(int ID, string Name, string Phone)
{
	_ID = ID;
	_Name = Name;
	_Phone = Phone;
}

Student::~Student()
{

}

int Student::getID()
{
	return _ID;
}

string Student::getName()
{
	return _Name;
}

string Student::getPhone()
{
	return _Phone;
}

void Student::print()
{
}

ostream& operator<<(ostream& out, Student& students)
{
	out << to_string(students.getID()) << endl;
	out << students.getName() << endl;
	out << students.getPhone() << endl;
	return out;
}