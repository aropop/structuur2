/*
 * point.h
 *
 *  Created on: 18-okt.-2013
 *      Author: arno
 */

#ifndef POINT_H_
#define POINT_H_

class Point{
public:
	 const double pi = 3.141592;
	double x;
	double y;

	Point(double x, double y);
	Point();
	Point(const Point &p);
	void rotate(double angle);
	Point operator+(Point p2);
};


#endif /* POINT_H_ */
