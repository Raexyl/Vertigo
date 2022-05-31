#ifndef VEC2_H
#define VEC2_H

namespace Impact
{
	class Vec2
	{
		public:
			float x = 0.0f;
			float y = 0.0f;

			Vec2();
			Vec2(float X, float Y);
			~Vec2();

			Vec2 operator+(Vec2 v);
			Vec2 operator-(Vec2 v);
			Vec2 operator*(float s);
			Vec2 operator/(float s);

			void operator+=(Vec2 v);
			void operator-=(Vec2 v);
			void operator*=(float s);
			void operator/=(float s);

			float SizeSquared(void);
			float Size(void);
			void Normalize(void);
			Vec2 Normalized(void);
	};
}

#endif