/*
 * Developer : Naveen Rohilla
 * Objective : Simple Linked List using head and tail
 */
 
 
#include <iostream>
using namespace std;

template <typename T>
class node {
	public:
		T data;
		node *next;		
		node(T ele = NULL) {
			data = ele;
			next = NULL;
		}	
};

template <typename T>
class SLL {
	protected:
		node<T> * head;
		node<T> * tail;	
	public:
		static int count;
		SLL() {
			head = 0;
			tail = 0;
		}
		void addToHead(T);
		void addToTail(T);
		void addToPos(int, T);
		void removeHead();
		void removeTail();
		void removeByPos(int);
		void removeByValue(T);
		void display();
		friend SLL<T>& operator+(SLL<T> m, T n) {
			m.addToTail(n);
			return m;
		}		
};
template <typename T>
int SLL<T> :: count=0;

//add element in the front of Linked List
template <typename T>
void SLL<T> :: addToHead(T ele) {
	node<T> * p = new node<T>(ele);
	if (head == 0) {
		head = p;
		tail = p;
	}
	else {
		p -> next = head;
		head = p;
	}	
	count++;
}

//add element at last of Linked List
template <typename T>
void SLL<T> :: addToTail(T ele) {
	node<T> * p = new node<T>(ele);
	if (tail == 0) {
		head = p;
		tail = p;
	}
	else {
		tail -> next = p;
		tail = p;
	}
	count++;
}

//add element at the given position in Linked List
template <typename T>
void SLL<T> :: addToPos(int pos, T ele) {
	node<T> * p = new node<T>(ele);
	if (pos == 1) {
		p -> next = head;
		head = p;
	}
	else {
		node<T> * temp = head;
		int i = 1;
		while (i != pos - 1) {
			temp = temp -> next;
			i++;
		}
		p -> next = temp -> next;
		temp -> next = p;
	}
	count++;
}

//remove element from front
template <typename T>
void SLL<T> :: removeHead() {
	if (head == 0) {
		cout << "Linked list is empty";
	}
	else {
		node<T> * temp = head;
		head = head -> next;
		delete temp;
		if (head == 0) {
			tail = 0;
		}
		count--;
	}
}

//remove element from tail
template <typename T>
void SLL<T> :: removeTail() {
	if(tail == 0) {
		cout << "Linked List is empty";
	}
	else {
		node<T> * temp = head;
		node<T> * prev = 0;
		while(temp != tail) {
			prev = temp;
			temp = temp -> next;
		}
		if (prev == NULL) {
			head = tail = NULL;
		}
		else {
			tail = prev;
			tail -> next = NULL;
		}
		delete temp;
		count--;
	}
}

//remove element from the given position
template <typename T>
void SLL<T> :: removeByPos(int pos) {
	node<T> * temp = head;
	node<T> * prev = NULL;
	int i = 1;
	while (i != pos) {
		prev = temp;
		temp = temp -> next;
		i++;
	}
	if (prev == NULL) {
		head = head -> next;
		if (head == NULL) {
			tail == NULL;
		}
	}
	else if(temp == tail) {
		prev -> next = NULL;
		tail = prev;
	}
	else {
		prev -> next = temp -> next;
	}
	delete temp;
	count--;
	
}

//remove element By value
template <typename T>
void SLL<T> :: removeByValue(T ele) {
	node<T> * temp = head;
	node<T> * prev = NULL;
	bool flag = true;
	while (temp != NULL) {
		if (temp -> data == ele) {
			if (prev == NULL) {
				head = head -> next;
				delete temp;
				temp = head;
				if (head == NULL) {
					tail = NULL;
				}
			}
			else if (temp == tail) {
				prev -> next = NULL;
				tail = prev;
				delete temp;
				temp = NULL;
			}
			else {
				prev -> next = temp -> next;
				delete temp;
				temp = prev -> next;
			}
			count--;
			flag = false;	
		}
		else {
			prev = temp;
			temp = temp -> next;
		}
	}
	if (flag) {
		cout << "Element not found";
	}
}

//display all the elements of the linked list
template <typename T>
void SLL<T> :: display() {
	if (head == NULL) {
		cout << "\nNo element in Linked List\n";
	}
	else {
		node<T> * temp = head;
		cout << "Total no. of elements = " << count << endl;
		while (temp != 0) {
			cout << temp -> data << "\t";
			temp = temp -> next;
		}
		
	}
}



