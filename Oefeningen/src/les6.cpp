/*
 * les6.cpp
 *
 *  Created on: 6-nov.-2013
 *      Author: arno
 */
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
/* oefening 1 */
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/* oefening 2 */
void read_array() {
	int n;
	std::cin >> n;
	int size(n);
	int * array = new int[n]; //pointer naar het eerste element van de array
	//de vierkante haken gaan gewoon telkens een int verder in het geheugen
	while (n > 0) {
		std::cin >> array[n];
		--n;
	}
	n = size;
	while (n > 0) {
		std::cout << array[n] << std::endl;
		--n;
	}
	delete[] array;
}
/* Oefening 3 */
class Ulist {
public:
	Ulist(int size) :
			size_(size) {
		first = new Node(size);
	}

	void add(int element) {
		Node * current;
		current = first;
		while (current->is_full()) {
			if (current->next == NULL) {
				current->next = new Node(size_);

			}
			current = current->next;
		}
		current->data[current->free++] = element;
	}

	bool remove(int element) {
		Node * current(first);
		bool found(false);
		while (current->next != NULL) {
			int index(0);
			while (index < size_) {
				if (current->data[index] == element) {
					current->remove(index);
					found = true;
					break;
				}
				++index;
			}
			if (found) {
				break;
			}
			current = current->next;
		}
		return found;
	}

	unsigned int size() const {
		const Node * current(first);
		int sizer(0);
		while (current != NULL) {
			sizer += current->free;
			current = current->next;
		}
		return sizer;
	}

	int get(int indx) {
		Node * current(first);
		int counter(0);
		while (counter < indx) {
			counter += current->free;
			if (counter >= indx) {
				return current->data[indx - (counter - current->free)];
			} else if (current->next == NULL) {
				throw 123;
			}
			current = current->next;
		}
		return 0;
	}

	void print() const {
		Node * current;
		current = first;
		while (current->next != NULL) {
			for (int i = 0; i < current->free; i++) {
				std::cout << current->data[i] << " ";
			}
			std::cout << std::endl;
			current = current->next;
		}
		for (int i = 0; i < current->free; i++) {
			std::cout << current->data[i] << " ";
		}
		std::cout << std::endl;
	}

private:
	int size_;
	struct Node {
		int size;
		int * data;
		int free;
		Node * next;
		Node(int size_in) {
			data = new int[size_in];
			size = size_in;
			free = 0;
			next = NULL;
		}
		void remove(int indx) {
			int to_swap(free - indx - 1);
			while (to_swap > 0) {
				data[indx + to_swap - 1] = data[indx + to_swap];
				to_swap = to_swap - 1;
			}
			free = free - 1;
		}
		bool is_full() {
			return (free == size);
		}
	};
	Node* first;
};

/*oef4*/
class statInterface {
public:
	statInterface(const char * filename) {
		stat(filename, buffer_);
	}

	int getMode() {
		return buffer_->st_mode;
	}

	struct stat * operator->() {
		return buffer_;
	}
private:
	struct stat * buffer_;
};

int les6(int argc, char *args[]) {
	//read_array();
//	Ulist l = Ulist(3);
//	l.add(5);
//	l.add(6);
//	l.add(3);
//	l.add(1);
//	l.print();
//	std::cout << l.size() << std::endl;
//	l.remove(6);
//	l.print();
//	try{
//		l.get(100);
//		l.get(3);
//	}catch(int e){
//		std::cout << "not in ul" << std::endl;
//	}
	statInterface si ("text.txt");
	std::cout << si->st_mode << std::endl;
	return 0;
}

