class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> result(n);
        stack<pair<int,int>> stk;

        for(int i = 0; i < n; i++)
        {
            int count = 1;
            int j = i + 1;
            int t = temperatures[i];

            while(!stk.empty() && t > stk.top().first)
            {
                auto pair = stk.top();
                stk.pop();
                result[pair.second] = i - pair.second;
            }
            stk.push({t, i});
        }        

        return result;
    }
};
