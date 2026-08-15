class Solution {
public:

    stack<int> numstk;
    stack<string> charstk;
    int k = 0;

    string decodeString(string s) {

        string curr = "";
        string result = "";
        
        for(char ch : s)
        {
            if(isdigit(ch))
            {
                k = k * 10 + (ch - '0');
            }

            else if(ch=='[')
            {
                numstk.push(k);
                charstk.push(curr);
                curr = "";
                k = 0;
            }

            else if(ch == ']')
            {
                int count = 0;
                string temp = "";

                if(!numstk.empty() && !charstk.empty())
                {
                    count = numstk.top();
                    temp = charstk.top();
                    numstk.pop();
                    charstk.pop();
                
                    result.clear();
                    for(int i = 0;i < count; i++)
                    {
                        result = result + curr;
                    }

                    curr = temp + result;
                }
            }

            else
            {
                curr = curr + ch;
            }
        }

        return curr;
    }
};