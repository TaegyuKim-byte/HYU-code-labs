#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
#include <vector>
#include <list>

template <class T>
class Node { //리스트의 원소 개개인
public:
	T data; //값
	Node<T>* next; //다음 원소를 가리키는 포인터
};

template <class T>
class List {
private:
	Node<T>* head; //첫번째 노드를 가리키는 포인터
public:
	List() : head(nullptr) {}

	~List() {
		Node<T>* current = nullptr;
		Node<T>* deleteNode = nullptr;

		current = head;

		while (current != nullptr) {
			deleteNode = current;
			current = current->next;
			delete current;
			current = nullptr;
		}

		head = nullptr;
	}

	List(T* arr, int n_nodes) { //Create a list with n_nodes
		Node<T>* current = nullptr; //연결고리?
		head = nullptr;
		
		for (int i = 0; i < n_nodes; i++) {
			Node<T>* newNode = new Node<T>(); 
			//for구문 안에서의 지역변수. 한번 반복될때마다 새로운 주소로 변수가 생성
			newNode->data = arr[i];
			newNode->next = nullptr;

			if (head == nullptr) {
				head = newNode;
			}
			else {
				current->next = newNode;
			}

			current = newNode;
		}
	}

	void insert_at(int idx, const T& data) {
		Node<T>* newNode = new Node<T>();
		Node<T>* newptr = head;

		newNode->data = data;

		if (idx == 0) {
			newNode->next = head;
			head = newNode;

			return;
		}

		for (int i = 0; i < idx - 1; i++) {
			newptr = newptr->next;
		}

		newNode->next = newptr->next;
		newptr->next = newNode;
	}

	void remove_at(int idx) {
		Node<T>* newptr = head;

		for (int i = 0; i < idx - 1; i++) {
			newptr = newptr->next;
		}

		newptr->next = newptr->next->next;
	}

	void pop_back() {
		Node<T>* current = head;

		while (current->next->next != nullptr) {
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;
	}

	void push_back(const T& val) {
		Node<T>* newNode = new Node<T>();
		newNode->data = val;
		newNode->next = nullptr;

		Node<T>* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}

		current->next = newNode;
	}

	void pop_front() {
		head = head->next;
	}

	void push_front(const T& val) {
		Node<T>* newNode = new Node<T>();

		newNode->data = val;
		newNode->next = head;
		head = newNode;
	}

	template <class U>
	friend std::ostream& operator<< (std::ostream& out, List<U>& rhs); //print out node
};

template <class T>
std::ostream& operator<< (std::ostream& out, List<T>& rhs) {
	Node<T>* current = rhs.head;
	while (current->next != nullptr) {
		out << current->data << ",";
		current = current->next;
	}
	out << current->data;

	return out;
}

#endif
