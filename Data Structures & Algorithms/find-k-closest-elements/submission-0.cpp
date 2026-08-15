class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        
        for(auto num : arr)
        {
            int diff = abs(num - x);
            minHeap.emplace(make_pair(diff, num));
        }

        vector<int> result;

        for(int i = 1; i <= k; i++)
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};