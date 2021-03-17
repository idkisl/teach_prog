#include <iostream>

template<class T>
void fibonachchi(T a, T b, unsigned int iterator = 0)
{
    if (iterator > 15)
    {
        return;
    }
    std::cout << a + b << " ";
    fibonachchi(b, a + b, iterator + 1);
}

template<class T>
void tribonachchi(T a, T b, T c, unsigned int iterator = 0)
{
    if (iterator > 15)
    {
        return;
    }
    std::cout << a + b + c << " ";
    tribonachchi(b, c, a + b + c, iterator + 1);
}


int main()
{
    fibonachchi(0, 1);
    std::cout << std::endl;
    tribonachchi(0, 0, 1);
    return 0;
}
