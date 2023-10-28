#include <iostream>
#include <chrono>
#include <math.h>
#include <vector>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

int main()
{
    long long n{600851475143}, max, temp;
    bool flag;

    std::vector<long> prime_set = {3};

    auto start = std::chrono::high_resolution_clock::now();

    for (long long i = 5; i <= std::sqrt(n); i += 2)
    {
        temp = std::sqrt(i);
        flag = true;
        for (long long j = 0; j < prime_set.size(); ++j)
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
            if (n % i == 0)
                max = i;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Largest prime:" << max << "\n";
    std::cout << "Nanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;

    return 0;
}