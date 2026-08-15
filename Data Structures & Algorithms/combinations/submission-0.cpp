class Solution {
public:

    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> comb;
        backtrack(1, n, k, comb);
        return res;
    }

    void backtrack(int i, int n, int k, vector<int> &comb)
    {
        if(i > n){
            if(comb.size() == k)
            {
                res.push_back(comb);
            }

            return;
        }

        comb.push_back(i);
        backtrack(i+1, n, k, comb);
        comb.pop_back();
        backtrack(i+1, n, k, comb);
    }
};