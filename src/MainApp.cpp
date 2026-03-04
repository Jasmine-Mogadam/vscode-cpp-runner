#include <iostream>
#include "MathLibrary.h"

void MathResult(int result)
{
    std::cout << "Math Result: " << result << std::endl;
}

int main()
{
    std::cout << "Run MathLibrary with Callbacks..." << std::endl;

    std::cout << "Adding 30 & 20: " << std::endl;
    Add(30, 20, MathResult);

    std::cout << "Subtracting 45 from 80: " << std::endl;
    Subtract(80, 45, MathResult);

    std::cout << "Multiplying 10 & 30: " << std::endl;
    Multiply(10, 30, MathResult);

    std::cout << "Dividing 70 by 2: " << std::endl;
    Divide(70, 2, MathResult);

    std::cout << "Getting the Modulus of 40 & 15: " << std::endl;
    Modulus(40, 15, MathResult);

    std::cout << "Which is Greater, 2 or 7? (2 > 7?): " << std::endl;
    Greater(2, 7, MathResult);

    std::cout << "Which is Lesser, 8 or 10? (8 < 10?): " << std::endl;
    Less(8, 10, MathResult);

    return 0;
};