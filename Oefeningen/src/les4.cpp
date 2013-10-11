/*
 * les4.cpp
 *
 *  Created on: 11-okt.-2013
 *      Author: arno
 */
#include <iostream>
#include <fstream>
#include <sstream>

//Vraag 1: maak een programma dat het eerste argument print
//Vraag 2:

void splits_string(std::string str){
	std::stringstream ss(str);
	std::string ret[2];
	ss >> ret[0]; //leest telkens 1 woord uit
	ss >> ret[1];
	std::cout << ret[0] << ret[1] <<std::endl;
}

int main(int argc, char *argv[]){
	std::cout << "ProgrammaNaam :'" << argv[0] << "'" << std::endl;
	for(int i = 1; i < argc; ++i){
		std::cout << "Argument nr: " << i << " is '" << argv[i] << "'" << std::endl;
	}
	std::string string;
	std::ifstream stream("src/text.txt");
	std::getline(stream, string);


	splits_string(string);

	return 0;
}




