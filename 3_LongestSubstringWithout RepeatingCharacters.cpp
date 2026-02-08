// Logic: Sliding Window + Hash Table
//
// Core Idea:
// Maintain a sliding window [left, right] that always contains
// unique characters. Expand the window by moving 'right' forward.
// If a duplicate character is found inside the window, move 'left'
// to the position right after the previous occurrence of that character.
//
// Time Complexity: O(n)
// Space Complexity: O(1) - fixed size array for ASCII characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // lastShow[c] stores the last index where character 'c' appeared
        // initialized to -1 meaning the character has not appeared yet
        vector<int> lastShow(256, -1);

        int left = 0;     // left boundary of the sliding window
        int result = 0;   // maximum length found so far

        for (int right = 0; right < s.size(); right++) {
            int cur = s[right];

            // If the current character appeared inside the current window,
            // move the left boundary to the position after its last occurrence
            if (lastShow[cur] >= left) {
                left = lastShow[cur] + 1;
            }

            // Update the last seen index of the current character
            lastShow[cur] = right;

            // Update the maximum length of valid window
            result = max(result, right - left + 1);
        }

        return result;
    }
};
