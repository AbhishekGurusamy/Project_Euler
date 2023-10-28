#include <iostream>
#include <chrono>

/*
A Pythagorean triplet is a set of three natural numbers, a<b<c, for which, a^2 + b^2 = c^2.
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int main()
{
    int n{1000};
    long a, b, c, answer{0};
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 3; i < n; ++i)
    {
        if (i & 1)
        {
            a = i;
            b = ((a * a) - 1) / 2;
            c = ((a * a) + 1) / 2;
        }
        else
        {
            a = i;
            b = ((a * a) - 4) / 2;
            c = ((a * a) + 4) / 2;
        }
        std::cout << "\na:" << a << "b:" << b << "c:" << c;
        if ((a + b + c) == n)
        {
            answer = a * b * c;
            break;
        }
        else if ((a + b + c) > n)
        {
            break;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "\nAnswer:" << answer;
    std::cout << "\nNanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;

    return 0;
}