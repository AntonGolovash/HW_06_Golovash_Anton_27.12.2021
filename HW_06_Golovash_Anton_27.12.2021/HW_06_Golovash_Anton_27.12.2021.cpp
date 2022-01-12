#include<iostream>
#include "OneWayList.h"
#include "OneWayList.cpp"
#include "Student.h"
//#include "Student.cpp"

//List2<Student>& SortById(List2<Student>& students)
//{
//
//}

int main()
{
	//---------------------------------------------------------------
	OneWayList<int> oneWayList;
	oneWayList.add(5);
	oneWayList.add(7);
	oneWayList.add(10);
	oneWayList.add(55);
	oneWayList.add(78);
	oneWayList.add(100);

	Node<int>* tmpNode = oneWayList.begin();
	while (tmpNode != nullptr)
	{
		cout << tmpNode->data << "\t";
		tmpNode = tmpNode->next;
	}
	cout << endl;
	oneWayList.insert(255, 2);

	cout << endl;
	cout << "list2.insert(255, 2)" << endl;
	cout << endl;

	tmpNode = oneWayList.begin();
	while (tmpNode != nullptr)
	{
		cout << tmpNode->data << "\t";
		tmpNode = tmpNode->next;
	}
	cout << endl;
	cout << oneWayList[2] << endl;

	oneWayList.remove(2);

	cout << endl;
	cout << oneWayList[2] << endl;
	//---------------------------------------------------------------
	OneWayList<Student> students {};
	students.add(Student(93, "John", "+380672583647"));
	students.add(Student(84, "Oliver", "+380663259874"));
	students.add(Student(45, "Liam", "+380976582149"));
	students.add(Student(36, "James", "+380506374982"));
	students.add(Student(52, "Lucas", "+380968749521"));

	//SortById(students);

	//Node<Student>* tmpNode = students.begin();
	//while (tmpNode != nullptr)
	//{
	//	cout << tmpNode->data << endl;
	//	tmpNode = tmpNode->next;
	//}
	//cout << endl;
}
