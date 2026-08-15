class StockSpanner {
public:

    stack<int> stk;

    StockSpanner() {
        
    }
    
    int next(int price) {

        stack<int> localstk;
        
        stk.push(price);
        localstk = stk;
        int count = 0;
        
        while(!localstk.empty() && localstk.top() <= price)
        {
            count++;
            localstk.pop();
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */