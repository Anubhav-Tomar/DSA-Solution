class Solution {
public:
    int solve(vector<int>& prices){
        int n = prices.size();
        vector<vector<int> > curr(2,vector<int>(3,0));
        vector<vector<int> > next(2,vector<int>(3,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limits=1; limits<=2; limits++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[index] + next[0][limits], 0 + next[1][limits]);
                    }
                    else{
                        profit = max(prices[index] + next[1][limits-1], 0 + next[0][limits]);
                    }
                    curr[buy][limits] = profit;
                }
                next = curr;
            }
        }
        return curr[1][2];
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};