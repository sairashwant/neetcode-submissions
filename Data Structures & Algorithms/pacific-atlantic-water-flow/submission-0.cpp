class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> result;
        vector<int> temp;

        if(heights.size() == 0)
            return result;

        vector<vector<bool>> pacific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(),false));

        int rows = heights.size();
        int cols = heights[0].size();

        for(int j = 0; j < cols; j++)
        {
            bfs(heights, pacific, 0, j);
        }
        for(int i = 0; i < rows; i++)
        {
            bfs(heights, pacific, i, 0);
        }
        for(int j = cols-1; j>= 0; j--)
        {
            bfs(heights, atlantic, rows-1, j);
        }
        for(int i = rows-1; i >= 0; i--)
        {
            bfs(heights, atlantic, i, cols-1);
        }

        for(int i = 0; i < pacific.size(); i++)
        {
            for(int j = 0; j < pacific[i].size(); j++)
            {
                if(pacific[i][j]==true && atlantic[i][j] == true)
                    {
                        temp.push_back(i);
                        temp.push_back(j);
                        result.push_back(temp);
                        temp.clear();
                    }
            }
        }
        return result;
    }

    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int i, int j)
    {
        queue<pair<int, int>> q;
        
        q.push({i, j});

        while(!q.empty())
        {
            auto value = q.front();
            int row = value.first;
            int col = value.second;
            ocean[row][col] = true;
            q.pop();

            if(row - 1 >= 0)
            {
                if(!ocean[row-1][col] && heights[row-1][col] >= heights[row][col])
                    {
                        ocean[row-1][col] = true;
                        q.push({row-1, col});
                    }
            }

            if(col - 1 >= 0)
            {
                if(!ocean[row][col-1] && heights[row][col-1] >= heights[row][col])
                {
                    ocean[row][col-1] = true;
                    q.push({row, col-1});
                }
            }

            if(row + 1 < heights.size())
            {
                if(!ocean[row+1][col] && heights[row+1][col] >= heights[row][col])
                    {
                        ocean[row+1][col] = true;
                        q.push({row+1, col});
                    }
            }

            if(!ocean[row][col+1] && col + 1 < heights[row].size())
            {
                if(heights[row][col+1] >= heights[row][col])
                    {
                        ocean[row][col+1] = true;
                        q.push({row, col+1});
                    }
            }
        }
    }
};
