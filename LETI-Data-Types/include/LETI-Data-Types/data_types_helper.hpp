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

	static std::string GetBinary(int num);
	static std::string GetBinary(float num);
	static std::string GetBinary(double num);

	template <typename T>
	static int GetSize(T var) { return sizeof(var); }

private:
	// Disallow creating an instance of this object
	DTHelper() {}
};
