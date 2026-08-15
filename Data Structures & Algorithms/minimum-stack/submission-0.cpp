class MinStack {
public:
    stack<int> stk;
    stack<int> stk2;
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        val = min(val, stk2.empty()? val : stk2.top());
        stk2.push(val);
    }
    
    void pop() {
        stk.pop();
        stk2.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        
        return stk2.top();
    }
};
