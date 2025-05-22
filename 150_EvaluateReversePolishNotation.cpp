class Solution {
public:
    // 计算逆波兰表达式（Reverse Polish Notation, RPN）的结果
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;  // 使用栈来存储操作数

        int tokensSize = tokens.size();

        for (int i = 0; i < tokensSize; i++) {
            // 如果当前 token 是操作符
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int newValue = st.top(); st.pop();  // 后弹出的数字(上一个运算结果）：作为右操作数
                int lastValue = st.top(); st.pop(); // 先弹出的数字：作为左操作数

                // 按照对应操作符执行计算，并将结果压回栈中
                if (tokens[i] == "+") st.push(lastValue + newValue);
                if (tokens[i] == "-") st.push(lastValue - newValue);
                if (tokens[i] == "*") st.push(lastValue * newValue);
                if (tokens[i] == "/") st.push(lastValue / newValue); // 注意整数除法
            }
            // 如果是数字字符串，转为整数压入栈中
            else {
                st.push(stoi(tokens[i]));  // stoi：string → int
            }
        }

        // 栈顶即为最终计算结果
        int result = st.top();
        st.pop();

        return result;
    }
};