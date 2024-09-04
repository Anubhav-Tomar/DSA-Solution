class Solution {
public:
    int solve(vector<vector<char>>& matrix, int row, int col, int &maxi, vector<vector<int>> &dp) {
        if (row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int right = solve(matrix, row, col + 1, maxi, dp);
        int diagonal = solve(matrix, row + 1, col + 1, maxi, dp);
        int down = solve(matrix, row + 1, col, maxi, dp);

        if (matrix[row][col] == '1') {
            dp[row][col] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[row][col]);
            return dp[row][col];
        }
        else{
            return 0;
        } 
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        solve(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
};