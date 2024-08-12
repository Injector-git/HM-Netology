#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>
Shape::Shape() {
	height = 0;
	radius = 0;
	volume = 0;
	square = 0;
}

void Shape::shift(int m, int n, int k)
{
	a.shift(m, n, k);
	b.shift(m, n, k);
	c.shift(m, n, k);
	d.shift(m, n, k);
	e.shift(m, n, k);
	f.shift(m, n, k);
	g.shift(m, n, k);
	h.shift(m, n, k);
}

void Shape::shift(int m, int n)
{
	a.shift(m, n, 0);
	b.shift(m, n, 0);
	c.shift(m, n, 0);
	d.shift(m, n, 0);
	e.shift(m, n, 0);
	f.shift(m, n, 0);
	g.shift(m, n, 0);
	h.shift(m, n, 0);
}

void Shape::scaleX(int scale)
{
	a.x *= scale;
	b.x *= scale;
	c.x *= scale;
	d.x *= scale;
	e.x *= scale;
	f.x *= scale;
	g.x *= scale;
	h.x *= scale;
}

void Shape::scaleY(int scale)
{
	a.y *= scale;
	b.y *= scale;
	c.y *= scale;
	d.y *= scale;
	e.y *= scale;
	f.y *= scale;
	g.y *= scale;
	h.y *= scale;
}

void Shape::scaleZ(int scale)
{
	a.z *= scale;
	b.z *= scale;
	c.z *= scale;
	d.z *= scale;
	e.z *= scale;
	f.z *= scale;
	g.z *= scale;
	h.z *= scale;
}

void Shape::scale(int scale)
{
	a.z /= scale;
	b.z /= scale;
	c.z /= scale;
	d.z /= scale;
	e.z /= scale;
	f.z /= scale;
	g.z /= scale;
	h.z /= scale;
}