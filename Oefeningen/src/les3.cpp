/*
 * les3.cpp
 *
 *  Created on: 9-okt.-2013
 *      Author: arno
 */

/*
 * Zie oef over fac en bestanden in les 2
 */

#include <iostream>
#include <stdint.h>
#include  <cmath>

int64_t fib(int x) {
	int64_t n(1), nMin(1);
	for (int i = 0; i < x; ++i) {
		int64_t temp = n;
		n += nMin;
		nMin = temp;
	}
	return n;
}

void rotate(float &x, float &y, float angle = 90) {
	double pi = 3.141592;

	float length = sqrt(x * x + y * y);
	float angle_rad = pi / 180 * angle;

	x = length * cos(angle_rad);
	y = length * sin(angle_rad);

}

void print_tafel() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= 10; ++i) {
		std::cout.width(10 + i);
		std::cout << i << " maal " << n << " is " << n * i << std::endl;
	}
}

void print_dubbel_uit() {
	std::string str;
	while (!std::cin.eof()) {
		std::getline(std::cin, str);
		std::cout << str << std::endl << str << std::endl;
	}
}

int main() {

	std::cout << fib(98) << std::endl;
	//print_tafel();
	print_dubbel_uit();
	return 0;
}

