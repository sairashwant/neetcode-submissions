class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> stk;
        int num1 = 0, num2 = 0, result;

        for(auto ch : tokens)
        {
            if(ch == "+")
            {
                if(!stk.empty())
                {
                    num1 = stoi(stk.top());
                    stk.pop();
                }

                if(!stk.empty())
                {
                    num2 = stoi(stk.top());
                    stk.pop();
                }

                string result = to_string(num1 + num2);

                stk.push(result);
            }
            
            else if(ch == "-")
            {
                if(!stk.empty())
                {
                    num1 = stoi(stk.top());
                    stk.pop();
                }

                if(!stk.empty())
                {
                    num2 = stoi(stk.top());
                    stk.pop();
                }

                string result = to_string(num2 - num1);

                stk.push(result);
            }

            else if(ch == "*")
            {
                if(!stk.empty())
                {
                    num1 = stoi(stk.top());
                    stk.pop();
                }

                if(!stk.empty())
                {
                    num2 = stoi(stk.top());
                    stk.pop();
                }

                string result = to_string(num1 * num2);

                stk.push(result);
            }

            else if(ch == "/")
            {
                if(!stk.empty())
                {
                    num1 = stoi(stk.top());
                    stk.pop();
                }

                if(!stk.empty())
                {
                    num2 = stoi(stk.top());
                    stk.pop();
                }

                string result = to_string(num2 / num1);

                stk.push(result);
            }

            else
                stk.push(ch);
        }

        return stoi(stk.top());
    }
};
