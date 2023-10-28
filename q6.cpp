#include <iostream>
#include <chrono>

/*
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385.
The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)^2 = 55^2 = 3025.
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025 - 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int main()
{
    int n{100};
    long long sum_of_squares, square_of_sum, difference, temp;

    auto start = std::chrono::high_resolution_clock::now();

    sum_of_squares = (n * (n + 1) * (2 * n + 1)) / 6;
    temp = (n * (n + 1)) / 2;
    square_of_sum = temp * temp;
    difference = square_of_sum - sum_of_squares;

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "\nAnswer:" << difference;
    std::cout << "\nNanoseconds:" << duration.count();
    std::cout << "\nSeconds:" << duration.count() * 1e-9;

    return 0;
}