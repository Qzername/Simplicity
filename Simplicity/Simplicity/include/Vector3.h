#pragma once
struct Vector3 {
	float x, y, z;

	Vector3 operator+(const Vector3& b) const {
		return Vector3(x + b.x, y + b.y, z + b.z);
	}

	Vector3 operator-(const Vector3& b) {
		return Vector3(x - b.x, y - b.y, z - b.z);
	}

	Vector3 operator*(const int b) {
		return Vector3(x * b, y * b, z * b);
	}

	Vector3 operator*(const float b) {
		return Vector3(x * b, y * b, z * b);
	}

	Vector3 operator+=(const Vector3& b) {
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}	

	Vector3 operator-=(const Vector3& b) {
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}
};