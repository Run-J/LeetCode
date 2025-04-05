class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int letters[26] = {0};

        if ( ransomNote.size() > magazine.size() )
        {
            return false;
        }


        for (int i = 0; i < magazine.length(); i++)
        {
            letters[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            letters[ransomNote[i] - 'a']--;

            // If it's less than zero, it means that the characters that appear in ransomNote are not in the magazine.
            if (letters[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }

        }

        return true;
        
    }
};