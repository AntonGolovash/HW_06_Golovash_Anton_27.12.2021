#include "List2.h"
using namespace std;

template<class T>
List2<T>::List2() : _head(nullptr), _tail(nullptr), _size(0)
{
	cout << "Constructor default:\t" << this << endl;
}

template<class T>
List2<T>::~List2()
{
	cout << "Destructor:\t" << this << endl;
	clear();
}

template<class T>
void List2<T>::add(T data)
{
	++_size;
	Node<T>* tmp = new Node<T>;
	tmp->next = nullptr;
	tmp->data = data;

	if (_head == nullptr)
	{
		_head = _tail = tmp;
		return;
	}
	_tail->next = tmp;
	_tail = tmp;

}

template<class T>
Node<T>& List2<T>::back()
{
	return *(_tail);
}

template<class T>
Node<T>* List2<T>::begin()
{
	if (_head != nullptr)
		return _head;
	cout << "Is empty" << endl;
	return _head;
}

template<class T>
void List2<T>::clear()
{
	while (_head != _tail)
	{
		Node<T>* tmp = _head;
		_head = _head->next;
		delete tmp;
		_size--;
	}
	if (_head == _tail)
	{
		Node<T>* tmp = _head;
		delete tmp;
		_size--;
	}
	if (_size == 0)
	{
		_head = _tail = nullptr;
		cerr << "The list size is - " << _size << endl;
		cerr << "The list is cleared" << endl;
		return;
	}
	if (_size != 0)
	{
		cerr << "The list is NOT cleared" << endl;
	}
}

template<class T>
inline void List2<T>::insert(T data, int index)
{
	if (_size <= index || index < 0)
	{
		throw std::bad_alloc();
	}
	Node<T>* newNode = new Node<T>;
	newNode->data = data;

	Node<T>* previous = nullptr;
	Node<T>* next = _head;

	while (index-- != 0)
	{
		previous = next;
		next = next->next;
	}
	previous->next = newNode;
	newNode->next = next;
	++_size;
}

template<class T>
inline void List2<T>::isEmpty()
{
	while (_head != _tail)
	{
		Node<T>* previous = _head;
		_head = _head->next;
		delete previous;
		_size--;
	}
	cout << "The List is empty" << endl;
}

template<class T>
inline void List2<T>::remove(int index)
{
	if (index == 0)
	{
		isEmpty();
		return;
	}

	if (_size <= index || index < 0)
		throw std::bad_alloc();
	Node<T>* previous = nullptr;
	Node<T>* target = _head;
	Node<T>* next = nullptr;

	if (index > 0)
	{
		for (int i = 0; i != index; i++)
		{
			previous = target;
			target = target->next;
		}
		next = target->next;
		delete target;
		previous->next = next;
		_size--;
	}
}

template<class T>
inline void List2<T>::replace(T data, int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc();
	this[index] = data;
}

template<class T>
int List2<T>::size()
{
	return _size;
}

template<class T>
inline T List2<T>::operator[](int index)
{
	if (_size <= index || index < 0)
	{
		throw std::bad_alloc();
	}
	Node<T>* target = _head;

	while (index-- != 0)
	{
		target = target->next;
	}

	return target->data;
}

