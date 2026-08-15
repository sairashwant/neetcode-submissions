class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> result;
    unordered_map<int, int> countMap;

      for (auto num : nums)
      {
        countMap[num]++;
      }

      priority_queue<pair<int, int>> pq;

      for(auto hm : countMap)
      {
        pq.emplace(make_pair(hm.second, hm.first));
      }

      for(int i = 0; i < k; i++)
      {
        result.push_back(pq.top().second);
        pq.pop();
      }

      return result;
    }
};
