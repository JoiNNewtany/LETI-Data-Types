#include <iostream>
#include "../include/LETI-Data-Types/data_types_helper.hpp"

// TODO: Rework main(), allow inputs
int main()
{
	int test_integer = 12;
	std::string int_bits = DTHelper::GetBinary(test_integer);
	std::cout << int_bits << '\n';

	float test_float = 3.14;
	std::string float_bits = DTHelper::GetBinary(test_float);
	std::cout << float_bits << '\n';

	double test_double = -3.14;
	std::string double_bits = DTHelper::GetBinary(test_double);
	std::cout << double_bits << '\n';

	return 0;
}
