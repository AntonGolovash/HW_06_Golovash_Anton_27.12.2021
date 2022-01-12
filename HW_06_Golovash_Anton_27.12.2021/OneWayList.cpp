#include "OneWayList.h"
using namespace std;

template<class T>
OneWayList<T>::OneWayList() : _head(nullptr), _tail(nullptr), _size(0)
{
	cout << "Constructor default:\t" << this << endl;
}

template<class T>
OneWayList<T>::~OneWayList()
{
	cout << "Destructor:\t" << this << endl;
	clear();
}

template<class T>
void OneWayList<T>::add(T data)
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
Node<T>& OneWayList<T>::back()
{
	return *(_tail);
}

template<class T>
Node<T>* OneWayList<T>::begin()
{
	if (_head != nullptr)
		return _head;
	cout << "Is empty" << endl;
	return _head;
}

template<class T>
void OneWayList<T>::clear()
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
inline void OneWayList<T>::insert(T data, int index)
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
inline void OneWayList<T>::isEmpty()
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
inline void OneWayList<T>::remove(int index)
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
inline void OneWayList<T>::replace(T data, int index)
{
	if (_size <= index || index < 0)
		throw std::bad_alloc();
	this[index] = data;
}

template<class T>
int OneWayList<T>::size()
{
	return _size;
}

template<class T>
void OneWayList<T>::unique()
{
	int index = 0;
	Node<T>* comparingNode = new Node<T>;
	comparingNode->data = _head;
	Node<T>* nodeForCompare = new Node<T>;
	nodeForCompare = comparingNode->next;
	while (comparingNode->next != _tail)
	{
		while (nodeForCompare != _tail)
		{
			if (comparingNode->data == nodeForCompare)
			{
				remove(index);
				unique();
			}
			index++;
			nodeForCompare = nodeForCompare->next;
		}
		comparingNode->data = comparingNode->next;
	}
}

template<class T>
inline T OneWayList<T>::operator[](int index)
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

