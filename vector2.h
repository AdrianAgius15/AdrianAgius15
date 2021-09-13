//----------------------------------------------------------------------------------------------
//	Filename:	vector2.h
//	Author:		Keith Bugeja
//----------------------------------------------------------------------------------------------
//	Implementation for Vectors in R2 (adapted from http://illuminaprt.codeplex.com)
//----------------------------------------------------------------------------------------------
#pragma once

#include <math.h>
#include <assert.h>

class Vector2
{
public:
	//Union of 2 vectors
	union
	{
		float Element[2];
		//Interprets values of X and Y
		struct { float X, Y; };
		//Interprets values of U and V
		struct { float U, V; };
	};

public:
	Vector2() {}

	Vector2(float p_fValue)
		: X(p_fValue), Y(p_fValue) {}

	Vector2(float p_x, float p_y)
		: X(p_x), Y(p_y) {}

	Vector2(const Vector2 &p_vector)
		: X(p_vector.X), Y(p_vector.Y) {}

	float operator[](int p_nIndex) const { return Element[p_nIndex]; }
	float& operator[](int p_nIndex) { return Element[p_nIndex]; }

	inline void Set(float p_x, float p_y) {
		X = p_x; Y = p_y;
	}

	//Calculates values of X and Y, and returns their new values if greater than a given constraint
	inline bool Equals(const Vector2 &p_vector, const float p_epsilon = 1e-5f) const 
	{
		if (fabs(X - p_vector.X) > p_epsilon) return false;
		if (fabs(Y - p_vector.Y) > p_epsilon) return false;

		return true;
	}

	//Method overload of vector equals function
	Vector2& operator=(const Vector2 &p_vector)
	{
		X = p_vector.X;
		Y = p_vector.Y;
		
		return *this;
	}

	//Returns equals vector function
	inline bool operator==(const Vector2 &p_vector) const {
		return Equals(p_vector);
	}

	//Returns not equal vector function
	inline bool operator!=(const Vector2& p_vector) const {
		return !(*this == p_vector);
	}

	//Returns vector multiplication operation
	inline Vector2 operator*(float p_fValue) const {
		return Vector2(p_fValue * X, p_fValue * Y);
	}

	//Returns vector division operation
	inline Vector2 operator/(float p_fValue) const 
	{
		assert(p_fValue != 0.f);
		return Vector2(*this * (1.0f / p_fValue));
	}

	//Method overload of vector multiplication function
	inline Vector2 operator*(const Vector2 &p_vector) const {
		return Vector2(p_vector.X * X, p_vector.Y * Y);
	}

	//Returns vector addition operation
	inline Vector2 operator+(const Vector2 &p_vector) const {
		return Vector2(X + p_vector.X, Y + p_vector.Y);
	}

	//Returns vector subtraction operation
	inline Vector2 operator-(const Vector2 &p_vector) const {
		return Vector2(X - p_vector.X, Y - p_vector.Y);
	}

	//Method overload of vector subtraction function
	inline Vector2 operator-(void) const {
		return Vector2(-X, -Y);
	}

	//Returns vector multiplication operation on current variable
	inline Vector2& operator*=(float p_fValue) {
		return *this = *this * p_fValue;
	}

	//Method overload of vector multiplication function on current variable
	inline Vector2& operator*=(const Vector2 &p_vector) {
		return *this = *this * p_vector;
	}

	//Returns vector division operation on current variable
	inline Vector2& operator/=(float p_fValue) {
		return *this = *this / p_fValue;
	}

	//Returns vector addition operation on current variable
	inline Vector2& operator+=(const Vector2 &p_vector) {
		return *this = *this + p_vector;
	}
	
	//Returns vector subtraction operation on current variable
	inline Vector2& operator-=(const Vector2 &p_vector) {
		return *this = *this - p_vector;
	}

	//Returns maximum value
	inline float MaxComponent() const {
		return std::max(X, Y);
	}

	//Returns minimum value
	inline float MinComponent() const {
		return std::min(X, Y);
	}
	
	//Returns maximum absolute value
	inline float MaxAbsComponent() const {
		return std::max(fabs(X), fabs(Y));
	}

	//Returns minimum absolute value
	inline float MinAbsComponent() const
	{
		return std::min(fabs(X), fabs(Y));
	}

	//Returns maximum vector
	static Vector2 Max(const Vector2 &p_vector1, const Vector2 &p_vector2) 
	{
		return Vector2(std::max(p_vector1.X, p_vector2.X),
			std::max(p_vector1.Y, p_vector2.Y));
	}

	//Returns minimum vector
	static Vector2 Min(const Vector2 &p_vector1, const Vector2 &p_vector2) 
	{
		return Vector2(std::min(p_vector1.X, p_vector2.X),
			std::min(p_vector1.Y, p_vector2.Y));
	}

	//Returns length
	inline float Length(void) const {
		return sqrt(X * X + Y * Y);
	}

	//Returns the square of the length
	inline float LengthSquared(void) const {
		return X * X + Y * Y;
	}

	inline void Normalize(void) {
		*this = Vector2::Normalize(*this);
	}

	//Return dot product of 2 vectors
	inline float Dot(const Vector2 &p_vector) const {
		return Vector2::Dot(*this, p_vector);
	}

	//Returns absolute dot product of 2 vectors
	inline float AbsDot(const Vector2 &p_vector) const {
		return Vector2::AbsDot(*this, p_vector);
	}
	
	//Method overload of dot product of 2 vectors
	static float Dot(const Vector2 &p_vector1, const Vector2 &p_vector2) {
		return p_vector1.X * p_vector2.X + p_vector1.Y * p_vector2.Y;
	}

	//Method overload of absolute dot product of 2 vectors
	static float AbsDot(const Vector2 &p_vector1, const Vector2 &p_vector2) {
		return fabs(p_vector1.X * p_vector2.X +
			p_vector1.Y * p_vector2.Y);
	}

	static Vector2 Normalize(const Vector2 &p_vector) {
		return p_vector / sqrt(p_vector.Length());
	}

	//Returns the square of the distance between 2 particles
	static float DistanceSquared(const Vector2 &p_point1, const Vector2 &p_point2) {
		return (p_point2 - p_point1).LengthSquared();
	}

	//Returns distance between 2 particles
	static float Distance(const Vector2 &p_point1, const Vector2 &p_point2) {
		return (p_point2 - p_point1).Length();
	}
};

inline Vector2 operator*(float p_fValue, const Vector2 &p_vector) {
	return Vector2(p_fValue * p_vector.X, p_fValue * p_vector.Y);
}