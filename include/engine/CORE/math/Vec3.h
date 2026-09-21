#ifndef VEC3_H
#define VEC3_H


template <typename T>
class Vec3
{
public:
	T m_x, m_y, m_z;
	Vec3(){}
	Vec3(T x, T y, T z)
		:m_x(x), m_y(y), m_z(z)
	{

	}

	Vec3& add( const Vec3& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		return *this;	
	}

	Vec3& subtract(const Vec3& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		return *this;
	}

	Vec3& scale(const T val)
	{
		m_x *= val;
		m_y *= val;
		m_z *= val;
		return *this;
	}

	Vec3& operator + (const Vec3& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		return *this;	
	}

	Vec3& operator - (const Vec3& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		return *this;
	}

	Vec3& operator * (const Vec3& rhs)
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		m_z *= rhs.m_z;
		return *this;
	}

	bool operator == (const Vec3& rhs)
	{
		if (m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	Vec3& operator += (const Vec3& rhs)
	{
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		return *this;
	}

	Vec3& operator -= (const Vec3& rhs)
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		return *this;
	}

};


#endif