// Solution 1: 
// Use small cookies to satisfy small appetites first
// Sort both arrays ascending.
// Always try to satisfy the child with the smallest remaining greed using the current smallest cookie that can fit.
// We scan cookies from small to large, and move the child pointer only when we can satisfy that child.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int satisfied = 0; // number of content children
        int child = 0;     // pointer to the smallest greed child not yet satisfied

        // Iterate cookies from smallest to largest
        for (int cookie = 0; cookie < s.size(); cookie++) {
            // If current cookie can satisfy the current smallest-greed child,
            // we match them and move to the next child.
            if (child < g.size() && s[cookie] >= g[child]) {
                satisfied++;
                child++;
            }

            // Optional micro-optimization: if all children are satisfied, break early
            // if (child == g.size()) break;
        }

        return satisfied;
    }
};



// Solution 2: 
// Use large cookies to satisfy large appetites first
// Sort both arrays ascending.
// Try to satisfy the child with the largest greed first,
// using the largest available cookie that can satisfy them.
// If the largest cookie cannot satisfy the current largest-greed child,
// then no smaller cookie can either -> skip this child.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int satisfied = 0;

        int cookie = s.size() - 1; // index of the largest remaining cookie

        // Iterate children from largest greed to smallest
        for (int child = g.size() - 1; child >= 0; child--) {
            // If we still have cookies and the largest cookie can satisfy this child
            if (cookie >= 0 && s[cookie] >= g[child]) {
                satisfied++;
                cookie--; // consume one cookie
            }
            // else: cannot satisfy this child; move to next smaller greed child
        }

        return satisfied;
    }
};

