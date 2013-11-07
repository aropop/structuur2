/*
 * les5.cpp
 *
 *  Created on: 18-okt.-2013
 *      Author: arno
 */

#include <iostream>
#include <sstream>
#include <math.h>
#include "rectangle.h"
#include "point.h"

//oefening 1

Point::Point(double x, double y) :
		x(x), y(y) {
	//do nothing
}

Point::Point() :
		x(0), y(0) {
	//support lege initialisatie
}

Point::Point(const Point &p) :
		x(p.x), y(p.y) {

}

void Point::rotate(double angle) {
	double length = sqrt((x * x) + (y * y));
	double angle_rad = (pi / 180) * angle;

	x = length * cos(angle_rad);
	y = length * sin(angle_rad);
}

Point Point::operator+(Point p2) {
	double new_x = x + p2.x;
	double new_y = y + p2.y;
	Point ret(new_x, new_y);
	return ret;
}

std::ostream& operator<<(std::ostream& out, Point p) {
	std::ostringstream return_string;
	return_string << "X: ";
	return_string << p.x;
	return_string << std::endl;
	return_string << "Y: ";
	return_string << p.y;
	out << return_string.str();
	return out;
}

//oefening 2
//werkt niet want maak een lokale "kopie" van de point die is meegegeven
//een beetje zoals call by value van scheme
//wanneer je een referentie gebruikt (... Point &p, ....) werkt het wel
//void scale(Point &p, double factor) {
void scale(Point p, double factor) {
	p.x = p.x * factor;
	p.y = p.y * factor;
}

//Oefening 5
//vector3d = 3 doubles = 8*3= 24
//1 int = 4
//1 char = 1
//3 vectord3d = 3 * 24= 72
// 1 int = 4
//totaal 81 bytes

int les5(int argc, char *args[]) {

	Point p(1, 1);
	Point p2(2, 3);
	Point p3;

	//p.rotate(90);

	scale(p, 5);

	Rectangle r(p, p2);

	std::cout << p3.x << " " << p3.y << std::endl;
	std::cout << sizeof(p3) << std::endl; //size of 2 doubles
	std::cout << p << std::endl;

	char i;
	std::cout << sizeof(i)  << std::endl;

	return 0;
}
