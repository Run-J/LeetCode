// Logic:
// Maintain a helper stack that stores the minimum value
// at each depth of the main stack.
// so all operations including getMin run in O(1) time.
class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (!minSt.empty()) minSt.push( min( val, minSt.top() ) );
        else minSt.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
