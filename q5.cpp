#include <iostream>
#include <chrono>
#include <set>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

int main()
{
    int n{20}, temp;
    std::multiset<int> factors = {2, 3};
    long long answer = 6L;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 4; i <= n; ++i)
    {
        if (answer % i)
        {
            temp = i;
            for (std::multiset<int>::iterator j = factors.begin(); j != factors.end(); ++j)
            {
                if (temp % (*j) == 0)
                {
                    temp /= (*j);
                }
            }
            factors.insert(temp);
            answer *= temp;
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "\nAnswer:" << answer;
    std::cout << "\nNanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;

    return 0;
}