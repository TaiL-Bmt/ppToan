#include "bigint.h"
#include <bits/stdc++.h>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>

void testOverflow();
void testNumberCannotBePresentedByDouble();
void testTimeExecution();

int main()
{
    testOverflow();
    testNumberCannotBePresentedByDouble();
    testTimeExecution();
    return 0;
}

void testOverflow()
{
    uint64_t num {1000000};
    std::cout << "=======================================\n";
    std::cout << "testOverflow\n";
    std::cout << "expected is 1,000,000,000,000,000,000,000,000\n";
    std::cout << "uint64_t: " << static_cast<uint64_t>(num * num * num * num) << std::endl;
    bigint num2 = (bigint)1 << 6;
    std::cout << "bigint lib: " << num2 << std::endl;
}

void testNumberCannotBePresentedByDouble()
{
    std::cout << "=======================================\n";
    std::cout << "testNumberCannotBePresentedByDouble\n";
    std::cout << "2^53 + 1 = 9007199254740992 + 1\n";
    double num = pow(2, 53);
    std::cout << "uint64_t: " << static_cast<uint64_t>(num)  + 1 << std::endl;
    std::cout << "double: " << static_cast<uint64_t>(num + 1) << std::endl;
    std::cout << "bigint: " << bigint(num) + 1 << std::endl; 
}

void testTimeExecution()
{
    std::cout << "=======================================\n";
    std::cout << "testTimeExecution\n";

    // Generate Input
    constexpr uint64_t numberOfSamples = 1e6;
    std::vector<bigint> leftValues;
    std::vector<bigint> rightValues;
    srand(time(0));
    for(int i = 0; i < numberOfSamples; i++)
    {
        leftValues.emplace_back(rand());
        rightValues.emplace_back(rand());
    }

    std::vector<bigint> result(leftValues.size(), 0);

    // Addition operator
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < leftValues.size(); i++)
    {
        result[i] = leftValues[i] + rightValues[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    double timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    timeTaken /= 1000000;
    std::cout << timeTaken << std::endl;

    // Substraction oprator
    start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < leftValues.size(); i++)
    {
        result[i] = leftValues[i] - rightValues[i];
    }
    end = std::chrono::high_resolution_clock::now();
    timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    timeTaken /= 1000000;
    std::cout << timeTaken << std::endl;

    // Multiplication opeartor
    start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < leftValues.size(); i++)
    {
        result[i] = leftValues[i] * rightValues[i];
    }
    end = std::chrono::high_resolution_clock::now();
    timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    timeTaken /= 1000000;
    std::cout << timeTaken << std::endl;
}

