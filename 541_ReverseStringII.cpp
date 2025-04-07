class Solution {
public:
    string reverseStr(string s, int k) {
        
        for (int i = 0; i < s.size(); i += (2*k) )
        {
            // 1. Reverse the first k characters of every 2k characters
            // 2. If the remaining characters are less than 2k but greater than or equal to k, reverse the first k characters
            if ( i+k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }

            // 3. If there are less than k characters left, reverse all the remaining characters.
            reverse( s.begin() + i, s.end() );
        }

        return s;

    }

};
