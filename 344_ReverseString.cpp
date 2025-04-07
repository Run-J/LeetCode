
// Two pointers
class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }

    }
};



class Solution {
public:
    void reverseString(vector<char>& s) {
        
    for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
        swap(s[i],s[j]);
    }

    }
};
