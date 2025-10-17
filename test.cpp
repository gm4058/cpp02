#include <iostream>
#include <cmath>

int main()
{
    float f = 42.41999999f;

    std::cout << f << std::endl;

    int  i = roundf(f * (1 << 8));

    std::cout << i << std::endl;

    float f2 = i / (float)(1 << 8);

    std::cout << f2 << std::endl;

    int i2 = 2147483647;

    std::cout << i2 << std::endl;

    int i3 = i2 << 8;

    std::cout << i3 << std::endl;

    int i4 = i3 >> 8;

    std::cout << i4 << std::endl;
}