#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include<string>


struct Coord {
public:
	Coord() {
		x = 1;
		y = 1;
		z = 1;
	}

	Coord(int _x, int _y) {
		x = _x;
		y = _y;
		z = 1;
	}

	Coord(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	int operator *=(int right) {
		x *= right;
		y *= right;
		z *= right;
	}

	int operator /=(int right) {
		x /= right;
		y /= right;
		z /= right;
	}

	void shift(int _x, int _y, int _z) {
		x += _x;
		y += _y;
		z += _z;
	}

	int x, y, z;
};

class Shape
{
public:
	Shape();
	void shift(int m, int n, int k);
	void shift(int m, int n);
	void scaleX(int scale);
	void scaleY(int scale);
	void scaleZ(int scale);
	void scale(int scale);
protected:
	Coord a, b, c, d, e, f, g, h;
	double height;
	double radius;
	double volume;
	double square;
};

class Line : public Shape {
public:
	Line(Coord _a, Coord _b) {
		a = _a;
		b = _b;
	}

};

class Square : public Shape {
public:
	Square(Coord _a, Coord _b, Coord _c) {
		a = _a;
		b = _b;
		c = _c;
		square = (a.x - b.x) * (a.y - b.y);

	}
};

class Cube : public Shape {
public:
	Cube(Coord _a, Coord _b, Coord _c, Coord _d, Coord _e, Coord _f, Coord _g, Coord _h) {
		a = _a;
		b = _b;
		c = _c;
		d = _d;
		e = _e;
		f = _f;
		g = _g;
		h = _h;
		square = (6 * a.x - b.x) * (a.y - b.y);
		volume = pow(a.x - b.x, 3);
	}
};

class Circle : public Shape {
public:
	Circle(Coord _a, Coord _b, double _radius, double _height) {
		a = _a;
		b = _b;
		radius = _radius;
		height = _height;
		//square = M_PI * radius * radius;
	}
	void shift(int m, int n, int k) = delete;
	void shift(int m, int n) = delete;
	void scaleX(int scale) = delete;
	void scaleY(int scale) = delete;
	void scaleZ(int scale) = delete;
	void scale(int scale) = delete;
};

class Cylinder : public Shape {
public:
	Cylinder(Coord _a, Coord _b, double _radius, double _height) {
		a = _a;
		b = _b;
		radius = _radius;
		height = _height;
		square = M_PI * radius * radius + 2 * radius * height;
		volume = M_PI *radius * radius * height;
	}

	void shift(int m, int n, int k) = delete;
	void shift(int m, int n) = delete;
	void scaleX(int scale) = delete;
	void scaleY(int scale) = delete;
	void scaleZ(int scale) = delete;
	void scale(int scale) = delete;
};