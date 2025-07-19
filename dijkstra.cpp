/*
题目描述（Problem Description）：
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。
小明的起点是第一个车站，终点是最后一个车站。然而，途中各个车站之间的道路状况、
交通拥堵程度以及可能的自然因素（如天气变化）等不同，这些因素都会影响每条路的通行时间。
小明希望能选择一条花费时间最少的路线，以确保他能够尽快到达目的地。

Xiaoming is a scientist who needs to attend an important international science conference to present his latest research.
His starting point is the first bus station, and the destination is the last one.
However, road conditions, traffic congestion, and natural factors (e.g., weather) may affect the travel time between stations.
Xiaoming wants to choose a route that minimizes total travel time to reach his destination as quickly as possible.

输入描述（Input Description）：
第一行包含两个正整数，N 和 M，表示一共有 N 个公共汽车站，M 条公交线路。
The first line contains two integers, N and M, representing the number of bus stations and the number of directed bus routes.

接下来 M 行，每行包含三个整数 S, E 和 V，表示从 S 站到 E 站有一条路径，耗时为 V。
The next M lines each contain three integers S, E and V, meaning there is a route from station S to E that takes V units of time.

输出描述（Output Description）：
输出一个整数，代表从起点（第1个车站）到终点（第N个车站）所需的最小时间。
Output an integer representing the minimum total time required to travel from station 1 to station N.

输入示例（Sample Input）：
7 9
1 2 1
1 3 4
2 3 2
2 4 5
3 4 2
4 5 3
2 6 4
5 7 4
6 7 9

输出示例（Sample Output）：
12
*/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main() {

    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }

    int start = 1;
    int end = n;

    // Store the shortest distance from the source to each node
    vector<int> minDist(n + 1, INT_MAX);

    // Record whether the vertex has been visited
    vector<bool> visited(n + 1, false);

    minDist[start] = 0;

    vector<int> parent(n + 1, -1);

    // Traverse all nodes
    for (int i = 1; i <= n; i++) {

        int minVal = INT_MAX;
        int cur = 1;

        // 1. Select the node that is closest to the source and has not been visited
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }

        // 2. Mark that the node has been visited
        visited[cur] = true;

        // 3. Update the distance from unvisited nodes to the source (i.e., update minDist array)
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
                minDist[v] = minDist[cur] + grid[cur][v];
                parent[v] = cur; // record the path
            }
        }

        // Debug
        cout << "select:" << cur << endl;
        for (int v = 1; v <= n; v++) cout << v << ":" << minDist[v] << " ";
        cout << endl << endl;
    }

    if (minDist[end] == INT_MAX)
        cout << -1 << endl; // Unable to reach the end
    else
        cout << minDist[end] << endl; // The shortest length to the destination

    // If ask to print out the path
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << "->" << i << endl;
    }

    return 0;
}