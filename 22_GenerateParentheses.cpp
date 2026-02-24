 // Logic:
 // - Use backtracking to generate all valid combinations of parentheses.
 // - Track the number of opening (`openCounter`) and closing (`closeCounter`) parentheses.
 // - Add `'('` if `openCounter < n`, and `')'` if `closeCounter < openCounter`.
 // - Once both counters reach `n`, a valid combination is formed.
class Solution {
private:
    vector<string> result;
    string path;

    void backtracking(int n, int openCounter, int closeCounter) {
        // If both open and close counters have reached n, we've built a valid combination
        if (openCounter == n && closeCounter == n) {
            result.push_back(path);
            return;
        }

        // If we can still add an opening parenthesis '('
        if (openCounter < n) {
            path.push_back('(');
            backtracking(n, openCounter + 1, closeCounter);
            path.pop_back();
        }

        // If we can still add a closing parenthesis ')', i.e., we have more opening parentheses to match
        if (closeCounter < openCounter) {
            path.push_back(')');
            backtracking(n, openCounter, closeCounter + 1);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        result.clear();
        path.clear();
        backtracking(n, 0, 0);
        return result;
    }
};
