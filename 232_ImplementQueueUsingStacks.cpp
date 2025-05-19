class MyQueue {
public:
    // 输入栈：负责 push 操作（入队）
    stack<int> stIn;

    // 输出栈：负责 pop / peek 操作（出队）
    stack<int> stOut;

    // 构造函数（初始化两个栈）
    MyQueue() {}

    // 入队操作：直接压入输入栈
    void push(int x) {
        stIn.push(x);
    }

    // 出队操作：
    // 如果输出栈为空，则将输入栈中的所有元素倒入输出栈（顺序反转）
    // 然后从输出栈弹出栈顶元素，即为队首
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }

        int result = stOut.top();
        stOut.pop();
        return result;
    }

    // 查看队首元素：
    // 复用 pop 函数拿出队首元素，再补回去，保持状态不变
    int peek() {
        int result = this->pop();   // 取出队首元素
        stOut.push(result);         // 恢复状态
        return result;
    }

    // 判断队列是否为空：
    // 只有两个栈都为空，队列才为空
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};