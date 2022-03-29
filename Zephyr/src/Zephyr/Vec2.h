#pragma once

template<typename T>
class ZEPHYR_API Vec2
{
public:
	Vec2()
	{
		X = T(0);
		Y = T(0);
	}

	Vec2(T x, T y)
	{
		X = x;
		Y = y;
	}

	T GetLength() const
	{
		return std::sqrt(GetLengthSq());
	}

	T GetLengthSq() const
	{
		return X * X + Y * Y;
	}

	Vec2 operator+(const Vec2& rhs) const
	{
		return Vec2(X + rhs.X, Y + rhs.Y);
	}

	Vec2& operator+=(const Vec2& rhs)
	{
		X += rhs.X;
		Y += rhs.Y;
		return *this;
	}

	bool operator==(const Vec2& rhs)
	{
		return X == rhs.X && Y == rhs.Y;
	}

	Vec2 operator-(const Vec2& rhs) const
	{
		return Vec2(X - rhs.X, Y - rhs.Y);
	}

	Vec2 operator-() const
	{
		return Vec2<T>(-X, -Y);
	}

	Vec2& operator-=(const Vec2& rhs)
	{
		X -= rhs.X;
		Y -= rhs.Y;
		return *this;
	}

	Vec2 operator*(const T scale) const
	{
		return Vec2<T>(X * scale, Y * scale);
	}

	Vec2 operator*(const Vec2<T> rhs) const
	{
		return Vec2<T>(X * rhs.X, Y * rhs.Y);
	}

	Vec2& operator *=(const T scale)
	{
		X *= scale;
		Y *= scale;
		return *this;
	}

	Vec2& operator *=(const Vec2& rhs)
	{
		X *= rhs.X;
		Y *= rhs.Y;
	}

	Vec2 operator/(const T scale) const
	{
		return Vec2(X / scale, Y / scale);
	}

	Vec2& operator/=(const Vec2<T> rhs) const
	{
		return Vec2(X / rhs.X, Y / rhs.Y);
	}

	Vec2 Norm() const
	{
		if (GetLength() != (T)0)
		{
			float mag = GetLength();
			return { X / mag, Y / mag };
		}
		else
		{
			return { 0.0f, 0.0f };
		}
	}

	T Dot(const Vec2<T> rhs) const
	{
		return X * rhs.X + Y * rhs.Y;
	}

	//for 2D vector, can only give magnitude (aka, the only component)!
	T Cross(const Vec2<T> rhs) const
	{
		return X * rhs.Y - Y * rhs.X;
	}

	template<typename U>
	explicit Vec2(const Vec2<U> src)
	{
		X = (T)src.X;
		Y = (T)src.Y;
	}

public:
	T X;
	T Y;
};
