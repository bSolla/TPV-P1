#pragma once


class Vector2D {
// --------------------- variables------------------------------------------------------
private:
	double x, y;

// ---------------------- methods ------------------------------------------------------
public:
	Vector2D () : x (0.0), y (0.0) {}
	Vector2D (double xVal, double yVal) : x (xVal), y (yVal) {}
	~Vector2D ();

	Vector2D operator+(const Vector2D &other);
	Vector2D operator-(const Vector2D &other);
	Vector2D operator*(const int &number);
	double operator*(const Vector2D &other);

	double getX () const { return x; }
	double getY () const { return y; }

	void setX (double newX) { x = newX; }
	void setY (double newY) { y = newY; }
};

