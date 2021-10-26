#include "ClassVector.h"
#include <iostream>
#include <string>
#include <cstring>
#include <climits>

void PrintMenu()
{
	std::cout << "1 - add up the vectors\n2 - subtract vectors\n3 - multiply vectors\n4 - change first vector\n5 - change second vector\n0 - exit" << std::endl;
}

void PrintVectorMenu()
{
	std::cout << "\n1 - Change element\n2 - multiply by number\n3 - divide by number\n0 - back";
}

int main()
{
	vector first(4);
	vector second(4);
	while (true)
	{
		system("cls");
		std::cout << first << std::endl;
		std::cout << second << std::endl;
		PrintMenu();
		int option = -1;
		std::cout << "Choose an option by number: ";
		std::cin >> option;
		switch (option)
		{
		case 1:
		{
			system("cls");
			std::cout << "The result:\n" << std::endl;
			vector sum;
			try
			{
				sum = first + second;
			}
			catch (const char* error)
			{
				std::cout << error << std::endl;
			}
			std::cout << sum << std::endl;
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "The result:\n" << std::endl;
			vector dif;
			try
			{
				dif = first - second;
			}
			catch (const char* error)
			{
				std::cout << error << std::endl;
			}
			std::cout << dif << std::endl;
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "The result:\n" << std::endl;
			double result = 0;
			try
			{
				result = first * second;
			}
			catch (const char* error)
			{
				std::cout << error << std::endl;
			}
			std::cout << result << std::endl;
			system("pause");
			break;
		}
		case 4:
		{
			bool flag = true;
			while (flag)
			{
				system("cls");
				std::cout << first << std::endl;
				PrintVectorMenu();
				int option1;
				std::cout << "\nChoose an option by number: ";
				std::cin >> option1;
				switch (option1)
				{
				case 1:
				{
					size_t index;
					double value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						first[index - 1] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					double value;
					std::cout << "Enter a multiplier: ";
					std::cin >> value;
					first *= value;
					break;
				}
				case 3:
				{
					double value;
					std::cout << "Enter a divisor: ";
					std::cin >> value;
					first /= value;
					break;
				}
				case 0:
				{
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 5:
		{
			bool flag = true;
			while (flag)
			{
				system("cls");
				std::cout << second << std::endl;
				PrintVectorMenu();
				int option2;
				std::cout << "\nChoose an option by number: ";
				std::cin >> option2;
				switch (option2)
				{
				case 1:
				{
					size_t index;
					double value;
					std::cout << "Which element: ";
					std::cin >> index;
					std::cout << "Enter a new value: ";
					std::cin >> value;
					try
					{
						second[index - 1] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					double value;
					std::cout << "Enter a multiplier: ";
					std::cin >> value;
					second *= value;
					break;
				}
				case 3:
				{
					double value;
					std::cout << "Enter a divisor: ";
					std::cin >> value;
					second /= value;
					break;
				}
				case 0:
				{
					flag = false;
					break;
				}
				}
			}
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}