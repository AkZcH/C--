#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    // Allocate memory for a boolean array
    bool *isPrime = (bool *)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        isPrime[i] = true; // Initialize all numbers as prime
    }

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    int limit = sqrt(n); // Only check up to the square root of n
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            // Mark multiples of i as non-prime
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count the number of primes
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    // Free allocated memory
    free(isPrime);

    return count;
}
