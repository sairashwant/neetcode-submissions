class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0; int j = heights.size()-1;
        int maxarea = 0;
        while(i < j)
        {
            int area = min(heights[i],heights[j])*(j-i);
            maxarea = max(area, maxarea);
            if(heights[i] <= heights[j])
                i=i+1;
            else
                j=j-1;
        }

        return maxarea;
    }
};
