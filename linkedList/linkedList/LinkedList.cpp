#include "LinkedList.h"
#include <assert.h>
template<class T>
Node<T>::Node()
{
	value = 0;
	next = 0;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}

template <class T>
LinkedList<T>::LinkedList(void)
{
	head = tail = 0;
	count = 0;
}

template <class T>
int LinkedList<T>::Length()
{
	return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

template <class T>
T LinkedList<T>::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node<T>* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = tmp;
	}
	count--;
}


template <class T>
LinkedList<T>::~LinkedList(void)
{
	while (count != 0)
		DeleteAt(0);
}


template<class T>
void LinkedList<T>::Display() {
	Node<T>* temp = head;
	while (temp != NULL) {
		cout << temp->value<<" ";
		temp = temp->next;
	}
}

template<class T>
void LinkedList<T>::clear()
{
	if (count == 0)
		return;
	Node<T>* tmp = head->next;
	while (tmp->next != 0)
	{
		delete head;
		head = tmp;
		tmp = tmp->next;
	}

	delete head;
	head = tail = 0;
	count = 0;
}


template<class T>
void LinkedList<T> ::Insert(T val) {
	if (count == 0) {
		Node<T>* n = new Node<T>(val);
		head = tail = n;
		count++;
	}
	else {
		Node<T>* tmp = head;
		bool flage=0;
		for (int i = 0; i < count; i++) {
			if (tmp->value >= val) {
				InsertAt(i, val);
				flage = 1;
				break;
			}
			tmp = tmp->next;
		}
		if (flage == 0) {
			Append(val);
		}
	}

}

template<class T>
T LinkedList<T>::getMin() {
	return head->value;
}

template<class T>
void LinkedList<T>::Merge(LinkedList<T>& list2) {
	for (int i = 0; i < list2.Length(); i++) {
		Insert(list2.At(i));
	}
}

template<class T>
LinkedList<T> LinkedList<T>::Intersection(LinkedList<T>& list2) {
	LinkedList<T> l;
	for (int i = 0; i < list2.Length(); i++) {
		Node<T>* tmp = head;
		for (int j = 0; j < count; j++) {
			if (tmp->value == list2.At(i)) {
				l.Append(tmp->value);
			}
			tmp = tmp->next;
		}
			
	}
	return l;
}


