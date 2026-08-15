class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int rows = board.size();
        int cols = board[0].size();

        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[0][j] == 'O')
                board[0][j] = 'T';
            
            if(board[rows-1][j] == 'O')
                board[rows-1][j] = 'T';
        }

        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][0] == 'O')
                board[i][0] = 'T';

            if(board[i][cols-1] == 'O')
                board[i][cols-1] = 'T';
        }

        for(int i =0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 'T')
                    bfs(board, i, j);
            }
        }

        for(int i =0; i < board.size(); i++)
        {
            for(int j = 0; j< board[i].size(); j++)
            {
                if(board[i][j] == 'O')
                    board[i][j]='X';
                
                if(board[i][j] == 'T')
                    board[i][j]='O';
            }
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i,j});

        while(!q.empty())
        {
            auto val = q.front();
            q.pop();
            int r = val.first;
            int c = val.second;

            if(r-1 >= 0)
            {
                if(board[r-1][c] == 'O')    
                {
                    board[r-1][c] = 'T';
                    q.push({r-1,c});
                }
            }

            if(c-1 >= 0)
            {
                if(board[r][c-1] == 'O')    
                {
                    board[r][c-1] = 'T';
                    q.push({r,c-1});
                }
            }

            if(r+1 < board.size())
            {
                if(board[r+1][c] == 'O')    
                {
                    board[r+1][c] = 'T';
                    q.push({r+1,c});
                }
            }

            if(c+1 < board[r].size())
            {
                if(board[r][c+1] == 'O')    
                {
                    board[r][c+1] = 'T';
                    q.push({r,c+1});
                }
            }

        }
    }
};
