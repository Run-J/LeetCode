
// 此解法尝试单队列实现
class MyStack {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size = size - 1;
        while (size--) { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }

        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        int size = que.size();
        size = size - 1;
        while (size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.push(que.front()); // 将获取完的元素也重新添加到队列尾部，保证数据结构没有变化
        que.pop();
        return result;
    }
    
    bool empty() {
        return que.empty();
    }
};
