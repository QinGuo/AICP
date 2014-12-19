#pragma once
#include "Micros.h"
#include"math.h"
#include <Eigen/Dense>

#ifndef POINT_H
#define POINT_H
class Point
{
public:
	
	Point(){v.x=0;v.y=0;v.z=0;active=false;}
	Point(float32_t x, float32_t y, float32_t z){ setPosition(x, y, z); }
	Point(Eigen::Vector3f v_in){ setPosition(v_in); }
	inline void setPosition(float32_t x, float32_t y, float32_t z){ v.x = x; v.y = 0; v.z = 0; active =true; };
	inline void setPosition(Eigen::Vector3f v_in){ v = v_in; active = true; };
	inline Eigen::Vector3f getPosision(){ return v; }
	Eigen::Vector3f Point::operator-(const Point &rhs) {
		Eigen::Vector3f out;
		if (this != &rhs) {
			out= this->v - rhs.v;
		}
		return out;
	}
private:
	bool active;
	Eigen::Vector3f v;
};
float32_t distanceOfPoints(Point& point1,Point& point2)
{
	Eigen::Vector3f  v_p1p2 = point1 - point2;
	v_p1p2.norm();
	
	return v_p1p2.norm();
}


#endif