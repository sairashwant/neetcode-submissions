class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        int i = 0;

        while(i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        vector<int> temp = newInterval;

        for(; i < intervals.size(); i++)
        {
            if(temp[1] >= intervals[i][0])
            {
                temp[0] = min(temp[0], intervals[i][0]);
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
