#pragma once
#include <iostream>

using namespace std;
template<class T>
class Node
{
public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template<class T>
class LinkedList
{
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();

	void Append(T val);
	void InsertAt(int pos, T val);
	void DeleteAt(int pos);
	void Display();
	int Length();
	T At(int pos);
	void clear();

	void Insert(T val);
	T getMin();
	void Merge(LinkedList<T> & list2);
	LinkedList<T> Intersection(LinkedList<T> & list2);

	~LinkedList(void);
};

