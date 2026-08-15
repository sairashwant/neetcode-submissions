class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        ans = nums;
        for(auto num : nums)
        {
            ans.push_back(num);
        }

        return ans;
    }
};