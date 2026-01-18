class Solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(const string& s, int startIndex) {
        // Reached the end: current `path` is one complete partition.
        if (startIndex == (int)s.size()) {
            result.push_back(path);
            return;
        }

        // Try all possible end positions for the next cut.
        for (int i = startIndex; i < (int)s.size(); i++) {
            // Prune: only proceed if s[startIndex..i] is a palindrome.
            if (!isPalindrome(s, startIndex, i)) continue;

            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backtracking(s, i + 1);                                   
            path.pop_back();                                          
        }
    }

    // Check palindrome on inclusive range [start, end].
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};
