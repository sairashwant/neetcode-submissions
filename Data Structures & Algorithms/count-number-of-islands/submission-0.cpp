class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        
        if(grid.size() == 0)
            return 0;
        
        int rows = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                    {
                        bfs(grid, i, j);
                        island++;
                    }
            }
        }

        return island;

    }

    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while(!q.empty())
        {
            auto node = q.front(); q.pop();
            int row = node.first; int col = node.second;

            if(row + 1 < grid.size())
                if(grid[row+1][col] == '1')
                    {
                        q.push({row+1,col});
                        grid[row+1][col]= '0';
                    }

            if(col + 1 < grid[0].size())
                if(grid[row][col+1] == '1')
                    {
                        q.push({row,col+1});
                        grid[row][col+1]= '0';
                    }

            if(row - 1 >= 0)
                if(grid[row-1][col] == '1')
                    {
                        q.push({row-1,col});
                        grid[row-1][col]= '0';
                    }
            
            if(col - 1 >= 0)
                if(grid[row][col-1] == '1')
                    {
                        q.push({row,col-1});
                        grid[row][col-1]= '0';
                    }

        }
    }
};
