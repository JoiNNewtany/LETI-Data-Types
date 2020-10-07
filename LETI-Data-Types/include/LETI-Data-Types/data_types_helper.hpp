#pragma once

#include <string>

/*
	Data Types Helper can display the in-memory binary representations
	of different data types.
*/
class DTHelper
{
public:
	~DTHelper() {}

	// Returns a binary representation of a number
	static std::string GetBinary(int num);
	static std::string GetBinary(float num);
	static std::string GetBinary(double num);

	// Prints a size of a variable in bytes
	template <typename T>
	static inline void PrintSize(T var)
	{
		T *ptr = 0;
		// Pointer increments by the size of the type
		ptr++;
		printf("%d", ptr);
	}

private:
	// Disallow creating an instance of this object
	DTHelper() {}
};
