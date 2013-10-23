/*
 * les5.cpp
 *
 *  Created on: 18-okt.-2013
 *      Author: arno
 */

#include "rectangle.h"
#include "point.h"

Rectangle::Rectangle(Point links_boven, Point rechts_onder) :
		links_boven(links_boven), links_onder(links_boven.x, rechts_onder.y), rechts_boven(
				rechts_onder.x, links_boven.y), rechts_onder(rechts_onder) {
	bereken_len_bre();
}

Rectangle::Rectangle(double x1, double x2, double y1, double y2):
		links_boven(x1, y2), links_onder(x1, y1), rechts_onder(x2,y1), rechts_boven(x2, y2){
	bereken_len_bre();
}

void Rectangle::bereken_len_bre(){
	lengte = rechts_onder.x - links_onder.x;
	breedte = rechts_boven.y - rechts_onder.y;
}

int Rectangle::area(){
	return lengte * breedte;
}

int Rectangle::perimeter(){
	return (2 * breedte) + (2 * lengte);
}

std::ostream& operator<<(std::ostream& out, Rectangle r){
	std::cout << "[Lengte: " << r.lengte << "] [Breedte: " << r.breedte << "]";
	return out;
}

Point& Rectangle::getTopLeft(){
	return links_boven;
}

Point& Rectangle::getBottomRight(){
	return rechts_onder;
}
