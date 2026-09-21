#ifndef VERTICES_H
#define VERTICES_H 
#include <vector>
#include <utility>

template <typename T> 
class Vertices
{
public:
	std::vector<T> m_verts;

	Vertices() = default;
	Vertices(const T* arr, std::size_t size)
	: m_verts(arr, arr + size)
	{}


	Vertices(std::vector<T> vec)
	:m_verts(std::move(vec))
	{

	}


	const T* data() const
	{
		return m_verts.data();
	}


	size_t size() const 
	{ 
		return m_verts.size();
	}


	size_t byteSize() const 
	{ 
		return m_verts.size() * sizeof(T);
	}
};

#endif