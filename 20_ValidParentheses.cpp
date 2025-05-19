class Solution {
public:
    // 判断括号字符串是否有效：必须左括号和右括号一一配对且嵌套顺序正确
    bool isValid(string s) {

        // 如果字符数是奇数，肯定无法完全配对
        if (s.size() % 2 != 0) return false;

        // 栈用于存放“期望遇到的右括号”
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            // 如果是左括号，压入与之对应的右括号（预期匹配值）
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else {
                // 遇到右括号时，若栈为空 or 栈顶不是当前字符，说明不匹配
                if (st.empty() || st.top() != s[i]) return false;

                // 匹配成功后，弹出
                st.pop();
            }
        }

        // 若所有括号都成功配对，栈应为空；如果不为空，意味着有相应的左括号没有右括号来匹配
        return st.empty();
    }
};
