// 59. Spiral Matrix II — Generate an n x n spiral matrix

// Core idea: Simulate the spiral path layer by layer
// Use `startX` and `startY` to represent the top-left starting point of each layer
// `offset` controls how far inward each layer goes
// `loop` is the number of full layers (or "circles"); if n is odd, there's a center element left

// For each layer, fill in values in the following order:
// 1. Top row: left to right
// 2. Right column: top to bottom
// 3. Bottom row: right to left
// 4. Left column: bottom to top

// At the end, if n is odd, assign the center element separately


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int startX = 0; 
        int startY = 0;
        int counter = 1;
        int offset = 1;
        int loop = n / 2;

        vector<vector<int>> nums(n, vector<int>(n, 0));
        while (loop--)
        {
            int i = startX;
            int j = startY;

            for ( ; j < n - offset; j++)
            {
                nums[startX][j] = counter++;
            } // j (horizontal) == 2 now

            for ( ; i < n - offset; i++)
            {
                nums[i][j] = counter++;
            } // i (vertical) == 2 now
            
            for ( ; j > startX; j--)
            {
                nums[i][j] = counter++;
            } // j (honrizontal) == startX now

            for ( ; i > startY; i--)
            {
                nums[i][j] = counter++;
            }

            startX++;
            startY++;
            offset++;
        }


        if (n % 2 == 1)
        {
            nums[startX][startY] = counter++;
        }

        return nums;
    }
};


// 59. 螺旋矩阵 II —— 生成 n x n 的螺旋矩阵

// 核心思路：使用循环模拟法（模拟螺旋路径）
// 使用 startX 和 startY 表示每层起始点（左上角）
// offset 表示当前层的边界偏移（用于控制内缩）
// loop 表示循环的层数（即圈数），n 为奇数时中间还有一个单独的点需要处理

// 每一层按照以下顺序填充：
// 1. 从左到右填充上边界
// 2. 从上到下填充右边界
// 3. 从右到左填充下边界
// 4. 从下到上填充左边界

// 最后如果 n 为奇数，中间的中心点需要单独赋值
