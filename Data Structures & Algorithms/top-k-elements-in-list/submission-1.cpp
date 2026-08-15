class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;

        for(auto num : nums)
        {
            countMap[num]++;
        }

        priority_queue<pair<int, int>> freq;

        for(auto element : countMap)
        {
            freq.emplace(make_pair(element.second, element.first));
        }

        vector<int> result;

        for(int i = 1; i <= k; i++)
        {
            result.push_back(freq.top().second);
            freq.pop();
        }

        return result;
    }
};
