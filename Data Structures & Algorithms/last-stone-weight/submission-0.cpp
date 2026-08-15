class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> weights(stones.begin(),stones.end());

        while(weights.size()!=1)
        {
            int first = weights.top();
            weights.pop();

            int second = weights.top();
            weights.pop();

            int diff = abs(first - second);
            weights.push(diff);
        }

        int res = weights.top();
        weights.pop();
        return res;
    }
};