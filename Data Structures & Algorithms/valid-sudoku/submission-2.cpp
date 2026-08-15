class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rows[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};

        for(int i=0; i < 9; i++)
        {
            for(int j=0 ; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int temp = (int) board[i][j] - '1';
                
                if(rows[i][temp] == 0)
                    rows[i][temp]++;
                
                else if(rows[i][temp] != 0)
                    return false;

                if(col[j][temp] == 0)
                    col[j][temp]++;
                
                else if(col[j][temp] != 0)
                    return false;

                if(box[(i / 3) * 3 + (j / 3)][temp] == 0)
                    box[(i / 3) * 3 + (j / 3)][temp]++;
                
                else if(box[(i / 3) * 3 + (j / 3)][temp] != 0)
                    return false;
                
            }
        }

        return true;
    }
};
