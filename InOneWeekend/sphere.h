#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{
public:
	sphere() {}
	sphere(point3 _center, double _radius, shared_ptr<material> _material)
		: center1(_center), radius(_radius), mat(_material) {}

	virtual bool hit(
		const ray& r, interval ray_t, hit_record& rec) const override;

private:
	point3 center1;
	double radius;
	shared_ptr<material> mat;
};

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const
{
	vec3 oc = r.origin() - center1;
	auto a = r.direction().length_squared();
	auto half_b = dot(oc, r.direction());
	auto c = oc.length_squared() - radius * radius;

	auto discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
	{
		return false;
	}
	auto sqrtd = sqrt(discriminant);

	// Find the nearest root that lies in the acceptable range.
	auto root = (-half_b - sqrtd) / a;
	if (!ray_t.surrounds(root))
	{
		root = (-half_b + sqrtd) / a;
		if (!ray_t.surrounds(root))
		{
			return false;
		}
	}

	rec.t = root;
	rec.p = r.at(rec.t);
	vec3 outward_normal = (rec.p - center1) / radius;
	rec.set_face_normal(r, outward_normal);
	rec.mat = mat;

	return true;
};
