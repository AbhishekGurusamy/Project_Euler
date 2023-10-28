#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

/*
By listing the first six prime numbers:
2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

int main()
{
    int n{10001};
    bool loop{true}, flag;
    int number{2};
    long long i{5}, temp;
    std::vector<int> prime_set = {3};

    auto start = std::chrono::high_resolution_clock::now();

    while (loop)
    {
        temp = std::sqrt(i);
        flag = true;
        for (int j = 0; j < prime_set.size(); ++j)
        {
            if (prime_set[j] > temp)
                break;

            if (i % prime_set[j] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            prime_set.push_back(i);
            ++number;
            if (number == n)
                loop = false;
        }
        i += 2;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "\nAnswer:" << prime_set[prime_set.size() - 1];
    std::cout << "\nNanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;

    return 0;
}