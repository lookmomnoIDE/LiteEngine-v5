#ifndef VEC4_H
#define VEC4_H



template <typename T>
class Vec4
{
public:
	T m_x, m_y, m_z, m_w;
	Vec4(){}
	Vec4(T x, T y, T z, T w)
		:m_x(x), m_y(y), m_z(z), m_w(w)
	{

	}

	Vec4& add( const Vec4& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		m_w += rhs.m_w;
		return *this;	
	}

	Vec4& subtract(const Vec4& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		m_w -= rhs.m_w;
		return *this;
	}

	Vec4& scale(const T val)
	{
		m_x *= val;
		m_y *= val;
		m_z *= val;
		m_w *= val;
		return *this;
	}

	Vec4& operator + (const Vec4& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		m_w += rhs.m_w;
		return *this;	
	}

	Vec4& operator - (const Vec4& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		m_w -= rhs.m_w;
		return *this;
	}

	Vec4& operator * (const Vec4& rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		m_z *= rhs.m_z;
		m_w *= rhs.m_w;
		return *this;
	}

	bool operator == (const Vec4& rhs)
	{
		if (m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z && m_w == rhs.m_w)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	Vec4& operator += (const Vec4& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		m_w += rhs.m_w;
		return *this;
	}

	Vec4& operator -= (const Vec4& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		m_w -= rhs.m_w;
		return *this;
	}

};


#endif