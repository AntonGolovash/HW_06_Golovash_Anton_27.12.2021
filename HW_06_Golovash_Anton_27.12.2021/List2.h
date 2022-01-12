#pragma once
#include<iostream>

template<class T1>
class Node;

template<class T>
class List2
{
public:
	List2();
	~List2();
	void add(T data);// add an item to the end of the list
	Node<T>& back();// return a reference to the last element of the list
	Node<T>* begin();// return a pointer to the first element of the list
	void clear();// delete all elements in the list
	void insert(T data, int index);// add an item to a specific position in the list
	void isEmpty();// checking the list for the emptiness
	void remove(int index);// delete an item from a specific position in the list
	void replace(T data, int index);// replace an item in a specific position in the list
	int size();// returns a size of the list
	void unique();// remove duplicate items from the list
	T operator[](int index);
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;
};

template<class T1>
class Node
{
public:
	Node<T1>* next;
	T1 data;

private:

};