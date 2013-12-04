/*
 * les8.cpp
 *
 *  Created on: 27-nov.-2013
 *      Author: arno
 */

#include <iostream>
#include <vector>

void kwadraten(int i){
	std::vector<int> vect;
	for (int x = 1; x <= i; ++x) {
		vect.push_back(x*x);
	}
	std::vector<int>::reverse_iterator rit;
	for(rit = vect.rbegin(); rit != vect.rend(); rit++){
		std::cout << *rit << std::endl;
	}
}

int sum (std::vector<int>::iterator it, std::vector<int>::iterator endit, int start){
	if(it == endit){
		return start;
	}else{
		return sum(++it, endit, start + *it);
	}
}

//template<class It, class Elems>
//Elems
//reduce (It begin, It end, Foo<Elem> fun, Elems neutral){

//}

int les8 (int argc, char* args[]){
	std::vector<int> v {1,2,3};
	std::cout << sum (v.begin(), v.end(), 0);
	return 0;

}

