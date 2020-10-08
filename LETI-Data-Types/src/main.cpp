#include <iostream>
#include <string>
#include "../include/LETI-Data-Types/data_types_helper.hpp"

// Prints the size of all required datatypes in bytes
void PrintDTSizes()
{
	std::cout << "short int: \t"   << DTHelper::GetSize<short int>()   << '\n';
	std::cout << "int: \t\t"       << DTHelper::GetSize<int>()         << '\n';
	std::cout << "long int: \t"    << DTHelper::GetSize<long int>()    << '\n';
	std::cout << "float: \t\t"     << DTHelper::GetSize<float>()       << '\n';
	std::cout << "double: \t"      << DTHelper::GetSize<double>()      << '\n';
	std::cout << "long double: \t" << DTHelper::GetSize<long double>() << '\n';
	std::cout << "char: \t\t"      << DTHelper::GetSize<char>()        << '\n';
	std::cout << "bool: \t\t"      << DTHelper::GetSize<bool>()        << '\n';
}

// Prints given number's binary representation
template <typename T>
void PrintNumAsBin(T num)
{
	if (typeid(T) == typeid(int))
	{
		// Pos counter assists with formatting
		int pos_counter = 0;
		for (char bit : DTHelper::GetBinary(num))
		{
			if (pos_counter == 1)
			{
				std::cout << "-";
			}

			std::cout << bit;
			pos_counter++;
		}
	}
	else if (typeid(T) == typeid(float))
	{
		int pos_counter = 0;
		for (char bit : DTHelper::GetBinary(num))
		{
			if (pos_counter == 1 ||
				pos_counter == 9)
			{
				std::cout << "-";
			}

			std::cout << bit;
			pos_counter++;
		}
	}
	else if (typeid(T) == typeid(double))
	{
		int pos_counter = 0;
		for (char bit : DTHelper::GetBinary(num))
		{
			if (pos_counter == 1 ||
				pos_counter == 12)
			{
				std::cout << "-";
			}

			std::cout << bit;
			pos_counter++;
		}
	}
}

// TODO: Use a formatting library for output
void ShowUsage(char name[])
{
	std::cerr << "\nUsage:\n" << name << " <option(s)> VALUES\n\n"
		<< "Example: \n"
		<< name << " -b int -12 \n\n"
		<< "Options:\n"
		<< "\t-h, --help\t\t\t\tPrint this help text and exit\n"
		<< "\t-s, --size\t\t\t\tDisplay data type sizes\n"
		<< "\t-b, --binary (int/float/double) NUMBER\tPrints given number's binary representation"
		<< '\n';
}

// TODO: Use a library for parsing arguments
int main(int argc, char* argv[])
{
	// If no arguments were passed
	if (argc < 2)
	{
		ShowUsage(argv[0]);
		std::getchar();
		return 1;
	}

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if ((arg == "-h") || (arg == "--help"))
		{
			ShowUsage(argv[0]);
			return 0;
		}
		else if ((arg == "-s") || (arg == "--size"))
		{
			PrintDTSizes();
		}
		else if ((arg == "-b") || (arg == "--binary"))
		{
			// Make sure we aren't at the end of argv
			if (i + 1 < argc)
			{
				i++; // Skip -b argument
				// Increment 'i' so we don't get the argument as the next argv[i]
				std::string type = argv[i++];
				std::string number = argv[i++];

				if (type == "int")
				{
					try
					{
						int num = std::stoi(number);
						PrintNumAsBin(num);
					}
					catch (std::invalid_argument)
					{
						std::cerr << "Invalid number: " << number << '\n';
						return 1;
					}
					catch (std::out_of_range)
					{
						std::cerr << "Number out of range: " << number << '\n';
						return 1;
					}
				}
				else if (type == "float")
				{
					try
					{
						float num = std::stof(number);
						PrintNumAsBin(num);
					}
					catch (std::invalid_argument)
					{
						std::cerr << "Invalid number: " << number << '\n';
						return 1;
					}
					catch (std::out_of_range)
					{
						std::cerr << "Number out of range: " << number << '\n';
						return 1;
					}
				}
				else if (type == "double")
				{
					try
					{
						double num = std::stod(number);
						PrintNumAsBin(num);
					}
					catch (std::invalid_argument)
					{
						std::cerr << "Invalid number: " << number << '\n';
						return 1;
					}
					catch (std::out_of_range)
					{
						std::cerr << "Number out of range: " << number << '\n';
						return 1;
					}
				}
				else
				{
					std::cerr << "Unrecognized type. Write --help to show accepted types.";
				}
			}
			else
			{
				std::cerr << "--binary option requires two arguments.\n";
				return 1;
			}
		}
		else
		{
			std::cerr << "Unrecognized argument. Write --help to show accepted arguments.\n";
			return 1;
		}
	}

	return 0;
}
