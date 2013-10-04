/*
 * les2.cpp
 *
 *  Created on: 4-okt.-2013
 *      Author: Arno
 */

/* 0x124 is hexa */
/* 0b123 is bin */

/* vraag 1: Double */
/* vraag 3: C++ gaat bij het uitvoeren van een functie nog extra adressen op de stack gestoken
 * zoals return adressen*/

#include <iostream>
#include <string.h>
#include <fstream>
#include "fac.h"

//vraag 3
int f() {
	int c;
	std::cout << std::hex << &c << std::endl;
	return 42;
}
void g() {
	int a, b;
	std::cout << std::hex << &a << std::endl;
	std::cout << std::hex << &b << std::endl;
	int d = f();
}

//vraag 4
bool macht_van_twee(int n) {
	return (n & (n - 1)); //binaire and geeft of 00....001 of 000...000 terug die dan boolean waarden zijn
}

//vraag 5
int ggd(int a, int b) {
	//c = rest
	if (b > a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	int c = a % b;
	if (c == 0) {
		return b;
	} else {
		return ggd(b, c);
	}
}

//vraag 7
void read_from_file(int how_many) {
	std::ifstream file("text.txt");
	std::string str;
	while (how_many > 0) {
		file >> str;
		std::cout << "Lengte: " << str.size() << std::endl;
		how_many = how_many - 1;
	}
	file.close();

}

int main() {
	//vraag 1
	double avogadro;
	avogadro = 6.02214179e23;
	std::cout << avogadro << std::endl;

	//vraag 2
	const char *str1, *str2, *str3;
	str1 = "Structuur 2";
	str2 = "C++ Compiler";
	str3 = "makefile";
	std::cout << "String: " << str1 << " Lengte: " << strlen(str1) << std::endl;
	std::cout << "String: " << str2 << " Lengte: " << strlen(str2) << std::endl;
	std::cout << "String: " << str3 << " Lengte: " << strlen(str3) << std::endl;

	//vraag 3
	g();

	//vraag 4
	std::cout << macht_van_twee(16) << std::endl;
	std::cout << macht_van_twee(13) << std::endl;

	//vraag 5
	std::cout << ggd(6, 8) << std::endl;

	//vraag 6
	std::cout << fac(13) << std::endl;

	//vraag 7
	read_from_file(10);

	return 0;
}

