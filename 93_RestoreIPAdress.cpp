class Solution {
private:
    vector<string> result;

    // Check whether substring s[start..end] is a valid IPv4 segment
    bool isValid(const string& s, int start, int end) {
        // Empty range is invalid
        if (start > end) {
            return false;
        }

        // Leading zero is not allowed unless the segment is exactly "0"
        if (s[start] == '0' && start != end) {
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; i++) {
            // Non-digit character is invalid
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }

            // Build the number incrementally
            num = num * 10 + (s[i] - '0');

            // IPv4 segment must be <= 255
            if (num > 255) {
                return false;
            }
        }

        return true;
    }

    // Backtracking to insert dots and build valid IP addresses
    void backtracking(string& s, int startIndex, int dotSum) {
        // If 3 dots have been inserted, check the last segment
        if (dotSum == 3) {
            // Validate the fourth (last) segment
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            // Check if current segment s[startIndex..i] is valid
            if (isValid(s, startIndex, i)) {
                // Insert dot after position i
                s.insert(s.begin() + i + 1, '.');
                dotSum++;

                // Move to the next segment (i + 2 because of the inserted dot)
                backtracking(s, i + 2, dotSum);

                // Backtrack: remove the dot
                s.erase(s.begin() + i + 1);
                dotSum--;
            } else {
                // If current segment is invalid, longer ones will also be invalid
                break;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();

        // Pruning: valid IP address length is between 4 and 12
        if (s.size() < 4 || s.size() > 12) {
            return result;
        }

        backtracking(s, 0, 0);
        return result;
    }
};
