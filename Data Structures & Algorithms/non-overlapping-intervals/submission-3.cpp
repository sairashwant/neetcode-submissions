class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        auto compare = [&] (auto a, auto b)
        {
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), compare);

        auto temp = intervals[0];
        auto count = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(temp[1] > intervals[i][0])
                count++;
            
            else
                temp = intervals[i];
        }

        return count;
    }
};
