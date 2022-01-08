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

string Student::operator<<(Student& students)
{
	stringstream ss;
	ss << to_string(Student::_ID) << endl;
	ss << Student::_Name<< endl;
	ss << Student::_Phone << endl;

	return ss.str();
}
