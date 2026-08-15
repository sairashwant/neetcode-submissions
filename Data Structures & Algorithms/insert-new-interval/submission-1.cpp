class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;

        intervals.push_back(newInterval);

        auto compare = [&] (auto a, auto b)
        {
            return a < b;
        };
        
        sort(intervals.begin(), intervals.end(), compare);

        int k = 0;

        vector<int> temp = intervals[0];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(temp[1] >= intervals[i][0])
            {
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else
            {
                result.push_back(temp);
                temp = intervals[i];
            }
        }
        result.push_back(temp);
        return result;
    }
};
