// KaratsubaRecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cmath>
#include <algorithm>
/*
procedure karatsuba(num1, num2)
	if (num1 < 10) or (num2 < 10)
		return num1 × num2

	// Calculates the size of the numbers. 
m = min(size_base10(num1), size_base10(num2))
m2 = floor(m / 2)
//m2 = ceil(m / 2) will also work 

// Split the digit sequences in the middle. 
high1, low1 = split_at(num1, m2)
high2, low2 = split_at(num2, m2)

// 3 calls made to numbers approximately half the size. 
z0 = karatsuba(low1, low2)
z1 = karatsuba((low1 + high1), (low2 + high2))
z2 = karatsuba(high1, high2)

return (z2 × 10 ^ (m2 × 2)) + ((z1 - z2 - z0) × 10 ^ m2) + z0
*/


class Karatsuba
{
public:
	Karatsuba() 
	{}
	int calculate(int num1, int num2)
	{
		if ((num1 < 10) || (num2 < 10))
			return (num1 * num2);

		// Calculates the size of the numbers. 
		int m = std::min(log10(num1) + 1, log10(num2) + 1);
		int m2 = std::floor(m / 2);
		//std::cout << "value of m2:" << m2 << std::endl;

		/* Split the digit sequences in the middle. */
		int high1 = num1 / static_cast<int>(pow(10, m2));
		int low1 = num1 % static_cast<int>(pow(10, m2));
		//std::cout << "value of low1:" << low1 << "value of high1:" << high1 << std::endl;
		int high2 = num2 / static_cast<int>(pow(10, m2));
		int low2 = num2 % static_cast<int>(pow(10, m2));
		//std::cout << "value of low2:" << low2 << "value of high2:" << high2 << std::endl;

		// 3 calls made to numbers approximately half the size. 
		int z0 = calculate(low1, low2);
		int	z1 = calculate((low1 + high1), (low2 + high2));
		int	z2 = calculate(high1, high2);

		return (z2 * static_cast<int>(pow(10, m2 * 2))) + ((z1 - z2 - z0) * static_cast<int>(pow(10, m2))) + z0;
	}

};

int main()
{
    std::cout << "Karatsuba recursion algorithm!\n";	
	Karatsuba karatsuba;
	std::cout << "Product of"<< 12345 <<" and "<< 6789 <<" is: "<< karatsuba.calculate(12345, 6789) << std::endl;
	std::cout << "Product of" << 1000 << " and " << 20000 << " is: " << karatsuba.calculate(1000, 20000) << std::endl;
	std::cout << "Product of" << 1 << " and " << 2 << " is: " << karatsuba.calculate(1, 2) << std::endl;
	std::cout << "Product of" << 10 << " and " << 0 << " is: " << karatsuba.calculate(10, 0) << std::endl;
}

