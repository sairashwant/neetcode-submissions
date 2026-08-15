class Solution {
    vector<vector<int>> memo;
public:
    bool stoneGame(vector<int>& piles) {
        memo.resize(piles.size()+1, vector<int>(piles.size()+1, -1));
        return pickStone(piles, 0, piles.size()-1) > 0;
    }

    int pickStone(vector<int>& piles, int start, int end)
    {
        if(start-end == 1)
            return piles[start];

        if(memo[start][end] != -1) return memo[start][end];

        int left = piles[start] - pickStone(piles, start+1, end);
        int right = piles[end] - pickStone(piles, start, end-1);

        return memo[start][end] = max(left, right);
    }
};