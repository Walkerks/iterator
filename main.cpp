#include <iostream>
#include <stdexcept>

using namespace std;

//LinkedList modified from https://stackoverflow.com/a/22141970





class LinkedList {



public:
	// Struct inside the class LinkedList
	struct Node {
		int x;
		Node *next;
	};
	// public member

	class Iterator {
	public:
		//default
		Iterator() {
			currentNode = nullptr;
		}
		//custom
		Iterator(Node * data) {
			currentNode = data;
		}
		//++it operator
		Iterator& operator++() {
			if (currentNode->next == nullptr) {
				throw out_of_range("At the end of the list");
			}
			currentNode = currentNode->next;
			return *this;
		}
		//deref
		Node & operator*() {
			checkPointer();
			return *currentNode;
		}
		//auto deref
		Node * operator->() {
			checkPointer();
			return currentNode;
		}

		bool operator!=(const Iterator &other) {
			//compare pointers
			return this->currentNode != other.currentNode;
		}
		//assignment op
		Iterator & operator=(const Iterator other) {
			if (this != &other) {
				currentNode = other.currentNode;
			}
			return *this;
		}

	private:
		void inline checkPointer() {
			if (currentNode == nullptr) {
				throw std::runtime_error("Uninitialized pointers");
			}
		}
		Node * currentNode;
	};

	// constructor
	LinkedList() {
		head = nullptr; // set head to NULL
		tail = nullptr;
	}

	// This prepends a new value at the beginning of the list
	void addValue(int val) {
		Node *n;   // create new Node
		//make tail be the end element
		//new element  <- element <- tail
		if (tail == nullptr) {
			tail = new Node();
			head = tail;
		}

		n = new Node();
		//if tail is not set yet, the list is empty and we need to set it
		
		n->x = val;             // set value
		n->next = head;         // make the node point to the next node.
								//  If the list is empty, this is NULL, so the end of the list --> OK
		head = n;               // last but not least, make the head point at the new node.
		

	}

	// returns the first element in the list and deletes the Node.
	// caution, no error-checking here!
	int popValue() {
		Node *n = head;
		int ret = n->x;
		//if we are returning head that is also tail, tail should be set to nullptr
		if (head == tail) {
			delete tail;
			tail == nullptr;
		}
		head = head->next;
		delete n;
		return ret;
	}

	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(tail);
	}
	// private member
private:
	Node *head; // this is the private member variable. It is just a pointer to the first Node
	Node *tail; //Last element in the lits that is a placeholder
};






int main() {
	LinkedList list;

	list.addValue(5);
	list.addValue(10);
	list.addValue(20);

	//Using iterator

	for (LinkedList::Iterator it = list.begin(); it != list.end(); ++it) {
		cout << (*it).x << std::endl;
		cout << it->x << std::endl;
	}

	cout << std::endl;

	//show the iterator went through the list from front to back

	cout << list.popValue() << endl;
	cout << list.popValue() << endl;
	cout << list.popValue() << endl;

	return 0;
}