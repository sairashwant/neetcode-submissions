class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        
        for(auto i : nums)
        {
            if(hashMap[i] == 0)
            {
                hashMap[i]++;
            }

            else
                return true;
        }

        return false;
    }
};