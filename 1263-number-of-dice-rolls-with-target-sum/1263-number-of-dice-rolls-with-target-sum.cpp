class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int d, int f, int t){
        vector<vector<int> > dp(d+1, vector<int>(t+1, 0));
        
        dp[0][0] = 1;

        for(int dice = 1; dice <= d; dice++){
            for(int target = 1; target <= t; target++){
                int ans = 0;
                for(int i=1; i<=f; i++){
                    if( target - i >= 0){
                        ans = (ans + dp[dice-1][target-i]) % mod;
                    }
                }
                dp[dice][target] = ans;
            }
        }
        return dp[d][t];
    }

    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};