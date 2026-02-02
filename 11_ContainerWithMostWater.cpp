class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while (left < right) {
            // Area is determined by the shorter side and the width
            int minHeight = min(height[left], height[right]);
            result = max(result, minHeight * (right - left));

            // Greedy choice:
            // The current area is limited by the shorter line.
            // Moving the taller line cannot increase the height,
            // and the width will only decrease.
            // Therefore, always move the shorter line.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
