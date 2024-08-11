#pragma once
#include "transform.h"

Transform::Transform(const Shape& sh) {
	shape = sh;
}
Shape Transform::shift( int m, int n, int k)
{
	sh.a.shift(m, n, k);
	sh.b.shift(m, n, k);
	sh.c.shift(m, n, k);
	sh.d.shift(m, n, k);
	sh.e.shift(m, n, k);
	sh.f.shift(m, n, k);
	sh.g.shift(m, n, k);
	sh.h.shift(m, n, k);

	return shape;
}

Shape Transform::scaleX(int scale)
{
	a.x *= scale;
	b.x *= scale;
	c.x *= scale;
	d.x *= scale;
	e.x *= scale;
	f.x *= scale;
	g.x *= scale;
	h.x *= scale;

	return shape;
}

Shape Transform::scaleY(int scale)
{
	a.y *= scale;
	b.y *= scale;
	c.y *= scale;
	d.y *= scale;
	e.y *= scale;
	f.y *= scale;
	g.y *= scale;
	h.y *= scale;

	return shape;
}

Shape Transform::scaleZ(int scale)
{
	a.z *= scale;
	b.z *= scale;
	c.z *= scale;
	d.z *= scale;
	e.z *= scale;
	f.z *= scale;
	g.z *= scale;
	h.z *= scale;

	return shape;
}

Shape Transform::scale(int scale)
{
	a.z /= scale;
	b.z /= scale;
	c.z /= scale;
	d.z /= scale;
	e.z /= scale;
	f.z /= scale;
	g.z /= scale;
	h.z /= scale;

	return shape;
}