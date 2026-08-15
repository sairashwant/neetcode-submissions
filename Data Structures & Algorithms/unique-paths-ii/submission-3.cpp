class Solution {
public:
    vector<vector<int>> cache;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        cache.resize(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));

        return dfs(obstacleGrid, 0, 0);
    }

    int dfs(vector<vector<int>>& obstacleGrid, int i, int j)
    {
        int down = 0;
        int right = 0;

        if(i == obstacleGrid.size() || j == obstacleGrid[i].size() || obstacleGrid[i][j] == 1)
            return 0;

        if(i == obstacleGrid.size()-1 && j == obstacleGrid[i].size()-1)
            return 1;

        if(cache[i][j] != -1)  return cache[i][j];

        if(i+1 <= obstacleGrid.size()-1)
            down = dfs(obstacleGrid, i+1, j);

        if(j+1 <= obstacleGrid[i].size()-1)
            right = dfs(obstacleGrid, i, j+1);

        return cache[i][j] = down + right;
    }
};