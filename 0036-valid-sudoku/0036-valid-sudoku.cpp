class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int grid[9][9] = {0};

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board.size(); j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    
                    int k = i/3 * 3 + j/3;

                    if(row[i][ch-'1']++ || col[j][ch-'1']++ || grid[k][ch-'1']++){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};