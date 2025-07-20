// ------------------------------------------------------------
// 题目：骑士的攻击
// 中文描述：
// 在象棋中，马的移动方式是“马走日”。给定骑士的起点和终点，
// 求最少需要多少步才能到达终点（每步按马的走法）。
//
// 棋盘大小为 1000 x 1000，坐标范围 [1, 1000]。
// 输入为多个测试用例，每个测试用例一行，输出最短步数。
//
// Description:
// Problem: Knight's Attack
// In chess, the knight moves in an "L" shape. Given a starting
// and ending position, compute the minimum number of moves
// required for the knight to reach the destination.
//
// The board is 1000x1000, with coordinates in [1, 1000].
// Input contains multiple test cases, each asking for one query.
// ------------------------------------------------------------

// Sample Input:
// 6
// 5 2 5 4
// 1 1 2 2
// 1 1 8 8
// 1 1 8 7
// 2 1 3 3
// 4 6 4 6

// Sample Output:
// 2
// 4
// 6
// 5
// 1
// 0


#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int moves[1001][1001];  // Stores move counts; also used as visited flags
int dir[8][2] = {       // All 8 knight move directions
    {-2,-1}, {-2,1}, {-1,2}, {1,2},
    {2,1}, {2,-1}, {1,-2}, {-1,-2}
};

int b1, b2; // Target position

// Structure representing a node in A* search
struct Knight {
    int x, y;    // Current position
    int g, h, f; // g: cost so far, h: heuristic, f: total cost

    // Priority queue will use this for ordering (min-heap by f)
    bool operator < (const Knight& k) const {
        return k.f < f; // higher f has lower priority
    }
};

priority_queue<Knight> que; // Min-heap for A* open list

// Heuristic function: estimated cost to goal (Euclidean distance squared)
int Heuristic(const Knight& k) {
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);
}

// A* pathfinding from start to target
void astar(const Knight& start) {
    Knight cur, next;
    que.push(start);

    while (!que.empty()) {
        cur = que.top(); que.pop();

        // Reached target
        if (cur.x == b1 && cur.y == b2) break;

        for (int i = 0; i < 8; i++) {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];

            // Check board boundaries
            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000)
                continue;

            // Not visited
            if (!moves[next.x][next.y]) {
                moves[next.x][next.y] = moves[cur.x][cur.y] + 1;

                // A* cost calculations
                next.g = cur.g + 5; // fixed step cost (could be 1)
                next.h = Heuristic(next);
                next.f = next.g + next.h;

                que.push(next);
            }
        }
    }
}

int main() {
    int n, a1, a2; // Number of test cases, and start position

    cin >> n;
    while (n--) {
        cin >> a1 >> a2 >> b1 >> b2;

        memset(moves, 0, sizeof(moves)); // Reset visited and move count
        while (!que.empty()) que.pop();  // Clear priority queue

        Knight start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = Heuristic(start);
        start.f = start.g + start.h;

        moves[a1][a2] = 0; // Start point visited, 0 moves
        astar(start);

        cout << moves[b1][b2] << endl; // Output min move count
    }

    return 0;
}