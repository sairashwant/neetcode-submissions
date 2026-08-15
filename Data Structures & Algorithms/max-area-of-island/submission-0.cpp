class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxarea = 0;

        for(int i =0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                    maxarea = max(maxarea, bfs(grid, i, j));
            }
        }

        return maxarea;
    }

    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        cout<<"called";
        int area = 1;
        int rowsize = grid.size();
        int colsize = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        while(!q.empty())
        {
            auto values = q.front(); q.pop();
            int row = values.first; int col = values.second;
            
            if(row + 1 < grid.size())
                if(grid[row+1][col] == 1)
                    {
                        q.push({row+1,col});
                        grid[row+1][col]= 0;
                        area++;
                    }

            if(col + 1 < grid[0].size())
                if(grid[row][col+1] == 1)
                    {
                        q.push({row,col+1});
                        grid[row][col+1]= 0;
                        area++;
                    }

            if(row - 1 >= 0)
                if(grid[row-1][col] == 1)
                    {
                        q.push({row-1,col});
                        grid[row-1][col]= 0;
                        area++;
                    }
            
            if(col - 1 >= 0)
                if(grid[row][col-1] == 1)
                    {
                        q.push({row,col-1});
                        grid[row][col-1]= 0;
                        area++;
                    }
        }
        return area;
    }
};
