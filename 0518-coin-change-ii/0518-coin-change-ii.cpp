class Solution {
public:
    int solve(int ind, int a, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            return (a % coins[0] == 0);
        }

        if(dp[ind][a] != -1){
            return dp[ind][a];
        }

        int take = 0;
        int notTake = solve(ind-1, a, coins, dp);
        if(a >= coins[ind]){
            take = solve(ind, a - coins[ind], coins, dp);
        }

        return dp[ind][a] = (take + notTake);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};