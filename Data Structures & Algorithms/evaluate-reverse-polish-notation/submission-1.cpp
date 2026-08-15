class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for(auto& ch : tokens)
        {
            if(ch=="+")
                {
                    int val1 = stoi(stk.top());
                    stk.pop();
                    int val2 = stoi(stk.top());
                    stk.pop();
                    int sum = val2 + val1;
                    stk.push(to_string(sum));
                }

            else if(ch=="-")
                {
                    int val1 = stoi(stk.top());
                    stk.pop();
                    int val2 = stoi(stk.top());
                    stk.pop();
                    int diff = val2 - val1;
                    stk.push(to_string(diff));
                }

            else if(ch=="*")
                {
                    int val1 = stoi(stk.top());
                    stk.pop();
                    int val2 = stoi(stk.top());
                    stk.pop();
                    int pdt = val2 * val1;
                    stk.push(to_string(pdt));
                }
            else if(ch=="/")
                {
                    int val1 = stoi(stk.top());
                    stk.pop();
                    int val2 = stoi(stk.top());
                    stk.pop();
                    int div = val2 / val1;
                    stk.push(to_string(div));
                }
            else
                stk.push(ch);
        }
        return stoi(stk.top());
    }
};
