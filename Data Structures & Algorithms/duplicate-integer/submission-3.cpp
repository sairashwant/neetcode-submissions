class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;
        for(int num : nums)
        {
            if(map[num]>0)
                return true;
            
            else
                map[num]++;
        }

        return false;
    }
};