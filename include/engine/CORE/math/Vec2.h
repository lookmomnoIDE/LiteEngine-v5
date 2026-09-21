#ifndef VEC2_H
#define VEC2_H


template <typename T>

class Vec2
{


public:
	T m_x, m_y;
	Vec2(){}
	Vec2(T x, T y)
		:m_x(x), m_y(y)
		{

		}

	Vec2& add(const Vec2& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}

	Vec2& subtract(const Vec2& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return *this;
	}

	Vec2& scale(const T val)
	{
		m_x *= val;
		m_y *= val;
		return *this;
	}

	Vec2& operator + (const Vec2& rhs) 
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}

	Vec2& operator - (const Vec2& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return *this;
	}

	Vec2& operator * (const Vec2& rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		return *this;
	}

	Vec2& operator = (const Vec2& rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
		return *this;
	}

	bool operator == (const Vec2& rhs)
	{
		if (m_x == rhs.m_x && m_y == rhs.m_y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Vec2& operator += (const Vec2& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		return *this;
	}

	Vec2& operator -= (const Vec2& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		return *this;
	}


};

#endif