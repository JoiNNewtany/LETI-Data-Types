#include "../include/LETI-Data-Types/data_types_helper.hpp"

std::string DTHelper::GetBinary(int num)
{
	std::string output;
	int count = 0;

	for (unsigned mask = 1 << 31; mask > 0; mask >>= 1)
	{
		output += (num & mask ? '1' : '0');
	}

	return output;
}

std::string DTHelper::GetBinary(float num)
{
	union
	{
		float input;
		int output;
	} data;

	data.input = num;

	return GetBinary(data.output);
}

std::string DTHelper::GetBinary(double num)
{
	union
	{
		double input;
		int output[2];
	} data;

	data.input = num;

	return GetBinary(data.output[1]) + GetBinary(data.output[0]);
}