/*
 * les9.cpp
 *
 *  Created on: 4-dec.-2013
 *      Author: arno
 */


class Point {
public:
	Point(int x, int y) : x_(x), y_(y){
	}

	virtual ~Point(){

	}
	virtual Point Scale(double r){
		x_ = x_ * r;
		y_ = y_ * r;
		return *this;
	}
private:
	int x_;
	int y_;
};


class Point3D : public Point {
public:
	Point3D(int x, int y, int z) : Point(x, y), z_(z){

	}

	Point3D ThreeDScale(double r){
		Point::Scale(r);
		z_ = z_ * r;
		return *this;
	}

private:
	int z_;
};

int les9(int argc, char*args[]){

	return 0;
}

