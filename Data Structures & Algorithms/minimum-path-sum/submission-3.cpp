class Solution {
public:
    vector<vector<int>> memo;
    int minPathSum(vector<vector<int>>& grid) {
        memo.resize(grid.size()+1, vector<int>(grid[0].size()+1, -1));

        return findpath(grid, 0, 0);
    }

    int findpath(vector<vector<int>>& grid, int i, int j)
    {
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];
        
        if(memo[i][j] != -1) return memo[i][j];

        int down = INT_MAX;
        int right = INT_MAX;

        if(i+1 < grid.size())
            down = grid[i][j] + findpath(grid, i+1, j);
        
        if(j+1 < grid[0].size())
            right = grid[i][j]+findpath(grid, i, j+1);

        return memo[i][j]=min(down, right);
    }
};