class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string stk;
        backtrack(0, 0, n, result, stk);
        return result;
    }

    void backtrack(int openB, int closeB, int n, vector<string> &result, string str)
    {
        if(openB == closeB && closeB == n)
        {
            result.push_back(str);
            return;
        }

        if(openB < n)
        {
            str += '(';
            backtrack(openB + 1, closeB, n, result, str);
            str.pop_back();
        }

        if(closeB < openB)
        {
            str += ')';
            backtrack(openB, closeB+1, n, result, str);
            str.pop_back();
        }
    }
};
