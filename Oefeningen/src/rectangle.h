/*
 * rectangle.h
 *
 *  Created on: 18-okt.-2013
 *      Author: arno
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "point.h"
#include <iostream>

class Rectangle{
public:
	Point links_boven, links_onder, rechts_boven, rechts_onder;
	double lengte, breedte;
	Rectangle(Point links_boven, Point rechts_onder);
	Rectangle(double x1, double x2, double y1, double y2);

	int area();
	int perimeter();

	Point& getTopLeft();
	Point& getBottomRight();

private:
	void bereken_len_bre();
};

#endif /* RECTANGLE_H_ */
