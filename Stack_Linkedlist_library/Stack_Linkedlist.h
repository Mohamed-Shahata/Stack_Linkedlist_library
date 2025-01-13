#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

#include <iostream>
using namespace std;

template <class T>

class Stack {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* top;

public:
	Stack();

	~Stack();

	void push(T value);

	void pop();

	void pop(T &value);

	T peek() const;

	bool isEmpty() const;

	int size() const;

	void clear();

	bool contains(T value) const;

	void reverse();

	void display() const;

	Stack<T> clone();

	void swap(Stack<T> &s);

	T* toArray() const;
};

template <class T>
Stack<T>::Stack() : top(nullptr)
{};

template <class T>
Stack<T>::~Stack() {
	clear();
};

template<class T>
void Stack<T>::push(T value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
};

template <class T>
bool Stack<T>::isEmpty() const {
	return top == nullptr;
};

template <class T>
void Stack<T>::pop() {
	if (isEmpty()) {
		throw underflow_error("Stack is empty. Cannot pop.");
	}
	else {
		Node* temp = top;
		top = temp->next;
		delete temp;
	}
};

template <class T>
void Stack<T>::pop(T& value) {
	if (isEmpty()) {
		throw underflow_error("Stack is empty. Cannot pop.");
	}
	else {
		Node* temp = top;
		top = temp->next;
		value = temp->data;
		delete temp;
	}
};

template <class T>
T Stack<T>::peek() const {
	if (isEmpty()) {
		throw underflow_error("Stack is empty. Cannot peek.");
	}
	else {
		return top->data;
	}
};

template <class T>
int Stack<T>::size() const {
	int size = 0;
	Node* temp = top;
	while (temp != nullptr) {
		size++;
		temp = temp->next;
	};
	return size;
};

template <class T>
void Stack<T>::clear() {
	Node* temp;
	while (top != nullptr) {
		temp = top;
		top = temp->next;
		delete temp;
	}
};

template <class T>
bool Stack<T>::contains(T value) const {
	if (isEmpty()) {
		throw underflow_error("Stack is empty. Cannot contains.");
	}
	else {
		Node* temp = top;
		while (temp != nullptr) {
			if (temp->data == value) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
};

template <class T>
void Stack<T>::reverse() {
	if (isEmpty()) {
		throw underflow_error("Stack is empty. Cannot reverse.");
	}
	else {
		Node* prev = nullptr;
		Node* temp = top;
		Node* next = nullptr;

		while (temp != nullptr) {
			next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
		}
		top = prev;

	}
}

template <class T>
void Stack<T>::display() const {
	if (isEmpty()) {
		cout << "[]" << endl;
	}
	else {
		Node* temp = top;
		cout << "[ ";
		while (temp != nullptr) {
			if (temp->next == nullptr) {
				cout << temp->data << " ";
			}
			else {
				cout << temp->data << ", ";
			}
			temp = temp->next;
		}
		cout << "]" << endl;
	}
};

template <class T>
Stack<T> Stack<T>::clone() {
	Stack<T> newStack;
	if (isEmpty()) {
		return newStack;
	}
	else {
		Stack<T> tempStack;
		Node*temp = top;

		while (temp != nullptr) {
			tempStack.push(temp->data);
			temp = temp->next;
		}

		while (!tempStack.isEmpty()) {
			newStack.push(tempStack.peek());
			tempStack.pop();
		}
		return newStack;
	}
}

template <class T>
void Stack<T>::swap(Stack<T> &s) {
	Node* temp = s.top;
	s.top = this->top;
	this->top = temp;
}


template <class T>
T* Stack<T>::toArray() const {
	int size = this->size();
	T* array = new T[size];
	Node* temp = top;
	int i = 0;
	while (temp != nullptr) {
		array[i] = temp->data;
		temp = temp->next;
		++i;
	}

	return array;

}

#endif