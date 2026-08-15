class MinStack {
public:

    stack<int> stk;
    stack<int> stk2;

    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(stk2.empty())
            stk2.push(val);
        else
            if(stk2.top() > val)
                stk2.push(val);
            else
                stk2.push(stk2.top());
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
