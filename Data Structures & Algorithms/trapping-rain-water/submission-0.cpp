class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMaxList(height.size(), 0);
        vector<int> rightMaxList(height.size(), 0);

        int leftMax = 0;
        int rightMax = 0;

        for(int i = 0; i < height.size(); i++)
        {
            leftMax = max(leftMax, height[i]);
            leftMaxList[i]=leftMax;
        }

        for(int i = height.size()-1; i >= 0; i--)
        {
            rightMax = max(rightMax, height[i]);
            rightMaxList[i]=rightMax;
        }

        int water = 0;
        for(int i = 0; i< height.size(); i++)
        {
            water += min(leftMaxList[i], rightMaxList[i])-height[i];
        }
        return water;
    }
};
