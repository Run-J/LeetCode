// Core idea:
// Use the sorted string as a hash key.
// All anagrams will produce the same sorted string,
// so they can be grouped together using a hash map.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map:
        // key   -> sorted version of the string
        // value -> all original strings that match this key
        unordered_map<string, vector<string>> mp;

        // Iterate through each string
        for (const string& s : strs) {
            // Create a key by sorting the characters
            string key = s;
            sort(key.begin(), key.end());

            // Group original string by its sorted key
            mp[key].push_back(s);
        }

        // Collect grouped anagrams from the map
        vector<vector<string>> result;
        for (const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
