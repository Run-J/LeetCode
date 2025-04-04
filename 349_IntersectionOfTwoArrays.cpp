
// Solution 1: use set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // remove the duplicates

        for (int num : nums2)
        {
            if ( nums_set.find(num) != nums_set.end() )
            {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};


// Solution 2: use array, here I can use array, bcoz the question description said the 1 <= nums1.length, nums2.length <= 1000
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> result;
        int nums_set[1005] = {0};

        for (int num : nums1)
        {
            nums_set[num] = 1;
        }

        for (int num : nums2)
        {
            if ( nums_set[num] == 1 ) result.insert(num);
        }

        return vector<int>(result.begin(), result.end() );

    }
};