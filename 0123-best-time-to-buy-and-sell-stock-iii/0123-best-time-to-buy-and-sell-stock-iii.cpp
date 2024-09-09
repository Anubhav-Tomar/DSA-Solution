class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, int limits, vector<vector<vector<int> > >& dp){
        if(index == prices.size()){
            return 0;
        }

        if(limits == 0){
            return 0;
        }

        if(dp[index][buy][limits] != -1){
            return dp[index][buy][limits];
        }

        int profit = 0;

        if(buy){
            profit = max(-prices[index] + solve(index+1, 0, prices, limits, dp), 0 + solve(index+1, 1, prices, limits, dp));
        }
        else{
             profit = max(prices[index] + solve(index+1, 1, prices, limits-1, dp), 0 + solve(index+1, 0, prices, limits, dp));
        }
        return dp[index][buy][limits] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(3, -1) ) );
        return solve(0, 1, prices, 2, dp);
    }
};