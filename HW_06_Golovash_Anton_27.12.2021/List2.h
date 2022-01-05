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
	void Add(T _data);
	void Clear();
	int Getsize();
	Node<T>& GetHead();
	Node<T>& GetTail();
	void Insert(T data, int index);
	void Replace(T data, int index);
	void Delete(int index);
	T operator[] (int index);
	void DeleteFirst();
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