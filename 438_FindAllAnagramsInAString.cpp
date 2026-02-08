// Logic: Sliding window + frequency difference array
//
// Core idea:
// Two strings are anagrams if and only if the frequency of every character is the same.
// Instead of sorting, we maintain a sliding window on `s` and compare it with `p`
// using a difference array.
//
// Invariant definitions:
// - need[c] = frequency of character c in p
//            minus
//            frequency of character c in current window
//
// - missing = total number of characters (by count) still missing
//             to make the current window an anagram of p
//
// When window length == p.size() and missing == 0,
// the current window is an anagram of p.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        // If s is shorter than p, no anagram is possible
        if (s.size() < p.size()) return result;

        // Build frequency table for string p
        vector<int> need(26, 0);
        for (char c : p) {
            need[c - 'a']++;
        }

        // Initially, the window is empty and we are missing all characters in p
        int missing = p.size();

        int left = 0;

        // Right pointer expands the sliding window
        for (int right = 0; right < s.size(); right++) {

            // cout << "Before" << endl;
            // cout << "Window [" << left << ", " << right << "] ";
            // cout << "missing=" << missing << " | need: ";
            // for (int i = 0; i < 26; i++) {
            //     if (need[i] != 0) {
            //         cout << char('a'+i) << ":" << need[i] << " ";
            //     }
            // }
            // cout << endl;
          
            // Add character s[right] into the window
            char in = s[right];

            // If this character is still needed, it contributes to reducing `missing`
            if (need[in - 'a'] > 0) {
                missing--;
            }

            // Update the difference array:
            // window has one more `in`, so p - window decreases by 1
            need[in - 'a']--;

            // If window size exceeds p.size(), shrink from the left
            if (right - left + 1 > p.size()) {
                char out = s[left];

                // If need[out] >= 0 before removal,
                // this character was contributing to a valid match.
                // Removing it causes the window to miss one required character.
                if (need[out - 'a'] >= 0) {
                    missing++;
                }

                // Restore the difference array since `out` leaves the window
                need[out - 'a']++;
                left++;
            }


            // cout << "After" << endl;
            // cout << "Window [" << left << ", " << right << "] ";
            // cout << "missing=" << missing << " | need: ";
            // for (int i = 0; i < 26; i++) {
            //     if (need[i] != 0) {
            //         cout << char('a'+i) << ":" << need[i] << " ";
            //     }
            // }
            // cout << endl;
            // cout << endl;

            // When window size equals p.size() and no characters are missing,
            // we have found an anagram starting at index `left`
            if (missing == 0 && right - left + 1 == p.size()) {
                result.push_back(left);
            }
        }

        return result;
    }
};
