#include <iostream>
#include <chrono>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

int main()
{
    /* Naive method. Slowest. Checking divisibility by 3 or 5 by checking every number.*/
    auto start_1 = std::chrono::high_resolution_clock::now();
    long answer{};
    for (int i = 3; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            answer += i;
        }
    }
    auto stop_1 = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nAnswer 1:" << answer;

    /* Slightly better. Still slow. Adding multiples of 3 and adding taking multiples of 5 skipping 15 multiples.*/
    answer = 0L;
    auto start_2 = std::chrono::high_resolution_clock::now();
    for (int i = 3; i < 1000; i += 3)
    {
        answer += i;
    }
    for (int j = 5; j < 1000; j += 5)
    {
        if (j % 15 == 0)
            continue;
        answer += j;
    }
    auto stop_2 = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nAnswer 2:" << answer;

    /* Using Sum of n natural numbers formula. Fastest. Adding multiples of 3,
     adding multiples of 5, and substracting multiples of 15*/
    answer = 0L;
    auto start_3 = std::chrono::high_resolution_clock::now();

    answer = (((1000 - 1) / 3) * (2 * 3 + (((1000 - 1) / 3) - 1) * 3)) / 2;

    answer += (((1000 - 1) / 5) * (2 * 5 + (((1000 - 1) / 5) - 1) * 5)) / 2;

    answer -= (((1000 - 1) / 15) * (2 * 15 + (((1000 - 1) / 15) - 1) * 15)) / 2;

    auto stop_3 = std::chrono::high_resolution_clock::now();
    std::cout << "\n\nAnswer 3:" << answer;

    auto duration_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_1 - start_1);
    auto duration_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_2 - start_2);
    auto duration_3 = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_3 - start_3);

    std::cout << "\nNano seconds 1:" << duration_1.count();
    std::cout << "\nSeconds 1:" << duration_1.count() * 1e-9;
    std::cout << "\nNano seconds 2:" << duration_2.count();
    std::cout << "\nSeconds 2:" << duration_2.count() * 1e-9;
    std::cout << "\nNano seconds 3:" << duration_3.count();
    std::cout << "\nSeconds 3:" << duration_3.count() * 1e-9;

    return 0;
}