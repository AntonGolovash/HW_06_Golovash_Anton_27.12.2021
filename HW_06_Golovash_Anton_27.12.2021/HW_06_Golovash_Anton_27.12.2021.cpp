#include<iostream>
#include "List2.h"
#include "List2.cpp"
#include "Student.h"
#include "Student.cpp"

List2<Student>& SortById(List2<Student>& students)
{

};

int main()
{
	//---------------------------------------------------------------
	List2<int> list2;
	list2.add(5);
	list2.add(7);
	list2.add(10);
	list2.add(55);
	list2.add(78);
	list2.add(100);

	Node<int>* tmpNode = list2.begin();
	while (tmpNode != nullptr)
	{
		cout << tmpNode->data << "\t";
		tmpNode = tmpNode->next;
	}
	cout << endl;
	list2.insert(255, 2);

	cout << endl;
	cout << "list2.insert(255, 2)" << endl;
	cout << endl;

	tmpNode = list2.begin();
	while (tmpNode != nullptr)
	{
		cout << tmpNode->data << "\t";
		tmpNode = tmpNode->next;
	}
	cout << endl;
	cout << list2[2] << endl;

	list2.remove(2);

	cout << endl;
	cout << list2[2] << endl;
	//---------------------------------------------------------------


}
