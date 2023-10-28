#include <iostream>
#include <chrono>
#include <vector>
#include <math.h>

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

int main()
{
    long int n{2000000};
    bool flag;
    long long sum{5};

    std::vector<long> prime_set = {3};

    auto start = std::chrono::high_resolution_clock::now();

    for (long long i = 5; i <= n; i += 2)
    {
        flag = true;
        for (long long j = 0; j < prime_set.size(); ++j)
        {

            if (prime_set[j] > std::sqrt(i))
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
            sum += i;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Summation of primes:" << sum << "\n";
    std::cout << "Nanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;
}