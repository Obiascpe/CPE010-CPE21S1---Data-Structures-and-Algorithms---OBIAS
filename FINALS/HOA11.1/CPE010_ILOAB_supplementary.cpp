#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> // kailangan para sa std::setw at std::left

// PROBLEM 1: Element Uniqueness Algorithm
long long comparisons = 0;

bool unique_elements(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

// PROBLEM 2: Exponentiation Algorithms
long long calls = 0;

// Linear Power O(n)
unsigned long long rpower(unsigned long long x, int n) {
    calls++;
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

// Binary Power O(log n)
unsigned long long brpower(unsigned long long x, int n) {
    calls++;
    if (n == 0) return 1;
    
    if (n % 2 == 1) { // Odd n
        unsigned long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else { // Even n
        unsigned long long y = brpower(x, n / 2);
        return y * y;
    }
}

// MAIN DRIVER FUNCTION
int main() {
    using clk = std::chrono::high_resolution_clock;
    using us = std::chrono::microseconds;

    std::cout << "PROBLEM 1: Unique(A) - Worst Case Performance\n";
    std::cout << std::left 
              << std::setw(10) << "n" 
              << std::setw(18) << "Measured Comp" 
              << std::setw(20) << "Theoretical Comp" 
              << std::setw(15) << "Time (us)" << "\n";
    std::cout << "-------------------------------------------------------------------------\n";

    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        comparisons = 0;
        auto start = clk::now();
        bool is_unique = unique_elements(A);
        auto end = clk::now();

        long long theoretical = (long long)n * (n - 1) / 2;
        auto duration = std::chrono::duration_cast<us>(end - start).count();

        std::cout << std::left 
                  << std::setw(10) << n 
                  << std::setw(18) << comparisons 
                  << std::setw(20) << theoretical 
                  << std::setw(15) << duration << "\n";
    }

    std::cout << "\nPROBLEM 2: rpower vs brpower (x = 1)\n";
    std::cout << std::left 
              << std::setw(10) << "n" 
              << std::setw(16) << "rpower Calls" 
              << std::setw(16) << "rpower (us)" 
              << std::setw(16) << "brpower Calls" 
              << std::setw(16) << "brpower (us)" << "\n";
    std::cout << "-------------------------------------------------------------------------\n";

    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        // Measure rpower
        calls = 0;
        auto start1 = clk::now();
        rpower(1, n);
        auto end1 = clk::now();
        long long r_calls = calls;
        auto r_time = std::chrono::duration_cast<us>(end1 - start1).count();

        // Measure brpower
        calls = 0;
        auto start2 = clk::now();
        brpower(1, n);
        auto end2 = clk::now();
        long long br_calls = calls;
        auto br_time = std::chrono::duration_cast<us>(end2 - start2).count();

        std::cout << std::left 
                  << std::setw(10) << n 
                  << std::setw(16) << r_calls 
                  << std::setw(16) << r_time 
                  << std::setw(16) << br_calls 
                  << std::setw(16) << br_time << "\n";
    }

    return 0;
}