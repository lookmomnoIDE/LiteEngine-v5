#ifndef INDICES_H
#define INDICES_H
#include <vector>
#include <glm.hpp>


class Indices
{
	std::vector<unsigned int> m_indices;
public:
	Indices() = default;
	Indices(const unsigned int* arr, std::size_t size)
	:m_indices(arr, arr + size)
	{

	}


	Indices(std::vector<unsigned int> vec)
	:m_indices(std::move(vec))
	{

	}


	Indices(unsigned int N)
	:m_indices(std::move(generateIndices(N)))
	{
		
	}

	const unsigned int* data() const
	{
		return m_indices.data();
	}


	size_t size() const 
	{ 
		return m_indices.size();
	}


	size_t count() const
	{
		return m_indices.count();
	}


	size_t byteSize() const 
	{ 
		return m_indices.size() * sizeof(unsigned int);
	}


	std::vector<unsigned int> generateIndices(unsigned int N)
{
	std::vector<unsigned int> indices(N);
	unsigned int* out = indices.data();

	unsigned int base = 0;
	for (size_t i = 0; i < N / 6; ++i, base += 4)
	{
		// CCW: BR -> TR -> TL, then BR -> TL -> BL
		out[0] = base + 0;
		out[1] = base + 1;
		out[2] = base + 3;
		out[3] = base + 1;
		out[4] = base + 2;
		out[5] = base + 3;
		out += 6;
	}
	return indices;
}
};

#endif