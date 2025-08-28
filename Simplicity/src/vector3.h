#pragma once
struct vector3 {
	float x, y, z;

	vector3 operator+(const vector3& b) const {
		return vector3(x + b.x, y + b.y, z + b.z);
	}

	vector3 operator-(const vector3& b) {
		return vector3(x - b.x, y - b.y, z - b.z);
	}

	vector3 operator*(const int b) {
		return vector3(x * b, y * b, z * b);
	}

	vector3 operator*(const float b) {
		return vector3(x * b, y * b, z * b);
	}

	vector3 operator+=(const vector3& b) {
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}	

	vector3 operator-=(const vector3& b) {
		x -= b.x;
		y -= b.y;
		z -= b.z;
		return *this;
	}
};