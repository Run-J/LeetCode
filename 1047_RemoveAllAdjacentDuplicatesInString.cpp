class Solution {
public:
    // 删除字符串中所有相邻重复的字符（两两抵消），直到无法再删
    string removeDuplicates(string s) {
        
        // 用 string 来模拟一个栈：result 是“当前保留的字符序列”
        string result;

        // 遍历输入字符串的每个字符
        for (char ch : s) {
            // 如果栈为空，或者栈顶元素 != 当前字符，就压入栈
            if (result.empty() || result.back() != ch) {
                result.push_back(ch);
            }
            // 否则说明出现相邻重复字符，弹出栈顶（抵消）
            else {
                result.pop_back();
            }
        }

        // 遍历结束后，栈中剩下的就是最终结果
        return result; 
    }
};