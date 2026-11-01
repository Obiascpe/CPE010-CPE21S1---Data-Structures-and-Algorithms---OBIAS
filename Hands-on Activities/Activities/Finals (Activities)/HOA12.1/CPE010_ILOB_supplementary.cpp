#include <iostream>

const int M = 4;
const int N = 4;

// Recursive function to count paths with the given cost
int countPaths(int matrix[M][N], int i, int j, int remainingCost)
{
    // Check if the position is outside the matrix
    if (i >= M || j >= N)
        return 0;

    // Subtract the current cell's cost
    remainingCost -= matrix[i][j];

    // Check if the destination is reached
    if (i == M - 1 && j == N - 1)
    {
        return (remainingCost == 0) ? 1 : 0;
    }

    // Stop if the remaining cost becomes negative
    if (remainingCost < 0)
        return 0;

    // Recursively move right and down
    int right = countPaths(matrix, i, j + 1, remainingCost);
    int down = countPaths(matrix, i + 1, j, remainingCost);

    // Return the total number of valid paths
    return right + down;
}

int main()
{
    int matrix[M][N] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 25;

    int result = countPaths(matrix, 0, 0, targetCost);

    std::cout << "Target Cost: " << targetCost << std::endl;
    std::cout << "Number of valid paths: " << result << std::endl;

    return 0;
}