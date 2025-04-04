class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int hashArray[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            int hash = s[i] - 'a';
            hashArray[hash]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            int hash = t[i] - 'a';
            hashArray[hash]--;
        }

        for (int i = 0; i < 26; i++)
        {
            // If any element of the record array is not zero zero, the strings s and t must be either more or less characters.
            if (hashArray[i] != 0) return false;
        }

        return true;

    }
};