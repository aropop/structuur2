/*
 * les6.cpp
 *
 *  Created on: 6-nov.-2013
 *      Author: arno
 */
#include <iostream>
/* oefening 1 */
void swap (int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
/* oefening 2 */
void read_array(){
	int n;
	std::cin >> n;
	int size(n);
	int * array = new int[n]; //pointer naar het eerste element van de array
	//de vierkante haken gaan gewoon telkens een int verder in het geheugen
	while (n > 0){
		std::cin >> array[n];
		--n;
	}
	n = size;
	while (n > 0){
		std::cout << array[n] << std::endl;
		--n;
	}
	delete[] array;
}
/* Oefening 3 */
class Ulist {
public:
	Ulist(int size): size_(size){
		first = new Node(size);
	}

	void add(int element){
		Node * current;
		current = first;
		while(current->is_full()){
			if(current->next == NULL){
				current->next = new Node(size_);

			}
			current = current->next;
		}
		current->data[current->free++] = element;
	}

	void print(){
		Node * current;
		current = first;
		while(current->is_full()){
			for(int i =0; i < current->free; i++){
				std::cout << current->data[i] << " ";
			}
			std::cout << std::endl;
			current = current->next;
		}
		for(int i =0; i < current->free; i++){
				std::cout << current->data[i] << " ";
		}
	}

private:
	int size_;
	struct Node {
		int size;
		int * data;
		int free;
		Node * next;
		Node(int size_in){
			data = new int[size_in];
			size = size_in;
			free = 0;
			next = NULL;
		}
		bool is_full(){
			return (free == size);
		}
	};
	Node* first;
};


int main(int argc, char *args[]){
	//read_array();
	Ulist l = Ulist(3);
	l.add(5);
	l.print();
	return 0;
}



