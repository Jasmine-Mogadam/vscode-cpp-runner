#include "MathLibrary.h"
#include <iostream>

void Add(int a, int b, void (*callback)(int))
{
    callback(a + b);
}
void Multiply(int a, int b, void (*callback)(int))
{
    callback(a * b);
}
void Subtract(int a, int b, void (*callback)(int))
{
    callback(a - b);
}
void Divide(int a, int b, void (*callback)(int))
{
    callback(a / b);
}
void Modulus(int a, int b, void (*callback)(int))
{
    callback(a % b);
}
void Greater(int a, int b, void (*callback)(int))
{
    callback(a > b ? a : b);
}
void Less(int a, int b, void (*callback)(int))
{
    callback(a < b ? a : b);
}