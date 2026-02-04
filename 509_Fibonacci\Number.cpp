// Solution 1: Use an extra DP array
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        // Step 1: Define the DP array and the meaning of its index
        // dp[i] represents the i-th Fibonacci number
        vector<int> dp(n + 1); // dynamic array

        // Step 2: Define the recurrence relation
        // The problem already gives us the transition formula:
        // dp[i] = dp[i - 1] + dp[i - 2]

        // Step 3: Initialize the DP array
        // According to the problem definition:
        // dp[0] = 0, dp[1] = 1
        dp[0] = 0;
        dp[1] = 1;

        // Step 4: Determine the traversal order
        // Since dp[i] depends on dp[i - 1] and dp[i - 2],
        // we must compute the values from left to right
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];

        // Step 5: Example to verify the DP array
        // Using the recurrence dp[i] = dp[i - 1] + dp[i - 2],
        // when n = 10, the dp array should be:
        // 0 1 1 2 3 5 8 13 21 34 55
        // If the result is incorrect, printing the dp array
        // can help debug and verify the computation.
    }
};


// Solution 2: No extra memory (only keep three necessary states)
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        // Only keep the last two Fibonacci values
        int dp[2] = {0};
        dp[0] = 0;
        dp[1] = 1;

        int sum = 0;

        // Iteratively compute Fibonacci numbers
        for (int i = 2; i < n; i++) {
            sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }

        return dp[1];
    }
};
