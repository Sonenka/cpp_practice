#include "vec3d.hpp"

Vec3D::Vec3D() : x(0.0), y(0.0), z(0.0) {}

Vec3D::Vec3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

double Vec3D::operator*(const Vec3D& v2) {
	return x * v2.x + y * v2.y + z * v2.z;
}

Vec3D Vec3D::operator& (const Vec3D v2) {
	return Vec3D(y * v2.z - z * v2.y, z * v2.x - x * v2.z, x * v2.y - y * v2.x);
}