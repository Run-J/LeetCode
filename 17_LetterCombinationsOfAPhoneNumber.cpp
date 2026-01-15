/*
 * LOGIC EXPLANATION:
 * 1. Mapping: We use an array (letterMap) to map each digit to its corresponding letters.
 * 2. Backtracking:
 * - We explore one digit at a time using the 'index' variable.
 * - For each digit, we loop through all possible letters it can represent.
 * - 's.push_back' adds a letter to our current path, and 'backtracking' moves to the next digit.
 * - 's.pop_back' (The Backtrack Step) removes the letter so we can try the next letter
 * for the same digit position.
 * 3. Base Case: When 'index' equals the input length, the current combination 's' is complete.
 */

class Solution {
private:
    const string letterMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> results;
    string s;

    void backtracking(const string& digits, int index) {
        // Base Case: If index reaches the end, we found a complete combination
        if (index == digits.size()) {
            results.push_back(s);
            return;
        }

        // Convert the current character digit to an integer index (e.g., '2' becomes 2)
        int digit = digits[index] - '0';
        string letters = letterMap[digit];

        // Iterate through all possible letters for the current digit
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);         // Choose: Add letter to current combination
            backtracking(digits, index + 1); // Explore the next level of the decision tree
            s.pop_back();                    // Un-choose: Remove letter to backtrack and try others
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        // Clear global state to ensure fresh results for every test case
        s.clear();
        results.clear();
        
        if (digits.empty()) return results;

        backtracking(digits, 0);
        return results;
    }
};
