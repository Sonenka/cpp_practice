#ifndef VEC3D_HPP
#define VEC3D_HPP
class Vec3D {
public:
	double x, y, z;
	Vec3D();
	Vec3D(double x_, double y_, double z_);

	double operator*(const Vec3D& v2);

	Vec3D operator& (const Vec3D v2);
};
#endif