// 📌 Topic: Range Sum — Optimized with Prefix Sum

// Core Idea:
// Use a prefix sum array to convert any range sum query [a, b]
// into constant time (O(1)) lookup.

// Steps:
// 1. Read the original array `vec` and build the prefix sum array `p`.
//    - p[i] stores the sum of all elements from index 0 to i.
//    - That is: p[i] = vec[0] + vec[1] + ... + vec[i]

// 2. For each query `a` and `b` (i.e., asking for the sum from a to b):
//    - If a == 0: return p[b]
//    - Else: return p[b] - p[a - 1] (sum of elements in range [a, b])

// Why it's efficient:
// Compared to the brute-force approach (looping from a to b),
// prefix sum allows range sum queries in O(1) time.



#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int numberOfElements = 0;
    cin >> numberOfElements;

    vector<int> vec(numberOfElements);
    vector<int> p(numberOfElements);

    int presum = 0;

    for (int i = 0; i < numberOfElements; i++)
    {
        cin >> vec[i];
        presum += vec[i];
        p[i] = presum;
    }


    int a = 0;
    int b = 0;

    while (cin >> a >> b)
    {
        int sum = 0;
        if (a == 0)
        {
            sum = p[b];
        }
        else
        {
            sum = p[b] - p[a-1];
        }

        cout << sum << endl;
    }


    return 0;
}


// 📌 题目相关：区间和，使用前缀和数组进行优化

// 核心思想：
// 利用前缀和数组，将任意区间 [a, b] 的和转换为 O(1) 时间复杂度的查询。

// 步骤：
// 1. 先读入原始数组 vec，并同时构造前缀和数组 p。
//    其中 p[i] 表示下标 [0, i] 之间所有元素的和。
//    即：p[i] = vec[0] + vec[1] + ... + vec[i]

// 2. 对于每组输入的查询 a, b（表示区间 [a, b]）
//    - 若 a == 0，直接返回 p[b]
//    - 否则返回 p[b] - p[a - 1]，即区间和 [a, b] 的值

// 优势：相比暴力求和（每次都循环 a 到 b），使用前缀和，可以将每次查询从将每次查询O(n * m)时间，m 是查询的次数，优化为 O(1)
